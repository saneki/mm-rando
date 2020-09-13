#include "z2.h"
#include "mmr.h"

/**
 * TODO
 **/
u8 before_message_character_process(z2_game_t *game, s16 *output_index) {
    u16 index = game->msgbox_ctxt.cur_msg_char_index;
    u8 current_character = game->msgbox_ctxt.cur_msg_raw[index];
    if (current_character == 0x09) {
        index++;
        current_character = game->msgbox_ctxt.cur_msg_raw[index];
        if (current_character == 0x01) {
            // check gi-index and skip until end command if item has been received before
            index++;
            u32 gi_index = game->msgbox_ctxt.cur_msg_raw[index] << 8;
            index++;
            gi_index |= game->msgbox_ctxt.cur_msg_raw[index];
            u32 new_gi_index = mmr_GetNewGiIndex_stub(game, gi_index, false);
            if (gi_index != new_gi_index) {
                do {
                    index++;
                    current_character = game->msgbox_ctxt.cur_msg_raw[index];
                } while (current_character != 0x09 || game->msgbox_ctxt.cur_msg_raw[index+1] != 0x02);
                index++;
            }
        } else if (current_character == 0x02) {
            // end command
            // does nothing by itself
        } else {
            index--;
        }
        (*output_index)--;
        game->msgbox_ctxt.cur_msg_char_index = index;
        return -1;
    }
    game->msgbox_ctxt.cur_msg_displayed[*output_index] = current_character;
    return current_character;
}
