#ifndef FAIRY_H
#define FAIRY_H

#include <stdbool.h>
#include "z2.h"

bool can_interact_with_fairy(GlobalContext *game, ActorPlayer *link);
bool get_next_fairy_instance(u16 *inst, GlobalContext *game);
void reset_fairy_instance_usage();
Actor* spawn_next_fairy_actor(GlobalContext *game, Vec3f pos);

#endif // FAIRY_H
