#include <stdbool.h>
#include "misc.h"
#include "z2.h"

/**
 * Hook function used to check if the Fisherman's Game should end.
 *
 * If speedup is enabled, checks if player has enough points to end early.
 **/
bool fisherman_should_end_game(z2_actor_t *actor, z2_game_t *game, u32 timer_hi, u32 timer_lo) {
    bool timeout = (timer_hi == 0 && timer_lo == 0);
    return ((MISC_CONFIG.speedups.fisherman_game && z2_file.minigame_counter >= 20) || timeout);
}

/**
 * Hook function used to check if the timer satisfies giving the player a reward.
 *
 * If speedup is enabled the minigame ends early, so ignores the timer check.
 **/
bool fisherman_should_pass_timer_check(z2_actor_t *actor, z2_game_t *game, u32 timer_hi, u32 timer_lo) {
    if (MISC_CONFIG.speedups.fisherman_game) {
        return true;
    } else {
        return timer_hi == 0 && timer_lo == 0;
    }
}
