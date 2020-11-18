#include <stdbool.h>
#include "misc.h"
#include "z2.h"
#include "mmr.h"

u16 item00_get_gi_index(z2_en_item00_t *actor, z2_game_t *game) {
    return *(u16*)(&actor->common.unk_0xE0); // TODO pick a definitely unused part of the item00 actor memory
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
    }
}

bool item00_give_item(z2_en_item00_t *actor, z2_game_t *game) {
    u16 gi_index = item00_get_gi_index(actor, game);
    if (gi_index == 0) {
        return false;
    }
    // TODO
}