#include "z2.h"
#include "mmr.h"
#include "item00.h"

z2_en_item00_t *rupeecrow_after_rupee_spawn(z2_game_t *game, z2_en_ruppecrow_t *actor, z2_en_item00_t *item) {
    u16 gi_index = 0x364 + (item->common.variable & 0x03);
    mmr_gi_t* entry = mmr_get_gi_entry(gi_index);
    if (entry->item != 0 && entry->message != 0) {
        item00_set_gi_index(item, gi_index);
        u16 draw_gi_index = mmr_GetNewGiIndex(game, 0, gi_index, false);
        item00_set_draw_gi_index(item, draw_gi_index);
    }
    return item;
}
