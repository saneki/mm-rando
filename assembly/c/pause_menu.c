#include "hud_colors.h"
#include "misc.h"
#include "quest_item_storage.h"
#include "quest_items.h"
#include "reloc.h"
#include "save_file.h"
#include "z2.h"

// Vertex buffers.
static Vtx gVertexBufs[(4 * 3) * 2];

// Vertex buffer pointers.
static Vtx* gVertex[3] = {
    &gVertexBufs[(4 * 0) * 2],
    &gVertexBufs[(4 * 1) * 2],
    &gVertexBufs[(4 * 2) * 2],
};

static Vtx* GetVtxBuffer(GlobalContext* ctxt, u32 vertIdx, int slot) {
    // Get vertex of current icon drawing to Item Select screen
    const Vtx* srcVtx = ctxt->pauseCtx.vtxBuf + vertIdx;

    // Get dest Vtx (factor in frame counter)
    int framebufIdx = ctxt->state.gfxCtx->displayListCounter & 1;
    Vtx* dstVtx = gVertex[slot] + (framebufIdx * 4);

    // Copy source Vtx over to dest Vtx
    for (int i = 0; i < 4; i++) {
        dstVtx[i] = srcVtx[i];
    }

    // Adjust X position
    dstVtx[0].v.ob[0] += 0x10;
    dstVtx[2].v.ob[0] += 0x10;

    // Adjust Y position
    dstVtx[0].v.ob[1] -= 0x10;
    dstVtx[1].v.ob[1] -= 0x10;

    return dstVtx;
}

static void DrawIcon(GraphicsContext* gfx, const Vtx* vtx, u32 segAddr, u16 width, u16 height, u16 qidx) {
    DispBuf* db = &gfx->polyOpa;
    // Instructions that happen before function
    gDPSetPrimColor(db->p++, 0, 0, 0xFF, 0xFF, 0xFF, gfx->globalContext->pauseCtx.itemAlpha & 0xFF);
    gSPVertex(db->p++, vtx, 4, 0); // Loads 4 vertices from RDRAM
    // Instructions that happen during function.
    gDPSetTextureImage(db->p++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 1, (void*)segAddr);
    gDPSetTile(db->p++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
    gDPLoadSync(db->p++);
    gDPLoadBlock(db->p++, 7, 0, 0, 0x400 - 1, 0x80);
    gDPPipeSync(db->p++);
    gDPSetTile(db->p++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 8, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0, 0);
    gDPSetTileSize(db->p++, 0, 0, 0, (width - 1) * 4, (height - 1) * 4);
    gSP1Quadrangle(db->p++, qidx + 0, qidx + 2, qidx + 3, qidx + 1, 0);
}

static void CycleQuestItem(GlobalContext* ctxt, u8 item, u8 slot) {
    u8 orig = gSaveContext.perm.inv.items[slot];
    // Replace item in inventory.
    gSaveContext.perm.inv.items[slot] = item;
    // Replace item in C buttons.
    for (int i = 1; i < 4; i++) {
        if (orig != Z2_ITEM_NONE && gSaveContext.perm.unk4C.formButtonItems[0].buttons[i] == orig) {
            gSaveContext.perm.unk4C.formButtonItems[0].buttons[i] = item;
            z2_ReloadButtonTexture(ctxt, i);
        }
    }
    // Play sound effect.
    z2_PlaySfx(0x4808);
}

static bool IsQuestItemInCorrectSlot(u8 item, int slot) {
    int cell;
    return quest_items_get_slot(&cell, item) && cell == slot;
}

static bool IsQuestItemWithStorageSelected(GlobalContext* ctxt) {
    // Get cell and selected item.
    s16 cell = ctxt->pauseCtx.cells1.item;
    u8 item = gSaveContext.perm.inv.items[cell];

    // Check if on a quest item slot.
    bool quest = IS_QUEST_SLOT(cell);

    // Verify we are in the right cell for this item.
    bool correctSlot = IsQuestItemInCorrectSlot(item, cell);

    // Check if there's a next item.
    u8 next = quest_item_storage_next(&SAVE_FILE_CONFIG.quest_storage, item);

    // Check if on "Z" or "R" side buttons.
    bool side = ctxt->pauseCtx.sideButton != 0;

    return (quest && correctSlot && !side && item != Z2_ITEM_NONE && next != Z2_ITEM_NONE);
}

/**
 * Hook function called during the draw loop for item icons on the "Select Item" subscreen.
 *
 * Used to draw the next quest item in storage for quest item slots.
 **/
void PauseMenu_SelectItemDrawIcon(GraphicsContext* gfx, u8 item, u16 width, u16 height, int slot, u16 quadIdx, u32 vertIdx) {
    // Call original function to draw underlying item texture
    u32 origSegAddr = gItemTextureSegAddrTable[item];
    z2_PauseDrawItemIcon(gfx, origSegAddr, width, height, quadIdx);
    // If quest item storage, draw next quest item texture on bottom-right of current texture
    if (MISC_CONFIG.flags.questItemStorage && IsQuestItemInCorrectSlot(item, slot)) {
        struct quest_item_storage* storage = &SAVE_FILE_CONFIG.quest_storage;
        if (quest_item_storage_has(storage, item)) {
            int sslot, unused;
            u8 next = quest_item_storage_next(storage, item);
            if (next != Z2_ITEM_NONE && quest_item_storage_get_slot(&sslot, &unused, next)) {
                u32 segAddr = gItemTextureSegAddrTable[next];
                Vtx* vtx = GetVtxBuffer(gfx->globalContext, vertIdx, sslot);
                DrawIcon(gfx, vtx, segAddr, width, height, quadIdx);
            }
        }
    }
}

/**
 * Hook function called after the main processing for the "Select Item" subscreen.
 *
 * Used to set the text on the A button to "Decide" for selecting quest items.
 **/
void PauseMenu_SelectItemSubscreenAfterProcess(GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.questItemStorage) {
        u16 text = ctxt->interfaceCtx.buttonATextCurrent;
        if (IsQuestItemWithStorageSelected(ctxt)) {
            // Set A button text to "Decide" (only if on "Info")
            if (text == Z2_BUTTON_TEXT_INFO) {
                z2_HudSetAButtonText(ctxt, Z2_BUTTON_TEXT_DECIDE);
            }
        } else {
            // Set A button text to "Info" (only if on "Decide")
            if (text == Z2_BUTTON_TEXT_DECIDE) {
                z2_HudSetAButtonText(ctxt, Z2_BUTTON_TEXT_INFO);
            }
        }
    }
}

/**
 * Hook function called before processing A button input on the "Select Item" subscreen.
 *
 * Checks if A button would be used to cycle quest items.
 **/
bool PauseMenu_SelectItemProcessAButton(GlobalContext* ctxt, u32 curVal, u32 noneVal) {
    if (MISC_CONFIG.flags.questItemStorage && IsQuestItemWithStorageSelected(ctxt)) {
        s16 cell = ctxt->pauseCtx.cells1.item;
        if (curVal != noneVal) {
            u8 item = (u8)curVal;
            // Check input for A button, and swap to next quest item.
            InputPad pad = ctxt->state.input->pressEdge.buttons;
            u8 next = quest_item_storage_next(&SAVE_FILE_CONFIG.quest_storage, item);
            if (pad.a && next != Z2_ITEM_NONE) {
                ctxt->state.input->pressEdge.buttons.a = 0;
                CycleQuestItem(ctxt, next, (u8)cell);
            }
        }
    }
    // Perform original check.
    return curVal == noneVal;
}

/**
 * Hook function called before determining if the A button should be shown as enabled or not.
 *
 * Checks if a quest item with storage is selected. If so, always show the A button as enabled.
 **/
bool PauseMenu_SelectItemShowAButtonEnabled(GlobalContext* ctxt) {
    if (MISC_CONFIG.flags.questItemStorage && IsQuestItemWithStorageSelected(ctxt)) {
        // If on a quest item with storage, show A button as enabled even during "Item Prompt."
        return true;
    } else {
        // Perform original check.
        return ctxt->msgCtx.unk11F10 == 0;
    }
}

/**
 * Hook function called while on pause menu before processing each frame.
 **/
void PauseMenu_BeforeUpdate(GlobalContext* ctxt) {
    // Update pause menu colors.
    HudColors_UpdatePauseMenuColors(ctxt);
}
