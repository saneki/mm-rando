#ifndef WORLD_SKULLTULA_H
#define WORLD_SKULLTULA_H

#include <stdbool.h>
#include "z2.h"

// World of Skulltula config struct magic: "SKUL"
#define WORLD_SKULLTULA_CONFIG_MAGIC (0x534B554C)

struct world_skulltula_config {
    u32 magic;
    u32 version;
    // Index of file with scene-specific data.
    u32 scene_mapping_file_index;
    // 0x71 scenes, align by 4 bytes.
    u8 file_indexes_by_scene[0x74];
};

void world_skulltula_debug_after_actor_dtor(z2_actor_t *actor);
void world_skulltula_after_scene_init(z2_game_t *game);
void world_skulltula_debug_process(z2_link_t *link, z2_game_t *game);
bool world_skulltula_enabled(void);

#endif // WORLD_SKULLTULA_H
