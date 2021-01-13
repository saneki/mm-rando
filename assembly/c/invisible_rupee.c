#include <stdbool.h>
#include <z64.h>
#include "Player.h"
#include "item00.h"

bool invisible_rupee_give_item(Actor *actor, GlobalContext *game) {
    u16 type = actor->params & 0x03;
    z2_en_item00_t* item = z2_fixed_drop_spawn(game, &actor->currPosRot.pos, type);

    u16 flag = actor->params >> 2;
    u16 gi_index = 0x350 + flag;
    item00_check_and_set_gi_index(item, game, gi_index);
}
