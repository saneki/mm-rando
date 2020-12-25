#include <stdbool.h>
#include "misc.h"
#include "z2.h"

/**
 * Hook function used to check whether or not the Sakon escape sequence should end.
 **/
bool sakon_should_end_thief_escape(ActorEnSuttari *sakon, z2_game_t *game) {
    // Check if Sakon has dropped the luggage (with speedup) or has finished the escape sequence.
    return ((MISC_CONFIG.speedups.blast_mask_thief && sakon->runningState == 6)
        || sakon->escapeStatus == -0x63);
}
