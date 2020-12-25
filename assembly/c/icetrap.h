#ifndef ICETRAP_H
#define ICETRAP_H

#include <stdbool.h>
#include "z2.h"

bool icetrap_give(ActorPlayer *link, z2_game_t *game);
bool icetrap_is_pending();
void icetrap_push_pending();

#endif // ICETRAP_H
