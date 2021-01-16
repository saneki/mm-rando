#include <stdbool.h>
#include <z64.h>
#include "Misc.h"
#include "MMR.h"
#include "Player.h"

// TODO pick a definitely unused part of the item00 actor memory
void Item00_SetGiIndex(ActorEnItem00* actor, u16 giIndex) {
    u16* pointer = (u16*)(&actor->base.unkE0);
    *pointer = giIndex;
}

u16 Item00_GetGiIndex(ActorEnItem00* actor) {
    u16* pointer = (u16*)(&actor->base.unkE0);
    return *pointer;
}

void Item00_SetDrawGiIndex(ActorEnItem00* actor, u16 drawGiIndex) {
    u16* pointer = (u16*)(&actor->base.unkE0);
    pointer++;
    *pointer = drawGiIndex;
}

u16 Item00_GetDrawGiIndex(ActorEnItem00* actor) {
    u16* pointer = (u16*)(&actor->base.unkE0);
    pointer++;
    return *pointer;
}

void Item00_CheckAndSetGiIndex(ActorEnItem00* actor, GlobalContext* ctxt, u16 giIndex) {
    GetItemEntry* entry = MMR_GetGiEntry(giIndex);
    if (entry->item != 0 && entry->message != 0) {
        Item00_SetGiIndex(actor, giIndex);
        u16 drawGiIndex = MMR_GetNewGiIndex(ctxt, 0, giIndex, false);
        Item00_SetDrawGiIndex(actor, drawGiIndex);
    }
}

void Item00_Constructor(ActorEnItem00* actor, GlobalContext* ctxt) {
    if (actor->collectableFlag != 0) {
        u16 sceneIndex = ctxt->sceneNum;
        // Stone Tower Temple (Inverted) has distinct collectable switches
        if (sceneIndex != 0x18 && actor->collectableFlag < 0x20) {
            sceneIndex = z2_check_scene_pairs(sceneIndex);
        }
        u16 collectableTableIndex = sceneIndex * 0x80 + actor->collectableFlag;

        u32 index = MISC_CONFIG.internal.collectableTableFileIndex;
        DmaEntry entry = dmadata[index];

        u32 start = entry.vromStart + collectableTableIndex * 2;

        // TODO optimization. check if this works on compressed files.
        // TODO optimization. maybe read the whole scene block when a scene loads.
        u16 giIndex;
        z2_ReadFile(&giIndex, start, 2);
        if (giIndex > 0) {
            Item00_SetGiIndex(actor, giIndex);
            u16 drawGiIndex = MMR_GetNewGiIndex(ctxt, 0, giIndex, false);
            Item00_SetDrawGiIndex(actor, drawGiIndex);
        }
    }
}

bool Item00_GiveItem(ActorEnItem00* actor, GlobalContext* ctxt) {
    u16 giIndex = Item00_GetGiIndex(actor);
    if (giIndex == 0) {
        return false;
    }
    MMR_GiveItem(ctxt, &actor->base, giIndex);
    Player_Pause(ctxt);
    return true;
}
