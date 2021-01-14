#include <z64.h>
#include "Item00.h"
#include "MMR.h"

ActorEnItem00* Rupeecrow_AfterRupeeSpawn(GlobalContext* ctxt, ActorEnRuppecrow* actor, ActorEnItem00* item) {
    u16 giIndex = 0x364 + (item->base.params & 0x03);
    Item00_CheckAndSetGiIndex(item, ctxt, giIndex);
    return item;
}
