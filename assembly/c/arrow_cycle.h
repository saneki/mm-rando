#ifndef ARROW_CYCLE
#define ARROW_CYCLE

#include "z2.h"

Actor * arrow_cycle_find_arrow(ActorPlayer *link, z2_game_t *game);
void arrow_cycle_handle(ActorPlayer *link, z2_game_t *game);

#endif // ARROW_CYCLE
