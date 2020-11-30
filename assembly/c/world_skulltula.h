#ifndef WORLD_SKULLTULA_H
#define WORLD_SKULLTULA_H

#include <stdbool.h>
#include "z2.h"

// World of Skulltula config struct magic: "SKUL"
#define WORLD_SKULLTULA_CONFIG_MAGIC (0x534B554C)

struct path_entry {
    u32 info;
    u32 segaddr;
};

struct world_skulltula_config {
    u32 magic;
    u32 version;
    // Index of file with scene-specific data.
    u32 scene_mapping_file_index;
    // 0x71 scenes, align by 4 bytes.
    u8 file_indexes_by_scene[0x74];
};

struct world_skulltula_scene_config {
    u32 count;
    u32 flags[0xC];
    u8 nodebuf[0x100];
    struct path_entry entries[0xC];
};

void world_skulltula_after_scene_init(z2_game_t *game);
bool world_skulltula_enabled(void);

#endif // WORLD_SKULLTULA_H
