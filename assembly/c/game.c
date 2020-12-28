#include "overlay_menu.h"
#include "z2.h"

/**
 * Hook function called after game processes next frame.
 **/
void game_after_update(GlobalContext *game) {
    OverlayMenu_Draw(game);
}
