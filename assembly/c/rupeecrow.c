#include "z2.h"
#include "mmr.h"
#include "item00.h"

z2_en_item00_t *rupeecrow_after_rupee_spawn(z2_game_t *game, z2_en_ruppecrow_t *actor, z2_en_item00_t *item) {
    u16 gi_index = 0x364 + (item->common.variable & 0x03);
    item00_check_and_set_gi_index(item, game, gi_index);
    return item;
}
