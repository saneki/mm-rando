#include <z64.h>
#include "MMR.h"
#include "Player.h"
#include "BaseRupee.h"

void ScRuppe_Constructor(ActorEnScRuppe* actor, GlobalContext* ctxt) {
    u16 giIndex = 0x366;
    // There's only two instances of this actor in the game. They'll both give the same item.
    // If more are discovered, this will have to be updated.

    Rupee_CheckAndSetGiIndex(&actor->base, ctxt, giIndex);
}

bool ScRuppe_GiveItem(ActorEnScRuppe* actor, GlobalContext* ctxt) {
    u16 giIndex = Rupee_GetGiIndex(&actor->base);
    if (giIndex == 0) {
        return false;
    }
    MMR_GiveItem(ctxt, &actor->base, giIndex);
    return true;
}
