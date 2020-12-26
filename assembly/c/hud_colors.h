#ifndef HUD_COLORS_H
#define HUD_COLORS_H

#include "z2.h"

// Magic number for hud_color_config: "HUDC"
#define HUD_COLOR_CONFIG_MAGIC 0x48554443

struct hud_color_config {
    u32 magic;
    u32 version;

    // Version 0
    ColorRGBA8 button_a;
    ColorRGBA8 button_b;
    ColorRGBA8 button_c;
    ColorRGBA8 button_start;
    ColorRGBA8 clock_emblem;
    ColorRGBA8 clock_emblem_inverted_1;
    ColorRGBA8 clock_emblem_inverted_2;
    ColorRGBA8 clock_emblem_sun;
    ColorRGBA8 clock_moon;
    ColorRGBA8 clock_sun;
    ColorRGBA8 heart;
    ColorRGBA8 heart_dd;
    ColorRGBA8 magic_normal;
    ColorRGBA8 magic_inf;
    ColorRGBA8 map;
    ColorRGBA8 map_entrance_cursor;
    ColorRGBA8 map_player_cursor;
    ColorRGBA8 rupee[3];

    // Version 1
    ColorRGBA8 button_icon_a;
    ColorRGBA8 button_icon_b;
    ColorRGBA8 button_icon_c;
    ColorRGBA8 menu_a_inner_1;
    ColorRGBA8 menu_a_inner_2;
    ColorRGBA8 menu_a_outer_1;
    ColorRGBA8 menu_a_outer_2;
    ColorRGBA8 menu_c_inner_1;
    ColorRGBA8 menu_c_inner_2;
    ColorRGBA8 menu_c_outer_1;
    ColorRGBA8 menu_c_outer_2;
    ColorRGBA8 note_a_1;
    ColorRGBA8 note_a_2;
    ColorRGBA8 note_a_shadow_1;
    ColorRGBA8 note_a_shadow_2;
    ColorRGBA8 note_c_1;
    ColorRGBA8 note_c_2;
    ColorRGBA8 note_c_shadow_1;
    ColorRGBA8 note_c_shadow_2;
    ColorRGBA8 pause_title_a;
    ColorRGBA8 pause_title_c;
    ColorRGBA8 prompt_1;
    ColorRGBA8 prompt_2;
    ColorRGBA8 prompt_glow;
    ColorRGBA8 score_lines;
    ColorRGBA8 score_note;

    // Version 2
    ColorRGBA8 dpad;

    // Version 3
    ColorRGBA8 menu_border_1;
    ColorRGBA8 menu_border_2;
    ColorRGBA8 menu_subtitle_text;
    ColorRGBA8 shop_cursor_1;
    ColorRGBA8 shop_cursor_2;
};

extern struct hud_color_config HUD_COLOR_CONFIG;

void hud_colors_init(void);
void hud_colors_main_menu_init(void);
void hud_colors_update_pause_menu_colors(GlobalContext *game);

#endif // HUD_COLORS_H
