#include "z2.h"

/**
 * TODO
 **/
u8 before_message_character_process(z2_game_t *game, s16 *output_index) {
    u16 index = game->msgbox_ctxt.cur_msg_char_index;
    u8 current_character = game->msgbox_ctxt.cur_msg_raw[index];
    if (current_character == 0x09) {
        return -1;
    }
    game->msgbox_ctxt.cur_msg_displayed[*output_index] = current_character;
    return current_character;
}
