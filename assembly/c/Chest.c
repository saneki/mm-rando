#include <z2.h>
#include "Items.h"
#include "Misc.h"
#include "MMR.h"

/**
 * Hook function used to write the chest get-item index on init.
 **/
void Chest_WriteGiIndex(ActorEnBox* actor, GlobalContext* ctxt) {
    if (!MISC_CONFIG.internal.vanillaLayout) {
        u16 result;
        // Read from chest-table file to determine gi-table index, and write to actor field.
        u16 index = (actor->base.params >> 5) & 0x7F;
        u32 prom = dmadata[MMR_ChestTableFileIndex].romStart + (index * 2);
        z2_RomToRam(prom, &result, sizeof(result));
        actor->giIndex = result;
        // If ice trap chest, use special value instead of index.
        GetItemEntry* entry = MMR_LoadGiEntry(actor->giIndex);
        if (entry->item == CUSTOM_ITEM_ICE_TRAP) {
            actor->giIndex = 0x76;
        }
    } else {
        // Vanilla Layout behavior.
        actor->giIndex = (actor->base.params >> 5) & 0x7F;
    }
}

/**
 * Hook function used to update the chest get-item index before opening.
 **/
u32 Chest_GetNewGiIndex(ActorEnBox* actor, GlobalContext* ctxt, bool grant) {
    if (!MISC_CONFIG.internal.vanillaLayout) {
        // Resolve new gi-table index if not ice trap.
        if (actor->giIndex != 0x76) {
            return MMR_GetNewGiIndex(ctxt, &actor->base, actor->giIndex, grant);
        }
    }
    return actor->giIndex;
}
