#include <stdbool.h>
#include "misc.h"
#include "z2.h"

/**
 * Helper function for advancing to the next actor cutscene. Is basically a copy of an existing
 * function within En_Toto.
 **/
static int toto_advance_actor_cutscene(z2_en_toto_t *toto, z2_game_t *game) {
    if (z2_ActorCutscene_GetCanPlayNext(toto->actor_cutscene)) {
        z2_actor_t *link = &(Z2_LINK(game)->common);
        z2_ActorCutscene_StartAndSetUnkLinkFields(toto->actor_cutscene, link);
        return 1;
    } else {
        z2_ActorCutscene_SetIntentToPlay(toto->actor_cutscene);
        return 0;
    }
}

/**
 * Hook function used to check whether or not to skip setting up for the "formal replay" part of
 * the actor cutscenes.
 **/
bool toto_should_skip_formal_replay(z2_en_toto_t *toto, z2_game_t *game) {
    bool finished = (toto->song_flags & 0xF) == 0xF;
    return MISC_CONFIG.speedups.sound_check && !finished;
}

/**
 * Hook function used for advancing actor cutscene while index is 0xC (preparing for "formal replay").
 **/
int toto_prepare_formal_replay(z2_en_toto_t *toto, z2_game_t *game) {
    if (toto_should_skip_formal_replay(toto, game)) {
        // End actor cutscenes prematurely if song not complete.
        toto->func_index = 0;
        toto->frame_count = 0;
        z2_ActorCutscene_End();
        return 0;
    } else {
        // Default behavior.
        return toto_advance_actor_cutscene(toto, game);
    }
}
