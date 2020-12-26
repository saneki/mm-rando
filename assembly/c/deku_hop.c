#include <stdbool.h>
#include "misc.h"
#include "z2.h"

struct deku_hop_state {
    u8 last_hop;
};

static struct deku_hop_state g_deku_hop_state = {
    .last_hop = 5,
};

void deku_hop_handle(ActorPlayer *link, z2_game_t *game) {
    if (!MISC_CONFIG.continuous_deku_hop) {
        return;
    }

    if (link->dekuHopCounter < 5 && link->dekuHopCounter > 0 && link->dekuHopCounter != g_deku_hop_state.last_hop) {
        if (game->state.input[0].pressEdge.buttons.a) {
            game->state.input[0].pressEdge.buttons.a = 0;
            link->dekuHopCounter++;
            g_deku_hop_state.last_hop = link->dekuHopCounter;
        }
    } else {
        g_deku_hop_state.last_hop = link->dekuHopCounter;
    }
}
