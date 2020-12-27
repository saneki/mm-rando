#include <stdbool.h>
#include "actor_ext.h"
#include "arrow_cycle.h"
#include "arrow_magic.h"
#include "deku_hop.h"
#include "dpad.h"
#include "external_effects.h"
#include "gfx.h"
#include "hud_colors.h"
#include "icetrap.h"
#include "misc.h"
#include "mmr.h"
#include "models.h"
#include "text.h"
#include "util.h"
#include "world_colors.h"
#include "z2.h"

void c_init() {
    heap_init();
    Sprite_Init();
    Dpad_Init();
    HudColors_Init();
    ActorExt_Init();
    models_init();
    mmr_init();
    misc_init();
    text_init();
    WorldColors_Init();
}

void before_player_actor_update(ActorPlayer *link, GlobalContext *game) {
    Dpad_BeforePlayerActorUpdate(link, game);
    ExternalEffects_Handle(link, game);
    ArrowCycle_Handle(link, game);
    ArrowMagic_Handle(link, game);
    DekuHop_Handle(link, game);
}

bool before_damage_process(ActorPlayer *link, GlobalContext *game) {
    return icetrap_give(link, game);
}

/**
 * Hook function called after preparing display buffers for writing during current frame.
 **/
void game_after_prepare_display_buffers(GraphicsContext *gfx) {
    // Check if models objheap should finish advancing.
    models_after_prepare_display_buffers(gfx);
}
