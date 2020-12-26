#include "items.h"
#include "misc.h"
#include "mmr.h"
#include "z2.h"

/**
 * Hook function used to write the chest get-item index on init.
 **/
void chest_write_gi_index(ActorEnBox *actor, GlobalContext *game) {
    if (!MISC_CONFIG.vanilla_layout) {
        u16 result;

        // Read from chest-table file to determine gi-table index, and write to actor field.
        u16 index = (actor->base.params >> 5) & 0x7F;
        u32 prom = z2_file_table[mmr_ChestTableFileIndex].romStart + (index * 2);
        z2_RomToRam(prom, &result, sizeof(result));
        actor->giIndex = result;

        // If ice trap chest, use special value instead of index.
        mmr_gi_t *entry = mmr_LoadGiEntry(actor->giIndex);
        if (entry->item == Z2_ICE_TRAP) {
            actor->giIndex = 0x76;
        }
    } else {
        // Vanilla Layout behavior
        actor->giIndex = (actor->base.params >> 5) & 0x7F;
    }
}

/**
 * Hook function used to update the chest get-item index before opening.
 **/
u32 chest_get_new_gi_index(ActorEnBox *actor, GlobalContext *game, bool grant) {
    if (!MISC_CONFIG.vanilla_layout) {
        // Resolve new gi-table index if not ice trap.
        if (actor->giIndex != 0x76) {
            return mmr_GetNewGiIndex(game, &(actor->base), actor->giIndex, grant);
        }
    }
    return actor->giIndex;
}
