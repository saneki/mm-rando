#include <z64.h>
#include "Item00.h"
#include "MMR.h"

ActorEnItem00* Rupeecrow_AfterRupeeSpawn(GlobalContext* ctxt, ActorEnRuppecrow* actor, ActorEnItem00* item) {
    u16 giIndex;
    if ((item->base.params & 0x03) == 1) {
        // blue rupee
        giIndex = 0x396 + (actor->rupeeSpawnCount / 5);
    } else {
        // green or red rupee
        giIndex = 0x382 + actor->rupeeSpawnCount;
    }
    Item00_CheckAndSetGiIndex(item, ctxt, giIndex);
    return item;
}
