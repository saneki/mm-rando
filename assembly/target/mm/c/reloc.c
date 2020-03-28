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

void * reloc_resolve_actor_ovl(z2_actor_ovl_table_t *ovl, u32 vram) {
    struct vram_info info = {
        .ram = ovl->ram,
        .virt_start = ovl->vram_start,
        .virt_end = ovl->vram_end,
    };

    return resolve(info, vram);
}

z2_actor_init_t * reloc_resolve_actor_init(z2_actor_ovl_table_t *ovl) {
    return reloc_resolve_actor_ovl(ovl, ovl->initialization);
}

void * get_ram_from_gamestate_vram(z2_gamestate_table_t *gs, u32 vram) {
    if (gs->ram && gs->vram_start <= vram && vram < gs->vram_end) {
        u32 offset = vram - gs->vram_start;
        return (void *)((char *)gs->ram + offset);
    } else {
        return NULL;
    }
}

void * get_ram_from_player_ovl_vram(z2_player_ovl_table_t *ovl, u32 vram) {
    if (ovl->ram && ovl->vram_start <= vram && vram < ovl->vram_end) {
        u32 offset = vram - ovl->vram_start;
        return (void *)((char *)ovl->ram + offset);
    } else {
        return NULL;
    }
}
