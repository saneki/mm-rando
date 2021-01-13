#include <z64.h>
#include "MMR.h"
#include "item00.h"

z2_en_item00_t *rupeecrow_after_rupee_spawn(GlobalContext *game, z2_en_ruppecrow_t *actor, z2_en_item00_t *item) {
    u16 gi_index = 0x364 + (item->common.params & 0x03);
    item00_check_and_set_gi_index(item, game, gi_index);
    return item;
}
