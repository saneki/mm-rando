#ifndef WORLD_SKULLTULA_H
#define WORLD_SKULLTULA_H

#include <stdbool.h>
#include "z2.h"

void world_skulltula_debug_after_actor_dtor(z2_actor_t *actor);
void world_skulltula_after_scene_init(z2_game_t *game);
void world_skulltula_debug_process(z2_link_t *link, z2_game_t *game);
bool world_skulltula_enabled(void);

#endif // WORLD_SKULLTULA_H
