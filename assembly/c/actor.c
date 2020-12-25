#include "actor_ext.h"
#include "models.h"
#include "z2.h"

/**
 * Hook function called after an actor's deconstructor function has been called.
 **/
void actor_after_dtor(Actor *actor, z2_game_t *game) {
    // Free any Actor Extended data this actor may point to.
    actor_ext_after_actor_dtor(actor);
    // Unload actor model information after dtor.
    models_after_actor_dtor(actor);
}

Actor* actor_spawn(z2_game_t *game, u8 id, Vec3f pos, Vec3s rot, u16 var) {
    return z2_SpawnActor(&(game->actor_ctxt), game, id, pos.x, pos.y, pos.z, rot.x, rot.y, rot.z, var);
}
