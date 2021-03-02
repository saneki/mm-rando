#include <z64.h>
#include "BaseRupee.h"

ActorEnItem00* RupeeCluster_SpawnRupee(GlobalContext* ctxt, Actor* spawner, ActorEnItem00* item, u8 count) {
    u16 giIndex;
    if (spawner->params == 0x4013) {
        // Deku Palace
        giIndex = 0x397 + count;
    } else if (spawner->params == 0x402D) {
        // Beneath the Graveyard
        giIndex = 0x39E + count;
    } else {
        giIndex = 0;
    }

    if (giIndex > 0) {
        Rupee_CheckAndSetGiIndex(&item->base, ctxt, giIndex);
    }
    return item;
}
