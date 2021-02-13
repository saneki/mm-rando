#ifndef _Z64ADDRESSES_H_
#define _Z64ADDRESSES_H_

#include <z64.h>

// Virtual File Addresses.
#define ItemTextureFileVROM              0xA36C10

// Data Addresses.
#define ArenaAddr                        0x8009CD20
#define DmaEntryTableAddr                0x8009F8B0
#define ActorOverlayTableAddr            0x801AEFD0
#define GetItemGraphicTableAddr          0x801BB170
#define GameStateTableAddr               0x801BD910
#define ItemTextureSegAddrTableAddr      0x801C1E6C // Segment address table used for item textures.
#define ObjectTableAddr                  0x801C2740
#define SongNotesAddr                    0x801CFC98
#define SaveContextAddr                  0x801EF670
#define GameArenaAddr                    0x801F5100
#define SegmentTableAddr                 0x801F8180
#define StaticContextAddr                0x803824D0
#define GlobalContextAddr                0x803E6B20 // Todo: Remove.

// Data.
#define gActorOverlayTable               ((ActorOverlay*)            ActorOverlayTableAddr)
#define gSaveContext                     (*(SaveContext*)            SaveContextAddr)
#define dmadata                          ((DmaEntry*)                DmaEntryTableAddr)
#define gGlobalContext                   (*(GlobalContext*)          GlobalContextAddr)
#define gGameStateInfo                   (*(GameStateTable*)         GameStateTableAddr)
#define gGetItemGraphicTable             ((GetItemGraphicEntry*)     GetItemGraphicTableAddr)
#define gObjectFileTable                 ((ObjectFileTableEntry*)    ObjectTableAddr)
#define gRspSegmentPhysAddrs             (*(SegmentTable*)           SegmentTableAddr)
#define gSongNotes                       (*(SongNotes*)              SongNotesAddr)
#define s803824D0                        (*(StaticContext*)          StaticContextAddr)

// Data (non-struct).
#define gItemTextureSegAddrTable         ((u32*)                     ItemTextureSegAddrTableAddr)

// Data (unknown).
#define s801BD8B0                        (*(struct_801BD8B0*)        0x801BD8B0)
#define s801D0B70                        (*(struct_801D0B70*)        0x801D0B70)

// Function Prototypes.
extern int z2_CanInteract(GlobalContext *game);
extern int z2_CanInteract2(GlobalContext *game, ActorPlayer *link);
extern void z2_DrawButtonAmounts(GlobalContext *game, u32 arg1, u16 alpha);
extern void z2_DrawBButtonIcon(GlobalContext *game);
extern void z2_DrawCButtonIcons(GlobalContext *game);
extern u32 z2_GetFloorPhysicsType(void *arg0, void *arg1, u8 arg2);
extern f32* z2_GetMatrixStackTop();
extern void z2_PlaySfx(u32 id);
extern Actor* z2_SpawnActor(ActorContext *actor_ctx, GlobalContext *game, u16 id,
                                          f32 x, f32 y, f32 z, u16 rx, u16 ry, u16 rz, u16 variable);
extern void z2_UpdateButtonUsability(GlobalContext *game);
extern void z2_WriteHeartColors(GlobalContext *game);
extern void z2_RemoveItem(u32 item, u8 slot);
extern void z2_ToggleSfxDampen(int enable);
extern void z2_HandleInputVelocity(f32 *linear_velocity, f32 input_velocity, f32 increaseBy, f32 decreaseBy);
extern bool z2_SetGetItemLongrange(Actor *actor, GlobalContext *game, u16 gi_index);

// Function Prototypes (Scene Flags).
// TODO parameters
extern void z2_get_generic_flag();
extern void z2_set_generic_flag();
extern void z2_remove_generic_flag(GlobalContext *game, s8 flag);
extern void z2_get_chest_flag();
extern void z2_set_chest_flag();
extern void z2_set_all_chest_flags();
extern void z2_get_all_chest_flags();
extern void z2_get_clear_flag();
extern void z2_set_clear_flag();
extern void z2_remove_clear_flag();
extern void z2_get_temp_clear_flag();
extern void z2_set_temp_clear_flag();
extern void z2_remove_temp_clear_flag();
extern void z2_get_collectible_flag();
extern void z2_set_collectibe_flag();
extern void z2_load_scene_flags();
extern void z2_check_scene_pairs();
extern void z2_store_scene_flags();

// Function Prototypes (Actors).
extern void z2_ActorProc(Actor *actor, GlobalContext *game);
extern void z2_ActorRemove(ActorContext *ctxt, Actor *actor, GlobalContext *game);
extern void z2_ActorUnload(Actor *actor);

// Function Prototypes (Actor Cutscene).
extern void z2_ActorCutscene_ClearWaiting(void);
extern void z2_ActorCutscene_ClearNextCutscenes(void);
extern void z2_ActorCutscene_MarkNextCutscenes(void);
extern void z2_ActorCutscene_End(void);
extern void z2_ActorCutscene_Update(void);
extern void z2_ActorCutscene_SetIntentToPlay(s16 index);
extern s16 z2_ActorCutscene_GetCanPlayNext(s16 index);
extern s16 z2_ActorCutscene_StartAndSetUnkLinkFields(s16 index, Actor *actor);
extern s16 z2_ActorCutscene_StartAndSetFlag(s16 index, Actor *actor);
extern s16 z2_ActorCutscene_Start(s16 index, Actor *actor);
extern s16 z2_ActorCutscene_Stop(s16 index);
extern s16 z2_ActorCutscene_GetCurrentIndex(void);
extern ActorCutscene* z2_ActorCutscene_GetCutscene(s16 index);
extern s16 z2_ActorCutscene_GetAdditionalCutscene(s16 index);
extern s16 z2_ActorCutscene_GetLength(s16 index);
extern s16 z2_ActorCutscene_GetCurrentCamera(void);
extern void z2_ActorCutscene_SetReturnCamera(s16 index);

// Function Prototypes (Drawing).
extern void z2_BaseDrawCollectable(Actor *actor, GlobalContext *game);
extern void z2_BaseDrawGiModel(GlobalContext *game, u32 graphic_id_minus_1);
extern void z2_CallSetupDList(GraphicsContext *gfx);
extern void z2_DrawHeartPiece(Actor *actor, GlobalContext *game);
extern void z2_PreDraw1(Actor *actor, GlobalContext *game, u32 unknown);
extern void z2_PreDraw2(Actor *actor, GlobalContext *game, u32 unknown);

// Function Prototypes (File Loading).
extern s32 z2_RomToRam(u32 src, void *dst, u32 length);
extern s16 z2_GetFileNumber(u32 vrom_addr);
extern u32 z2_GetFilePhysAddr(u32 vrom_addr);
extern DmaEntry* z2_GetFileTable(u32 vrom_addr);
extern void z2_LoadFile(DmaParams *loadfile);
extern void z2_LoadFileFromArchive(u32 phys_file, u8 index, u8 *dest, u32 length);
extern void z2_LoadVFileFromArchive(u32 virt_file, u8 index, u8 *dest, u32 length);
extern void z2_ReadFile(void *mem_addr, u32 vrom_addr, u32 size);

extern void z2_Yaz0_LoadAndDecompressFile(u32 prom_addr, void *dest, u32 length);

// Function Prototypes (Get Item).
extern void z2_SetGetItem(Actor *actor, GlobalContext *game, s32 unk2, u32 unk3);
extern void z2_GiveItem(GlobalContext *game, u8 item_id);
extern void z2_GiveMap(u32 map_index);

// Function Prototypes (HUD).
extern void z2_HudSetAButtonText(GlobalContext *game, u16 text_id);
extern void z2_InitButtonNoteColors(GlobalContext *game);
extern void z2_ReloadButtonTexture(GlobalContext *game, u8 idx);
extern void z2_UpdateButtonsState(u32 state);

// Function Prototypes (Math).
extern f32 z2_Math_Sins(s16 angle);
extern f32 z2_Math_Vec3f_DistXZ(Vec3f *p1, Vec3f *p2);

// Function Prototypes (Objects).
extern s8 z2_GetObjectIndex(const SceneContext *ctxt, u16 object_id);

// Function Prototypes (OS).
extern void z2_memcpy(void *dest, const void *src, size_t size);

// Function Prototypes (RNG).
extern u32 z2_RngInt();
extern void z2_RngSetSeed(u32 seed);

// Function Prototypes (Rooms).
extern void z2_LoadRoom(GlobalContext *game, RoomContext *room_ctxt, uint8_t room_id);
extern void z2_UnloadRoom(GlobalContext *game, RoomContext *room_ctxt);

// Function Prototypes (Sound).
extern void z2_SetBGM2(u16 bgm_id);

// Function Prototypes (Text).
extern void z2_ShowMessage(GlobalContext *game, u16 message_id, u8 something); // TODO figure out something?

// Relocatable Functions (kaleido_scope).
#define z2_PauseDrawItemIcon_VRAM        0x80821AD4

// Relocatable Functions (player_actor).
#define z2_LinkDamage_VRAM               0x80833B18
#define z2_LinkInvincibility_VRAM        0x80833998
#define z2_PerformEnterWaterEffects_VRAM 0x8083B8D0
#define z2_PlayerHandleBuoyancy_VRAM     0x808475B4
#define z2_UseItem_VRAM                  0x80831990

// Relocatable Types (file_choose).
#define FileChooseDataVRAM               0x80813DF0

// Function Prototypes (Relocatable kaleido_scope functions).
typedef void (*z2_PauseDrawItemIcon_Func)(GraphicsContext* gfx, u32 segAddr, u16 width, u16 height, u16 quadVtxIdx);

// Function Prototypes (Relocatable player_actor functions).
typedef void (*z2_LinkDamage_Func)(GlobalContext* ctxt, ActorPlayer* player, u32 type, u32 arg3);
typedef void (*z2_LinkInvincibility_Func)(ActorPlayer* player, u8 frames);
typedef void (*z2_PerformEnterWaterEffects_Func)(GlobalContext* ctxt, ActorPlayer* player);
typedef void (*z2_PlayerHandleBuoyancy_Func)(ActorPlayer* player);
typedef void (*z2_UseItem_Func)(GlobalContext* ctxt, ActorPlayer* player, u8 item);

#endif
