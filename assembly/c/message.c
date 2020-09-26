#include <stdio.h>
#include "z2.h"
#include "mmr.h"

struct message_extension_state {
    bool is_wrapping;
    s8 last_space_index;
    f32 last_space_cursor_position;

    char recovery_heart_name[15];
    char recovery_heart_description[48];
    s8 current_char;
    char *current_replacement;
    u16 current_replacement_length;
};

static struct message_extension_state g_message_extension_state = {
    .is_wrapping = false,
    .last_space_index = -1,
    .last_space_cursor_position = 0,

    .recovery_heart_name = "Recovery Heart",
    .recovery_heart_description = "Replenishes a small amount of your\x11life energy.",
    .current_char = -1,
    .current_replacement_length = 0,
};

typedef struct message_character_process_variables_s {
    u8               unk_0x00[0x0020];               /* 0x0000 */
    f64              f20;                            /* 0x0020 */
    f64              f22;                            /* 0x0028 */
    f64              f24;                            /* 0x0030 */
    f64              f26;                            /* 0x0038 */
    u32              s0;                             /* 0x0040 */
    u32              s1;                             /* 0x0044 */
    u32              s2;                             /* 0x0048 */
    u32              s3;                             /* 0x004C */
    u32              s4;                             /* 0x0050 */ // global context
    u32              s5;                             /* 0x0054 */
    u32              s6;                             /* 0x0058 */
    u32              s7;                             /* 0x005C */
    u32              fp;                             /* 0x0060 */
    u32              return_address;                 /* 0x0064 */
    u8               unk_0x68[0x0008];               /* 0x0068 */
    u32              msgbox_ctxt;                    /* 0x0070 */
    u8               unk_0x74[0x0030];               /* 0x0074 */
    f32              cursor_position;                /* 0x00A4 */
    u8               unk_0xA8[0x0014];               /* 0x00A8 */
    u32              unk_0xBC;                       /* 0x00BC */
    u8               unk_0xC0[0x0006];               /* 0x00C0 */
    u8               number_of_new_lines;            /* 0x00C6 */
    u8               unk_0xC7[0x0007];               /* 0x00C7 */
    u16              unk_0xCE;                       /* 0x00CE */
    s16              number_of_new_lines_2;          /* 0x00D0 */
    u8               unk_0xD2[0x0008];               /* 0x00D2 */
    s16              output_index;                   /* 0x00DA */
    u32              link_actor;                     /* 0x00DC */
    u32              s3_2;                           /* 0x00E0 */
} message_character_process_variables_t;

/**
 * TODO
 **/
u8 before_message_character_process(z2_game_t *game, message_character_process_variables_t *args) {
    u16 index = game->msgbox_ctxt.cur_msg_char_index;
    u8 current_character = game->msgbox_ctxt.cur_msg_raw[index];
    if (current_character == 0x09) {
        index++;
        current_character = game->msgbox_ctxt.cur_msg_raw[index];
        if (current_character == 0x03 || current_character == 0x04) {
            if (g_message_extension_state.current_char == -1) {
                index++;
                u32 gi_index = game->msgbox_ctxt.cur_msg_raw[index] << 8;
                index++;
                gi_index |= game->msgbox_ctxt.cur_msg_raw[index];
                u32 new_gi_index = mmr_GetNewGiIndex_stub(game, gi_index, false);
                if (new_gi_index != gi_index) {
                    if (new_gi_index == 0x0A) {
                        if (current_character == 0x03) {
                            g_message_extension_state.current_replacement = g_message_extension_state.recovery_heart_name;
                            g_message_extension_state.current_replacement_length = 14;
                        } else {
                            g_message_extension_state.current_replacement = g_message_extension_state.recovery_heart_description;
                            g_message_extension_state.current_replacement_length = 47;
                        }
                        g_message_extension_state.current_char = 0;
                    }
                }
                if (g_message_extension_state.current_char == -1) {
                    args->output_index--;
                    game->msgbox_ctxt.cur_msg_char_index = index;
                    return -1;
                }
            }
            if (g_message_extension_state.current_char < g_message_extension_state.current_replacement_length) {
                game->msgbox_ctxt.cur_msg_char_index--;
                current_character = g_message_extension_state.current_replacement[g_message_extension_state.current_char++];
                game->msgbox_ctxt.cur_msg_displayed[args->output_index] = current_character;
                return current_character;
            }
            g_message_extension_state.current_char = -1;
            current_character = 0x01;
        }

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
        } else if (current_character == 0x11) { // begin auto text wrapping
            g_message_extension_state.is_wrapping = true;
        } else if (current_character == 0x12) { // end auto text wrapping
            g_message_extension_state.is_wrapping = false;
            g_message_extension_state.last_space_index = -1;
            g_message_extension_state.last_space_cursor_position = 0;
        } else {
            index--;
        }
        args->output_index--;
        game->msgbox_ctxt.cur_msg_char_index = index;
        return -1;
    }
    
    if (g_message_extension_state.is_wrapping) {
        if (current_character == 0x20) {
            // set last_space_index
            g_message_extension_state.last_space_index = args->output_index;
            // set last_space_cursor_position
            g_message_extension_state.last_space_cursor_position = args->cursor_position;
        } else {
            // if cursor_position > 200 // just a guess at line length
            if (args->cursor_position > 200 && g_message_extension_state.last_space_index >= 0) {
                // replace character at last_space_index with 0x11
                game->msgbox_ctxt.cur_msg_displayed[g_message_extension_state.last_space_index] = 0x11;
                // add one to number_of_new_lines
                args->number_of_new_lines_2++;
                // subtract last_space_cursor_position from cursor_position
                args->cursor_position -= g_message_extension_state.last_space_cursor_position;
                g_message_extension_state.last_space_index = -1;
                g_message_extension_state.last_space_cursor_position = 0;
                // TODO subtract the width of a space from cursor_position
            }
        }
    }
    game->msgbox_ctxt.cur_msg_displayed[args->output_index] = current_character;
    return current_character;
}
