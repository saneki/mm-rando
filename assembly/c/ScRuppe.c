#include <z64.h>
#include "MMR.h"
#include "Player.h"

// TODO pick a definitely unused part of the ScRuppe actor memory
void ScRuppe_SetGiIndex(ActorEnScRuppe* actor, u16 giIndex) {
    u16* pointer = (u16*)(&actor->base.unkE0);
    *pointer = giIndex;
}

u16 ScRuppe_GetGiIndex(ActorEnScRuppe* actor) {
    u16* pointer = (u16*)(&actor->base.unkE0);
    return *pointer;
}

void ScRuppe_SetDrawGiIndex(ActorEnScRuppe* actor, u16 drawGiIndex) {
    u16* pointer = (u16*)(&actor->base.unkE0);
    pointer++;
    *pointer = drawGiIndex;
}

u16 ScRuppe_GetDrawGiIndex(ActorEnScRuppe* actor) {
    u16* pointer = (u16*)(&actor->base.unkE0);
    pointer++;
    return *pointer;
}

void ScRuppe_CheckAndSetGiIndex(ActorEnScRuppe* actor, GlobalContext* ctxt, u16 giIndex) {
    GetItemEntry* entry = MMR_GetGiEntry(giIndex);
    if (entry->item != 0 && entry->message != 0) {
        ScRuppe_SetGiIndex(actor, giIndex);
        u16 drawGiIndex = MMR_GetNewGiIndex(ctxt, 0, giIndex, false);
        ScRuppe_SetDrawGiIndex(actor, drawGiIndex);
    }
}

void ScRuppe_Constructor(ActorEnScRuppe* actor, GlobalContext* ctxt) {
    u16 giIndex = 0x366;
    // There's only two instances of this actor in the game. They'll both give the same item.
    // If more are discovered, this will have to be updated.

    ScRuppe_CheckAndSetGiIndex(actor, ctxt, giIndex);
}

bool ScRuppe_GiveItem(ActorEnScRuppe* actor, GlobalContext* ctxt) {
    u16 giIndex = ScRuppe_GetGiIndex(actor);
    if (giIndex == 0) {
        return false;
    }
    MMR_GiveItem(ctxt, &actor->base, giIndex);
    return true;
}
