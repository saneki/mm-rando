#ifndef ACTOR_H
#define ACTOR_H

#include "z2.h"

void actor_after_dtor(Actor *actor, z2_game_t *game);
Actor* actor_spawn(z2_game_t *game, u8 id, Vec3f pos, Vec3s rot, u16 var);

#endif // ACTOR_H
