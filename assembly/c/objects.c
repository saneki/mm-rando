#include "world_skulltula.h"
#include "z2.h"

/**
 * Helper function which replicates vanilla behavior of calculating object heap size for new scene.
 **/
static u32 objects_get_default_heap_size(z2_game_t *game) {
    u16 scene = game->scene_index;
    if (scene == 0x6C || scene == 0x6D || scene == 0x6E || scene == 0x6F) {
        // Four regions of Clock Town.
        return 0x17E800;
    } else if (scene == 0x15) {
        // Milk Bar.
        return 0x18B000;
    } else if (scene == 0x2D) {
        // Termina Field.
        return 0x16F800;
    } else {
        return 0x159000;
    }
}

/**
 * Hook function used to get amount of heap space to allocate for object data when loading current scene.
 **/
u32 objects_get_heap_size(z2_game_t *game, z2_obj_ctxt_t *objs) {
    // Get original heap size.
    u32 result = objects_get_default_heap_size(game);
    // Allocate extra data for certain scenes if World Skulltula enabled.
    if (world_skulltula_enabled()) {
        u16 scene = game->scene_index;
        if (scene == 0x35 || scene == 0x61) {
            // If Romani Ranch or Stock Pot Inn, allocate extra space for Skullwalltula.
            z2_obj_file_t *obj = &z2_obj_table[0x20];
            u32 extra = obj->vrom_end - obj->vrom_start;
            result += extra;
        }
    }
    return result;
}
