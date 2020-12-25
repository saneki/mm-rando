#include "z2.h"

struct vram_info {
    void *ram;
    u32 virt_start;
    u32 virt_end;
};

static void * resolve(struct vram_info info, u32 vram) {
    if (info.ram && info.virt_start <= vram && vram < info.virt_end) {
        u32 offset = vram - info.virt_start;
        return (void *)((char *)info.ram + offset);
    } else {
        return NULL;
    }
}

void * reloc_resolve_actor_ovl(ActorOverlay *ovl, u32 vram) {
    struct vram_info info = {
        .ram = ovl->loadedRamAddr,
        .virt_start = (u32)ovl->vramStart,
        .virt_end = (u32)ovl->vramEnd,
    };

    return resolve(info, vram);
}

ActorInit * reloc_resolve_actor_init(ActorOverlay *ovl) {
    return reloc_resolve_actor_ovl(ovl, (u32)ovl->initInfo);
}

void * reloc_resolve_gamestate(GameStateOverlay *gs, u32 vram) {
    struct vram_info info = {
        .ram = gs->loadedRamAddr,
        .virt_start = gs->vramStart,
        .virt_end = gs->vramEnd,
    };

    return resolve(info, vram);
}

void * reloc_resolve_player_ovl(PlayerOverlay *ovl, u32 vram) {
    struct vram_info info = {
        .ram = ovl->loadedRamAddr,
        .virt_start = ovl->vramStart,
        .virt_end = ovl->vramEnd,
    };

    return resolve(info, vram);
}
