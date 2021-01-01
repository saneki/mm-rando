#ifndef _Z64ADDRESSES_H_
#define _Z64ADDRESSES_H_

#include <z64.h>

/* Virtual File Addresses */
#define ItemTextureFileVROM              0xA36C10

/* Data Addresses */
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

/* Data */
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

/* Data (non-struct) */
#define gItemTextureSegAddrTable         ((u32*)                     ItemTextureSegAddrTableAddr)

/* Data (Unknown) */
#define s801BD8B0                        (*(struct_801BD8B0*)        0x801BD8B0)
#define s801D0B70                        (*(struct_801D0B70*)        0x801D0B70)

/* Function Addresses */
#define z2_CanInteract_addr              0x801233E4
#define z2_CanInteract2_addr             0x80123358
#define z2_DrawButtonAmounts_addr        0x80117BD0
#define z2_DrawBButtonIcon_addr          0x80118084
#define z2_DrawCButtonIcons_addr         0x80118890
#define z2_GetFloorPhysicsType_addr      0x800C99D4
#define z2_GetMatrixStackTop_addr        0x80180234
#define z2_PlaySfx_addr                  0x8019F0C8
#define z2_SpawnActor_addr               0x800BAC60
#define z2_UpdateButtonUsability_addr    0x80110038
#define z2_WriteHeartColors_addr         0x8010069C
#define z2_RemoveItem_addr               0x801149A0
#define z2_ToggleSfxDampen_addr          0x8019C300
#define z2_HandleInputVelocity_addr      0x800FF2F8
#define z2_SetGetItemLongrange_addr      0x800B8BD0

/* Scene Flags */
#define z2_get_generic_flag_addr         0x800B5BB0
#define z2_set_generic_flag_addr         0x800B5BF4
#define z2_remove_generic_flag_addr      0x800B5C34
#define z2_get_chest_flag_addr           0x800B5C78
#define z2_set_chest_flag_addr           0x800B5C90
#define z2_set_all_chest_flags_addr      0x800B5CAC
#define z2_get_all_chest_flags_addr      0x800B5CB8
#define z2_get_clear_flag_addr           0x800B5CC4
#define z2_set_clear_flag_addr           0x800B5CDC
#define z2_remove_clear_flag_addr        0x800B5CF8
#define z2_get_temp_clear_flag_addr      0x800B5D18
#define z2_set_temp_clear_flag_addr      0x800B5D30
#define z2_remove_temp_clear_flag_addr   0x800B5D4C
#define z2_get_collectible_flag_addr     0x800B5D6C
#define z2_set_collectibe_flag_addr      0x800B5DB0
#define z2_load_scene_flags_addr         0x800B9170
#define z2_check_scene_pairs_addr        0x80169CBC
#define z2_store_scene_flags_addr        0x80169D40

/* Function Addresses (Actors) */
#define z2_ActorDtor_addr                0x800B6948
#define z2_ActorRemove_addr              0x800BB498
#define z2_ActorUnload_addr              0x800B670C

/* Function Addresses (Actor Cutscene) */
#define z2_ActorCutscene_ClearWaiting_addr             0x800F1648
#define z2_ActorCutscene_ClearNextCutscenes_addr       0x800F1678
#define z2_ActorCutscene_MarkNextCutscenes_addr        0x800F16A8
#define z2_ActorCutscene_End_addr                      0x800F17FC
#define z2_ActorCutscene_Update_addr                   0x800F1A7C
#define z2_ActorCutscene_SetIntentToPlay_addr          0x800F1BA4
#define z2_ActorCutscene_GetCanPlayNext_addr           0x800F1BE4
#define z2_ActorCutscene_StartAndSetUnkLinkFields_addr 0x800F1C68
#define z2_ActorCutscene_StartAndSetFlag_addr          0x800F1CE0
#define z2_ActorCutscene_Start_addr                    0x800F1D84
#define z2_ActorCutscene_Stop_addr                     0x800F1FBC
#define z2_ActorCutscene_GetCurrentIndex_addr          0x800F207C
#define z2_ActorCutscene_GetCutscene_addr              0x800F208C
#define z2_ActorCutscene_GetAdditionalCutscene_addr    0x800F20B8
#define z2_ActorCutscene_GetLength_addr                0x800F20F8
#define z2_ActorCutscene_GetCurrentCamera_addr         0x800F21B8
#define z2_ActorCutscene_SetReturnCamera_addr          0x800F23C4

/* Function Addresses (Drawing) */
#define z2_BaseDrawCollectable_addr      0x800A7128
#define z2_DrawHeartPiece_addr           0x800A75B8
#define z2_PreDraw2_addr                 0x800B8050
#define z2_PreDraw1_addr                 0x800B8118
#define z2_BaseDrawGiModel_addr          0x800EE320
#define z2_CallSetupDList_addr           0x8012C2DC

/* Function Addresses (File Loading) */
#define z2_RomToRam_addr                 0x80080790
#define z2_GetFileTable_addr             0x800808F4
#define z2_GetFilePhysAddr_addr          0x80080950
#define z2_GetFileNumber_addr            0x800809BC
#define z2_LoadFile_addr                 0x80080A08
#define z2_ReadFile_addr                 0x80080C90
#define z2_LoadFileFromArchive_addr      0x80178DAC
#define z2_LoadVFileFromArchive_addr     0x80178E3C

#define z2_Yaz0_LoadAndDecompressFile_addr 0x80081178

/* Function Addresses (Get Item) */
#define z2_SetGetItem_addr               0x800B8A1C
#define z2_GiveItem_addr                 0x80112E80
#define z2_GiveMap_addr                  0x8012EF0C

/* Function Addresses (HUD) */
#define z2_UpdateButtonsState_addr       0x8010EF68
#define z2_ReloadButtonTexture_addr      0x80112B40
#define z2_HudSetAButtonText_addr        0x8011552C
#define z2_InitButtonNoteColors_addr     0x80147564

/* Function Addresses (Math) */
#define z2_Math_Sins_addr                0x800FED84
#define z2_Math_Vec3f_DistXZ_addr        0x800FF92C

/* Function Addresses (Objects) */
#define z2_GetObjectIndex_addr           0x8012F608

/* Function Addresses (OS) */
#define z2_memcpy_addr                   0x800FEC90

/* Function Addresses (RNG) */
#define z2_RngInt_addr                   0x80086FA0
#define z2_RngSetSeed_addr               0x80086FD0

/* Function Addresses (Rooms) */
#define z2_LoadRoom_addr                 0x8012E96C
#define z2_UnloadRoom_addr               0x8012EBF8

/* Function Addresses (Sound) */
#define z2_SetBGM2_addr                  0x801A3098

/* Function Addresses (Text) */
#define z2_ShowMessage_addr              0x801518B0

/* Function Prototypes */
typedef int (*z2_CanInteract_proc)(GlobalContext *game);
typedef int (*z2_CanInteract2_proc)(GlobalContext *game, ActorPlayer *link);
typedef void (*z2_DrawButtonAmounts_proc)(GlobalContext *game, u32 arg1, u16 alpha);
typedef void (*z2_DrawBButtonIcon_proc)(GlobalContext *game);
typedef void (*z2_DrawCButtonIcons_proc)(GlobalContext *game);
typedef u32 (*z2_GetFloorPhysicsType_proc)(void *arg0, void *arg1, u8 arg2);
typedef f32* (*z2_GetMatrixStackTop_proc)();
typedef void (*z2_PlaySfx_proc)(u32 id);
typedef Actor* (*z2_SpawnActor_proc)(ActorContext *actor_ctx, GlobalContext *game, u16 id,
                                          f32 x, f32 y, f32 z, u16 rx, u16 ry, u16 rz, u16 variable);
typedef void (*z2_UpdateButtonUsability_proc)(GlobalContext *game);
typedef void (*z2_WriteHeartColors_proc)(GlobalContext *game);
typedef void (*z2_RemoveItem_proc)(u32 item, u8 slot);
typedef void (*z2_ToggleSfxDampen_proc)(int enable);
typedef void (*z2_HandleInputVelocity_proc)(f32 *linear_velocity, f32 input_velocity, f32 increaseBy, f32 decreaseBy);
typedef bool (*z2_SetGetItemLongrange_proc)(Actor *actor, GlobalContext *game, u16 gi_index);

/* Function Prototypes (Scene Flags) */
// TODO parameters
typedef void (*z2_get_generic_flag_proc)();
typedef void (*z2_set_generic_flag_proc)();
typedef void (*z2_remove_generic_flag_proc)(GlobalContext *game, s8 flag);
typedef void (*z2_get_chest_flag_proc)();
typedef void (*z2_set_chest_flag_proc)();
typedef void (*z2_set_all_chest_flags_proc)();
typedef void (*z2_get_all_chest_flags_proc)();
typedef void (*z2_get_clear_flag_proc)();
typedef void (*z2_set_clear_flag_proc)();
typedef void (*z2_remove_clear_flag_proc)();
typedef void (*z2_get_temp_clear_flag_proc)();
typedef void (*z2_set_temp_clear_flag_proc)();
typedef void (*z2_remove_temp_clear_flag_proc)();
typedef void (*z2_get_collectible_flag_proc)();
typedef void (*z2_set_collectibe_flag_proc)();
typedef void (*z2_load_scene_flags_proc)();
typedef void (*z2_check_scene_pairs_proc)();
typedef void (*z2_store_scene_flags_proc)();

/* Function Prototypes (Actors) */
typedef void (*z2_ActorProc_proc)(Actor *actor, GlobalContext *game);
typedef void (*z2_ActorRemove_proc)(ActorContext *ctxt, Actor *actor, GlobalContext *game);
typedef void (*z2_ActorUnload_proc)(Actor *actor);

/* Function Prototypes (Actor Cutscene) */
typedef void (*z2_ActorCutscene_ClearWaiting_proc)(void);
typedef void (*z2_ActorCutscene_ClearNextCutscenes_proc)(void);
typedef void (*z2_ActorCutscene_MarkNextCutscenes_proc)(void);
typedef void (*z2_ActorCutscene_End_proc)(void);
typedef void (*z2_ActorCutscene_Update_proc)(void);
typedef void (*z2_ActorCutscene_SetIntentToPlay_proc)(s16 index);
typedef s16 (*z2_ActorCutscene_GetCanPlayNext_proc)(s16 index);
typedef s16 (*z2_ActorCutscene_StartAndSetUnkLinkFields_proc)(s16 index, Actor *actor);
typedef s16 (*z2_ActorCutscene_StartAndSetFlag_proc)(s16 index, Actor *actor);
typedef s16 (*z2_ActorCutscene_Start_proc)(s16 index, Actor *actor);
typedef s16 (*z2_ActorCutscene_Stop_proc)(s16 index);
typedef s16 (*z2_ActorCutscene_GetCurrentIndex_proc)(void);
typedef ActorCutscene* (*z2_ActorCutscene_GetCutscene_proc)(s16 index);
typedef s16 (*z2_ActorCutscene_GetAdditionalCutscene_proc)(s16 index);
typedef s16 (*z2_ActorCutscene_GetLength_proc)(s16 index);
typedef s16 (*z2_ActorCutscene_GetCurrentCamera_proc)(void);
typedef void (*z2_ActorCutscene_SetReturnCamera_proc)(s16 index);

/* Function Prototypes (Drawing) */
typedef void (*z2_ActorDraw_proc)(Actor *actor, GlobalContext *game);
typedef void (*z2_BaseDrawGiModel_proc)(GlobalContext *game, u32 graphic_id_minus_1);
typedef void (*z2_CallDList_proc)(GraphicsContext *gfx);
typedef void (*z2_PreDraw_proc)(Actor *actor, GlobalContext *game, u32 unknown);

/* Function Prototypes (File Loading) */
typedef s32 (*z2_RomToRam_proc)(u32 src, void *dst, u32 length);
typedef s16 (*z2_GetFileNumber_proc)(u32 vrom_addr);
typedef u32 (*z2_GetFilePhysAddr_proc)(u32 vrom_addr);
typedef DmaEntry* (*z2_GetFileTable_proc)(u32 vrom_addr);
typedef void (*z2_LoadFile_proc)(DmaParams *loadfile);
typedef void (*z2_LoadFileFromArchive_proc)(u32 phys_file, u8 index, u8 *dest, u32 length);
typedef void (*z2_LoadVFileFromArchive_proc)(u32 virt_file, u8 index, u8 *dest, u32 length);
typedef void (*z2_ReadFile_proc)(void *mem_addr, u32 vrom_addr, u32 size);

typedef void (*z2_Yaz0_LoadAndDecompressFile_proc)(u32 prom_addr, void *dest, u32 length);

/* Function Prototypes (Get Item) */
typedef void (*z2_SetGetItem_proc)(Actor *actor, GlobalContext *game, s32 unk2, u32 unk3);
typedef void (*z2_GiveItem_proc)(GlobalContext *game, u8 item_id);
typedef void (*z2_GiveMap_proc)(u32 map_index);

/* Function Prototypes (HUD) */
typedef void (*z2_HudSetAButtonText_proc)(GlobalContext *game, u16 text_id);
typedef void (*z2_InitButtonNoteColors_proc)(GlobalContext *game);
typedef void (*z2_ReloadButtonTexture_proc)(GlobalContext *game, u8 idx);
typedef void (*z2_UpdateButtonsState_proc)(u32 state);

/* Function Prototypes (Math) */
typedef f32 (*z2_Math_Sins_proc)(s16 angle);
typedef f32 (*z2_Math_Vec3f_DistXZ_proc)(Vec3f *p1, Vec3f *p2);

/* Function Prototypes (Objects) */
typedef s8 (*z2_GetObjectIndex_proc)(const SceneContext *ctxt, u16 object_id);

/* Function Prototypes (OS) */
typedef void (*z2_memcpy_proc)(void *dest, const void *src, size_t size);

/* Function Prototypes (RNG) */
typedef u32 (*z2_RngInt_proc)();
typedef void (*z2_RngSetSeed_proc)(u32 seed);

/* Function Prototypes (Rooms) */
typedef void (*z2_LoadRoom_proc)(GlobalContext *game, RoomContext *room_ctxt, uint8_t room_id);
typedef void (*z2_UnloadRoom_proc)(GlobalContext *game, RoomContext *room_ctxt);

/* Function Prototypes (Sound) */
typedef void (*z2_SetBGM2_proc)(u16 bgm_id);

/* Function Prototypes (Text) */
typedef void (*z2_ShowMessage_proc)(GlobalContext *game, u16 message_id, u8 something); // TODO figure out something?

/* Functions */
#define z2_CanInteract                   ((z2_CanInteract_proc)           z2_CanInteract_addr)
#define z2_CanInteract2                  ((z2_CanInteract2_proc)          z2_CanInteract2_addr)
#define z2_DrawButtonAmounts             ((z2_DrawButtonAmounts_proc)     z2_DrawButtonAmounts_addr)
#define z2_DrawBButtonIcon               ((z2_DrawBButtonIcon_proc)       z2_DrawBButtonIcon_addr)
#define z2_DrawCButtonIcons              ((z2_DrawCButtonIcons_proc)      z2_DrawCButtonIcons_addr)
#define z2_GetFloorPhysicsType           ((z2_GetFloorPhysicsType_proc)   z2_GetFloorPhysicsType_addr)
#define z2_GetMatrixStackTop             ((z2_GetMatrixStackTop_proc)     z2_GetMatrixStackTop_addr)
#define z2_PlaySfx                       ((z2_PlaySfx_proc)               z2_PlaySfx_addr)
#define z2_SpawnActor                    ((z2_SpawnActor_proc)            z2_SpawnActor_addr)
#define z2_UpdateButtonUsability         ((z2_UpdateButtonUsability_proc) z2_UpdateButtonUsability_addr)
#define z2_WriteHeartColors              ((z2_WriteHeartColors_proc)      z2_WriteHeartColors_addr)
#define z2_RemoveItem                    ((z2_RemoveItem_proc)            z2_RemoveItem_addr)
#define z2_ToggleSfxDampen               ((z2_ToggleSfxDampen_proc)       z2_ToggleSfxDampen_addr)
#define z2_HandleInputVelocity           ((z2_HandleInputVelocity_proc)   z2_HandleInputVelocity_addr)
#define z2_SetGetItemLongrange           ((z2_SetGetItemLongrange_proc)   z2_SetGetItemLongrange_addr)

/* Functions (Scene Flags) */
#define z2_get_generic_flag ((z2_get_generic_flag_proc) z2_get_generic_flag_addr)
#define z2_set_generic_flag ((z2_set_generic_flag_proc) z2_set_generic_flag_addr)
#define z2_remove_generic_flag ((z2_remove_generic_flag_proc) z2_remove_generic_flag_addr)
#define z2_get_chest_flag ((z2_get_chest_flag_proc) z2_get_chest_flag_addr)
#define z2_set_chest_flag ((z2_set_chest_flag_proc) z2_set_chest_flag_addr)
#define z2_set_all_chest_flags ((z2_set_all_chest_flags_proc) z2_set_all_chest_flags_addr)
#define z2_get_all_chest_flags ((z2_get_all_chest_flags_proc) z2_get_all_chest_flags_addr)
#define z2_get_clear_flag ((z2_get_clear_flag_proc) z2_get_clear_flag_addr)
#define z2_set_clear_flag ((z2_set_clear_flag_proc) z2_set_clear_flag_addr)
#define z2_remove_clear_flag ((z2_remove_clear_flag_proc) z2_remove_clear_flag_addr)
#define z2_get_temp_clear_flag ((z2_get_temp_clear_flag_proc) z2_get_temp_clear_flag_addr)
#define z2_set_temp_clear_flag ((z2_set_temp_clear_flag_proc) z2_set_temp_clear_flag_addr)
#define z2_remove_temp_clear_flag ((z2_remove_temp_clear_flag_proc) z2_remove_temp_clear_flag_addr)
#define z2_get_collectible_flag ((z2_get_collectible_flag_proc) z2_get_collectible_flag_addr)
#define z2_set_collectibe_flag ((z2_set_collectibe_flag_proc) z2_set_collectibe_flag_addr)
#define z2_load_scene_flags ((z2_load_scene_flags_proc) z2_load_scene_flags_addr)
#define z2_check_scene_pairs ((z2_check_scene_pairs_proc) z2_check_scene_pairs_addr)
#define z2_store_scene_flags ((z2_store_scene_flags_proc) z2_store_scene_flags_addr)

/* Functions (Actors) */
#define z2_ActorDtor                     ((z2_ActorProc_proc)             z2_ActorDtor_addr)
#define z2_ActorRemove                   ((z2_ActorRemove_proc)           z2_ActorRemove_addr)
#define z2_ActorUnload                   ((z2_ActorUnload_proc)           z2_ActorUnload_addr)

/* Functions (Actor Cutscene) */
#define z2_ActorCutscene_ClearWaiting             ((z2_ActorCutscene_ClearWaiting_proc)             z2_ActorCutscene_ClearWaiting_addr)
#define z2_ActorCutscene_ClearNextCutscenes       ((z2_ActorCutscene_ClearNextCutscenes_proc)       z2_ActorCutscene_ClearNextCutscenes_addr)
#define z2_ActorCutscene_MarkNextCutscenes        ((z2_ActorCutscene_MarkNextCutscenes_proc)        z2_ActorCutscene_MarkNextCutscenes_addr)
#define z2_ActorCutscene_End                      ((z2_ActorCutscene_End_proc)                      z2_ActorCutscene_End_addr)
#define z2_ActorCutscene_Update                   ((z2_ActorCutscene_Update_proc)                   z2_ActorCutscene_Update_addr)
#define z2_ActorCutscene_SetIntentToPlay          ((z2_ActorCutscene_SetIntentToPlay_proc)          z2_ActorCutscene_SetIntentToPlay_addr)
#define z2_ActorCutscene_GetCanPlayNext           ((z2_ActorCutscene_GetCanPlayNext_proc)           z2_ActorCutscene_GetCanPlayNext_addr)
#define z2_ActorCutscene_StartAndSetUnkLinkFields ((z2_ActorCutscene_StartAndSetUnkLinkFields_proc) z2_ActorCutscene_StartAndSetUnkLinkFields_addr)
#define z2_ActorCutscene_StartAndSetFlag          ((z2_ActorCutscene_StartAndSetFlag_proc)          z2_ActorCutscene_StartAndSetFlag_addr)
#define z2_ActorCutscene_Start                    ((z2_ActorCutscene_Start_proc)                    z2_ActorCutscene_Start_addr)
#define z2_ActorCutscene_Stop                     ((z2_ActorCutscene_Stop_proc)                     z2_ActorCutscene_Stop_addr)
#define z2_ActorCutscene_GetCurrentIndex          ((z2_ActorCutscene_GetCurrentIndex_proc)          z2_ActorCutscene_GetCurrentIndex_addr)
#define z2_ActorCutscene_GetCutscene              ((z2_ActorCutscene_GetCutscene_proc)              z2_ActorCutscene_GetCutscene_addr)
#define z2_ActorCutscene_GetAdditionalCutscene    ((z2_ActorCutscene_GetAdditionalCutscene_proc)    z2_ActorCutscene_GetAdditionalCutscene_addr)
#define z2_ActorCutscene_GetLength                ((z2_ActorCutscene_GetLength_proc)                z2_ActorCutscene_GetLength_addr)
#define z2_ActorCutscene_GetCurrentCamera         ((z2_ActorCutscene_GetCurrentCamera_proc)         z2_ActorCutscene_GetCurrentCamera_addr)
#define z2_ActorCutscene_SetReturnCamera          ((z2_ActorCutscene_SetReturnCamera_proc)          z2_ActorCutscene_SetReturnCamera_addr)

/* Functions (Drawing) */
#define z2_BaseDrawCollectable           ((z2_ActorDraw_proc)             z2_BaseDrawCollectable_addr)
#define z2_BaseDrawGiModel               ((z2_BaseDrawGiModel_proc)       z2_BaseDrawGiModel_addr)
#define z2_CallSetupDList                ((z2_CallDList_proc)             z2_CallSetupDList_addr)
#define z2_DrawHeartPiece                ((z2_ActorDraw_proc)             z2_DrawHeartPiece_addr)
#define z2_PreDraw1                      ((z2_PreDraw_proc)               z2_PreDraw1_addr)
#define z2_PreDraw2                      ((z2_PreDraw_proc)               z2_PreDraw2_addr)

/* Functions (File Loading) */
#define z2_GetFileNumber                 ((z2_GetFileNumber_proc)         z2_GetFileNumber_addr)
#define z2_GetFilePhysAddr               ((z2_GetFilePhysAddr_proc)       z2_GetFilePhysAddr_addr)
#define z2_GetFileTable                  ((z2_GetFileTable_proc)          z2_GetFileTable_addr)
#define z2_LoadFile                      ((z2_LoadFile_proc)              z2_LoadFile_addr)
#define z2_LoadFileFromArchive           ((z2_LoadFileFromArchive_proc)   z2_LoadFileFromArchive_addr)
#define z2_LoadVFileFromArchive          ((z2_LoadVFileFromArchive_proc)  z2_LoadVFileFromArchive_addr)
#define z2_ReadFile                      ((z2_ReadFile_proc)              z2_ReadFile_addr)
#define z2_RomToRam                      ((z2_RomToRam_proc)              z2_RomToRam_addr)

#define z2_Yaz0_LoadAndDecompressFile    ((z2_Yaz0_LoadAndDecompressFile_proc) z2_Yaz0_LoadAndDecompressFile_addr)

/* Functions (Get Item) */
#define z2_SetGetItem                    ((z2_SetGetItem_proc)            z2_SetGetItem_addr)
#define z2_GiveItem                      ((z2_GiveItem_proc)              z2_GiveItem_addr)
#define z2_GiveMap                       ((z2_GiveMap_proc)               z2_GiveMap_addr)

/* Functions (HUD) */
#define z2_HudSetAButtonText             ((z2_HudSetAButtonText_proc)     z2_HudSetAButtonText_addr)
#define z2_InitButtonNoteColors          ((z2_InitButtonNoteColors_proc)  z2_InitButtonNoteColors_addr)
#define z2_ReloadButtonTexture           ((z2_ReloadButtonTexture_proc)   z2_ReloadButtonTexture_addr)
#define z2_UpdateButtonsState            ((z2_UpdateButtonsState_proc)    z2_UpdateButtonsState_addr)

/* Functions (Math) */
#define z2_Math_Sins                     ((z2_Math_Sins_proc)             z2_Math_Sins_addr)
#define z2_Math_Vec3f_DistXZ             ((z2_Math_Vec3f_DistXZ_proc)     z2_Math_Vec3f_DistXZ_addr)

/* Functions (Objects) */
#define z2_GetObjectIndex                ((z2_GetObjectIndex_proc)        z2_GetObjectIndex_addr)

/* Functions (OS) */
#define z2_memcpy                        ((z2_memcpy_proc)                z2_memcpy_addr)

/* Functions (RNG) */
#define z2_RngInt                        ((z2_RngInt_proc)                z2_RngInt_addr)
#define z2_RngSetSeed                    ((z2_RngSetSeed_proc)            z2_RngSetSeed_addr)

/* Functions (Rooms) */
#define z2_LoadRoom                      ((z2_LoadRoom_proc)              z2_LoadRoom_addr)
#define z2_UnloadRoom                    ((z2_UnloadRoom_proc)            z2_UnloadRoom_addr)

/* Functions (Sound) */
#define z2_SetBGM2                       ((z2_SetBGM2_proc)               z2_SetBGM2_addr)

/* Functions (Text) */
#define z2_ShowMessage                   ((z2_ShowMessage_proc)           z2_ShowMessage_addr)

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

#endif // _Z64ADDRESSES_H_
