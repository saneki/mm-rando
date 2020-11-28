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

struct world_skulltula_debug {
    u32 magic;
    u32 command;
    z2_actor_t *spawned;
    z2_xyz_t pos;
    z2_rot_t rot;
    size_t amount_index;
    u32 path_count;
    z2_xyz_t path[6];
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
    for (int i = 0; i < 6; i++) {
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

static void world_skulltula_debug_build_path(struct world_skulltula_debug *debug) {
    if (debug->path_count > 0) {
        for (int i = 0; i < debug->path_count; i++) {
            // Todo
        }
    }
}

/**
 * Process debug commands.
 **/
static void world_skulltula_debug_process_command(z2_link_t *link, z2_game_t *game, struct world_skulltula_debug *debug) {
    u32 cmd = debug->command;
    if (cmd == 1) {
        // Copy Link position and rotation to debug.
        debug->pos.x = (s16)link->common.pos_2.x;
        debug->pos.y = (s16)link->common.pos_2.y;
        debug->pos.z = (s16)link->common.pos_2.z;
        debug->rot = link->common.rot_2;
    } else if (cmd == 2) {
        // Spawn or update Skullwalltula actor at position in debug.
        u16 var = 0xFF02;
        z2_xyz_t pos = debug->pos;
        z2_rot_t rot = debug->rot;
        if (debug->spawned) {
            z2_ActorRemove(&game->actor_ctxt, debug->spawned, game);
        }
        debug->spawned = z2_SpawnActor(&game->actor_ctxt, game, 0x50, (f32)pos.x, (f32)pos.y, (f32)pos.z, rot.x, rot.y, rot.z, var);
    } else if (cmd == 3) {
        // Despawn existing Skullwalltula actor.
        if (debug->spawned) {
            z2_ActorRemove(&game->actor_ctxt, debug->spawned, game);
            debug->spawned = NULL;
        }
    }
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
        debug->command = 1;
        world_skulltula_debug_process_command(link, game, debug);
        debug->command = 2;
        world_skulltula_debug_process_command(link, game, debug);
        // Clear Z bit.
        pad.z = 0;
    }

    // A + L: append current Skullwalltula position as node to path list.
    if (pad.a && raw.l) {
        if (debug->path_count < 6) {
            z2_xyz_t cur;
            cur.x = (s16)debug->spawned->pos_2.x;
            cur.y = (s16)debug->spawned->pos_2.y;
            cur.z = (s16)debug->spawned->pos_2.z;
            debug->path[debug->path_count++] = cur;
        }
        // Clear A bit.
        pad.a = 0;
    }

    // B + L: clear path list.
    if (pad.b && raw.l) {
        world_skulltula_debug_clear_path(debug);
        // Clear B bit.
        pad.b = 0;
    }

    // R + L: build path list to buffer for usage.
    if (pad.r && raw.l) {
        world_skulltula_debug_build_path(debug);
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
        debug->command = 2;
        world_skulltula_debug_process_command(link, game, debug);
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
        world_skulltula_debug_process_command(link, game, &g_debug);
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