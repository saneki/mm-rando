#include <stdbool.h>
#include "z2.h"

void buttons_check_item_usability(bool *dest, z2_game_t *game, u8 b, u8 c1, u8 c2, u8 c3) {
    u8 previous[4], prevstates[5];

    // Backup modified fields
    ButtonsState buttonsState = z2_file.extra.buttonsState;

    // Backup button items
    for (int i = 0; i < 4; i++)
        previous[i] = z2_file.perm.unk4C.formButtonItems[0].buttons[i];

    // Backup button states
    for (int i = 0; i < 5; i++)
        prevstates[i] = z2_file.extra.buttonsUsable[i];

    z2_file.perm.unk4C.formButtonItems[0].b      = b;
    z2_file.perm.unk4C.formButtonItems[0].cLeft  = c1;
    z2_file.perm.unk4C.formButtonItems[0].cDown  = c2;
    z2_file.perm.unk4C.formButtonItems[0].cRight = c3;

    z2_UpdateButtonUsability(game);

    // Set dest to enabled-states (which are either 0x00 or 0xFF)
    for (int i = 0; i < 4; i++)
        dest[i] = (z2_file.extra.buttonsUsable[i] == 0);

    // Restore button items
    for (int i = 0; i < 4; i++)
        z2_file.perm.unk4C.formButtonItems[0].buttons[i] = previous[i];

    // Restore button states
    for (int i = 0; i < 5; i++)
        z2_file.extra.buttonsUsable[i] = prevstates[i];

    // Restore modified fields
    z2_file.extra.buttonsState = buttonsState;
}

bool buttons_check_c_item_usable(z2_game_t *game, u8 c) {
    bool dest[4];

    buttons_check_item_usability(dest, game, 0xFF, c, 0xFF, 0xFF);
    return dest[1];
}
