#include <stdbool.h>
#include "misc.h"
#include "z2.h"
#include "mmr.h"
#include "player.h"

u16 item00_get_gi_index(z2_en_item00_t *actor) {
    return *(u16*)(&actor->common.unk_0xE0); // TODO pick a definitely unused part of the item00 actor memory
}

u16 item00_get_draw_gi_index(z2_en_item00_t *actor) {
    u16* pointer = (u16*)(&actor->common.unk_0xE0);
    pointer++;
    return *pointer;
}

void item00_set_draw_gi_index(z2_en_item00_t *actor, u16 draw_gi_index) {
    u16* pointer = (u16*)(&actor->common.unk_0xE0);
    pointer++;
    *pointer = draw_gi_index;
}

void item00_constructor(z2_en_item00_t *actor, z2_game_t *game) {
    if (actor->collectable_flag != 0) {
        u16 collectable_table_index = game->scene_index * 0x60 + actor->collectable_flag;
        
        u32 index = MISC_CONFIG.collectable_table_file_index;
        z2_file_table_t entry = z2_file_table[index];

        u32 start = entry.vrom_start + collectable_table_index * 2;

        // TODO optimization. check if this works on compressed files.
        // TODO optimization. maybe read the whole scene block when a scene loads.
        z2_ReadFile(&actor->common.unk_0xE0, start, 2); // TODO pick a definitely unused part of the item00 actor memory

        u16 gi_index = item00_get_gi_index(actor);
        if (gi_index > 0) {
            u16 draw_gi_index = mmr_GetNewGiIndex(game, 0, gi_index, false);
            item00_set_draw_gi_index(actor, draw_gi_index);
        }
    }
}

bool item00_give_item(z2_en_item00_t *actor, z2_game_t *game) {
    u16 gi_index = item00_get_gi_index(actor);
    if (gi_index == 0) {
        return false;
    }
    mmr_GiveItem(game, &(actor->common), gi_index);
    player_pause(game);
    return true;
}