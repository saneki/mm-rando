#include <stdbool.h>
#include "z2.h"
#include "mmr.h"
#include "player.h"
#include "item00.h"

bool invisible_rupee_give_item(z2_actor_t *actor, z2_game_t *game) {
    u16 type = actor->variable & 0x03;
    z2_en_item00_t* item = z2_fixed_drop_spawn(game, &actor->pos_2, type);

    // TODO
    // if (isRandomized) {
    u16 flag = actor->variable >> 2;
    u16 gi_index = 0x34D + flag;
    item00_set_gi_index(item, gi_index);
    u16 draw_gi_index = mmr_GetNewGiIndex(game, 0, gi_index, false);
    item00_set_draw_gi_index(item, draw_gi_index);
    // }
}