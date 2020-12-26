#ifndef RELOC_H
#define RELOC_H

#include "z2.h"

#define GET_RELOC_FUNC(NAME, OVL) ((NAME##_proc)reloc_resolve_player_ovl(&OVL, NAME##_vram))
#define GET_RELOC_PAUSE_FUNC(NAME)  GET_RELOC_FUNC(NAME, s801D0B70.kaleidoScope)
#define GET_RELOC_PLAYER_FUNC(NAME) GET_RELOC_FUNC(NAME, s801D0B70.playerActor)

/* Macros for resolving RAM addresses from gamestate entries */
#define GET_GS_RELOC_TYPE(NAME, GS) (*(NAME##_t *)reloc_resolve_gamestate(&(GS), (NAME##_vram)))

/* Relocatable player functions */
#define z2_LinkDamage        GET_RELOC_PLAYER_FUNC(z2_LinkDamage)
#define z2_LinkInvincibility GET_RELOC_PLAYER_FUNC(z2_LinkInvincibility)
#define z2_UseItem           GET_RELOC_PLAYER_FUNC(z2_UseItem)

#define z2_PerformEnterWaterEffects GET_RELOC_PLAYER_FUNC(z2_PerformEnterWaterEffects)
#define z2_PlayerHandleBuoyancy     GET_RELOC_PLAYER_FUNC(z2_PlayerHandleBuoyancy)

/* Relocatable pause menu functions */
#define z2_PauseDrawItemIcon GET_RELOC_PAUSE_FUNC(z2_PauseDrawItemIcon)

/* Relocatable file select data */
#define ResolveGamestateRelocType(Type, Vram, Gs) ((Type*)reloc_resolve_gamestate(&(Gs), (Vram)))
#define ResolveFileChooseData() ResolveGamestateRelocType(FileChooseData, FileChooseDataVRAM, gGameStateInfo.fileSelect)

void * reloc_resolve_actor_ovl(ActorOverlay *ovl, u32 vram);
ActorInit * reloc_resolve_actor_init(ActorOverlay *ovl);
void * reloc_resolve_gamestate(GameStateOverlay *gs, u32 vram);
void * reloc_resolve_player_ovl(PlayerOverlay *ovl, u32 vram);

#endif // RELOC_H
