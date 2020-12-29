#ifndef _Z64ACTOR_H_
#define _Z64ACTOR_H_

#include <n64.h>
#include <types.h>
#include <unk.h>
#include <z64math.h>

struct Actor;
struct BgPolygon;
struct GlobalContext;

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3s rot;
} PosRot; // size = 0x14

typedef void(*ActorFunc)(struct Actor *this, struct GlobalContext *ctxt);

typedef union {
    struct {
        u8 damage : 4;
        u8 effect : 4;
    };
    u8 value;
} ActorDamageByte; // size = 0x1

typedef struct {
    /* 0x00 */ ActorDamageByte attack[32];
} ActorDamageChart; // size = 0x20

// Related to collision?
typedef struct {
    /* 0x00 */ ActorDamageChart* damageChart;
    /* 0x04 */ Vec3f displacement;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8 mass;
    /* 0x17 */ u8 health;
    /* 0x18 */ u8 damage;
    /* 0x19 */ u8 damageEffect;
    /* 0x1A */ u8 impactEffect;
    /* 0x1B */ UNK_TYPE1 pad1B[0x1];
} ActorA0; // size = 0x1C

// typedef void(*ActorShadowDrawFunc)(struct Actor* actor, struct LightMapper* mapper, struct GlobalContext* ctxt);

typedef struct {
    /* 0x00 */ Vec3s rot;
    /* 0x08 */ f32 yDisplacement;
    /* 0x0C */ void* shadowDrawFunc;
    /* 0x10 */ f32 scale;
    /* 0x14 */ u8 alphaScale; // 255 means always draw full opacity if visible
} ActorShape; // size = 0x18

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 type;
    /* 0x04 */ u32 flags;
    /* 0x08 */ s16 objectId;
    /* 0x0C */ u32 instanceSize;
    /* 0x10 */ ActorFunc init;
    /* 0x14 */ ActorFunc destroy;
    /* 0x18 */ ActorFunc update;
    /* 0x1C */ ActorFunc draw;
} ActorInit; // size = 0x20

typedef enum {
    ALLOCTYPE_NORMAL,
    ALLOCTYPE_ABSOLUTE,
    ALLOCTYPE_PERMANENT,
} AllocType;

typedef struct {
    /* 0x00 */ u32 vromStart;
    /* 0x04 */ u32 vromEnd;
    /* 0x08 */ void* vramStart;
    /* 0x0C */ void* vramEnd;
    /* 0x10 */ void* loadedRamAddr; // original name: "allocp"
    /* 0x14 */ ActorInit* initInfo;
    /* 0x18 */ char* name;
    /* 0x1C */ u16 allocType; // bit 0: don't allocate memory, use actorContext->0x250? bit 1: Always keep loaded?
    /* 0x1E */ s8 nbLoaded; // original name: "clients"
    /* 0x1F */ UNK_TYPE1 pad1F[0x1];
} ActorOverlay; // size = 0x20

typedef struct Actor {
    /* 0x000 */ s16 id;
    /* 0x002 */ u8 type;
    /* 0x003 */ s8 room;
    /* 0x004 */ u32 flags;
    /* 0x008 */ PosRot initPosRot;
    /* 0x01C */ s16 params;
    /* 0x01E */ s8 objBankIndex;
    /* 0x01F */ UNK_TYPE1 unk1F;
    /* 0x020 */ u16 soundEffect;
    /* 0x022 */ UNK_TYPE1 pad22[0x2];
    /* 0x024 */ PosRot currPosRot;
    /* 0x038 */ s8 cutscene;
    /* 0x039 */ u8 unk39;
    /* 0x03A */ UNK_TYPE1 pad3A[0x2];
    /* 0x03C */ PosRot topPosRot;
    /* 0x050 */ u16 unk50;
    /* 0x052 */ UNK_TYPE1 pad52[0x2];
    /* 0x054 */ f32 unk54;
    /* 0x058 */ Vec3f scale;
    /* 0x064 */ Vec3f velocity;
    /* 0x070 */ f32 speedXZ;
    /* 0x074 */ f32 gravity;
    /* 0x078 */ f32 minVelocityY;
    /* 0x07C */ struct BgPolygon *wallPoly;
    /* 0x080 */ struct BgPolygon *floorPoly;
    /* 0x084 */ u8 wallPolySource;
    /* 0x085 */ u8 floorPolySource;
    /* 0x086 */ s16 wallRot;
    /* 0x088 */ f32 floorHeight;
    /* 0x08C */ f32 waterSurfaceDist;
    /* 0x090 */ u16 bgcheckFlags;
    /* 0x092 */ s16 rotTowardsLinkY;
    /* 0x094 */ f32 sqrdDistanceFromLink;
    /* 0x098 */ f32 xzDistanceFromLink;
    /* 0x09C */ f32 yDistanceFromLink;
    /* 0x0A0 */ ActorA0 unkA0;
    /* 0x0BC */ ActorShape shape;
    /* 0x0D4 */ Vec3f unkD4;
    /* 0x0E0 */ Vec3f unkE0;
    /* 0x0EC */ Vec3f projectedPos;
    /* 0x0F8 */ f32 unkF8;
    /* 0x0FC */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ Vec3f lastPos;
    /* 0x114 */ u8 unk114;
    /* 0x115 */ u8 unk115;
    /* 0x116 */ u16 textId;
    /* 0x118 */ s16 freeze;
    /* 0x11A */ u16 hitEffectParams;
    /* 0x11C */ u8 hitEffectIntensity;
    /* 0x11D */ u8 hasBeenDrawn;
    /* 0x11E */ UNK_TYPE1 pad11E[0x1];
    /* 0x11F */ u8 naviEnemyId;
    /* 0x120 */ struct Actor* parent;
    /* 0x124 */ struct Actor* child;
    /* 0x128 */ struct Actor* prev;
    /* 0x12C */ struct Actor* next;
    /* 0x130 */ ActorFunc init;
    /* 0x134 */ ActorFunc destroy;
    /* 0x138 */ ActorFunc update;
    /* 0x13C */ ActorFunc draw;
    /* 0x140 */ ActorOverlay *overlayEntry;
} Actor; // size = 0x144

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x144 */ s32 dynaPolyId;
    /* 0x148 */ f32 unk148;
    /* 0x14C */ f32 unk14C;
    /* 0x150 */ s16 unk150;
    /* 0x152 */ s16 unk152;
    /* 0x154 */ u32 unk154;
    /* 0x158 */ u8 dynaFlags;
    /* 0x159 */ UNK_TYPE1 pad159[0x3];
} DynaPolyActor; // size = 0x15C

// Macro for getting the ActorPlayer pointer from the GlobalContext pointer.
#define Z2_LINK(CTX) ((ActorPlayer*)(((CTX)->actorCtx.actorList[2].first)))

typedef union {
    struct {
        u16 unknown;
        u16 id;
    };
    u32 value;
} PlayerAnimation; // size = 0x4

typedef union {
    struct {
        u32 state1;
        u32 state2;
        u32 state3;
    };
    u32 flags[3];
} PlayerStateFlags; // size = 0xC

// See: ActorPlayer::heldItemActionParam
typedef enum {
    HELD_ITEM_BOW = 0x9,
    HELD_ITEM_HOOKSHOT = 0xD,
    HELD_ITEM_OCARINA = 0x14,
    HELD_ITEM_BOTTLE = 0x15,
} PlayerHeldItem;

typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ u8 pad144[0x2];
    /* 0x146 */ u8 itemButton;
    /* 0x147 */ s8 itemActionParam;
    /* 0x148 */ u8 unk148;
    /* 0x149 */ u8 unk149;
    /* 0x14A */ s8 heldItemActionParam; // Which item Link currently has out?
    /* 0x14B */ u8 form;
    /* 0x14C */ UNK_TYPE1 pad14C[0x5];
    /* 0x151 */ u8 unk151;
    /* 0x152 */ UNK_TYPE1 unk152;
    /* 0x153 */ u8 mask;
    /* 0x154 */ u8 maskC; // C button index (starting at 1) of current/recently worn mask.
    /* 0x155 */ u8 previousMask;
    /* 0x156 */ UNK_TYPE1 pad156[0xF2];
    /* 0x248 */ PlayerAnimation currentAnimation;
    /* 0x24C */ UNK_TYPE1 pad24C[0x100];
    /* 0x34C */ Actor* heldActor;
    /* 0x350 */ UNK_TYPE1 pad350[0x18];
    /* 0x368 */ Vec3f unk368;
    /* 0x374 */ UNK_TYPE1 pad374[0x10];
    /* 0x384 */ u16 getItem;
    /* 0x386 */ UNK_TYPE1 pad386[0xC];
    /* 0x394 */ u8 unk394;
    /* 0x395 */ UNK_TYPE1 pad395[0x37];
    /* 0x3CC */ s16 unk3CC;
    /* 0x3CE */ s8 unk3CE;
    /* 0x3CF */ UNK_TYPE1 pad3CF[0x361];
    /* 0x730 */ Actor* unk730;
    /* 0x734 */ UNK_TYPE1 pad734[0x334];
    /* 0xA68 */ f32 *tableA68; // Transformation-dependant f32 array, [11] used for distance to begin swimming.
    /* 0xA6C */ PlayerStateFlags stateFlags;
    /* 0xA78 */ UNK_TYPE1 padA78[0x8];
    /* 0xA80 */ Actor* unkA80;
    /* 0xA84 */ UNK_TYPE1 padA84[0x4];
    /* 0xA88 */ Actor* unkA88;
    /* 0xA8C */ f32 unkA8C;
    /* 0xA90 */ UNK_TYPE1 padA90[0x40];
    /* 0xAD0 */ f32 linearVelocity;
    /* 0xAD4 */ u16 movementAngle;
    /* 0xAD6 */ UNK_TYPE1 padAD6[0x5];
    /* 0xADB */ u8 swordActive;
    /* 0xADC */ UNK_TYPE1 padADC[0x2];
    /* 0xADE */ u8 unkADE;
    /* 0xADF */ UNK_TYPE1 padADF[0x4];
    /* 0xAE3 */ s8 unkAE3;
    /* 0xAE4 */ UNK_TYPE1 padAE4[0x3];
    /* 0xAE7 */ u8 animTimer; // Some animation timer? Relevant to: transformation masks.
    /* 0xAE8 */ u16 frozenTimer;
    /* 0xAEA */ UNK_TYPE1 padAEA[0x3E];
    /* 0xB28 */ s16 unkB28;
    /* 0xB2A */ UNK_TYPE1 padB2A[0x36];
    /* 0xB60 */ u16 blastMaskTimer;
    /* 0xB62 */ UNK_TYPE1 padB62[0x5];
    /* 0xB67 */ u8 dekuHopCounter;
    /* 0xB68 */ UNK_TYPE1 padB68[0xA];
    /* 0xB72 */ u16 floorType; // Determines sound effect used while walking.
    /* 0xB74 */ UNK_TYPE1 padB74[0x28];
    /* 0xB9C */ Vec3f unkB9C;
    /* 0xBA8 */ UNK_TYPE1 padBA8[0x1D0];
} ActorPlayer; // size = 0xD78

#endif // _Z64ACTOR_H_
