#include <stdbool.h>
#include "misc.h"
#include "reloc.h"
#include "z2.h"

// Function in Bg_Ingate used to update the actor's movement. It will also update the flags when
// its path is finished.
#define UpdateCanoeMovement_addr 0x80953BEC
typedef void (*UpdateCanoeMovement_proc)(ActorBgIngate *actor);

/**
 * Helper function used to resolve and call function for processing boat movement along its path.
 **/
static void boat_cruise_process_movement(ActorBgIngate *canoe) {
    ActorOverlay *entry = &z2_actor_ovl_table[0xA7];
    UpdateCanoeMovement_proc function = reloc_resolve_actor_ovl(entry, UpdateCanoeMovement_addr);
    if (function != NULL) {
        function(canoe);
    }
}

/**
 * Hook function used to continue moving boat if needed during frame when processing boat archery
 * end.
 **/
void boat_cruise_before_cruise_end(ActorBgIngate *canoe, z2_game_t *game) {
    if (MISC_CONFIG.speedups.boat_archery && canoe->flags == 0x19) {
        boat_cruise_process_movement(canoe);
    }
}

/**
 * Hook function used to get speed of boat during cruise or archery.
 **/
s16 boat_cruise_get_boat_speed(ActorBgIngate *canoe, int mode) {
    if (mode == 0) {
        // Boat Cruise
        if (!MISC_CONFIG.speedups.boat_archery) {
            return 4;
        } else {
            return 8;
        }
    } else {
        // Boat Archery
        return 1;
    }
}

/**
 * Hook function used to continue moving boat if needed when "idling" after ending boat archery.
 **/
void boat_cruise_handle_idle(ActorBgIngate *canoe, z2_game_t *game) {
    if (MISC_CONFIG.speedups.boat_archery && canoe->flags == 0x19) {
        boat_cruise_process_movement(canoe);
    }
}

/**
 * Hook function used to check if archery should be ended.
 *
 * If the speedup is enabled, checks if the player has enough points to end the game early.
 **/
bool boat_cruise_should_end_archery(ActorBgIngate *canoe, z2_game_t *game) {
    bool finished = (canoe->flags & 2) == 2;
    if (MISC_CONFIG.speedups.boat_archery) {
        return finished || (((z2_file.owl.eventInf[3] & 0x20) != 0) && (z2_file.extra.minigameCounter[0] >= 20));
    } else {
        return finished;
    }
}
