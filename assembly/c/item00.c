#include <stdbool.h>
#include "Misc.h"
#include <z64.h>
#include "MMR.h"
#include "Player.h"

// TODO pick a definitely unused part of the item00 actor memory
void item00_set_gi_index(z2_en_item00_t *item, u16 gi_index) {
    u16* pointer = (u16*)(&item->common.unkE0);
    *pointer = gi_index;
}

u16 item00_get_gi_index(z2_en_item00_t *item) {
    u16* pointer = (u16*)(&item->common.unkE0);
    return *pointer;
}

void item00_set_draw_gi_index(z2_en_item00_t *item, u16 draw_gi_index) {
    u16* pointer = (u16*)(&item->common.unkE0);
    pointer++;
    *pointer = draw_gi_index;
}

u16 item00_get_draw_gi_index(z2_en_item00_t *item) {
    u16* pointer = (u16*)(&item->common.unkE0);
    pointer++;
    return *pointer;
}

void item00_check_and_set_gi_index(z2_en_item00_t *item, GlobalContext *game, u16 gi_index) {
    GetItemEntry* entry = MMR_GetGiEntry(gi_index);
    if (entry->item != 0 && entry->message != 0) {
        item00_set_gi_index(item, gi_index);
        u16 draw_gi_index = MMR_GetNewGiIndex(game, 0, gi_index, false);
        item00_set_draw_gi_index(item, draw_gi_index);
    }
}

void item00_constructor(z2_en_item00_t *actor, GlobalContext *game) {
    if (actor->collectable_flag != 0) {
        u16 scene_index = game->sceneNum;
        if (scene_index != 0x18 && actor->collectable_flag < 0x20) { // Stone Tower Temple (Inverted) has distinct collectable switches
            scene_index = z2_check_scene_pairs(scene_index);
        }
        u16 collectable_table_index = scene_index * 0x80 + actor->collectable_flag;

        u32 index = MISC_CONFIG.internal.collectable_table_file_index;
        DmaEntry entry = dmadata[index];

        u32 start = entry.vromStart + collectable_table_index * 2;

        // TODO optimization. check if this works on compressed files.
        // TODO optimization. maybe read the whole scene block when a scene loads.
        u16 gi_index;
        z2_ReadFile(&gi_index, start, 2);
        if (gi_index > 0) {
            item00_set_gi_index(actor, gi_index);
            u16 draw_gi_index = MMR_GetNewGiIndex(game, 0, gi_index, false);
            item00_set_draw_gi_index(actor, draw_gi_index);
        }
    }
}

bool item00_give_item(z2_en_item00_t *actor, GlobalContext *game) {
    u16 gi_index = item00_get_gi_index(actor);
    if (gi_index == 0) {
        return false;
    }
    mmr_GiveItem(game, &(actor->common), gi_index);
    player_pause(game);
    return true;
}
