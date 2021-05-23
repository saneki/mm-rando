#include <z64.h>
#include "Misc.h"
#include "MMR.h"

void DoorWarp_GiveItem(ActorDoorWarp1* actor, GlobalContext* ctxt) {
    actor->warpTimer--;
    if (actor->warpTimer == 0 && !MISC_CONFIG.internal.vanillaLayout) {
        MMR_ProcessItem(ctxt, 0x77);
    }
}
