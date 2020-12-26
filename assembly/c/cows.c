#include "misc.h"
#include "z2.h"

/**
 * Get the En_Cow actor which is closest to Link and which can give milk.
 **/
static Actor * cows_get_closest_to_link(z2_game_t *game) {
    Actor *closest = NULL;

    // Iterate actor_list entries.
    for (int i = 0; i < Z2_ACTOR_LIST_ENTRIES; i++) {
        s32 count = game->actorCtx.actorList[i].length;
        Actor *cur = game->actorCtx.actorList[i].first;
        // Iterate actor linked list for each entry.
        for (s32 j = 0; j < count; j++, cur = cur->next) {
            // In vanilla game: cow only gives milk if variable 0 or 2.
            // In MMR, just make sure variable is not 1, since it is used for the gi-table index.
            if (cur->id == Z2_ACTOR_EN_COW && cur->params != 1) {
                // Check if we already have a closest but the current actor is closer.
                if (closest != NULL && cur->xzDistanceFromLink < closest->xzDistanceFromLink) {
                    closest = cur;
                // Check if we don't have a closest yet.
                } else if (closest == NULL) {
                    closest = cur;
                }
            }
        }
    }

    return closest;
}

/**
 * Hook function which checks if a cow is close enough to Link to give milk.
 **/
bool cows_is_close_enough_to_give_milk(Actor *actor, z2_game_t *game) {
    if (actor->xzDistanceFromLink < 150.0) {
        if (!MISC_CONFIG.close_cows) {
            return true;
        } else {
            return actor == cows_get_closest_to_link(game);
        }
    } else {
        return false;
    }
}
