#include <z64.h>
#include "BaseRupee.h"
#include "MMR.h"

void DekuScrubPlaygroundRupee_GiveItem(GlobalContext* ctxt, ActorEnGamelupy* actor) {
    u16 giIndex = Rupee_GetGiIndex(&actor->base);
    if (giIndex > 0) {
        if (MMR_GiveItem(ctxt, giIndex)) {
            Rupee_SetGiIndex(&actor->base, 0);
        }
    } else {
        z2_AddRupees(actor->isBlueRupee ? 5 : 1);
        z2_PlaySfxAtActor(&actor->base, 0x4803);
    }
}
