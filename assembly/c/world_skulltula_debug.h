#ifndef WORLD_SKULLTULA_DEBUG_H
#define WORLD_SKULLTULA_DEBUG_H

#include <stdbool.h>
#include "z2.h"

// World of Skulltula debug struct magic: "SDBG"
#define WORLD_SKULLTULA_DEBUG_MAGIC (0x53444247)

void world_skulltula_debug_after_actor_dtor(z2_actor_t *actor);
void world_skulltula_debug_after_scene_init(z2_game_t *game);
bool world_skulltula_debug_enabled(void);
void world_skulltula_debug_process(z2_link_t *link, z2_game_t *game);

#endif // WORLD_SKULLTULA_DEBUG_H
