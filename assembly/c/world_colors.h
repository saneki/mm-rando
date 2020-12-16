#ifndef WORLD_COLORS_H
#define WORLD_COLORS_H

#include "color.h"

#define WORLD_COLOR_CONFIG_MAGIC 0x57524C44

struct world_color_config {
    u32 magic;
    u32 version;
    rgbs_t goron_punch;
    rgbs_t goron_rolling;
    rgbs_t sword_blue_pri;
    rgbs_t sword_red_pri;
    rgbs_t sword_slash_env;
    rgbs_t sword_slash_pri;
    rgbs_t blue_bubble;
};

void WorldColors_Init(void);

#endif // WORLD_COLORS_H
