#include <stdbool.h>
#include "z2.h"

void draw_b_button_icon_color_fix(GlobalContext *game) {
    // Clear the Env color before drawing amounts/text
    DispBuf *db = &(game->state.gfxCtx->overlay);
    gDPSetEnvColor(db->p++, 0x00, 0x00, 0x00, 0xFF);

    z2_DrawBButtonIcon(game);
}

void draw_c_button_icons_color_fix(GlobalContext *game) {
    // Clear the Env color before drawing amounts/text
    DispBuf *db = &(game->state.gfxCtx->overlay);
    gDPSetEnvColor(db->p++, 0x00, 0x00, 0x00, 0xFF);

    z2_DrawCButtonIcons(game);
}
