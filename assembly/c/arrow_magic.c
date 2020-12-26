#include <stdbool.h>
#include "arrow_cycle.h"
#include "misc.h"
#include "z2.h"

struct arrow_magic_state {
    Actor *arrow;
};

static struct arrow_magic_state g_arrow_magic_state = {
    .arrow = NULL,
};

static void arrow_magic_update_state(struct arrow_magic_state *state, ActorPlayer *link, GlobalContext *game) {
    Actor *arrow = state->arrow;
    // Check if arrow has been shot, speed is checked to ensure arrow isn't just put away.
    if (link->base.child == NULL && arrow != NULL && arrow->speedXZ != 0.0) {
        // Update state to consume magic once arrow is shot.
        if (gSaveContext.extra.magicConsumeState == 4) {
            gSaveContext.extra.magicConsumeState = 2;
        } else if (arrow->params == 7) {
            // Update magic consume cost, prevents Deku Bubble from taking more magic than expected
            // if used while an elemental arrow effect is still active.
            gSaveContext.extra.magicConsumeCost = 2;
            // Deku Bubble won't set magic consumption state to 0 later, so apply magic cost manually.
            if (!HasInfiniteMagic(gSaveContext)) {
                gSaveContext.perm.unk24.currentMagic -= gSaveContext.extra.magicConsumeCost;
                if (gSaveContext.perm.unk24.currentMagic < 0) {
                    gSaveContext.perm.unk24.currentMagic = 0;
                }
            }
        }
        state->arrow = NULL;
    } else {
        state->arrow = ArrowCycle_FindArrow(link, game);
    }
}

/**
 * Hook function used to get the initial magic consumption state for an elemental arrow.
 **/
s16 arrow_magic_get_initial_consume_state(GlobalContext *game) {
    if (MISC_CONFIG.arrow_magic_show) {
        return 4;
    } else {
        return 1;
    }
}

/**
 * Hook function used to check whether or not the magic cost of the current elemental arrow should
 * be written to RDRAM.
 **/
bool arrow_magic_should_set_magic_cost(GlobalContext *game, bool inf_magic) {
    if (MISC_CONFIG.arrow_magic_show) {
        // If showing magic cost, always set magic cost field for consistency.
        return true;
    } else {
        // Vanilla behavior, do not set magic cost field if infinite magic is active.
        return !inf_magic;
    }
}

/**
 * Handle arrow magic consumption state.
 **/
void arrow_magic_handle(ActorPlayer *link, GlobalContext *game) {
    if (MISC_CONFIG.arrow_magic_show) {
        arrow_magic_update_state(&g_arrow_magic_state, link, game);
    }
}
