#include "z2.h"
#include "item00.h"

z2_en_item00_t *sword_school_gong_rupee_spawn(z2_game_t *game, z2_xyzf_t *position, u16 type) {
    z2_en_item00_t* item = z2_fixed_drop_spawn(game, position, type);
    item00_check_and_set_gi_index(item, game, 0x360);
    return item;
}
