#include <stdbool.h>
#include "linheap.h"
#include "util.h"
#include "z2.h"

#define slot_count 8

// Temporary flag for testing overriding draw functionality.
static const bool g_models_test = false;

static struct linheap g_object_heap = {
    .start = NULL,
    .cur = NULL,
    .size = 0x20000,
};

struct model {
    u16 object_id;
    s8 graphic_id;
};

struct loaded_object {
    u16 object_id;
    u8 *buf;
};

static struct loaded_object object_slots[slot_count] = { 0 };

static void load_object_file(u32 object_id, u8 *buf) {
    z2_obj_file_t *entry = &(z2_obj_table[object_id]);
    u32 vrom_start = entry->vrom_start;
    u32 size = entry->vrom_end - vrom_start;
    z2_ReadFile(buf, vrom_start, size);
}

static void load_object(struct loaded_object *object, u32 object_id) {
    object->object_id = object_id;
    load_object_file(object_id, object->buf);
}

static size_t get_object_size(u32 object_id) {
    z2_obj_file_t info = z2_obj_table[object_id];
    return (size_t)(info.vrom_end - info.vrom_start);
}

static struct loaded_object* get_object(u32 object_id) {
    for (int i = 0; i < slot_count; i++) {
        struct loaded_object *object = &(object_slots[i]);
        if (object->object_id == object_id) {
            return object;
        }
        if (object->object_id == 0) {
            size_t objsize = get_object_size(object_id);
            object->buf = linheap_alloc(&g_object_heap, objsize);
            load_object(object, object_id);
            return object;
        }
    }

    return NULL;
}

static void scale_top_matrix(f32 scale_factor) {
    f32 *matrix = z2_GetMatrixStackTop();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[4*i + j] *= scale_factor;
        }
    }
}

static void set_object_segment(z2_game_t *game, const void *buf) {
    z2_disp_buf_t *xlu = &(game->common.gfx->poly_xlu);
    gSPSegment(xlu->p++, 6, (u32)buf);

    z2_disp_buf_t *opa = &(game->common.gfx->poly_opa);
    gSPSegment(opa->p++, 6, (u32)buf);
}

static void draw_model_low_level(z2_actor_t *actor, z2_game_t *game, s8 graphic_id_minus_1) {
    z2_PreDraw1(actor, game, 0);
    z2_PreDraw2(actor, game, 0);
    z2_BaseDrawGiModel(game, graphic_id_minus_1);
}

static void draw_model(struct model model, z2_actor_t *actor, z2_game_t *game, f32 base_scale) {
    struct loaded_object *object = get_object(model.object_id);
    if (object) {
        // Update RDRAM segment table with object pointer during the draw function.
        // This is required by Moon's Tear (and possibly others), which programatically resolves a
        // segmented address using that table when writing instructions to the display list.
        z2_segment.current_object = (u32)object->buf & 0xFFFFFF;

        set_object_segment(game, object->buf);
        scale_top_matrix(base_scale);
        draw_model_low_level(actor, game, model.graphic_id - 1);
    }
}

/**
 * Hook function for drawing Heart Piece actors as their new item.
 **/
void models_draw_heart_piece(z2_actor_t *actor, z2_game_t *game) {
    if (g_models_test) {
        z2_CallSetupDList(z2_game.common.gfx);
        struct model model = {
            .object_id  = Z2_OBJECT_GI_SUTARU,
            .graphic_id = Z2_GRAPHIC_GI_SUTARU,
        };
        draw_model(model, actor, game, 25.0);
    } else {
        z2_DrawHeartPiece(actor, game);
    }
}

/**
 * Hook function for drawing Skulltula Token actors as their new item.
 **/
void models_draw_skulltula_token(z2_actor_t *actor, z2_game_t *game) {
    if (g_models_test) {
        z2_CallSetupDList(z2_game.common.gfx);
        struct model model = {
            .object_id  = Z2_OBJECT_GI_HEARTS,
            .graphic_id = Z2_GRAPHIC_HEART_PIECE,
        };
        draw_model(model, actor, game, 1.0);
    } else {
        draw_model_low_level(actor, game, Z2_GRAPHIC_ST_TOKEN - 1);
    }
}

/**
 * Hook function called before Stray Fairy actor's main function.
 **/
void models_before_stray_fairy_main(z2_actor_t *actor, z2_game_t *game) {
    // If not a Stray Fairy, rotate like En_Item00 does.
    if (g_models_test) {
        actor->rot_2.y = (u16)(actor->rot_2.y + 0x3C0);
    }
}

/**
 * Hook function for drawing Stray Fairy actors as their new item.
 *
 * Return true if overriding functionality, false if using original functionality.
 **/
bool models_draw_stray_fairy(z2_actor_t *actor, z2_game_t *game) {
    if (g_models_test) {
        z2_CallSetupDList(z2_game.common.gfx);
        struct model model = {
            .object_id  = Z2_OBJECT_GI_HEARTS,
            .graphic_id = Z2_GRAPHIC_HEART_PIECE,
        };
        draw_model(model, actor, game, 25.0);
        return true;
    } else {
        return false;
    }
}

/**
 * Hook function for drawing Heart Container actors as their new item.
 *
 * Return true if overriding functionality, false if using original functionality.
 **/
bool models_draw_heart_container(z2_actor_t *actor, z2_game_t *game) {
    if (g_models_test) {
        z2_CallSetupDList(z2_game.common.gfx);
        struct model model = {
            .object_id  = Z2_OBJECT_GI_SUTARU,
            .graphic_id = Z2_GRAPHIC_GI_SUTARU,
        };
        draw_model(model, actor, game, 1.0);
        return true;
    } else {
        return false;
    }
}

/**
 * Hook function for replacing original behaviour of the Get-Item draw function for Boss Remains,
 * which wrote the segmented address instruction (for the object) in the function itself, instead
 * of the caller.
 **/
void models_write_boss_remains_object_segment(z2_game_t *game, u32 graphic_id_minus_1) {
    z2_disp_buf_t *opa = &(game->common.gfx->poly_opa);

    // Get index of object, and use it to get the data pointer
    s8 index = z2_GetObjectIndex(&game->obj_ctxt, Z2_OBJECT_BSMASK);

    // Only write segment instruction if object found in game's object list.
    // Otherwise, assume it was set by the caller.
    if (index >= 0) {
        void *data = game->obj_ctxt.obj[index].data;

        // Write segmented address instruction
        gSPSegment(opa->p++, 6, (u32)data);
    }
}

/**
 * Hook function for drawing Boss Remain actors as their new item.
 **/
void models_draw_boss_remains(z2_actor_t *actor, z2_game_t *game, u32 graphic_id_minus_1) {
    if (g_models_test) {
        z2_CallSetupDList(z2_game.common.gfx);
        struct model model = {
            .object_id  = Z2_OBJECT_GI_HEARTS,
            .graphic_id = Z2_GRAPHIC_HEART_CONTAINER,
        };
        draw_model(model, actor, game, 1.0);
    } else {
        draw_model_low_level(actor, game, graphic_id_minus_1);
    }
}

/**
 * Hook function for drawing Moon's Tear actor as its new item.
 **/
bool models_draw_moons_tear(z2_actor_t *actor, z2_game_t *game) {
    if (g_models_test) {
        z2_CallSetupDList(z2_game.common.gfx);
        struct model model = {
            .object_id  = Z2_OBJECT_GI_SUTARU,
            .graphic_id = Z2_GRAPHIC_GI_SUTARU,
        };
        draw_model(model, actor, game, 1.0);
        return true;
    } else {
        return false;
    }
}

/**
 * Reset object heap pointer and clear all loaded object slots.
 **/
void models_clear_object_heap(void) {
    linheap_clear(&g_object_heap);
    for (size_t i = 0; i < slot_count; i++) {
        object_slots[i].object_id = 0;
        object_slots[i].buf = NULL;
    }
}

/**
 * Initialize object heap.
 **/
void models_init(void) {
    void *alloc = heap_alloc(g_object_heap.size);
    linheap_init(&g_object_heap, alloc);
}
