#ifndef ACTOR_H
#define ACTOR_H

#include "z2.h"

void actor_after_dtor(Actor *actor, GlobalContext *game);
Actor* actor_spawn(GlobalContext *game, u8 id, Vec3f pos, Vec3s rot, u16 var);

#endif // ACTOR_H
