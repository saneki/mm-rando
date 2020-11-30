#include <stdbool.h>
#include "extended_objects.h"
#include "util.h"
#include "world_skulltula.h"
#include "world_skulltula_debug.h"
#include "z2.h"

struct world_skulltula_config WORLD_SKULLTULA_CONFIG = {
    .magic = WORLD_SKULLTULA_CONFIG_MAGIC,
    .version = 0,
};

// Empty path with 0 nodes.
static struct path_entry g_empty_path = {
    .info = 0x00FFFFFF,
    .segaddr = 0,
};

static struct world_skulltula_scene_config g_scene_config = { 0 };

// Function to load object immediately as special object.
typedef u32 (*func_0x8012F2E0_proc)(z2_obj_ctxt_t *ctxt, s16 object_id);
#define func_0x8012F2E0 ((func_0x8012F2E0_proc) 0x8012F2E0)

// Function to load object as normal object?
typedef void * (*func_0x8012F73C_proc)(z2_obj_ctxt_t *ctxt, u32 index, s16 object_id);
#define func_0x8012F73C ((func_0x8012F73C_proc) 0x8012F73C)

static void load_object_file(u32 object_id, u8 *buf) {
    z2_obj_file_t *entry = extended_objects_get((s16)object_id);
    u32 vrom_start = entry->vrom_start;
    u32 size = entry->vrom_end - vrom_start;
    z2_ReadFile(buf, vrom_start, size);
}

static size_t get_object_size(u32 object_id) {
    z2_obj_file_t info = *extended_objects_get((s16)object_id);
    return (size_t)(info.vrom_end - info.vrom_start);
}

/**
 * Helper function called to apply fixes after loading scene config structure from file data.
 **/
static void world_skulltula_scene_config_apply_fixup(struct world_skulltula_scene_config *config) {
    // Fix segmented addresses in path entries to use direct reference (base index 0).
    for (u32 i = 0; i < config->count; i++) {
        // Randomizer places offset relative to path node buffer into segaddr field.
        u32 offset = config->entries[i].segaddr;
        config->entries[i].segaddr = (u32)(config->nodebuf + offset) & 0xFFFFFF;
    }
}

/**
 * Helper function called to load required object if possible.
 **/
void world_skulltula_after_scene_init(z2_game_t *game) {
    // Initialize debug structure.
    world_skulltula_debug_after_scene_init(game);
    // Attempt to load object 0x20 for Skullwalltula actor if not already loaded.
    s8 index = z2_GetObjectIndex(&game->obj_ctxt, 0x20);
    if (index < 0) {
        s8 result = func_0x8012F2E0(&game->obj_ctxt, 0x20);
    }
    // Load scene-specific config structure from file.
    if (WORLD_SKULLTULA_CONFIG.scene_mapping_file_index != 0) {
        u8 scene = (u8)game->scene_index;
        u32 vrom = z2_file_table[WORLD_SKULLTULA_CONFIG.scene_mapping_file_index].vrom_start;
        u8 vindex = WORLD_SKULLTULA_CONFIG.file_indexes_by_scene[scene];
        if (vindex > 0) {
            z2_LoadVFileFromArchive(vrom, vindex - 1, (void*)&g_scene_config, sizeof(g_scene_config));
            world_skulltula_scene_config_apply_fixup(&g_scene_config);
        } else {
            g_scene_config.count = 0;
        }
    }
}

/**
 * Helper function called to check whether or not World Skulltula are enabled.
 **/
bool world_skulltula_enabled(void) {
    return (WORLD_SKULLTULA_CONFIG.scene_mapping_file_index != 0) || world_skulltula_debug_enabled();
}

/**
 * Hook function used to get path entry of Skullwalltula actor.
 **/
struct path_entry * world_skulltula_get_path_override(z2_game_t *game, u32 path_index, u32 unknown, u32 *node) {
    if (world_skulltula_debug_enabled()) {
        if (path_index != 0xFE) {
            // If index less than 0xFE, use default behavior.
            return (struct path_entry *)z2_Scene_GetPathEntry(game, path_index, unknown, node);
        } else {
            // If 0xFE, use "empty" path for overwriting later.
            return &g_empty_path;
        }
    } else {
        // Default behavior (get path from scene data).
        return (struct path_entry *)z2_Scene_GetPathEntry(game, path_index, unknown, node);
    }
}
