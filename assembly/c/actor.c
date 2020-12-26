#include "actor_ext.h"
#include "models.h"
#include "z2.h"

/**
 * Hook function called after an actor's deconstructor function has been called.
 **/
void Actor_AfterDtor(Actor *actor, GlobalContext *ctxt) {
    // Free any Actor Extended data this actor may point to.
    ActorExt_AfterActorDtor(actor);
    // Unload actor model information after dtor.
    models_after_actor_dtor(actor);
}

Actor* Actor_Spawn(GlobalContext *ctxt, u8 id, Vec3f pos, Vec3s rot, u16 params) {
    return z2_SpawnActor(&ctxt->actorCtx, ctxt, id, pos.x, pos.y, pos.z, rot.x, rot.y, rot.z, params);
}
