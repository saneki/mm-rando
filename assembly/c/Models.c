#include <stdbool.h>
#include <z2.h>
#include "Items.h"
#include "ItemOverride.h"
#include "LoadedModels.h"
#include "Misc.h"
#include "MMR.h"
#include "Models.h"
#include "Objheap.h"
#include "Util.h"

#define OBJHEAP_SLOTS (12)
#define OBJHEAP_SIZE  (0x20000)

struct objheap_item gObjheapItems[OBJHEAP_SLOTS] = { 0 };
struct objheap gObjheap = { 0 };

static void ScaleTopMatrix(f32 scaleFactor) {
    f32* matrix = z2_GetMatrixStackTop();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[4*i + j] *= scaleFactor;
        }
    }
}

static void SetObjectSegment(GlobalContext* ctxt, const void* buf) {
    // Write to polyXlu.
    DispBuf* xlu = &ctxt->state.gfxCtx->polyXlu;
    gSPSegment(xlu->p++, 6, (u32)buf);
    // Write to polyOpa.
    DispBuf* opa = &ctxt->state.gfxCtx->polyOpa;
    gSPSegment(opa->p++, 6, (u32)buf);
}

static void DrawModelLowLevel(Actor* actor, GlobalContext* ctxt, s8 graphicIdMinus1) {
    z2_PreDraw1(actor, ctxt, 0);
    z2_PreDraw2(actor, ctxt, 0);
    z2_BaseDrawGiModel(ctxt, graphicIdMinus1);
}

static void DrawModel(struct Model model, Actor* actor, GlobalContext* ctxt, f32 baseScale) {
    // If both graphic & object are 0, draw nothing.
    if (model.graphicId == 0 && model.objectId == 0) {
        return;
    }

    struct objheap_item* object = objheap_allocate(&gObjheap, model.objectId, actor->room);
    if (object) {
        // Update RDRAM segment table with object pointer during the draw function.
        // This is required by Moon's Tear (and possibly others), which programatically resolves a
        // segmented address using that table when writing instructions to the display list.
        gRspSegmentPhysAddrs.currentObject = (u32)object->buf & 0xFFFFFF;
        // Scale matrix and call low-level draw functions.
        SetObjectSegment(ctxt, object->buf);
        ScaleTopMatrix(baseScale);
        DrawModelLowLevel(actor, ctxt, model.graphicId - 1);
    }
}

/**
 * "Fix" the graphic Id used in the Get-Item table.
 **/
static u8 FixGraphicId(u8 graphic) {
    if (graphic >= 0x80) {
        return (u8)(0x100 - (u16)graphic);
    } else {
        return graphic;
    }
}

/**
 * Get the Get-Item table entry for a specific index, and optionally load relevant entry values
 * into a model structure for drawing.
 **/
static GetItemEntry* PrepareGiEntry(struct Model* model, GlobalContext* ctxt, u16 giIndex, bool resolve) {
    if (resolve) {
        giIndex = MMR_GetNewGiIndex(ctxt, 0, giIndex, false);
    }
    GetItemEntry* entry = MMR_GetGiEntry(giIndex);

    if (model != NULL) {
        u16 gfx, obj;
        if (ItemOverride_GetGraphic(giIndex, &gfx, &obj)) {
            model->graphicId = FixGraphicId((u8)gfx);
            model->objectId = obj;
        } else {
            u8 graphic = FixGraphicId(entry->graphic);
            model->objectId = entry->object;
            model->graphicId = graphic;
        }
    }

    return entry;
}

/**
 * Load information from the Get-Item table using an index and draw the corresponding model.
 **/
static void DrawFromGiTable(Actor* actor, GlobalContext* ctxt, f32 scale, u16 giIndex) {
    struct Model model;
    GetItemEntry* entry = PrepareGiEntry(&model, ctxt, giIndex, true);
    z2_CallSetupDList(gGlobalContext.state.gfxCtx);
    DrawModel(model, actor, ctxt, scale);
}

/**
 * Load the actor model information for later reference if not already stored, and return in model
 * parameter.
 **/
static bool SetLoadedActorModel(struct Model* model, Actor* actor, GlobalContext* ctxt, u16 giIndex) {
    if (!LoadedModels_GetActorModel(model, NULL, actor)) {
        GetItemEntry* entry = PrepareGiEntry(model, ctxt, giIndex, true);
        LoadedModels_AddActorModel(*model, entry, actor);
        return true;
    } else {
        return false;
    }
}

/**
 * Cause model to "float" using rotation value.
 **/
static void ApplyHoverFloat(Actor* actor, f32 base, f32 multiplier) {
    f32 rot = z2_Math_Sins(actor->shape.rot.y);
    actor->shape.yDisplacement = (rot * multiplier) + base;
}

/**
 * Check if a model should rotate backwards (trap item).
 **/
static bool ShouldRotateBackwards(GlobalContext* ctxt, u16 giIndex) {
    // Only rotate ice traps backwards if Ice Trap Quirks enabled.
    if (MISC_CONFIG.flags.iceTrapQuirks) {
        struct Model model;
        GetItemEntry* entry = PrepareGiEntry(&model, ctxt, giIndex, true);
        return entry->item == Z2_ICE_TRAP;
    } else {
        return false;
    }
}

/**
 * Rotate an actor model by a specific amount.
 **/
static void RotateActor(Actor* actor, GlobalContext* ctxt, u16 giIndex, u16 amount) {
    if (!ShouldRotateBackwards(ctxt, giIndex)) {
        actor->shape.rot.y += amount;
    } else {
        actor->shape.rot.y -= amount;
    }
}

/**
 * Hook function for drawing Heart Piece actors as their new item.
 **/
void Models_DrawHeartPiece(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        u16 index = actor->params + 0x80;
        DrawFromGiTable(actor, ctxt, 22.0, index);
    } else {
        z2_DrawHeartPiece(actor, ctxt);
    }
}

/**
 * Hook function for rotating En_Item00 actors (Heart Piece).
 **/
void Models_RotateEnItem00(Actor* actor, GlobalContext* ctxt) {
    // MMR Heart Pieces use masked variable 0x1D or greater.
    if (MISC_CONFIG.flags.freestanding && (actor->params & 0xFF) >= 0x1D) {
        // Rotate Heart Piece.
        u16 index = actor->params + 0x80;
        RotateActor(actor, ctxt, index, 0x3C0);
    } else {
        actor->shape.rot.y += 0x3C0;
    }
}

/**
 * Get the Get-Item index for a Skulltula Token actor.
 **/
static u16 GetSkulltulaTokenGiIndex(Actor* actor, GlobalContext* ctxt) {
    u16 chestFlag = (actor->params & 0xFC) >> 2;
    // Checks if Swamp Spider House scene
    u16 baseIndex = ctxt->sceneNum == 0x27 ? 0x13A : 0x158;
    u16 giIndex = baseIndex + chestFlag;
    return giIndex;
}

/**
 * Hook function for drawing Skulltula Token actors as their new item.
 **/
void Models_DrawSkulltulaToken(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        u16 giIndex = GetSkulltulaTokenGiIndex(actor, ctxt);
        DrawFromGiTable(actor, ctxt, 1.0, giIndex);
    } else {
        DrawModelLowLevel(actor, ctxt, Z2_GRAPHIC_ST_TOKEN - 1);
    }
}

/**
 * Hook function for rotating Skulltula Token actors.
 **/
void Models_RotateSkulltulaToken(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        u16 giIndex = GetSkulltulaTokenGiIndex(actor, ctxt);
        RotateActor(actor, ctxt, giIndex, 0x38E);
    } else {
        actor->shape.rot.y += 0x38E;
    }
}

/**
 * Check whether or not a model draws a Stray Fairy.
 **/
static bool IsStrayFairyModel(struct Model model) {
    return model.graphicId == 0x4F;
}

/**
 * Get the Get-Item index for a Stray Fairy.
 **/
static u16 GetStrayFairyGiIndex(Actor* actor, GlobalContext* ctxt) {
    if ((actor->params & 0xF) == 3) {
        // Clock Town stray fairy
        return 0x3B;
    } else {
        // Dungeon stray fairies
        u16 curDungeonOffset = *(u16*)0x801F3F38;
        u16 chestFlag = ((actor->params & 0xFE00) >> 9) & 0x1F;
        return 0x16D + (curDungeonOffset * 0x14) + chestFlag;
    }
}

/**
 * Check if a Stray Fairy actor should be drawn as its Get-Item.
 **/
static bool ShouldOverrideStrayFairyDraw(Actor* actor, GlobalContext* ctxt) {
    u16 flag = actor->params & 0xF;

    // Check if a Stray Fairy is in a Great Fairy fountain:
    // 1 is used for Stray Fairies in the Great Fairy fountain.
    // 8 is used for animating Stray Fairies when being given to the fountain.
    // Optionally check Great Fairy fountain scene: 0x26
    return (flag != 1) && (flag != 8);
}

/**
 * Hook function called before Stray Fairy actor's main function.
 **/
void Models_BeforeStrayFairyMain(Actor* actor, GlobalContext* ctxt) {
    // If not a Stray Fairy, rotate like En_Item00 does.
    bool draw = ShouldOverrideStrayFairyDraw(actor, ctxt);
    if (MISC_CONFIG.flags.freestanding && draw) {
        GetItemEntry* entry;
        struct Model model;
        u16 giIndex = GetStrayFairyGiIndex(actor, ctxt);
        SetLoadedActorModel(&model, actor, ctxt, giIndex);
        if (LoadedModels_GetActorModel(&model, (void**)&entry, actor)) {
            // Check that we are not drawing a stray fairy.
            if (!IsStrayFairyModel(model)) {
                // Rotate at the same speed of a Heart Piece actor.
                RotateActor(actor, ctxt, giIndex, 0x3C0);
            }
        }
    }
}

/**
 * Hook function for drawing Stray Fairy actors as their new item.
 *
 * Return true if overriding functionality, false if using original functionality.
 **/
bool Models_DrawStrayFairy(Actor* actor, GlobalContext* ctxt) {
    bool draw = ShouldOverrideStrayFairyDraw(actor, ctxt);
    if (MISC_CONFIG.flags.freestanding && draw) {
        GetItemEntry* entry;
        struct Model model;
        u16 giIndex = GetStrayFairyGiIndex(actor, ctxt);
        SetLoadedActorModel(&model, actor, ctxt, giIndex);
        if (!LoadedModels_GetActorModel(&model, (void**)&entry, actor)) {
            return false;
        }
        // Check if we are drawing a stray fairy.
        if (IsStrayFairyModel(model)) {
            // Update stray fairy actor according to type, and perform original draw.
            ActorEnElforg* elforg = (ActorEnElforg*)actor;
            u8 fairyType = entry->type >> 4;
            elforg->color = fairyType;
            return false;
        } else {
            z2_CallSetupDList(gGlobalContext.state.gfxCtx);
            DrawModel(model, actor, ctxt, 25.0);
            return true;
        }
    } else {
        return false;
    }
}

/**
 * Get the Get-Item index for a Heart Container actor.
 **/
static u16 GetHeartContainerGiIndex(GlobalContext* ctxt) {
    // This is a (somewhat) reimplementation of MMR function at: 0x801DC138
    // The original function returns in A2 and A3 to setup calling a different function.
    if (ctxt->sceneNum == 0x1F) {
        return 0x11A;
    } else if (ctxt->sceneNum == 0x44) {
        return 0x11B;
    } else if (ctxt->sceneNum == 0x5F) {
        return 0x11C;
    } else {
        return 0x11D;
    }
}

/**
 * Hook function for drawing Heart Container actors as their new item.
 *
 * Return true if overriding functionality, false if using original functionality.
 **/
bool Models_DrawHeartContainer(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        u16 index = GetHeartContainerGiIndex(ctxt);
        DrawFromGiTable(actor, ctxt, 1.0, index);
        return true;
    } else {
        return false;
    }
}

/**
 * Hook function for rotating Heart Container actors.
 **/
void Models_RotateHeartContainer(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        u16 giIndex = GetHeartContainerGiIndex(ctxt);
        RotateActor(actor, ctxt, giIndex, 0x400);
    } else {
        actor->shape.rot.y += 0x400;
    }
}

/**
 * Hook function for replacing original behaviour of the Get-Item draw function for Boss Remains,
 * which wrote the segmented address instruction (for the object) in the function itself, instead
 * of the caller.
 **/
void Models_WriteBossRemainsObjectSegment(GlobalContext* ctxt, u32 graphicIdMinus1) {
    DispBuf* opa = &ctxt->state.gfxCtx->polyOpa;
    // Get index of object, and use it to get the data pointer
    s8 index = z2_GetObjectIndex(&ctxt->sceneContext, Z2_OBJECT_BSMASK);
    // Only write segment instruction if object found in ctxt's object list.
    // Otherwise, assume it was set by the caller.
    if (index >= 0) {
        void* data = ctxt->sceneContext.objects[index].vramAddr;
        // Write segmented address instruction
        gSPSegment(opa->p++, 6, (u32)data);
    }
}

/**
 * Hook function for drawing Boss Remain actors as their new item.
 * Currently draws the item on the Oath to Order check. Will need
 * to be updated if Boss Remains are randomized.
 **/
void Models_DrawBossRemains(Actor* actor, GlobalContext* ctxt, u32 graphicIdMinus1) {
    if (MISC_CONFIG.flags.freestanding && (actor->parent->parent == NULL || actor->parent->parent->id != 0)) {
        DrawFromGiTable(actor, ctxt, 1.0, 0x77);
    } else {
        DrawModelLowLevel(actor, ctxt, graphicIdMinus1);
    }
}

/**
 * Check whether or not a model draws a Moon's Tear.
 **/
static bool IsMoonsTearModel(struct Model model) {
    return model.graphicId == 0x5A && model.objectId == 0x1B1;
}

/**
 * Check if a Moon's Tear actor should be drawn as its Get-Item.
 **/
static bool ShouldOverrideMoonsTearDraw(Actor* actor, GlobalContext* ctxt) {
    // Check if a vanilla Moon's Tear is being drawn.
    struct Model model;
    GetItemEntry* entry = PrepareGiEntry(&model, ctxt, 0x96, true);
    return !IsMoonsTearModel(model);
}

/**
 * Hook function called before a Moon's Tear actor's main function.
 **/
void Models_BeforeMoonsTearMain(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        if (ShouldOverrideMoonsTearDraw(actor, ctxt)) {
            // If the Moon's Tear on display, reposition and rotate.
            if (actor->params == 0) {
                actor->currPosRot.pos.x = 157.0;
                actor->currPosRot.pos.y = -32.0;
                actor->currPosRot.pos.z = -103.0;
                RotateActor(actor, ctxt, 0x96, 0x3C0);
                ApplyHoverFloat(actor, 30.0, 18.0);
            }
        }
    }
}

/**
 * Hook function for drawing Moon's Tear actor as its new item.
 **/
bool Models_DrawMoonsTear(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        if (ShouldOverrideMoonsTearDraw(actor, ctxt)) {
            struct Model model;
            bool resolve;
            if (actor->params == 0) {
                // Moon's Tear on display in observatory (not collectible).
                resolve = false;
            } else {
                // Moon's Tear on ground outside observatory (collectible).
                resolve = true;
            }
            GetItemEntry* entry = PrepareGiEntry(&model, ctxt, 0x96, resolve);
            z2_CallSetupDList(gGlobalContext.state.gfxCtx);
            DrawModel(model, actor, ctxt, 1.0);
            return true;
        }
    }
    return false;
}

/**
 * Hook function for drawing Lab Fish Heart Piece actor as its new item.
 **/
bool Models_DrawLabFishHeartPiece(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        DrawFromGiTable(actor, ctxt, 25.0, 0x112);
        return true;
    } else {
        return false;
    }
}

/**
 * Hook function for rotating Lab Fish Heart Piece actor.
 **/
void Models_RotateLabFishHeartPiece(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        RotateActor(actor, ctxt, 0x112, 0x3E8);
    } else {
        actor->shape.rot.y += 0x3E8;
    }
}

/**
 * Check whether or not a model draws a Seahorse.
 **/
static bool IsSeahorseModel(struct Model model) {
    return model.graphicId == 0x63 && model.objectId == 0x1F0;
}

/**
 * Check if a Seahorse actor should be drawn as its Get-Item.
 **/
static bool ShouldOverrideSeahorseDraw(Actor* actor, GlobalContext* ctxt) {
    // Check if a vanilla Seahorse is being drawn.
    struct Model model;
    GetItemEntry* entry = PrepareGiEntry(&model, ctxt, 0x95, true);
    // Ensure that only the fishtank Seahorse is being drawn over.
    bool isFishtank = actor->params == 0xFFFF;
    return isFishtank && !IsSeahorseModel(model);
}

/**
 * Hook function called before a Seahorse actor's main function.
 **/
void Models_BeforeSeahorseMain(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        if (ShouldOverrideSeahorseDraw(actor, ctxt)) {
            RotateActor(actor, ctxt, 0x95, 0x3C0);
            ApplyHoverFloat(actor, -1000.0, 1000.0);
        }
    }
}

/**
 * Hook function for drawing Seahorse actor as its new item.
 **/
bool Models_DrawSeahorse(Actor* actor, GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.freestanding) {
        if (ShouldOverrideSeahorseDraw(actor, ctxt)) {
            DrawFromGiTable(actor, ctxt, 50.0, 0x95);
            return true;
        }
    }

    return false;
}

void Models_DrawShopInventory(ActorEnGirlA* actor, GlobalContext* ctxt, u32 graphicIdMinus1) {
    if (MISC_CONFIG.flags.shopModels) {
        DrawFromGiTable(&actor->base, ctxt, 1.0, actor->giIndex);
    } else {
        DrawModelLowLevel(&actor->base, ctxt, graphicIdMinus1);
    }
}

void Models_AfterActorDtor(Actor* actor) {
    if (MISC_CONFIG.flags.freestanding) {
        if (actor->id == Z2_ACTOR_EN_ELFORG) {
            LoadedModels_RemoveActorModel(actor);
        }
    }
}

/**
 * Reset object heap pointer and clear all loaded object slots.
 **/
void Models_ClearObjectHeap(void) {
    objheap_clear(&gObjheap);
}

/**
 * Initialize object heap.
 **/
void Models_Init(void) {
    void* alloc = Util_HeapAlloc(OBJHEAP_SIZE);
    objheap_init(&gObjheap, alloc, OBJHEAP_SIZE, gObjheapItems, OBJHEAP_SLOTS);
}

struct ModelsState {
    // Pointer to graphics context, cannot be retrieved from normal pointer during room unload.
    GraphicsContext* gfx;
    // Pointer to polyOpa, used to check if objheap should finish advance.
    const Gfx* prevOpa;
};

static struct ModelsState gState = { 0 };

/**
 * Helper function called after preparing game's display buffers for writing (write pointer set to buffer start).
 * Used to finish advancing objheap when needed.
 **/
void Models_AfterPrepareDisplayBuffers(GraphicsContext* gfx) {
    // Apparently gfx pointer cannot be retrieved during room unload, so store in global.
    if (gfx != NULL) {
        gState.gfx = gfx;
    }
    // Note: This assumes that when the polyOpa buffer pointer has been reset to start, it has already been flushed
    // to RDP. While this is very likely, it is not guaranteed.
    // If alternative Opa buffer has been cleared, both DLists should be rid of pointers to object data in previous room.
    if (gState.prevOpa != NULL && gfx->polyOpa.buf != gState.prevOpa) {
        objheap_flush_operation(&gObjheap);
        gState.prevOpa = NULL;
    }
}

/**
 * Helper function called when unloading previous room, to prepare for finishing advance of objheap in a subsequent frame.
 **/
void Models_PrepareAfterRoomUnload(GlobalContext* ctxt) {
    // Note: During frame processing loop, unloads room before drawing actors.
    // Not sure how to get alternative Opa buffer, so get current and check if non-NULL and non-equal (there are only 2).
    gState.prevOpa = gState.gfx->polyOpa.buf;

    // Determine operation before finish advancing or reverting.
    // Normally, objects from previously loaded rooms would no longer draw so this isn't an issue, but is required for hack
    // used to draw actors with 0xFF room, so that the pointer can be safely swapped to data of the relevant room.
    s8 curRoom = (s8)ctxt->roomContext.currRoom.num;
    objheap_handle_room_unload(&gObjheap, curRoom);
}

/**
 * Helper function called when loading next room, to prepare objheap for advancing.
 **/
void Models_PrepareBeforeRoomLoad(RoomContext* roomCtx, s8 roomIndex) {
    if ((s8)roomCtx->currRoom.num == -1) {
        // If loading first room in scene, remember room index.
        objheap_init_room(&gObjheap, roomIndex);
    } else {
        // Safeguard: If previous Opa DList pointer is non-NULL, still waiting to flush advance or revert operation.
        // If attempting to prepare advance before this has happened, prevent flushing advance or revert operations.
        if (gState.prevOpa) {
            gState.prevOpa = NULL;
        }
        // If not loading first room in scene, prepare objheap for advance.
        objheap_prepare_advance(&gObjheap, roomIndex);
    }
}
