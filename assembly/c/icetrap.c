#include <stdbool.h>
#include "reloc.h"
#include "z2.h"

static u8 gPendingFreezes = 0;

bool Icetrap_IsPending(void) {
    return gPendingFreezes > 0;
}

void Icetrap_PushPending(void) {
    if (gPendingFreezes < 0xFF) {
        gPendingFreezes += 1;
    }
}

bool Icetrap_Give(ActorPlayer* player, GlobalContext* ctxt) {
    // Ensure this is the Player actor, and not Kafei.
    if (player->base.id != 0) {
        return false;
    }

    u32 mask1 = Z2_ACTION_STATE1_TIME_STOP |
                Z2_ACTION_STATE1_TIME_STOP_2;

    // Return early if Link is in certain state.
    if ((player->stateFlags.state1 & mask1) != 0) {
        return false;
    }

    if (gPendingFreezes) {
        gPendingFreezes -= 1;
        z2_LinkInvincibility(player, 0x14);
        z2_LinkDamage(ctxt, player, Z2_DAMAGE_EFFECT_FREEZE, 0x40800000);
        return true;
    } else {
        return false;
    }
}
