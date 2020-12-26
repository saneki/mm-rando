#ifndef HUD_COLORS_H
#define HUD_COLORS_H

#include "z2.h"

// Magic number for hud_color_config: "HUDC"
#define HUD_COLOR_CONFIG_MAGIC 0x48554443

struct hud_color_config {
    u32 magic;
    u32 version;

    // Version 0
    Color button_a;
    Color button_b;
    Color button_c;
    Color button_start;
    Color clock_emblem;
    Color clock_emblem_inverted_1;
    Color clock_emblem_inverted_2;
    Color clock_emblem_sun;
    Color clock_moon;
    Color clock_sun;
    Color heart;
    Color heart_dd;
    Color magic_normal;
    Color magic_inf;
    Color map;
    Color map_entrance_cursor;
    Color map_player_cursor;
    Color rupee[3];

    // Version 1
    Color button_icon_a;
    Color button_icon_b;
    Color button_icon_c;
    Color menu_a_inner_1;
    Color menu_a_inner_2;
    Color menu_a_outer_1;
    Color menu_a_outer_2;
    Color menu_c_inner_1;
    Color menu_c_inner_2;
    Color menu_c_outer_1;
    Color menu_c_outer_2;
    Color note_a_1;
    Color note_a_2;
    Color note_a_shadow_1;
    Color note_a_shadow_2;
    Color note_c_1;
    Color note_c_2;
    Color note_c_shadow_1;
    Color note_c_shadow_2;
    Color pause_title_a;
    Color pause_title_c;
    Color prompt_1;
    Color prompt_2;
    Color prompt_glow;
    Color score_lines;
    Color score_note;

    // Version 2
    Color dpad;

    // Version 3
    Color menu_border_1;
    Color menu_border_2;
    Color menu_subtitle_text;
    Color shop_cursor_1;
    Color shop_cursor_2;
};

extern struct hud_color_config HUD_COLOR_CONFIG;

void hud_colors_init(void);
void hud_colors_main_menu_init(void);
void hud_colors_update_pause_menu_colors(GlobalContext *game);

#endif // HUD_COLORS_H
