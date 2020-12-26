#include <stdbool.h>
#include "z2.h"

void buttons_check_item_usability(bool *dest, GlobalContext *game, u8 b, u8 c1, u8 c2, u8 c3) {
    u8 previous[4], prevstates[5];

    // Backup modified fields
    ButtonsState buttonsState = gSaveContext.extra.buttonsState;

    // Backup button items
    for (int i = 0; i < 4; i++)
        previous[i] = gSaveContext.perm.unk4C.formButtonItems[0].buttons[i];

    // Backup button states
    for (int i = 0; i < 5; i++)
        prevstates[i] = gSaveContext.extra.buttonsUsable[i];

    gSaveContext.perm.unk4C.formButtonItems[0].b      = b;
    gSaveContext.perm.unk4C.formButtonItems[0].cLeft  = c1;
    gSaveContext.perm.unk4C.formButtonItems[0].cDown  = c2;
    gSaveContext.perm.unk4C.formButtonItems[0].cRight = c3;

    z2_UpdateButtonUsability(game);

    // Set dest to enabled-states (which are either 0x00 or 0xFF)
    for (int i = 0; i < 4; i++)
        dest[i] = (gSaveContext.extra.buttonsUsable[i] == 0);

    // Restore button items
    for (int i = 0; i < 4; i++)
        gSaveContext.perm.unk4C.formButtonItems[0].buttons[i] = previous[i];

    // Restore button states
    for (int i = 0; i < 5; i++)
        gSaveContext.extra.buttonsUsable[i] = prevstates[i];

    // Restore modified fields
    gSaveContext.extra.buttonsState = buttonsState;
}

bool buttons_check_c_item_usable(GlobalContext *game, u8 c) {
    bool dest[4];

    buttons_check_item_usability(dest, game, 0xFF, c, 0xFF, 0xFF);
    return dest[1];
}
