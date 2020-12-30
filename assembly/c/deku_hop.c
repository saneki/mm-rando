#include <z2.h>
#include "misc.h"

struct DekuHopState {
    u8 lastHop;
};

static struct DekuHopState gDekuHopState = {
    .lastHop = 5,
};

void DekuHop_Handle(ActorPlayer* player, GlobalContext* ctxt) {
    if (!MISC_CONFIG.flags.continuousDekuHop) {
        return;
    }

    if (player->dekuHopCounter < 5 && player->dekuHopCounter > 0 && player->dekuHopCounter != gDekuHopState.lastHop) {
        if (ctxt->state.input[0].pressEdge.buttons.a) {
            ctxt->state.input[0].pressEdge.buttons.a = 0;
            player->dekuHopCounter++;
            gDekuHopState.lastHop = player->dekuHopCounter;
        }
    } else {
        gDekuHopState.lastHop = player->dekuHopCounter;
    }
}
