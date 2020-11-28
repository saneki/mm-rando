#include <stdbool.h>
#include "extended_objects.h"
#include "util.h"
#include "world_skulltula.h"
#include "z2.h"

// World of Skulltula debug struct magic: "SKUL"
#define WORLD_SKULLTULA_DEBUG_MAGIC (0x534B554C)

// Whether or not the debug feature is enabled.
static bool g_debug_enable = false;

#define AMOUNT_COUNT (2)

// Amounts to move Skullwalltula actor when debugging.
static s16 g_amounts[AMOUNT_COUNT] = { 1, 8 };

#define PATH_NODE_MAX (10)

struct path_entry {
    u32 info;
    u32 segaddr;
};

struct pathbuf {
    z2_xyz_t nodes[PATH_NODE_MAX];
    struct path_entry entry;
};

static struct pathbuf g_debug_pathbuf = { 0 };

// Empty path with 0 nodes.
static struct path_entry g_empty_path = {
    .info = 0x00FFFFFF,
    .segaddr = 0,
};

struct world_skulltula_debug {
    u32 magic;
    u32 command;
    z2_actor_t *spawned;
    z2_xyz_t pos;
    z2_rot_t rot;
    size_t amount_index;
    u32 path_count;
    z2_xyz_t path[PATH_NODE_MAX];
    bool enabled;
};

static struct world_skulltula_debug g_debug = {
    .magic = WORLD_SKULLTULA_DEBUG_MAGIC,
    .command = 0,
    .spawned = NULL,
    .pos = { 0 },
    .rot = { 0 },
    .amount_index = 1,
    .path_count = 0,
    .path = { 0 },
    .enabled = false,
};

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
 * Clear path count & values in debug struct.
 **/
static void world_skulltula_debug_clear_path(struct world_skulltula_debug *debug) {
    debug->path_count = 0;
    for (int i = 0; i < PATH_NODE_MAX; i++) {
        debug->path[i].x = debug->path[i].y = debug->path[i].z = 0;
    }
}

/**
 * Initialize debug struct values.
 **/
static void world_skulltula_debug_init(struct world_skulltula_debug *debug) {
    debug->command = 0;
    debug->spawned = NULL;
    debug->amount_index = 1;
    debug->enabled = false;
    world_skulltula_debug_clear_path(debug);
}

static void world_skulltula_debug_build_pathbuf(struct world_skulltula_debug *debug, struct pathbuf *pathbuf) {
    // Copy over nodes.
    for (int i = 0; i < debug->path_count; i++) {
        pathbuf->nodes[i] = debug->path[i];
    }
    // Build info value with node count.
    pathbuf->entry.info = ((u8)debug->path_count << 24) | 0xFFFFFF;
    // Build segaddr for direct reference (index 0).
    pathbuf->entry.segaddr = ((u32)pathbuf & 0xFFFFFF);
}

static void world_skulltula_debug_spawn(z2_game_t *game, struct world_skulltula_debug *debug, u16 var) {
    // u16 var = 0xFF02;
    z2_xyz_t pos = debug->pos;
    z2_rot_t rot = debug->rot;
    if (debug->spawned) {
        z2_ActorRemove(&game->actor_ctxt, debug->spawned, game);
    }
    debug->spawned = z2_SpawnActor(&game->actor_ctxt, game, 0x50, (f32)pos.x, (f32)pos.y, (f32)pos.z, rot.x, rot.y, rot.z, var);
}

/**
 * Process specified debug command.
 **/
static void world_skulltula_debug_process_command(z2_link_t *link, z2_game_t *game, struct world_skulltula_debug *debug, u32 cmd) {
    if (cmd == 1) {
        // Copy Link position and rotation to debug.
        debug->pos.x = (s16)link->common.pos_2.x;
        debug->pos.y = (s16)link->common.pos_2.y;
        debug->pos.z = (s16)link->common.pos_2.z;
        debug->rot = link->common.rot_2;
    } else if (cmd == 2) {
        // Spawn or update Skullwalltula actor at position in debug.
        world_skulltula_debug_spawn(game, debug, 0xFF02);
    } else if (cmd == 3) {
        // Despawn existing Skullwalltula actor.
        if (debug->spawned) {
            z2_ActorRemove(&game->actor_ctxt, debug->spawned, game);
            debug->spawned = NULL;
        }
    } else if (cmd == 4) {
        // Append current position as path node.
        if (debug->path_count < PATH_NODE_MAX) {
            z2_xyz_t cur;
            cur.x = (s16)debug->spawned->pos_2.x;
            cur.y = (s16)debug->spawned->pos_2.y;
            cur.z = (s16)debug->spawned->pos_2.z;
            debug->path[debug->path_count++] = cur;
        }
    } else if (cmd == 5) {
        // Clear current path.
        world_skulltula_debug_clear_path(debug);
    } else if (cmd == 6) {
        world_skulltula_debug_build_pathbuf(debug, &g_debug_pathbuf);
        if (debug->spawned && debug->path_count > 1) {
            // For initial position, use first path node.
            debug->pos = g_debug_pathbuf.nodes[0];
            // Respawn Skullwalltula.
            world_skulltula_debug_spawn(game, debug, 0xFE02);
            z2_en_sw_t *sw = (z2_en_sw_t*)debug->spawned;
            // Point to entry.
            if (sw) {
                // Point to path entry.
                sw->path_entry = &g_debug_pathbuf.entry;
                sw->path_node_index = 1;
            }
            world_skulltula_debug_clear_path(debug);
        }
    }
}

/**
 * Process current debug command in RDRAM.
 **/
static void world_skulltula_debug_process_current_command(z2_link_t *link, z2_game_t *game, struct world_skulltula_debug *debug) {
    world_skulltula_debug_process_command(link, game, debug, debug->command);
    // Reset command value.
    debug->command = 0;
}

/**
 * Process controller inputs for debug.
 **/
static void world_skulltula_debug_process_input(z2_link_t *link, z2_game_t *game, struct world_skulltula_debug *debug) {
    z2_pad_t pad = game->common.input[0].pad_pressed;
    z2_pad_t raw = game->common.input[0].raw.pad;
    s16 amount = g_amounts[debug->amount_index];

    // Z + L: spawn Skullwalltula at Link position.
    if (pad.z && raw.l) {
        // Force Link to full health.
        z2_file.current_health = z2_file.max_health = 0x140;
        // Spawn at Link's current position.
        world_skulltula_debug_process_command(link, game, debug, 1);
        world_skulltula_debug_process_command(link, game, debug, 2);
        // Clear Z bit.
        pad.z = 0;
    }

    // A + L: append current Skullwalltula position as node to path list.
    if (pad.a && raw.l) {
        world_skulltula_debug_process_command(link, game, debug, 4);
        // Clear A bit.
        pad.a = 0;
    }

    // B + L: clear path list.
    if (pad.b && raw.l) {
        world_skulltula_debug_process_command(link, game, debug, 5);
        // Clear B bit.
        pad.b = 0;
    }

    // R + L: build path list to buffer for usage.
    if (pad.r && raw.l) {
        world_skulltula_debug_process_command(link, game, debug, 6);
        // Clear R bit.
        pad.r = 0;
    }

    // C-down + L: cycle through values used to move Skullwalltula by certain amount.
    if (pad.cd && raw.l) {
        debug->amount_index = (debug->amount_index + 1) % AMOUNT_COUNT;
        // Clear C-down bit.
        pad.cd = 0;
    }

    // Handle D-Pad inputs for actor movement & rotation.
    if (raw.du) {
        if (raw.l) {
            debug->pos.y += amount;
        } else {
            debug->pos.x += amount;
        }
    }
    if (raw.dl) {
        debug->pos.z += -amount;
    }
    if (raw.dr) {
        debug->pos.z += amount;
    }
    if (raw.dd) {
        if (raw.l) {
            debug->pos.y += -amount;
        } else {
            debug->pos.x += -amount;
        }
    }

    // If movement occurred, update position.
    if (raw.du || raw.dl || raw.dr || raw.dd) {
        // Respawn Skullwalltula at updated position.
        world_skulltula_debug_process_command(link, game, debug, 2);
    }

    // Clear inputs for D-Pad and L.
    pad.du = pad.dl = pad.dr = pad.dd = 0;
    raw.du = raw.dl = raw.dr = raw.dd = 0;
    pad.l = raw.l = 0;
    game->common.input[0].pad_pressed = pad;
    game->common.input[0].raw.pad = raw;
}

/**
 * Helper function called to process inputs for debug.
 **/
void world_skulltula_debug_process(z2_link_t *link, z2_game_t *game) {
    if (g_debug_enable && g_debug.enabled) {
        // First process debug command if using direct RDRAM for input.
        world_skulltula_debug_process_current_command(link, game, &g_debug);
        // Process debug controller input.
        world_skulltula_debug_process_input(link, game, &g_debug);
    }
}

/**
 * Helper function called to invalidate pointer to Skullwalltula actor used by debug.
 **/
void world_skulltula_debug_after_actor_dtor(z2_actor_t *actor) {
    if (g_debug.spawned == actor) {
        g_debug.spawned = NULL;
    }
}

/**
 * Helper function called to load required object if possible.
 **/
void world_skulltula_after_scene_init(z2_game_t *game) {
    // Initialize debug structure.
    world_skulltula_debug_init(&g_debug);

    // Attempt to load object 0x20 for Skullwalltula actor.
    u8 scene = (u8)z2_file.scene;
    // Attempt to load Skullwalltula object if not already loaded.
    s8 index = z2_GetObjectIndex(&game->obj_ctxt, 0x20);
    if (index < 0) {
        s8 result = func_0x8012F2E0(&game->obj_ctxt, 0x20);
    }
    // Enable debug feature.
    g_debug.enabled = true;
}

/**
 * Whether or not World Skulltula are enabled.
 **/
bool world_skulltula_enabled(void) {
    // For now, just use debug flag.
    return g_debug_enable;
}

/**
 * Hook function used to get path entry of Skullwalltula actor.
 **/
struct path_entry * world_skulltula_get_path_override(z2_game_t *game, u32 path_index, u32 unknown, u32 *node) {
    if (g_debug_enable) {
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
