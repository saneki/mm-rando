#include <z64.h>
#include "Item00.h"
#include "MMR.h"

u16 ScRuppe_GetGiIndex(Actor* actor) {
    u16 giIndex = 0x366;
    // There's only two instances of this actor in the game. They'll both give the same item.
    // If more are discovered, this will have to be updated.
    
    GetItemEntry* entry = MMR_GetGiEntry(giIndex);
    if (entry->item == 0 || entry->message == 0) {
        giIndex = 0;
    }
    return giIndex;
}

bool ScRuppe_GiveItem(Actor* actor, GlobalContext* ctxt) {
    u16 giIndex = ScRuppe_GetGiIndex(actor);
    if (giIndex > 0) {
        MMR_GiveItem(ctxt, actor, giIndex);
        return true;
    }
    return false;
}
