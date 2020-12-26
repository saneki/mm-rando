#ifndef Z2_H
#define Z2_H

#include <n64.h>
#include <stdbool.h>
#include "types.h"

typedef u8 UNK_TYPE1;
typedef u16 UNK_TYPE2;
typedef u32 UNK_TYPE4;

typedef void (*FuncPtr)(void);

#define Z2_SCREEN_WIDTH      320
#define Z2_SCREEN_HEIGHT     240

/**
 * Correlates to form field in z2_file_t.
 **/
typedef enum {
    Z2_FORM_FIERCE_DEITY,
    Z2_FORM_GORON,
    Z2_FORM_ZORA,
    Z2_FORM_DEKU,
    Z2_FORM_HUMAN,
} z2_form_t;

typedef enum {
    Z2_TIMESPEED_NORMAL,
    Z2_TIMESPEED_STOPPED = 0xFFFFFFFD,
    Z2_TIMESPEED_INVERTED = 0xFFFFFFFE,
} z2_timespeed_t;

typedef enum {
    // 0x00 (Inventory)
    Z2_ITEM_OCARINA,
    Z2_ITEM_BOW,
    Z2_ITEM_FIRE_ARROW,
    Z2_ITEM_ICE_ARROW,
    Z2_ITEM_LIGHT_ARROW,
    Z2_ITEM_FAIRY_OCARINA,
    Z2_ITEM_BOMB,
    Z2_ITEM_BOMBCHU,
    Z2_ITEM_DEKU_STICK,
    Z2_ITEM_DEKU_NUT,
    Z2_ITEM_MAGIC_BEAN,
    Z2_ITEM_SLINGSHOT,
    Z2_ITEM_POWDER_KEG,
    Z2_ITEM_PICTOGRAPH,
    Z2_ITEM_LENS,
    Z2_ITEM_HOOKSHOT,
    Z2_ITEM_FAIRY_SWORD,
    Z2_ITEM_HOOKSHOT_OOT,

    // 0x12 (Bottle)
    Z2_ITEM_EMPTY_BOTTLE,
    Z2_ITEM_RED_POTION,
    Z2_ITEM_GREEN_POTION,
    Z2_ITEM_BLUE_POTION,
    Z2_ITEM_FAIRY,
    Z2_ITEM_DEKU_PRINCESS,
    Z2_ITEM_MILK,
    Z2_ITEM_MILK_HALF,
    Z2_ITEM_FISH,
    Z2_ITEM_BUGS,
    Z2_ITEM_BLUE_FIRE,
    Z2_ITEM_POE,
    Z2_ITEM_BIG_POE,
    Z2_ITEM_WATER,
    Z2_ITEM_HOT_WATER,
    Z2_ITEM_ZORA_EGG,
    Z2_ITEM_GOLD_DUST,
    Z2_ITEM_MUSHROOM,
    Z2_ITEM_SEAHORSE,
    Z2_ITEM_CHATEAU_ROMANI,
    Z2_ITEM_EEL,
    Z2_ITEM_EMPTY_BOTTLE_2,

    // 0x28 (Quest)
    Z2_ITEM_MOON_TEAR,
    Z2_ITEM_TOWN_DEED,
    Z2_ITEM_SWAMP_DEED,
    Z2_ITEM_MOUNTAIN_DEED,
    Z2_ITEM_OCEAN_DEED,
    Z2_ITEM_ROOM_KEY,
    Z2_ITEM_MAMA_LETTER,
    Z2_ITEM_KAFEI_LETTER,
    Z2_ITEM_PENDANT,
    Z2_ITEM_MAP,

    // 0x32 (Masks)
    Z2_ITEM_DEKU_MASK,
    Z2_ITEM_GORON_MASK,
    Z2_ITEM_ZORA_MASK,
    Z2_ITEM_FIERCE_DEITY_MASK,
    Z2_ITEM_MASK_OF_TRUTH,
    Z2_ITEM_KAFEI_MASK,
    Z2_ITEM_ALL_NIGHT_MASK,
    Z2_ITEM_BUNNY_HOOD,
    Z2_ITEM_KEATON_MASK,
    Z2_ITEM_GARO_MASK,
    Z2_ITEM_ROMANI_MASK,
    Z2_ITEM_CIRCUS_LEADER_MASK,
    Z2_ITEM_POSTMAN_HAT,
    Z2_ITEM_COUPLE_MASK,
    Z2_ITEM_GREAT_FAIRY_MASK,
    Z2_ITEM_GIBDO_MASK,
    Z2_ITEM_DON_GERO_MASK,
    Z2_ITEM_KAMARO_MASK,
    Z2_ITEM_CAPTAIN_HAT,
    Z2_ITEM_STONE_MASK,
    Z2_ITEM_BREMEN_MASK,
    Z2_ITEM_BLAST_MASK,
    Z2_ITEM_MASK_OF_SCENTS,
    Z2_ITEM_GIANT_MASK,

    // 0x4A (???)
    Z2_ITEM_BOW_FIRE_ARROW,
    Z2_ITEM_BOW_ICE_ARROW,
    Z2_ITEM_BOW_LIGHT_ARROW,

    // 0x4D (Equipment)
    Z2_ITEM_KOKIRI_SWORD,
    Z2_ITEM_RAZOR_SWORD,
    Z2_ITEM_GILDED_SWORD,
    Z2_ITEM_HELIX_SWORD,
    Z2_ITEM_HERO_SHIELD,
    Z2_ITEM_MIRROR_SHIELD,
    Z2_ITEM_QUIVER_30,
    Z2_ITEM_QUIVER_40,
    Z2_ITEM_QUIVER_50,
    Z2_ITEM_BOMB_BAG_20,
    Z2_ITEM_BOMB_BAG_30,
    Z2_ITEM_BOMB_BAG_40,
    Z2_ITEM_WALLET_UNUSED,
    Z2_ITEM_ADULT_WALLET,
    Z2_ITEM_GIANT_WALLET,
    Z2_ITEM_FISHING_ROD,

    // 0x5D (Remains)
    Z2_ITEM_ODOLWA_REMAINS,
    Z2_ITEM_GOHT_REMAINS,
    Z2_ITEM_GYORG_REMAINS,
    Z2_ITEM_TWINMOLD_REMAINS,

    // 0x61 (Songs)
    Z2_ITEM_SONATA_OF_AWAKENING,
    Z2_ITEM_GORON_LULLABY,
    Z2_ITEM_NEW_WAVE_BOSSA_NOVA,
    Z2_ITEM_ELEGY_OF_EMPTINESS,
    Z2_ITEM_OATH_TO_ORDER,
    Z2_ITEM_SARIA_SONG,
    Z2_ITEM_SONG_OF_TIME,
    Z2_ITEM_SONG_OF_HEALING,
    Z2_ITEM_EPONA_SONG,
    Z2_ITEM_SONG_OF_SOARING,
    Z2_ITEM_SONG_OF_STORMS,
    Z2_ITEM_SUN_SONG,

    // 0x6D (Misc Equipment?)
    Z2_ITEM_BOMBER_NOTEBOOK,
    Z2_ITEM_HEART_PIECE = 0x7B,

    // 0x83 (Pickups)
    Z2_ITEM_HEART = 0x83,
    Z2_ITEM_GREEN_RUPEE,
    Z2_ITEM_BLUE_RUPEE,
    Z2_ITEM_RED_RUPEE = 0x87,
    Z2_ITEM_PURPLE_RUPEE,
    Z2_ITEM_SILVER_RUPEE,
    Z2_ITEM_PICKUP_DEKU_NUTS_10 = 0x8E,
    Z2_ITEM_PICKUP_ARROWS_10 = 0x93,
    Z2_ITEM_PICKUP_ARROWS_20,

    // 0xFF (None)
    Z2_ITEM_NONE = 0xFF,
} z2_item_t;

/**
 * Item inventory slots.
 **/
typedef enum {
    Z2_SLOT_OCARINA,
    Z2_SLOT_BOW,
    Z2_SLOT_FIRE_ARROW,
    Z2_SLOT_ICE_ARROW,
    Z2_SLOT_LIGHT_ARROW,
    Z2_SLOT_QUEST1,
    Z2_SLOT_BOMB,
    Z2_SLOT_BOMBCHU,
    Z2_SLOT_DEKU_STICK,
    Z2_SLOT_DEKU_NUT,
    Z2_SLOT_MAGIC_BEAN,
    Z2_SLOT_QUEST2,
    Z2_SLOT_POWDER_KEG,
    Z2_SLOT_PICTOGRAPH,
    Z2_SLOT_LENS,
    Z2_SLOT_HOOKSHOT,
    Z2_SLOT_FAIRY_SWORD,
    Z2_SLOT_QUEST3,
    Z2_SLOT_BOTTLE_1,
    Z2_SLOT_BOTTLE_2,
    Z2_SLOT_BOTTLE_3,
    Z2_SLOT_BOTTLE_4,
    Z2_SLOT_BOTTLE_5,
    Z2_SLOT_BOTTLE_6,
} z2_item_slot_t;

/**
 * Mask inventory slots.
 **/
typedef enum {
    Z2_SLOT_POSTMAN_HAT,
    Z2_SLOT_ALL_NIGHT_MASK,
    Z2_SLOT_BLAST_MASK,
    Z2_SLOT_STONE_MASK,
    Z2_SLOT_GREAT_FAIRY_MASK,
    Z2_SLOT_DEKU_MASK,
    Z2_SLOT_KEATON_MASK,
    Z2_SLOT_BREMEN_MASK,
    Z2_SLOT_BUNNY_HOOD,
    Z2_SLOT_DON_GERO_MASK,
    Z2_SLOT_MASK_OF_SCENTS,
    Z2_SLOT_GORON_MASK,
    Z2_SLOT_ROMANI_MASK,
    Z2_SLOT_CIRCUS_LEADER_MASK,
    Z2_SLOT_KAFEI_MASK,
    Z2_SLOT_COUPLE_MASK,
    Z2_SLOT_MASK_OF_TRUTH,
    Z2_SLOT_ZORA_MASK,
    Z2_SLOT_KAMARO_MASK,
    Z2_SLOT_GIBDO_MASK,
    Z2_SLOT_GARO_MASK,
    Z2_SLOT_CAPTAIN_HAT,
    Z2_SLOT_GIANT_MASK,
    Z2_SLOT_FIERCE_DEITY_MASK,
} z2_mask_slot_t;

enum z2_button_states {
    Z2_BUTTONS_STATE_BLACK_SCREEN,
    Z2_BUTTONS_STATE_TRANSITION,
    // Postman's timing game.
    Z2_BUTTONS_STATE_TRANSITION_2,
    Z2_BUTTONS_STATE_DIALOGUE = 5,
    // Used when on Epona sometimes, for example holding B (bow) while pressing A ("Return").
    Z2_BUTTONS_STATE_6 = 6,
    Z2_BUTTONS_STATE_PAUSE = 7,
    Z2_BUTTONS_STATE_ARCHERY_GAME = 8,
    Z2_BUTTONS_STATE_MINIGAME = 0xC,
    Z2_BUTTONS_STATE_SHOP = 0xF,
    Z2_BUTTONS_STATE_ITEM_PROMPT = 0x10,
    // Boat cruise archery game.
    Z2_BUTTONS_STATE_BOAT_ARCHERY = 0x11,
    // Honey & Darling minigame.
    Z2_BUTTONS_STATE_HONEY_DARLING = 0x14,
    Z2_BUTTONS_STATE_PICTOBOX = 0x15,
    Z2_BUTTONS_STATE_SWORDSMAN_GAME = 0x16,
    Z2_BUTTONS_STATE_NORMAL = 0x32,
};

typedef enum {
    // Time is stopped but Link & NPC animations continue.
    // Used for: NPC dialogue, get item, area transition, cutscene, form transition, using ocarina, etc.
    Z2_ACTION_STATE1_TIME_STOP    = 0x20000000,
    // Form transition, using ocarina.
    Z2_ACTION_STATE1_SPECIAL_2    = 0x10000000,
    // Swimming.
    Z2_ACTION_STATE1_SWIM         = 0x08000000,
    // Damaged.
    Z2_ACTION_STATE1_DAMAGED      = 0x04000000,
    // Zora fins are out, "Put Away" may be prompted.
    Z2_ACTION_STATE1_ZORA_WEAPON  = 0x01000000,
    // On Epona.
    Z2_ACTION_STATE1_EPONA        = 0x00800000,
    // Shielding.
    Z2_ACTION_STATE1_SHIELD       = 0x00400000,
    // Using Zora fins.
    Z2_ACTION_STATE1_ZORA_FINS    = 0x00200000,
    // Aiming bow, hookshot, Zora fins, etc.
    Z2_ACTION_STATE1_AIM          = 0x00100000,
    // In the air (without jumping beforehand).
    Z2_ACTION_STATE1_FALLING      = 0x00080000,
    // In the air (with jumping beforehand).
    Z2_ACTION_STATE1_AIR          = 0x00040000,
    // In Z-target view.
    Z2_ACTION_STATE1_Z_VIEW       = 0x00020000,
    // Z-target check-able or speak-able.
    Z2_ACTION_STATE1_Z_CHECK      = 0x00010000,
    // Z-target enabled.
    Z2_ACTION_STATE1_Z_ON         = 0x00008000,
    // Hanging from ledge.
    Z2_ACTION_STATE1_LEDGE_HANG   = 0x00002000,
    // Charging spin attack.
    Z2_ACTION_STATE1_CHARGE_SPIN  = 0x00001000,
    // Hold above head.
    Z2_ACTION_STATE1_HOLD         = 0x00000800,
    // Hold new item over head.
    Z2_ACTION_STATE1_GET_ITEM     = 0x00000400,
    // Time is stopped (does not affect Tatl, HUD animations).
    // Used for: transition to day/night, Pictograph Box prompt.
    Z2_ACTION_STATE1_TIME_STOP_2  = 0x00000200,
    // Dead.
    Z2_ACTION_STATE1_DEAD         = 0x00000080,
    // When walking in a cutscene? Unsure.
    // Used during Postman's minigame.
    Z2_ACTION_STATE1_MOVE_SCENE   = 0x00000020,
    // Zora electric barrier.
    Z2_ACTION_STATE1_BARRIER      = 0x00000010,
    // Item is out, may later prompt "Put Away."
    // Relevant to Bow, Hookshot, not Great Fairy Sword.
    Z2_ACTION_STATE1_ITEM_OUT     = 0x00000008,
    // Climbing ledge.
    Z2_ACTION_STATE1_LEDGE_CLIMB  = 0x00000004,
} z2_action_state1_t;

typedef enum {
    // Idle animation.
    Z2_ACTION_STATE2_IDLE         = 0x10000000,
    // Using ocarina? Maybe more.
    Z2_ACTION_STATE2_OCARINA      = 0x08000000,
    // Kamaro mask dance.
    Z2_ACTION_STATE2_KAMARO       = 0x02000000,
    // Can get down from Epona.
    Z2_ACTION_STATE2_CAN_DOWN     = 0x00400000,
    // Tatl C up button prompt.
    Z2_ACTION_STATE2_TATL_BUTTON  = 0x00200000,
    // When tatl is out.
    Z2_ACTION_STATE2_TATL_OUT     = 0x00100000,
    // Z-target jumping (sidehop, backflip).
    Z2_ACTION_STATE2_Z_JUMP       = 0x00080000,
    // Spin attack.
    Z2_ACTION_STATE2_SPIN_ATTACK  = 0x00020000,
    // Frozen, ends once ice cracks.
    Z2_ACTION_STATE2_FROZEN       = 0x00004000,
    // Stationary while climbing.
    Z2_ACTION_STATE2_CLIMB_STAY   = 0x00001000,
    // Diving.
    Z2_ACTION_STATE2_DIVING       = 0x00000800,
    // Diving, swimming as Zora.
    Z2_ACTION_STATE2_DIVING_2     = 0x00000400,
    // Grabbing onto a block.
    Z2_ACTION_STATE2_GRABBING     = 0x00000100,
    // Climbing. Also occurs during: transforming, hanging from ledge,
    // deku spinning, goron ball, sliding
    Z2_ACTION_STATE2_CLIMBING     = 0x00000040,
    // Running / moving.
    Z2_ACTION_STATE2_MOVING       = 0x00000020,
    // Pushing or pulling a block.
    Z2_ACTION_STATE2_PUSH_PULL    = 0x00000010,
    // Is set for some movement frames.
    Z2_ACTION_STATE2_MOVING_2     = 0x00000008,
    // "Check" or "Speak" prompt may appear.
    Z2_ACTION_STATE2_CHECK        = 0x00000002,
    // "Grab" prompt may appear.
    Z2_ACTION_STATE2_MAY_GRAB     = 0x00000001,
} z2_action_state2_t;

typedef enum {
    // Bremen mask march.
    Z2_ACTION_STATE3_BREMEN      = 0x20000000,
    // Rolling (non-Goron).
    Z2_ACTION_STATE3_ROLLING     = 0x08000000,
    // Attacking with sword, B button weapon.
    Z2_ACTION_STATE3_ATTACK      = 0x02000000,
    // Hover with flower petals? Maybe more.
    Z2_ACTION_STATE3_DEKU_AIR_2  = 0x01000000,
    // Deku hopping on water.
    Z2_ACTION_STATE3_DEKU_HOP    = 0x00200000,
    // Goron spike roll.
    Z2_ACTION_STATE3_GORON_SPIKE = 0x00080000,
    // Transforming (latter-half).
    Z2_ACTION_STATE3_TRANS_PART  = 0x00020000,
    // Zora swimming/diving.
    Z2_ACTION_STATE3_ZORA_SWIM   = 0x00008000,
    // Hover with flower petals.
    Z2_ACTION_STATE3_DEKU_AIR    = 0x00002000,
    // Jumping out of Deku flower.
    Z2_ACTION_STATE3_DEKU_RISE   = 0x00000200,
    // Deku flower dive.
    Z2_ACTION_STATE3_DEKU_DIVE   = 0x00000100,
    // Pull back bow string.
    Z2_ACTION_STATE3_PULL_BOW    = 0x00000040,
    // Post-attack.
    Z2_ACTION_STATE3_ATTACK_2    = 0x00000008,
    // Beginning of jump attack.
    Z2_ACTION_STATE3_JUMP_ATTACK = 0x00000002,
} z2_action_state3_t;

typedef enum {
    // Item "pickup", such as a rupee, arrows, magic, deku stick, etc.
    Z2_ACTOR_EN_ITEM00 = 0xE,
    // Arrow.
    Z2_ACTOR_EN_ARROW = 0xF,
    // Fairy.
    Z2_ACTOR_EN_ELF = 0x10,
    // Gold skulltula token.
    Z2_ACTOR_EN_SI = 0xE3,
    // Cow.
    Z2_ACTOR_EN_COW = 0xF3,
    // Stray fairy.
    Z2_ACTOR_EN_ELFORG = 0x1B0,
    // Stray fairy in bubble.
    Z2_ACTOR_EN_ELFBUB = 0x1B1,
} z2_actor_id_t;

typedef enum {
    // Step-on switches.
    Z2_ACTOR_TYPE_SWITCH,
    // Typically larger, more complex set pieces.
    Z2_ACTOR_TYPE_PROP,
    // Main player (Link).
    Z2_ACTOR_TYPE_PLAYER,
    // Bombs, Bombchus.
    Z2_ACTOR_TYPE_BOMB,
    // NPCs.
    Z2_ACTOR_TYPE_NPC,
    // Enemies, used for triggering room clear state.
    Z2_ACTOR_TYPE_ENEMY,
    Z2_ACTOR_TYPE_PROP2,
    Z2_ACTOR_TYPE_ITEM,
    Z2_ACTOR_TYPE_MISC,
    Z2_ACTOR_TYPE_BOSS,
    Z2_ACTOR_TYPE_DOOR,
    Z2_ACTOR_TYPE_CHEST,
} z2_actor_type_t;

typedef enum {
    Z2_FLOOR_TYPE_DIRT = 0,
    Z2_FLOOR_TYPE_SAND = 1,
    Z2_FLOOR_TYPE_STONE = 2,
    Z2_FLOOR_TYPE_WET1 = 4,
    Z2_FLOOR_TYPE_WET2 = 5,
    Z2_FLOOR_TYPE_PLANTS = 6,
    Z2_FLOOR_TYPE_GRASS = 8,
    Z2_FLOOR_TYPE_WOOD = 0xA,
    Z2_FLOOR_TYPE_SNOW = 0xE,
    Z2_FLOOR_TYPE_ICE = 0xF,
} z2_floor_type_t;

typedef enum {
    Z2_FLOOR_PHYSICS_NORMAL = 0,
    Z2_FLOOR_PHYSICS_ICE = 5,
    Z2_FLOOR_PHYSICS_SNOW = 0xE,
} z2_floor_physics_t;

typedef enum {
    // Damaged normally.
    Z2_DAMAGE_EFFECT_NORMAL = 0,
    // Flies backwards screaming.
    Z2_DAMAGE_EFFECT_FLY_BACK = 1,
    // Flies backwards.
    Z2_DAMAGE_EFFECT_FLY_BACK_2 = 2,
    // Freezes.
    Z2_DAMAGE_EFFECT_FREEZE = 3,
    // Electrocutes.
    Z2_DAMAGE_EFFECT_ELECTRIC = 4,
} z2_damage_effect_t;

typedef enum {
    Z2_CAMERA_STATE_NONE,
    Z2_CAMERA_STATE_NORMAL0,
    Z2_CAMERA_STATE_NORMAL3,
    Z2_CAMERA_STATE_CIRCLE5,
    Z2_CAMERA_STATE_HORSE0,
    Z2_CAMERA_STATE_ZORA0,
    Z2_CAMERA_STATE_PREREND0,
    Z2_CAMERA_STATE_PREREND1,
    Z2_CAMERA_STATE_DOORC,
    Z2_CAMERA_STATE_DEMO0,
    Z2_CAMERA_STATE_FREE0,
    Z2_CAMERA_STATE_FUKAN0,
    Z2_CAMERA_STATE_NORMAL1,
    Z2_CAMERA_STATE_NANAME,
    Z2_CAMERA_STATE_CIRCLE0,
    Z2_CAMERA_STATE_FIXED0,
    Z2_CAMERA_STATE_SPIRAL,
    Z2_CAMERA_STATE_DUNGEON0,
    Z2_CAMERA_STATE_ITEM0,
    Z2_CAMERA_STATE_ITEM1,
    Z2_CAMERA_STATE_ITEM2,
    Z2_CAMERA_STATE_ITEM3,
    Z2_CAMERA_STATE_NAVI,
    Z2_CAMERA_STATE_WARP0,
    Z2_CAMERA_STATE_DEATH,
    Z2_CAMERA_STATE_REBIRTH,
    Z2_CAMERA_STATE_TREASURE,
    Z2_CAMERA_STATE_TRANSFORM,
    Z2_CAMERA_STATE_ATTENTION,
    Z2_CAMERA_STATE_WARP1,
    Z2_CAMERA_STATE_DUNGEON1,
    Z2_CAMERA_STATE_FIXED1,
    Z2_CAMERA_STATE_FIXED2,
    Z2_CAMERA_STATE_MAZE,
    Z2_CAMERA_STATE_REMOTEBOMB,
    Z2_CAMERA_STATE_CIRCLE1,
    Z2_CAMERA_STATE_CIRCLE2,
    Z2_CAMERA_STATE_CIRCLE3,
    Z2_CAMERA_STATE_CIRCLE4,
    Z2_CAMERA_STATE_FIXED3,
    Z2_CAMERA_STATE_TOWER0,
    Z2_CAMERA_STATE_PARALLEL0,
    Z2_CAMERA_STATE_NORMALD,
    Z2_CAMERA_STATE_SUBJECTD,
    Z2_CAMERA_STATE_START0,
    Z2_CAMERA_STATE_START2,
    Z2_CAMERA_STATE_STOP0,
    Z2_CAMERA_STATE_JCRUISING,
    Z2_CAMERA_STATE_CLIMEMAZE,
    Z2_CAMERA_STATE_SIDED,
    Z2_CAMERA_STATE_DUNGEON2,
    Z2_CAMERA_STATE_BOSS_SHIGE,
    Z2_CAMERA_STATE_KEEPBACK,
    Z2_CAMERA_STATE_CIRCLE6,
    Z2_CAMERA_STATE_CIRCLE7,
    Z2_CAMERA_STATE_CHUBOSS,
    Z2_CAMERA_STATE_RFIXED1,
    Z2_CAMERA_STATE_TRESURE1,
    Z2_CAMERA_STATE_BOMBBASKET,
    Z2_CAMERA_STATE_CIRCLE8,
    Z2_CAMERA_STATE_FUKAN1,
    Z2_CAMERA_STATE_DUNGEON3,
    Z2_CAMERA_STATE_TELESCOPE,
    Z2_CAMERA_STATE_ROOM0,
    Z2_CAMERA_STATE_RCIRC0,
    Z2_CAMERA_STATE_CIRCLE9,
    Z2_CAMERA_STATE_ONTHEPOLE,
    Z2_CAMERA_STATE_INBUSH,
    Z2_CAMERA_STATE_BOSS_LAST,
    Z2_CAMERA_STATE_BOSS_INI,
    Z2_CAMERA_STATE_BOSS_HAK,
    Z2_CAMERA_STATE_BOSS_KON,
    Z2_CAMERA_STATE_CONNECT0,
    Z2_CAMERA_STATE_MORAY,
    Z2_CAMERA_STATE_NORMAL2,
    Z2_CAMERA_STATE_BOMBBOWL,
    Z2_CAMERA_STATE_CIRCLEa,
    Z2_CAMERA_STATE_WHIRLPOOL,
    Z2_CAMERA_STATE_KOKKOGAME,
    Z2_CAMERA_STATE_GIANT,
    Z2_CAMERA_STATE_SCENE0,
    Z2_CAMERA_STATE_ROOM1,
    Z2_CAMERA_STATE_WATER2,
    Z2_CAMERA_STATE_SOKONASI,
    Z2_CAMERA_STATE_FORCEKEEP,
    Z2_CAMERA_STATE_PARALLEL1,
    Z2_CAMERA_STATE_START1,
    Z2_CAMERA_STATE_ROOM2,
    Z2_CAMERA_STATE_NORMAL4,
    Z2_CAMERA_STATE_SHELL,
    Z2_CAMERA_STATE_DUNGEON4,
} z2_camera_state;

typedef enum {
    Z2_CAMERA_MODE_NORMAL,
    Z2_CAMERA_MODE_JUMP,
    Z2_CAMERA_MODE_GORONDASH,
    Z2_CAMERA_MODE_NUTSSHOT,
    Z2_CAMERA_MODE_BOWARROWZ,
    Z2_CAMERA_MODE_NUTSFLY,
    Z2_CAMERA_MODE_SUBJECT,
    Z2_CAMERA_MODE_BOOKEEPON,
    Z2_CAMERA_MODE_ZORAFIN,
    Z2_CAMERA_MODE_KEEPON,
    Z2_CAMERA_MODE_PARALLEL,
    Z2_CAMERA_MODE_TALK,
    Z2_CAMERA_MODE_PACHINCO,
    Z2_CAMERA_MODE_BOWARROW,
    Z2_CAMERA_MODE_BATTLE,
    Z2_CAMERA_MODE_NUTSHIDE,
    Z2_CAMERA_MODE_STILL,
    Z2_CAMERA_MODE_CHARGE,
    Z2_CAMERA_MODE_CLIMB,
    Z2_CAMERA_MODE_CLIMBZ,
    Z2_CAMERA_MODE_FOOKSHOT,
    Z2_CAMERA_MODE_FREEFALL,
    Z2_CAMERA_MODE_HANG,
    Z2_CAMERA_MODE_HANGZ,
    Z2_CAMERA_MODE_PUSHPULL,
    Z2_CAMERA_MODE_NUTSFLYZ,
    Z2_CAMERA_MODE_GORONJUMP,
    Z2_CAMERA_MODE_BOOMERANG,
    Z2_CAMERA_MODE_CHARGEZ,
    Z2_CAMERA_MODE_ZORAFINZ,
} z2_camera_mode;

typedef enum {
    // No timer.
    Z2_TIMER_STATE_NONE,
    // Timer is not being displayed yet.
    Z2_TIMER_STATE_PRE,
    // Timer is in middle of screen.
    Z2_TIMER_STATE_INIT,
    // Timer is moving into position.
    Z2_TIMER_STATE_MOVING,
    // Timer is positioned.
    Z2_TIMER_STATE_SET,
    // Timer is finished and no longer displaying.
    Z2_TIMER_STATE_FINISHED,
} z2_timer_state_t;

/* Macro for checking if a timer state is visible. */
#define IS_TIMER_VISIBLE(TSTATE) (Z2_TIMER_STATE_INIT <= (TSTATE) && (TSTATE) < Z2_TIMER_STATE_FINISHED)

typedef enum {
    // Skull kid on clock tower.
    Z2_TIMER_TYPE_SKULL_KID = 3,
    // Treasure chest game, maybe others.
    Z2_TIMER_TYPE_TCG = 4,
    // Drowning.
    Z2_TIMER_TYPE_DROWNING = 5,
    // None.
    Z2_TIMER_TYPE_NONE = 0x63,
} z2_timer_type_t;

typedef enum {
    // Poe sisters fight.
    Z2_TIMER_INDEX_POE_SISTERS = 1,
    // Treasure Chest Shop game.
    Z2_TIMER_INDEX_TREASURE_CHEST_GAME = 4,
    // Drowning.
    Z2_TIMER_INDEX_DROWNING = 5,
    // Clock tower skull kid encounter.
    Z2_TIMER_INDEX_SKULL_KID = 0x13,
    // Honey & Darling game.
    Z2_TIMER_INDEX_HONEY_DARLING = 0x14,
} z2_timer_index_t;

enum z2_button_text {
    Z2_BUTTON_TEXT_ATTACK = 0x00,
    Z2_BUTTON_TEXT_CHECK = 0x01,
    Z2_BUTTON_TEXT_ENTER = 0x02,
    Z2_BUTTON_TEXT_RETURN = 0x03,
    Z2_BUTTON_TEXT_OPEN = 0x04,
    Z2_BUTTON_TEXT_JUMP = 0x05,
    Z2_BUTTON_TEXT_DECIDE = 0x06,
    Z2_BUTTON_TEXT_DIVE = 0x07,
    Z2_BUTTON_TEXT_FASTER = 0x08,
    Z2_BUTTON_TEXT_THROW = 0x09,
    Z2_BUTTON_TEXT_BLANK = 0x0A,
    Z2_BUTTON_TEXT_CLIMB = 0x0B,
    Z2_BUTTON_TEXT_DROP = 0x0C,
    Z2_BUTTON_TEXT_DOWN = 0x0D,
    Z2_BUTTON_TEXT_QUIT = 0x0E,
    Z2_BUTTON_TEXT_SPEAK = 0x0F,
    Z2_BUTTON_TEXT_NEXT = 0x10,
    Z2_BUTTON_TEXT_GRAB = 0x11,
    Z2_BUTTON_TEXT_STOP = 0x12,
    Z2_BUTTON_TEXT_PUT_AWAY = 0x13,
    Z2_BUTTON_TEXT_J_SOW = 0x14,
    Z2_BUTTON_TEXT_INFO = 0x15,
    Z2_BUTTON_TEXT_WARP = 0x16,
    Z2_BUTTON_TEXT_SNAP = 0x17,
    Z2_BUTTON_TEXT_EXPLODE = 0x18,
    Z2_BUTTON_TEXT_DANCE = 0x19,
    Z2_BUTTON_TEXT_MARCH = 0x1A,
    Z2_BUTTON_TEXT_1 = 0x1B,
    Z2_BUTTON_TEXT_2 = 0x1C,
    Z2_BUTTON_TEXT_3 = 0x1D,
    Z2_BUTTON_TEXT_4 = 0x1E,
    Z2_BUTTON_TEXT_5 = 0x1F,
    Z2_BUTTON_TEXT_6 = 0x20,
    Z2_BUTTON_TEXT_7 = 0x21,
    Z2_BUTTON_TEXT_8 = 0x22,
    Z2_BUTTON_TEXT_CURL = 0x23,
    Z2_BUTTON_TEXT_SURFACE = 0x24,
    Z2_BUTTON_TEXT_SWIM = 0x25,
    Z2_BUTTON_TEXT_PUNCH = 0x26,
    Z2_BUTTON_TEXT_POUND = 0x27,
    Z2_BUTTON_TEXT_J_HOOK = 0x28,
    Z2_BUTTON_TEXT_SHOOT = 0x29,
};

enum z2_seg {
    Z2_SEG_DIRECT_REFERENCE,
    Z2_SEG_NINTENDO_LOGO,
    Z2_SEG_CURRENT_SCENE,
    Z2_SEG_CURRENT_ROOM,
    Z2_SEG_GAMEPLAY_KEEP,
    Z2_SEG_GAMEPLAY_DUNGEON_FIELD_KEEP,
    Z2_SEG_CURRENT_OBJECT,
    Z2_SEG_LINK_ANIMATION, // Unsure if used.
    Z2_SEG_CURRENT_MASK = 10,
    Z2_SEG_Z_BUFFER = 14,
    Z2_SEG_FRAME_BUFFER = 15,
};

enum z2_graphic_id {
    Z2_GRAPHIC_HEART_CONTAINER = 0x13,
    Z2_GRAPHIC_HEART_PIECE = 0x14,
    Z2_GRAPHIC_GI_GLASSES = 0x30,
    // Skulltula Token used with Z2_OBJECT_GI_SUTARU
    Z2_GRAPHIC_GI_SUTARU = 0x4B,
    // Skulltula Token used with Z2_OBJECT_ST
    Z2_GRAPHIC_ST_TOKEN = 0x57,
    Z2_GRAPHIC_MOONS_TEAR = 0x5A,
    Z2_GRAPHIC_ODOLWA_REMAINS = 0x5D,
    Z2_GRAPHIC_GOHT_REMAINS = 0x64,
    Z2_GRAPHIC_GYORG_REMAINS = 0x65,
    Z2_GRAPHIC_TWINMOLD_REMAINS = 0x66,
};

enum z2_object_id {
    // Skulltula, Skullwalltula, Gold Skulltula Token.
    Z2_OBJECT_ST = 0x20,
    // Music Notes (Get Item).
    Z2_OBJECT_GI_MELODY = 0x8F,
    // Heart Piece, Heart Container.
    Z2_OBJECT_GI_HEARTS = 0x96,
    // Lens of Truth (Get Item).
    Z2_OBJECT_GI_GLASSES = 0xC0,
    // Magic Bean (Get Item).
    Z2_OBJECT_GI_BEAN = 0xC6,
    // Keaton Mask
    Z2_OBJECT_GI_KI_TAN_MASK = 0x100,
    // Gold Skulltula Token (Get Item).
    Z2_OBJECT_GI_SUTARU = 0x125,
    // Moon's Tear.
    Z2_OBJECT_GI_RESERVE00 = 0x1B1,
    // Title Deeds.
    Z2_OBJECT_GI_RESERVE01 = 0x1B2,
    // Boss Remains.
    Z2_OBJECT_BSMASK = 0x1CC,
};

/* Structure type aliases. */
struct Actor;
typedef struct z2_game_s  z2_game_t;

/**
 * Floating point matrix (copied from krimtonz' gu.h)
 **/
typedef union {
    f32 mf[4][4];
    f32 f[16];
    struct {
        f32 xx, xy, xz, xw,
            yx, yy, yz, yw,
            zx, zy, zz, zw,
            wx, wy, wz, ww;
    };
} MtxF;

/// =============================================================
/// Position & Rotation
/// =============================================================

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Vec3f; // size = 0xC

typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} Vec3s; // size = 0x6

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3s rot;
} PosRot; // size = 0x14

/// =============================================================
/// Colors
/// =============================================================

typedef struct {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
} ColorRGB8; // size = 0x3

typedef union {
    struct {
        /* 0x0 */ u8 r;
        /* 0x1 */ u8 g;
        /* 0x2 */ u8 b;
        /* 0x3 */ u8 a;
    };
    u8 bytes[4];
} ColorRGBA8; // size = 0x4

typedef struct {
    /* 0x0 */ u16 r;
    /* 0x2 */ u16 g;
    /* 0x4 */ u16 b;
} ColorRGB16; // size = 0x6

typedef struct {
    /* 0x0 */ u16 r1;
    /* 0x2 */ u16 r2;
    /* 0x4 */ u16 g1;
    /* 0x6 */ u16 g2;
    /* 0x8 */ u16 b1;
    /* 0xA */ u16 b2;
} ColorRRGGBB16; // size = 0xC

typedef ColorRGB8 RGB8;
typedef ColorRGBA8 RGBA8;
typedef ColorRGB16 RGB16;
typedef ColorRRGGBB16 RRGGBB16;

/// =============================================================
/// Controller & Inputs
/// =============================================================

typedef union {
    struct {
        u16 a  : 1;
        u16 b  : 1;
        u16 z  : 1;
        u16 s  : 1;
        u16 du : 1;
        u16 dd : 1;
        u16 dl : 1;
        u16 dr : 1;
        u16    : 2;
        u16 l  : 1;
        u16 r  : 1;
        u16 cu : 1;
        u16 cd : 1;
        u16 cl : 1;
        u16 cr : 1;
    };
    u16 value;
} InputPad; // size = 0x2

typedef struct {
    /* 0x0 */ InputPad buttons;
    /* 0x2 */ s8 xAxis;
    /* 0x3 */ s8 yAxis;
    /* 0x4 */ s8 status;
    /* 0x5 */ UNK_TYPE1 pad5[0x1];
} InputInfo; // size = 0x6

typedef struct {
    /* 0x00 */ InputInfo current;
    /* 0x06 */ InputInfo last;
    /* 0x0C */ InputInfo pressEdge;
    /* 0x12 */ InputInfo releaseEdge;
} Input; // size = 0x18

/// =============================================================
/// Gfx Context
/// =============================================================

typedef struct {
    /* 0x0 */ u32 size;
    /* 0x4 */ Gfx* buf;
    /* 0x8 */ Gfx* p;
    /* 0xC */ Gfx* d;
} DispBuf; // size = 0x10

typedef struct {
    /* 0x000 */ Gfx* polyOpaBuffer;
    /* 0x004 */ Gfx* polyXluBuffer;
    /* 0x008 */ UNK_TYPE1 pad8[0x08];
    /* 0x010 */ Gfx* overlayBuffer;
    /* 0x014 */ UNK_TYPE1 pad14[0x24];
    /* 0x038 */ OSMesg taskMesg[8];
    /* 0x058 */ OSMesgQueue* unk58;
    /* 0x05C */ OSMesgQueue taskQueue;
    /* 0x074 */ UNK_TYPE1 pad74[0x4];
    /* 0x078 */ OSScTask task;
    /* 0x0D0 */ UNK_TYPE1 padD0[0xD0];
    /* 0x1A0 */ Gfx* unk1A0;
    /* 0x1A4 */ DispBuf unk1A4;
    /* 0x1B4 */ Gfx* unk1B4;
    /* 0x1B8 */ DispBuf unk1B8;
    /* 0x1C8 */ UNK_TYPE1 pad1C8[0xAC];
    /* 0x274 */ UNK_TYPE4 unk274; // OSViMode*
    /* 0x278 */ void* zbuffer;
    /* 0x27C */ UNK_TYPE1 pad27C[0x1C];
    /* 0x298 */ DispBuf overlay;
    /* 0x2A8 */ DispBuf polyOpa;
    /* 0x2B8 */ DispBuf polyXlu;
    /* 0x2C8 */ u32 displayListCounter;
    /* 0x2CC */ void* framebuffer;
    /* 0x2D0 */ UNK_TYPE4 unk2D0;
    /* 0x2D4 */ u32 viConfigFeatures;
    /* 0x2D8 */ UNK_TYPE1 pad2D8[0x3];
    /* 0x2DB */ u8 framebufferCounter;
    /* 0x2DC */ void* func2DC;
    /* 0x2E0 */ z2_game_t* globalContext;
    /* 0x2E4 */ f32 viConfigXScale;
    /* 0x2E8 */ f32 viConfigYScale;
    /* 0x2EC */ UNK_TYPE1 pad2EC[0x4];
} GraphicsContext; // size = 0x02F0

/// =============================================================
/// Context Structure
/// =============================================================

typedef struct GameAlloc GameAlloc;
typedef struct GameAllocNode GameAllocNode;
typedef struct GameState GameState;

struct GameAllocNode {
    /* 0x0 */ GameAllocNode* next;
    /* 0x4 */ GameAllocNode* prev;
    /* 0x8 */ u32 size;
    /* 0xC */ UNK_TYPE1 padC[0x4];
}; // size = 0x10

struct GameAlloc {
    /* 0x00 */ GameAllocNode base;
    /* 0x10 */ GameAllocNode* head;
}; // size = 0x14

typedef struct {
    /* 0x0 */ UNK_TYPE4 size;
    /* 0x4 */ void* heapStart;
    /* 0x8 */ void* heapAppendStart;
    /* 0xC */ void* heapAppendEnd;
} GameStateHeap; // size = 0x10

typedef void (*GameStateFunc)(struct GameState* gameState);

struct GameState {
    /* 0x00 */ GraphicsContext* gfxCtx;
    /* 0x04 */ GameStateFunc main;
    /* 0x08 */ GameStateFunc destroy;
    /* 0x0C */ GameStateFunc nextGameStateInit;
    /* 0x10 */ u32 nextGameStateSize;
    /* 0x14 */ Input input[4];
    /* 0x74 */ GameStateHeap heap;
    /* 0x84 */ GameAlloc alloc;
    /* 0x98 */ UNK_TYPE1 pad98[0x3];
    /* 0x9B */ u8 running; // If 0, switch to next game state
    /* 0x9C */ u32 frames;
    /* 0xA0 */ UNK_TYPE1 padA0[0x2];
    /* 0xA2 */ u8 framerateDivisor; // game speed?
    /* 0xA3 */ UNK_TYPE1 unkA3;
}; // size = 0xA4

/// =============================================================
/// View & Camera
/// =============================================================

typedef struct {
    /* 0x0 */ s32 topY;
    /* 0x4 */ s32 bottomY;
    /* 0x8 */ s32 leftX;
    /* 0xC */ s32 rightX;
} Viewport; // size = 0x10

typedef struct {
    /* 0x000 */ u32 magic;
    /* 0x004 */ GraphicsContext* gfxCtx;
    /* 0x008 */ Viewport viewport;
    /* 0x018 */ f32 fovy;
    /* 0x01C */ f32 zNear;
    /* 0x020 */ f32 zFar;
    /* 0x024 */ f32 scale;
    /* 0x028 */ Vec3f eye;
    /* 0x034 */ Vec3f focalPoint;
    /* 0x040 */ Vec3f upDir;
    /* 0x04C */ UNK_TYPE1 pad4C[0x4];
    /* 0x050 */ Vp vp;
    /* 0x060 */ Mtx projection;
    /* 0x0A0 */ Mtx viewing;
    /* 0x0E0 */ Mtx unkE0;
    /* 0x120 */ Mtx* projectionPtr;
    /* 0x124 */ Mtx* viewingPtr;
    /* 0x128 */ Vec3f quakeRot;
    /* 0x134 */ Vec3f quakeScale;
    /* 0x140 */ f32 quakeSpeed;
    /* 0x144 */ Vec3f currQuakeRot;
    /* 0x150 */ Vec3f currQuakeScale;
    /* 0x15C */ u16 normal;
    /* 0x15E */ UNK_TYPE1 pad15E[0x2];
    /* 0x160 */ u32 flags; // bit 3: Render to an orthographic perspective
    /* 0x164 */ UNK_TYPE4 unk164;
} View; // size = 0x168

typedef struct {
    union {
        struct {
            Vec3f    unk_0x00;                     /* 0x0000 */
            struct {
                f32  unk_1_0x00;
                f32  unk_1_0x04;
                s16  unk_1_0x08;
                s16  unk_1_0x0A;
                s16  unk_1_0x0C;
                f32  unk_1_0x10;
            };
        }            t1;
        struct {
            u16      unk_0x00;
        }            t2;
        u8           unk_0x00[0x50];
    };
    Vec3f            unk_0x50;                       /* 0x0050 */
    Vec3f            unk_0x5C;                       /* 0x005C */
    Vec3f            unk_0x68;                       /* 0x0068 */
    u8               unk_0x74[0x0C];                 /* 0x0074 */
    Vec3f            unk_0x80;                       /* 0x0080 */
    GameState       *game;                           /* 0x008C */
    struct Actor    *focus;                          /* 0x0090 */
    Vec3f            focus_pos;                      /* 0x0094 */
    u32              unk_0xA0;                       /* 0x00A0 */
    u32              unk_0xA4;                       /* 0x00A4 */
    struct Actor    *actor;                          /* 0x00A8 */
    u8               unk_0xAC[0x94];                 /* 0x00AC */
    s16              unk_0x140;                      /* 0x0140 */
    s16              state;                          /* 0x0142 */
    s16              mode;                           /* 0x0144 */
    s16              unk_0x146;                      /* 0x0146 */
    s16              unk_0x148;                      /* 0x0148 */
    s16              unk_0x14A;                      /* 0x014A */
    s16              unk_flag_0x14C;                 /* 0x014C */
    u8               unk_0x14E[0x2A];                /* 0x014E */
} z2_camera_t;                                       /* 0x0178 */

/// =============================================================
/// Actor Context
/// =============================================================

/**
 * Number of array elements in actor_list field of z2_actor_ctxt_t.
 **/
#define Z2_ACTOR_LIST_ENTRIES 0x10

/**
 * z2_actor_ctxt_t
 **/
typedef struct {
    /* game_t 0x1CA0 */
    u8               unk_0x00[0x04];                 /* 0x0000 */
    s8               unk_0x04;                       /* 0x0004 */
    u8               unk_0x05;                       /* 0x0005 */
    u8               unk_0x06[0x05];                 /* 0x0006 */
    s8               unk_0x0B;                       /* 0x000B */
    u8               unk_0x0C[0x02];                 /* 0x000C */
    u8               n_actors_loaded;                /* 0x000E */
    u8               unk_0x0F;                       /* 0x000F */
    struct {
        s32          count;                          /* 0x0000 */
        struct Actor *first;                         /* 0x0004 */
        s32          unk;                            /* 0x0008 */
                                                     /* 0x000C */
    }                actor_list[0x10];               /* 0x0010 */
    u8               unk_0xD0[0x50];                 /* 0x00D0 */
    struct {
        MtxF         unk_0x120;                      /* 0x0120 */
        f32          unk_0x160;                      /* 0x0160 */
        f32          unk_0x164;                      /* 0x0164 */
        s16          unk_0x168;                      /* 0x0168 */
        u8           unk_0x16A;                      /* 0x016A */
        u8           unk_0x16B;                      /* 0x016B */
        s8           unk_0x16C;                      /* 0x016C */
        struct {
            f32      unk_0x00;                       /* 0x0000 */
            f32      unk_0x04;                       /* 0x0004 */
            f32      unk_0x08;                       /* 0x0008 */
            f32      unk_0x0C;                       /* 0x000C */
            s32      unk_0x10;                       /* 0x0010 */
                                                     /* 0x0014 */
        }            unk_0x170[0x03];                /* 0x0170 */
        s32          unk_0x1AC;                      /* 0x01AC */
        s32          unk_0x1B0;                      /* 0x01B0 */
        s32          unk_0x1B4;                      /* 0x01B4 */
    };
    s32              switch_1;                       /* 0x01B8, perm */
    s32              switch_2;                       /* 0x01BC, perm */
    s32              switch_3;                       /* 0x01C0 */
    s32              switch_4;                       /* 0x01C4 */
    s32              chest;                          /* 0x01C8 */
    s32              clear;                          /* 0x01CC */
    s32              unk_0x01D0;                     /* 0x01D0 */
    s32              collectible_1;                  /* 0x01D4, perm */
    s32              collectible_2;                  /* 0x01D8 */
    s32              collectible_3;                  /* 0x01DC */
    s32              collectible_4;                  /* 0x01E0 */
    struct {
        u8           unk_0x00[0x0A];                 /* 0x0000 */
        s8           unk_0x0A;                       /* 0x000A */
        s8           unk_0x0B;                       /* 0x000B */
        s16          unk_0x0C;                       /* 0x000C */
        s16          unk_0x0E;                       /* 0x000E */
                                                     /* 0x0010 */
    }                unk_0x1E4;                      /* 0x01E4 */
    s8               unk_0x1F4;                      /* 0x01F4 */
    u8               unk_0x1F5;                      /* 0x01F5 */
    f32              unk_0x1F8;                      /* 0x01F8 */
    u8               unk_0x1FC[0x54];                /* 0x01FC */
    s32              unk_0x250;                      /* 0x0250 */
    struct Actor    *elegy_statues[0x04];            /* 0x0254 */
    u8               unk_0x264[0x04];                /* 0x0264 */
    u8               unk_0x268;                      /* 0x0268 */
    u8               unk_0x269[0x03];                /* 0x0269 */
    u8               unk_0x26C[0x18];                /* 0x026C */
} z2_actor_ctxt_t;                                   /* 0x0284 */

/// =============================================================
/// Collision Context
/// =============================================================

typedef struct {
    s16              poly_idx;                       /* 0x0000 */
    u16              list_next;                      /* 0x0002 */
} z2_col_list_t;                                     /* 0x0004 */

typedef struct {
    struct {
        u32                      : 1;
        u32          drop        : 1;                /* Link drops one unit into the floor. */
        u32          special     : 4;
        u32          interaction : 5;
        u32                      : 3;
        u32          behavior    : 5;
        u32          exit        : 5;
        u32          camera      : 8;
    }                flags_1;                        /* 0x0000 */
    struct {
        u32          pad         : 4;
        u32          wall_damage : 1;
        u32                      : 6;
        u32                      : 3;
        u32          hookshot    : 1;
        u32          echo        : 6;
        u32                      : 5;
        u32          terrain     : 2;
        u32          material    : 4;
    }                flags_2;                        /* 0x0004 */
} z2_col_type_t;                                     /* 0x0008 */

typedef struct {
    Vec3s            pos;                            /* 0x0000 */
    s16              width;                          /* 0x0006 */
    s16              depth;                          /* 0x0008 */
    struct {
        u32                 : 12;
        u32          active : 1;
        u32          group  : 6;
        u32                 : 5;
        u32          camera : 8;
    } flags;                                         /* 0x000A */
} z2_col_water_t;                                    /* 0x000E */

typedef struct {
    u16              type;                           /* 0x0000, index of z2_col_type in scene file */
    /* Vertex indices, a and b are bitmasked for some reason. */
    struct {
        u16          unk_0 : 3;
        u16          va    : 13;
    }                mask_1;                         /* 0x0002 */
    struct {
        u16          unk_1 : 3;
        u16          vb    : 13;
    }                mask_2;                         /* 0x0004 */
    u16              vc;                             /* 0x0006 */
    Vec3s            norm;                           /* 0x0008, normal vector. */
    s16              dist;                           /* 0x000E, plane distance from origin. */
} z2_col_poly_t;                                     /* 0x0010 */

typedef struct {
    Vec3s            min;                            /* 0x0000 */
    Vec3s            max;                            /* 0x0006 */
    u16              n_vtx;                          /* 0x000C */
    Vec3s           *vtx;                            /* 0x000E */
    u16              n_poly;                         /* 0x0012 */
    z2_col_poly_t   *poly;                           /* 0x0014 */
    z2_col_type_t   *type;                           /* 0x0018 */
    z2_camera_t     *camera;                         /* 0x001C */
    u16              n_water;                        /* 0x0020 */
    z2_col_water_t  *water;                          /* 0x0022 */
} z2_col_hdr_t;                                      /* 0x0026 */

typedef struct {
    struct Actor    *actor;                          /* 0x0000 */
    z2_col_hdr_t    *col_hdr;                        /* 0x0004 */
    u16              unk_0x08;                       /* 0x0008 */
    u16              unk_0x0A;                       /* 0x000A */
    u16              unk_0x0C;                       /* 0x000C */
    s16              unk_0x0E;                       /* 0x000E, number of polys? */
    s16              unk_0x10;                       /* 0x0010 */
    Vec3f            scale_1;                        /* 0x0014 */
    Vec3s            rot_1;                          /* 0x0020 */
    Vec3f            pos_1;                          /* 0x0028 */
    Vec3f            scale_2;                        /* 0x0034 */
    Vec3s            rot_2;                          /* 0x0040 */
    Vec3f            pos_2;                          /* 0x0048 */
    s16              unk_0x54;                       /* 0x0054 */
    s16              unk_0x56;                       /* 0x0056 */
    s16              unk_0x58;                       /* 0x0058 */
    s16              unk_0x5A;                       /* 0x005A */
    u8               unk_0x5C[0x08];                 /* 0x005C */
} z2_col_chk_actor_t;                                /* 0x0064 */

typedef struct {
    u16              floor_list_idx;                 /* 0x0000 */
    u16              wall_list_idx;                  /* 0x0002 */
    u16              ceil_list_idx;                  /* 0x0004 */
} z2_col_lut_t;                                      /* 0x0006 */

typedef struct {
    /* static collision stuff */
    z2_col_hdr_t    *col_hdr;                        /* 0x0000 */
    Vec3f            bbox_min;                       /* 0x0004 */
    Vec3f            bbox_max;                       /* 0x0010 */
    s32              n_sect_x;                       /* 0x001C */
    s32              n_sect_y;                       /* 0x0020 */
    s32              n_sect_z;                       /* 0x0024 */
    Vec3f            sect_size;                      /* 0x0028 */
    Vec3f            sect_inv;                       /* 0x0034 */
    z2_col_lut_t    *stc_lut;                        /* 0x0040 */
    u16              stc_list_max;                   /* 0x0044 */
    u16              stc_list_pos;                   /* 0x0046 */
    z2_col_list_t   *stc_list;                       /* 0x0048 */
    u8              *stc_check;                      /* 0x004C */

                                                     /* bg actor collision struct start */
    s8               unk_0x50[0x04];                 /* 0x0050, MIGHT BE [0x04]???? */
    z2_col_chk_actor_t actors[50];                   /* 0x0054 */
    u16              actor_loaded[50];               /* 0x13DC */
                                                     /* dynamic collision stuff */
    z2_col_poly_t   *dyn_poly;                       /* 0x1440 */
    Vec3s           *dyn_vtx;                        /* 0x1444 */
    s32              unk_0x1448;                     /* 0x1448 */
    void            *unk_0x144C;                     /* 0x144C */
                                                     /* struct */
    struct {
        z2_col_list_t *list;                         /* 0x1450 */
        s32          count;                          /* 0x1454 */
        s32          max;                            /* 0x1458 */
    } dyn;
                                                     /* bg actor collision struct end */
    u32              dyn_list_max;                   /* 0x145C */
    u32              dyn_poly_max;                   /* 0x1460 */
    u32              dyn_vtx_max;                    /* 0x1464 */
    u32              mem_size;                       /* 0x1468 */
    u32              unk_0x146C;                     /* 0x146C */
} z2_col_ctxt_t;                                     /* 0x1470 */

/// =============================================================
/// HUD Context
/// =============================================================

typedef union {
    struct {
        /* 0x00 */ s16 fadeout;
        /* 0x02 */ s16 buttonA;
        /* 0x04 */ s16 buttonB;
        /* 0x06 */ s16 buttonCLeft;
        /* 0x08 */ s16 buttonCDown;
        /* 0x0A */ s16 buttonCRight;
        /* 0x0C */ s16 life;
        /* 0x0E */ s16 magicRupees;
        /* 0x10 */ s16 minimap;
    };
    s16 values[9];
} InterfaceAlphas; // size = 0x12

typedef struct {
    /* 0x000 */ View view;
    /* 0x168 */ UNK_TYPE1 pad168[0x8];
    /* 0x170 */ void* parameterStatic;
    /* 0x174 */ void* doActionStatic;
    /* 0x178 */ void* iconItemStatic;
    /* 0x17C */ void* minimapTexture;
    /* 0x180 */ UNK_TYPE1 pad180[0x4];
    /* 0x184 */ u32 actionRomAddr;
    /* 0x188 */ void* actionRam;
    /* 0x18C */ u32 actionSize;
    /* 0x190 */ UNK_TYPE1 pad190[0x80];
    /* 0x210 */ s16 buttonATextTransitionTimer;
    /* 0x212 */ u16 buttonATextCurrent;
    /* 0x214 */ u16 buttonATextTransition;
    /* 0x216 */ UNK_TYPE1 pad216[0x10];
    /* 0x226 */ s16 lifeColorChange;
    /* 0x228 */ s16 lifeColorChangeDirection;
    /* 0x22A */ ColorRGB16 heartbeatInnerColor;
    /* 0x230 */ ColorRGB16 heartbeatOuterColor;
    /* 0x236 */ ColorRRGGBB16 heartInnerColor;
    /* 0x242 */ ColorRRGGBB16 heartOuterColor;
    /* 0x24E */ s16 unk24E;
    /* 0x250 */ s16 unk250;
    /* 0x252 */ s16 lifeSizeChange;
    /* 0x254 */ s16 lifeSizeChangeDirection; // 1 means shrinking, 0 growing
    /* 0x256 */ UNK_TYPE1 pad256[0xE];
    /* 0x264 */ InterfaceAlphas alphas;
    /* 0x276 */ UNK_TYPE1 pad272[0x98];
    /* 0x30E */ u8 restrictionFlags[0xC];
    /* 0x31A */ UNK_TYPE1 pad31A[0x2E];
} InterfaceContext; // size = 0x348

/// =============================================================
/// Pause Context
/// =============================================================

typedef union {
    struct {
        /* 0x0 */ u16 item;
        /* 0x2 */ u16 map;
        /* 0x4 */ u16 quest;
        /* 0x6 */ u16 mask;
    };
    u16 values[0x4];
} PauseCells; // size = 0x8

typedef struct {
    /* 0x000 */ View view;
    /* 0x168 */ void* iconItemStatic;
    /* 0x16C */ void* iconItem24;
    /* 0x170 */ void* iconItemMap;
    /* 0x174 */ void* iconText;
    /* 0x178 */ void* unk178;
    /* 0x17C */ Gfx* bgDList;
    /* 0x180 */ UNK_TYPE1 pad180[0x10];
    /* 0x190 */ Vtx* vtxBuf;
    /* 0x194 */ UNK_TYPE1 pad194[0x58];
    /* 0x1EC */ u16 state;
    /* 0x1EE */ u16 debugMenu;
    /* 0x1F0 */ u8 unk1F0;
    /* 0x1F1 */ UNK_TYPE1 pad1F1[0x3];
    /* 0x1F4 */ f32 unk1F4;
    /* 0x1F8 */ UNK_TYPE1 pad1F8[0x8];
    /* 0x200 */ u16 switchingScreen;
    /* 0x202 */ u16 unk202;
    /* 0x204 */ u16 screenIndex;
    /* 0x206 */ UNK_TYPE1 pad206[0x6];
    /* 0x20C */ f32 unk20C;
    /* 0x210 */ f32 unk210;
    /* 0x214 */ f32 unk214;
    /* 0x218 */ f32 unk218;
    /* 0x21C */ f32 unk21C;
    /* 0x220 */ f32 unk220;
    /* 0x224 */ u16 itemAlpha;
    /* 0x226 */ UNK_TYPE1 pad226[0x12];
    /* 0x238 */ PauseCells cells1;
    /* 0x240 */ UNK_TYPE1 pad240[0x2];
    /* 0x242 */ u16 itemX;
    /* 0x244 */ UNK_TYPE1 pad244[0x4];
    /* 0x248 */ u16 maskX;
    /* 0x24A */ UNK_TYPE1 pad24A[0x2];
    /* 0x24C */ u16 itemY;
    /* 0x24E */ UNK_TYPE1 pad24E[0x4];
    /* 0x252 */ u16 maskY;
    /* 0x254 */ UNK_TYPE1 pad254[0x4];
    /* 0x258 */ s16 sideButton;
    /* 0x25A */ UNK_TYPE1 pad25A[0x2];
    /* 0x25C */ u16 selectedItem;
    /* 0x25E */ u16 itemItem;
    /* 0x260 */ u16 mapItem;
    /* 0x262 */ u16 questItem;
    /* 0x264 */ u16 maskItem;
    /* 0x266 */ u16 unk266;
    /* 0x268 */ PauseCells cells2;
    /* 0x270 */ UNK_TYPE1 pad270[0x60];
} PauseContext; // size = 0x2D0

/// =============================================================
/// Object Context
/// =============================================================

typedef struct {
    /* 0x00 */ u32 vromAddr;
    /* 0x04 */ void* dramAddr;
    /* 0x08 */ u32 size;
} DmaParams;

typedef struct {
    /* 0x00 */ u32 vromAddr; // VROM address (source)
    /* 0x04 */ void* dramAddr; // DRAM address (destination)
    /* 0x08 */ u32 size; // File Transfer size
    /* 0x0C */ char* filename; // Filename for debugging
    /* 0x10 */ s32 line; // Line for debugging
    /* 0x14 */ s32 unk14;
    /* 0x18 */ OSMesgQueue* notifyQueue; // Message queue for the notification message
    /* 0x1C */ OSMesg notifyMsg; // Completion notification message
} DmaRequest; // size = 0x20

typedef struct {
    /* 0x00 */ s16 id; // Negative ids mean that the object is unloaded
    /* 0x02 */ UNK_TYPE1 pad2[0x2];
    /* 0x04 */ void* vramAddr;
    /* 0x08 */ DmaRequest dmaReq;
    /* 0x28 */ OSMesgQueue loadQueue;
    /* 0x40 */ OSMesg loadMsg;
} SceneObject; // size = 0x44

typedef struct {
    /* 0x000 */ void* objectVramStart;
    /* 0x004 */ void* objectVramEnd;
    /* 0x008 */ u8 objectCount;
    /* 0x009 */ u8 spawnedObjectCount;
    /* 0x00A */ u8 mainKeepIndex;
    /* 0x00B */ u8 keepObjectId;
    /* 0x00C */ SceneObject objects[35]; // TODO: OBJECT_EXCHANGE_BANK_MAX array size
} SceneContext; // size = 0x958

/// =============================================================
/// Room Context
/// =============================================================

typedef struct {
    /* 0x0 */ u32 opaqueDl;
    /* 0x4 */ u32 translucentDl;
} RoomMeshType0Params; // size = 0x8

// Fields TODO
typedef struct {
    /* 0x0 */ u8 type;
    /* 0x1 */ u8 format; // 1 = single, 2 = multi
} RoomMeshType1; // size = 0x2

// Size TODO
typedef struct {
    /* 0x0 */ UNK_TYPE1 pad0[0x10];
} RoomMeshType1Params; // size = 0x10

typedef struct {
    /* 0x0 */ UNK_TYPE1 pad0[0x10];
} RoomMeshType2Params; // size = 0x10

typedef struct {
    /* 0x0 */ u8 type;
    /* 0x1 */ u8 count;
    /* 0x2 */ UNK_TYPE1 pad2[0x2];
    /* 0x4 */ RoomMeshType0Params* paramsStart;
    /* 0x8 */ RoomMeshType0Params* paramsEnd;
} RoomMeshType0; // size = 0xC

typedef struct {
    /* 0x0 */ u8 type;
    /* 0x1 */ u8 count;
    /* 0x2 */ UNK_TYPE1 pad2[0x2];
    /* 0x4 */ RoomMeshType2Params* paramsStart;
    /* 0x8 */ RoomMeshType2Params* paramsEnd;
} RoomMeshType2; // size = 0xC

typedef union {
    RoomMeshType0 type0;
    RoomMeshType1 type1;
    RoomMeshType2 type2;
} RoomMesh; // size = 0xC

typedef struct {
    /* 0x00 */ s8 num;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ s8 echo;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 enablePosLights;
    /* 0x07 */ UNK_TYPE1 pad7[0x1];
    /* 0x08 */ RoomMesh* mesh;
    /* 0x0C */ void* segment;
    /* 0x10 */ UNK_TYPE1 pad10[0x4];
} Room; // size = 0x14

typedef struct {
    /* 0x00 */ Room currRoom;
    /* 0x14 */ Room prevRoom;
    /* 0x28 */ void* roomMemPages[2]; // In a scene with transitions, roomMemory is split between two pages that toggle each transition. This is one continuous range, as the second page allocates from the end
    /* 0x30 */ u8 activeMemPage; // 0 - First page in memory, 1 - Second page
    /* 0x31 */ s8 unk31;
    /* 0x32 */ UNK_TYPE1 pad32[0x2];
    /* 0x34 */ void* activeRoomVram;
    /* 0x38 */ DmaRequest dmaRequest;
    /* 0x58 */ OSMesgQueue loadQueue;
    /* 0x70 */ OSMesg loadMsg[1];
    /* 0x74 */ void* unk74;
    /* 0x78 */ s8 transitionCount;
    /* 0x79 */ s8 unk79;
    /* 0x7A */ UNK_TYPE2 unk7A[1];
    /* 0x7C */ void* transitionList;
} RoomContext; // size = 0x80

/// =============================================================
/// Ocarina & Song
/// =============================================================

enum z2_stored_song {
    // No stored song while using ocarina.
    Z2_STORED_SONG_OCARINA_NONE = 0xFE,
    // No stored song (while not using ocarina).
    Z2_STORED_SONG_NONE = 0xFF,
};

typedef struct {
    /* Might be part of a larger messagebox context. */
    /* 0x00 */ s8 notes[0x9]; // 8 notes + extra terminator (0xFF).
    /* 0x09 */ UNK_TYPE1 pad9[0x3];
    /* 0x0C */ s16 alphas[0x8]; // Note alphas.
} SongNotes; // size = 0x1C

/**
 * Song state substructure which alternates between 2 via frame counter.
 **/
typedef struct {
    /* 0x0 */ s8 recentNote;
    /* 0x1 */ s8 storedSong;
    /* 0x2 */ s8 noteIndex;
    /* 0x3 */ UNK_TYPE1 pad3;
    /* 0x4 */ s8 playbackRecentNote;
    /* 0x5 */ u8 playbackState; // 1 while doing playback, is reset to 0 to show the "You Played X song" text.
    /* 0x6 */ u8 playbackNoteIndex;
    /* 0x7 */ UNK_TYPE1 pad7;
} SongFrameInfo; // size = 0x8

/**
 * Structure with some song state.
 *
 * Usually located at: 0x801FD43A
 **/
typedef struct {
    /* 0x00 */ SongFrameInfo frameInfo[2];
    /* 0x10 */ u16 frameCount;
    /* 0x12 */ s16 analogAngle; // Angle of analog stick, modifies sound.
    /* 0x14 */ UNK_TYPE1 pad14[0x14];
    /* 0x28 */ u8 hasPlayedNote; // 1 if has played note since using ocarina.
    /* 0x29 */ UNK_TYPE1 pad29[0x07];
    /* 0x30 */ u16 flags; // 0x37DF if all songs.
    /* 0x32 */ u8 noteIndex3;
    /* 0x33 */ UNK_TYPE1 pad33;
} SongInfo; // size = 0x34

/// =============================================================
/// Static Context
/// =============================================================

typedef struct {
    u8               unk_0x00[0x32];                 /* 0x0000 */
    s16              time_speed;                     /* 0x0032 */
    u8               unk_0x34[0x06];                 /* 0x0034 */
    s16              acceleration;                   /* 0x003A */
    u8               unk_0x3C[0x0E];                 /* 0x003C */
    s16              turn_speed;                     /* 0x004A */
    u8               unk_0x4E[0x50];                 /* 0x004C */
    s16              gravity;                        /* 0x009C */
    u8               unk_0x9E[0x72];                 /* 0x009E */
    u16              update_rate;                    /* 0x0110 */
} z2_static_ctxt_t;                                  /* 0x0112 */

/// =============================================================
/// Messagebox Context
/// =============================================================

// Font textures are loaded into here
typedef struct {
    /* 0x0000 */ u8 unk0[2][120][128];
    /* 0x7800 */ u8 unk7800[93][128];
} Font; // size = 0xA680

typedef struct {
    /* 0x00000 */ View view;
    /* 0x00168 */ Font font;
    /* 0x0A7E8 */ UNK_TYPE1 padA7E8[0x7200];
    /* 0x119E8 */ u8 currentMessageRaw[0x500]; // Length may be wrong.
    /* 0x11EE8 */ u32 messageDataOffset;
    /* 0x11EEC */ u32 messageDataLength;
    /* 0x11EF0 */ u8 unk11EF0;
    /* 0x11EF1 */ UNK_TYPE1 pad11EF1[0xF];
    /* 0x11F00 */ SongInfo* songInfo;
    /* 0x11F04 */ u16 currentMessageId;
    /* 0x11F06 */ u16 unk11F06;
    /* 0x11F08 */ UNK_TYPE1 pad11F08[0x2];
    /* 0x11F0A */ u8 unk11F0A;
    /* 0x11F0B */ UNK_TYPE1 pad11F0B[0x5];
    /* 0x11F10 */ u32 unk11F10;
    /* 0x11F14 */ UNK_TYPE1 pad11F14[0x4];
    /* 0x11F18 */ u8 unk11F18; // Related to horizontal alignment.
    /* 0x11F19 */ UNK_TYPE1 pad11F19[0x9];
    /* 0x11F22 */ u8 messageState1;
    /* 0x11F23 */ UNK_TYPE1 unk11F23;
    /* 0x11F24 */ u8 currentMessageDisplayed[0xC0]; // Length may be wrong.
    /* 0x11FE4 */ UNK_TYPE1 pad1FE4[0x8];
    /* 0x11FEC */ u16 currentMessageCharIndex;
    /* 0x11FEE */ u16 unk11FEE;
    /* 0x11FF0 */ UNK_TYPE1 pad11FF0[0xA];
    /* 0x11FFA */ u16 messageTextScreenY;
    /* 0x11FFC */ UNK_TYPE1 pad11FFC[0x1C];
    /* 0x12018 */ ColorRGB16 currentCharColor;
    /* 0x1201E */ s16 currentCharAlpha;
    /* 0x12020 */ u8 messageState2;
    /* 0x12021 */ u8 selection;
    /* 0x12022 */ UNK_TYPE1 pad12022;
    /* 0x12023 */ u8 messageState3;
    /* 0x12024 */ UNK_TYPE1 pad12024[0x4];
    /* 0x12028 */ u16 playbackSong;
    /* 0x1202A */ u16 unk1202A;
    /* 0x1202C */ u16 unk1202C;
    /* 0x1202E */ UNK_TYPE1 pad1202E[0x6];
    /* 0x12034 */ ColorRGB16 scoreLineColor;
    /* 0x1203A */ UNK_TYPE1 pad1203A[0x2];
    /* 0x1203C */ s16 scoreLineAlpha;
    /* 0x1203E */ UNK_TYPE1 pad1203E[0x6];
    /* 0x12044 */ s16 unk12044;
    /* 0x12046 */ UNK_TYPE1 pad12046[0x24];
    /* 0x1206A */ s16 messageBoxScreenY;
    /* 0x1206C */ UNK_TYPE1 pad1206C[0x18];
    /* 0x12084 */ void* messageTable;
    /* 0x12088 */ UNK_TYPE1 pad12088[0x8];
    /* 0x12090 */ s16 messageDataFile; // 0 = main file, 1 = credits file.
    /* 0x12092 */ UNK_TYPE1 pad12092[0x36];
    /* 0x120C8 */ ColorRGB16 normalCharColor;
    /* 0x120CE */ UNK_TYPE1 pad120CE[0xA];
} MessageContext; // size = 0x120D8

/// =============================================================
/// Game Structure
/// =============================================================

struct z2_game_s {
    GameState        state;                          /* 0x00000 */
    u16              scene_index;                    /* 0x000A4 */
    u8               scene_draw_id;                  /* 0x000A6 */
    u8               unk_0x000A7[0x09];              /* 0x000A7 */
    void            *scene_addr;                     /* 0x000B0 */
    u8               unk_0x00B4[0x04];               /* 0x000B4 */
    View             view_scene;                     /* 0x000B8 */
    z2_camera_t      cameras[4];                     /* 0x00220 */
    z2_camera_t     *active_cameras[4];              /* 0x00800 */
    s16              camera_cur;                     /* 0x00810 */
    s16              camera_next;                    /* 0x00812 */
    u8               unk_0x814[0x1C];                /* 0x00814 */
    z2_col_ctxt_t    col_ctxt;                       /* 0x00830 */
    z2_actor_ctxt_t  actor_ctxt;                     /* 0x01CA0 */
    u8               unk_0x1F24[0x04];               /* 0x01F24 */
    void            *cutscene_ptr;                   /* 0x01F28 */
    s8               cutscene_state;                 /* 0x01F2C */
    u8               unk_0x1F2D[0x29DB];             /* 0x01F2D */
    MessageContext   msgCtx;                         /* 0x04908 */
    u8               unk_0x169E0[0x8];               /* 0x169E0 */
    InterfaceContext interfaceCtx;                   /* 0x169E8 */
    PauseContext     pauseCtx;                       /* 0x16D30 */
    u8               unk_0x17000[0xD88];             /* 0x17000 */
    SceneContext     sceneContext;                   /* 0x17D88 */
    RoomContext      roomContext;                    /* 0x186E0 */
    u8               room_cnt;                       /* 0x18760 */
    u8               unk_0x18761[0xDF];              /* 0x18761 */
    u32              scene_frame_counter;            /* 0x18840 */
    u8               unk_0x18844[0x31];              /* 0x18844 */
    u8               scene_load_flag;                /* 0x18875 */
    u8               unk_0x18876[0x04];              /* 0x18876 */
    u16              entrance_index;                 /* 0x1887A, double check this offset. */
    u8               unk_0x1887C[0x2CE];             /* 0x1887C */
    u8               flag_0x18B4A;                   /* 0x18B4A */
};                                                   /* 0x18B4B */

/// =============================================================
/// Savefile Structure
/// =============================================================

typedef struct {
    /* 0x0 */ u16 transitionState;
    /* 0x2 */ u16 state;
    /* 0x4 */ u16 alphaTransition;
    /* 0x6 */ u16 previousState;
} ButtonsState; // size = 0x8

typedef union {
    struct {
        s8 b;
        s8 cLeft;
        s8 cDown;
        s8 cRight;
    };
    s8 buttons[0x04];
} SaveContextButtonSet;

typedef union {
    struct {
        u8         : 5;
        u8 map     : 1;
        u8 compass : 1;
        u8 bossKey : 1;
    };
    u8 value;
} SaveContextDungeonItems;

typedef union {
    struct {
        u32          : 16;
        u32 scene    : 7;
        u32 entrance : 5;
        u32 offset   : 4;
    };
    u32 value;
} SaveContextEntrance;

typedef union {
    struct {
        u16        : 10;
        u16 shield : 2;
        u16        : 2;
        u16 sword  : 2;
    };
    u16 value;
} SaveContextEquipment;

typedef union {
    struct {
        u16 hiddenOwl       : 1;
        u16                 : 4;
        u16 dungeonEntrance : 1;
        u16 stoneTower      : 1;
        u16 ikanaCanyon     : 1;
        u16 southernSwamp   : 1;
        u16 woodfall        : 1;
        u16 milkRoad        : 1;
        u16 clockTown       : 1;
        u16 mountainVillage : 1;
        u16 snowhead        : 1;
        u16 zoraCape        : 1;
        u16 greatBay        : 1;
    };
    u16 value;
} SaveContextOwlsActive;

typedef union {
    struct {
        u32 heartPiece        : 4;
        u32                   : 3;
        u32 lullabyIntro      : 1;
        u32                   : 5;
        u32 bombersNotebook   : 1;
        u32 sunsSong          : 1;
        u32 songOfStorms      : 1;
        u32 songOfSoaring     : 1;
        u32 eponasSong        : 1;
        u32 songOfHealing     : 1;
        u32 songOfTime        : 1;
        u32 sariasSong        : 1;
        u32 oathToOrder       : 1;
        u32 elegyOfEmptiness  : 1;
        u32 newWaveBossaNova  : 1;
        u32 goronLullaby      : 1;
        u32 sonataOfAwakening : 1;
        u32                   : 2;
        u32 twinmoldsRemains  : 1;
        u32 gyorgsRemains     : 1;
        u32 gohtsRemains      : 1;
        u32 odolwasRemains    : 1;
    };
    u32 value;
} SaveContextQuestStatus;

typedef union {
    struct {
        u32           : 9;
        u32 dekuNut   : 3;
        u32 dekuStick : 3;
        u32           : 3;
        u32 wallet    : 2;
        u32           : 6;
        u32 bombBag   : 3;
        u32 quiver    : 3;
    };
    u32 value;
} SaveContextUpgrades;

typedef struct {
    /* 0x00 */ u8 items[0x18];
    /* 0x18 */ u8 masks[0x18];
    /* 0x30 */ u8 quantities[0x18];
    /* 0x48 */ SaveContextUpgrades upgrades;
    /* 0x4C */ SaveContextQuestStatus questStatus;
    /* 0x50 */ SaveContextDungeonItems dungeonItems[0xA];
    /* 0x5A */ u8 dungeonKeys[0x9];
    /* 0x63 */ u8 defenseHearts;
    /* 0x64 */ u8 strayFairies[0xA];
    /* 0x6E */ char formName[0x8][0x3];
    /* 0x86 */ UNK_TYPE1 pad86[0x2];
} SaveContextInventory; // size = 0x88

typedef union {
    struct {
        /* 0x00 */ u32 chestFlags;
        /* 0x04 */ u32 switchFlags[2];
        /* 0x0C */ u32 clearedRooms;
        /* 0x10 */ u32 collectibleFlags;
    };
    u32 flags[5];
    u8 bytes[0x14];
} CycleSceneFlags; // size = 0x14

typedef union {
    struct {
        /* 0x00 */ u32 chestFlags;
        /* 0x04 */ u32 switchFlags[2];
        /* 0x0C */ u32 clearedRooms;
        /* 0x10 */ u32 collectibleFlags;
        /* 0x14 */ u32 unk14;
        /* 0x18 */ u32 unk18;
    };
    u32 flags[7];
    u8 bytes[0x1C];
} PermanentSceneFlags; // size = 0x1C

#define HasInfiniteMagic(Save) (((Save).perm.weekEventReg[0xE] & 8) != 0)
#define SetInfiniteMagic(Save) ((Save).perm.weekEventReg[0xE] |= 8)
#define HasGreatSpin(Save) ((Save).perm.weekEventReg[0x17])

typedef struct {
    /* 0x00 */ u8 zelda[6]; // Will always be "ZELDA3" for a valid save
    /* 0x06 */ UNK_TYPE1 pad6[0xA];
    /* 0x10 */ s16 maxLife;
    /* 0x12 */ s16 currentLife;
    /* 0x14 */ u8 magicLevel;
    /* 0x15 */ s8 currentMagic;
    /* 0x16 */ u16 rupees;
    /* 0x18 */ u32 tatlTimer;
    /* 0x1C */ u8 hasMagic;
    /* 0x1D */ u8 hasDoubleMagic;
    /* 0x1E */ u8 hasDoubleDefense;
    /* 0x1F */ UNK_TYPE1 pad1F[0x3];
    /* 0x22 */ SaveContextOwlsActive owlsHit;
    /* 0x24 */ UNK_TYPE1 pad48[0x4];
} SaveContext_struct1; // size = 0x28

typedef struct {
    /* 0x00 */ SaveContextButtonSet formButtonItems[4];
    /* 0x10 */ SaveContextButtonSet formButtonSlots[4];
    /* 0x20 */ SaveContextEquipment equipment;
} SaveContext_struct2; // size = 0x22

typedef struct {
    /* 0x0000 */ SaveContextEntrance entrance;
    /* 0x0004 */ u8 mask;
    /* 0x0005 */ u8 introFlag;
    /* 0x0006 */ u8 mashTimer;
    /* 0x0007 */ UNK_TYPE1 unk7;
    /* 0x0008 */ u32 cutscene;
    /* 0x000C */ u16 time;
    /* 0x000E */ u16 owlLoad;
    /* 0x0010 */ u32 isNight;
    /* 0x0014 */ s32 timeSpeed;
    /* 0x0018 */ u32 day;
    /* 0x001C */ u32 daysElapsed;
    /* 0x0020 */ u8 currentForm;
    /* 0x0021 */ UNK_TYPE1 pad21;
    /* 0x0022 */ u8 tatlFlag;
    /* 0x0023 */ u8 owlSave;
    /* 0x0024 */ SaveContext_struct1 unk24;
    /* 0x004C */ SaveContext_struct2 unk4C;
    /* 0x006E */ UNK_TYPE1 pad6E[0x2];
    /* 0x0070 */ SaveContextInventory inv;
    /* 0x00F8 */ PermanentSceneFlags sceneFlags[120];
    /* 0x0E18 */ UNK_TYPE1 padE18[0x60];
    /* 0x0E78 */ u32 pictoFlags0;
    /* 0x0E7C */ u32 pictoFlags1;
    /* 0x0E80 */ UNK_TYPE1 padE80[0x24];
    /* 0x0EA4 */ u8 minimapBitfield[0x1C]; // Bit per scene indicating whether minimap is enabled.
    /* 0x0EC0 */ u16 skullTokens[2];
    /* 0x0EC4 */ UNK_TYPE1 padEC4[0x1A];
    /* 0x0EDE */ u16 bankRupees;
    /* 0x0EE0 */ UNK_TYPE1 padEE0[0x10];
    /* 0x0EF0 */ u32 lotteryGuess;
    /* 0x0EF4 */ UNK_TYPE1 padEF4[0x04];
    // [0xF0C] & 0x01 = Woodfall Temple Raised
    // [0xF0C] & 0x02 = Swamp Clear
    // [0xF19] & 0x80 = Mountain Clear
    // [0xF2C] & 0x20 = Canyon Clear
    // [0xF2F] & 0x80 = Ocean Clear
    /* 0x0EF8 */ u8 weekEventReg[100];
    /* 0x0F5C */ u32 mapsVisited;
    /* 0x0F60 */ u32 worldMapVisible; // 0x00007FFF is full map.
    /* 0x0F64 */ UNK_TYPE1 padF64[0x88];
    /* 0x0FEC */ u8 lotteryCodes[9];
    /* 0x0FF5 */ u8 spiderHouseMaskOrder[6];
    /* 0x0FFB */ u8 bomberCode[5];
    /* 0x1000 */ UNK_TYPE1 pad1000[0xA];
    /* 0x100A */ u16 checksum;
} SaveContextPerm; // size = 0x100C

// Save Context that is only stored in an owl save
typedef struct {
    /* 0x0000 */ u8 eventInf[8];
    // (cleared if you leave temple)
    // [5] & 0x40 = Gyorg Intro cutscene seen
    // [5] & 0x20 = Twinmold Intro cutscene seen
    // [5] & 0x10 = Odolwa Intro cutscene seen
    // [5] & 0x08 = Goht Unfrozen cutscene seen
    // [6] & 0x04 = Goht Intro cutscene seen
    // [6] & 0x02 = Majora Intro cutscene seen
    /* 0x0008 */ UNK_TYPE1 pad8[0x2];
    /* 0x000A */ u16 jinxCounter;
    /* 0x000C */ s16 rupeeCounter;
    /* 0x000E */ UNK_TYPE1 padE[0xC6];
    /* 0x00D4 */ u8 pictoboxPhoto[0x2BC0];
} SaveContextOwl; // size = 0x2C94

// Extra information in the save context that is not saved
typedef struct {
    /* 0x000 */ s32 fileIndex;
    /* 0x004 */ UNK_TYPE1 pad4[0x4];
    /* 0x008 */ u32 titleSetupIndex;
    /* 0x00C */ s32 sceneSetupIndex;
    /* 0x010 */ s32 voidFlag;
    /* 0x014 */ UNK_TYPE1 pad14[0x2E];
    /* 0x042 */ s16 unk42;
    /* 0x044 */ UNK_TYPE1 pad44[0x43];
    // u16 64 = after death entrance
    /* 0x087 */ s8 unk87;
    /* 0x088 */ UNK_TYPE1 pad88[0xA8];
    /* 0x130 */ u8 timers[0x40];
    /* 0x170 */ UNK_TYPE1 pad170[0x106];
    /* 0x276 */ u8 unk276;
    /* 0x277 */ UNK_TYPE1 unk277;
    /* 0x278 */ u8 buttonsUsable[5];
    /* 0x27D */ UNK_TYPE1 pad27D[0x3];
    /* 0x280 */ ButtonsState buttonsState;
    /* 0x288 */ s16 magicConsumeState;
    /* 0x28A */ UNK_TYPE1 pad28A[0x4];
    /* 0x28E */ u16 magicMeterSize;
    /* 0x290 */ UNK_TYPE1 pad290[0x2];
    /* 0x292 */ s16 magicConsumeCost;
    /* 0x294 */ UNK_TYPE1 pad294[0x6];
    /* 0x29A */ u16 minigameCounter[2];
    /* 0x29E */ UNK_TYPE1 pad29E[0xE];
    /* 0x2AC */ u8 cutsceneTrigger;
    /* 0x2AD */ UNK_TYPE1 pad2AD[0x5];
    /* 0x2B2 */ u16 environmentTime;
    /* 0x2B4 */ UNK_TYPE1 pad2B4[0x4];
    /* 0x2B8 */ s16 unk2b8;
    /* 0x2BA */ UNK_TYPE1 pad2BA[0xA];
    /* 0x2C4 */ f32 unk2C4;
    /* 0x2C8 */ CycleSceneFlags cycleSceneFlags[120];
} SaveContextExtra; // size = 0xC28

/**
 * Savefile structure.
 **/
typedef struct {
    /* 0x0000 */ SaveContextPerm perm;
    /* 0x100C */ SaveContextOwl owl;
    /* 0x3CA0 */ SaveContextExtra extra;
    // Todo: Move these fields later?
    /* 0x48C8 */ UNK_TYPE1 pad48C8[0x1010];
    /* 0x58D8 */ ColorRGB16 heartDdBeatingRgb;
    /* 0x58DE */ UNK_TYPE1 pad58DE[0x12];
    /* 0x58F0 */ ColorRGB16 heartDdRgb;
} SaveContext; // size = 0x58F6

/// =============================================================
/// Actor Structures
/// =============================================================

typedef void(*ActorFunc)(struct Actor *this, z2_game_t *ctxt);

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

/**
 * Actor.
 **/
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
    /* 0x07C */ z2_col_poly_t *wallPoly;
    /* 0x080 */ z2_col_poly_t *floorPoly;
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

/// =============================================================
/// Link Actor
/// =============================================================

/**
 * Macro for getting the ActorPlayer pointer from the z2_game_t pointer.
 **/
#define Z2_LINK(GAME) ((ActorPlayer*)((GAME->actor_ctxt.actor_list[2].first)))

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

/**
 * Link actor.
 **/
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

/// =============================================================
/// Other Actors
/// =============================================================

/**
 * En_Box actor (Treasure Chest).
 **/
typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ UNK_TYPE1 pad144[0xA8];
    /* 0x1EC */ s16 animCounter; // Used for fancy light animation?
    /* 0x1EE */ u8 unk1EE;
    /* 0x1EF */ u8 unk1EF;
    /* 0x1F0 */ u8 unk1F0;
    /* 0x1F1 */ u8 chestType;
    /* 0x1F2 */ UNK_TYPE1 pad1F2[0x28];
    /* 0x21A */ s16 unk21A;
    /* 0x21C */ u32 giIndex;
    /* 0x220 */ u32 unk220;
} ActorEnBox; // size = 0x224?

/**
 * En_Elf actor.
 **/
typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ UNK_TYPE1 pad144[0x116];
    /* 0x25A */ u16 animTimer; // Counts from 0 to 0x5F as "fairy heal" animation progresses.
} ActorEnElf; // size = 0x25C?

/**
 * En_Test4 actor.
 **/
typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ u8 daynight;
    /* 0x145 */ u8 unk145;
    /* 0x146 */ u16 timerBoundaries[0x3];
} ActorEnTest4; // size = 0x14C?

/**
 * En_Elforg actor (stray fairy).
 **/
typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ u8 unk144;
    /* 0x145 */ u8 unk145;
    /* 0x146 */ u8 unk146;
    /* 0x147 */ u8 unk147;
    /* 0x148 */ void* unk148;
    /* 0x14C */ u32 unk14C; // Looks like segmented address into Object data.
    /* 0x150 */ u32 unk150;
    /* 0x154 */ f32 unk154[0x4];
    /* 0x164 */ void* unk164; // Points into struct (field 0x188).
    /* 0x168 */ void* unk168;
    /* 0x16C */ UNK_TYPE1 pad16C[0x8];
    /* 0x174 */ void* func174;
    /* 0x178 */ UNK_TYPE1 pad178[0x9E];
    /* 0x216 */ s16 unk216;
    /* 0x218 */ s16 color;
    /* 0x21A */ u16 unk21A;
    /* 0x21C */ u32 frameCount;
    /* 0x220 */ u32 unk220;
    /* 0x224 */ f32 unk224;
    /* 0x228 */ UNK_TYPE1 pad228[0x4];
    /* 0x22C */ void* unk22C;
} ActorEnElforg; // size = 0x230?

/**
 * En_Akindonuts actor (Business Scrub)
 **/
typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ UNK_TYPE1 pad144[0x1E8];
    /* 0x32C */ u16 state; // Not sure what else to call this, or what else it does.
    /* 0x32E */ UNK_TYPE1 pad32E[0xE];
    /* 0x33C */ u16 lastMessageId;
} ActorEnAkindonuts; // size = ?

/**
 * En_GirlA actor (Shop Inventory Data)
 **/
typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ UNK_TYPE1 pad144[0x5A];
    /* 0x19E */ u16 giIndex;
} ActorEnGirlA; // size = ?

/**
 * En_Toto actor (Toto)
 **/
typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ UNK_TYPE1 pad144[0x16C];
    /* 0x2B0 */ u8 funcIndex;
    /* 0x2B1 */ u8 frameCount;
    /* 0x2B2 */ u8 actorCutscene;
    /* 0x2B3 */ u8 songFlags;
    /* 0x2B4 */ UNK_TYPE1 pad2B4[0x4];
    /* 0x2B8 */ void* curState;
    /* 0x2BC */ UNK_TYPE1 pad2BC[0x4];
    /* 0x2C0 */ void* unk2C0;
    /* 0x2C4 */ Actor* stagelights;
    /* 0x2C8 */ UNK_TYPE1 pad2C8[0x8];
} ActorEnToto; // size = 0x2D0

/**
 * En_Suttari (Sakon)
 **/
typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ UNK_TYPE1 pad144[0x4];
    /* 0x148 */ void* function;
    /* 0x14C */ UNK_TYPE1 pad14C[0x98];
    /* 0x1E4 */ u16 unk1E4;
    /* 0x1E6 */ u16 flags;
    /* 0x1E8 */ UNK_TYPE1 pad1E8[0x10];
    /* 0x1F8 */ s32 escapeStatus;
    /* 0x1FC */ UNK_TYPE1 pad1FC[0x254];
    /* 0x450 */ u32 runningState;
    /* 0x454 */ UNK_TYPE1 pad454[0x2];
    /* 0x456 */ s16 actorCutscene1;
    /* 0x458 */ s16 actorCutscene2;
    /* 0x45A */ UNK_TYPE1 pad45A[0x2];
} ActorEnSuttari; // size = 0x45C

typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ UNK_TYPE1 pad144[0x18];
    /* 0x15C */ u8 pathProgress;
    /* 0x15D */ s8 speedMultiplier;
    /* 0x15E */ u8 unk15E;
    /* 0x15F */ u8 unk15F;
    /* 0x160 */ UNK_TYPE1 pad160[0x8];
} ActorObjBoat; // size = 0x168

/**
 * Bg_Ingate (Boat Cruise Canoe)
 **/
typedef struct {
    /* 0x000 */ Actor base;
    /* 0x144 */ UNK_TYPE1 pad144[0x18];
    /* 0x15C */ void* function;
    /* 0x160 */ u16 flags;
    /* 0x162 */ UNK_TYPE1 pad162[0x2];
    /* 0x164 */ void* pathList;
    /* 0x168 */ s16 speed;
    /* 0x16A */ UNK_TYPE1 pad16A[0x26];
} ActorBgIngate; // size = 0x190

/// =============================================================
/// Actor Cutscene
/// =============================================================

typedef struct {
    /* 0x0 */ s16 priority; // Lower means higher priority. -1 means it ignores priority
    /* 0x2 */ s16 length;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 additionalCutscene;
    /* 0xA */ u8 sound;
    /* 0xB */ u8 unkB;
    /* 0xC */ s16 unkC;
    /* 0xE */ u8 unkE;
    /* 0xF */ u8 letterboxSize;
} ActorCutscene; // size = 0x10

/// =============================================================
/// Arenas
/// =============================================================

typedef struct z2_arena_node    z2_arena_node_t;
typedef struct z2_arena         z2_arena_t;

struct z2_arena_node {
    u16              magic;                          /* 0x0000 */
    u16              free;                           /* 0x0002 */
    u32              size;                           /* 0x0004 */
    z2_arena_node_t *next;                           /* 0x0008 */
    z2_arena_node_t *prev;                           /* 0x000C */
};                                                   /* 0x0010 */

struct z2_arena {
    z2_arena_node_t *first;                          /* 0x0000 */
    void            *start;                          /* 0x0004 */
    void            *unk_0x08;                       /* 0x0008 */
    void            *unk_0x0C;                       /* 00000C */
};                                                   /* 0x0010 */

/// =============================================================
/// Overlays & Tables
/// =============================================================

typedef struct {
    u32              vrom_start;                     /* 0x0000 */
    u32              vrom_end;                       /* 0x0004 */
    u32              prom_start;                     /* 0x0008 */
    u32              prom_end;                       /* 0x000C */
} z2_file_table_t;                                   /* 0x0010 */

typedef struct {
    /* 0x0000 */ void *loadedRamAddr;
    /* 0x0004 */ u32 vromStart;
    /* 0x0008 */ u32 vromEnd;
    /* 0x000C */ u32 vramStart;
    /* 0x0010 */ u32 vramEnd;
    /* 0x0014 */ UNK_TYPE4 unk14;
    /* 0x0018 */ FuncPtr init;
    /* 0x001C */ FuncPtr destroy;
    /* 0x0020 */ UNK_TYPE4 unk20;
    /* 0x0024 */ UNK_TYPE4 unk24;
    /* 0x0028 */ UNK_TYPE4 unk28;
    /* 0x002C */ u32 instanceSize;
} GameStateOverlay; // size = 0x30

typedef union {
    struct {
        /* 0x000 */ GameStateOverlay reset;
        /* 0x030 */ GameStateOverlay mapSelect;
        /* 0x060 */ GameStateOverlay n64Logo;
        /* 0x090 */ GameStateOverlay gameplay;
        /* 0x0C0 */ GameStateOverlay titleScreen;
        /* 0x0F0 */ GameStateOverlay fileSelect;
        /* 0x120 */ GameStateOverlay newDay;
    };
    GameStateOverlay states[7];
} GameStateTable; // size = 0x150

typedef struct {
    /* 0x0 */ u32 vromStart;
    /* 0x4 */ u32 vromEnd;
} ObjectFileTableEntry; // size = 0x8

typedef struct {
    /* 0x00 */ void* loadedRamAddr;
    /* 0x04 */ u32 vromStart;
    /* 0x08 */ u32 vromEnd;
    /* 0x0C */ u32 vramStart;
    /* 0x10 */ u32 vramEnd;
    /* 0x14 */ UNK_TYPE1 pad14[0x4];
    /* 0x18 */ char* filename;
} PlayerOverlay; // size = 0x1C

typedef void (*z2_DrawGi_proc)(z2_game_t *game, u32 graphic_id_minus_1);

typedef struct {
    z2_DrawGi_proc   function;                       /* 0x0000 */
    u32              dl_seg_addrs[0x08];             /* 0x0004, Segment addresses used with G_DL instruction. */
} z2_gi_graphic_table_t;                             /* 0x0024 */

/// =============================================================
/// File Select Context
/// =============================================================

typedef struct {
    u8               unk_0x00[0x8D4];                /* 0x0000 */
    u16              rupee_colors[0x09];             /* 0x08D4 */
    u8               unk_0x8E6[0x16];                /* 0x08E6 */
    ColorRGB16       heart_rgb[0x02];                /* 0x08FC */
    ColorRGB16       heart_under_rgb[0x02];          /* 0x0908 */
    u8               unk_0x914[0x7AC];               /* 0x0914 */
} z2_file_select_ctxt_t;                             /* 0x10C0 */

/// =============================================================
/// Misc & Unknown
/// =============================================================

typedef struct {
    u32              direct_reference;               /* 0x0000 */
    u32              nintendo_logo;                  /* 0x0004 */
    u32              current_scene;                  /* 0x0008 */
    u32              current_room;                   /* 0x000C */
    u32              gameplay_keep;                  /* 0x0010 */
    u32              gameplay_dungeon_field_keep;    /* 0x0014 */
    u32              current_object;                 /* 0x0018 */
    u32              link_animation;                 /* 0x001C */
    u32              unk_0x20;                       /* 0x0020 */
    u32              unk_0x24;                       /* 0x0024 */
    u32              current_mask;                   /* 0x0028 */
    u32              unk_0x2C;                       /* 0x002C */
    u32              unk_0x30;                       /* 0x0030 */
    u32              unk_0x34;                       /* 0x0034 */
    u32              z_buffer;                       /* 0x0038 */
    u32              frame_buffer;                   /* 0x003C */
} z2_segment_t;                                      /* 0x0040 */

typedef struct {
    union {
        u16          digits[8];                      /* 0x0000 */
        struct {
            u16      minutes[2];                     /* 0x0000 */
            u16      sep1;                           /* 0x0004 */
            u16      seconds[2];                     /* 0x0006 */
            u16      sep2;                           /* 0x000A */
            u16      milliseconds[2];                /* 0x000C */
        };
    };
    u16              beep_seconds;                   /* 0x0010, previous seconds[1] value that had a beep. */
                                                     /* Likely used to determine when to do the next beep. */
} z2_timer_digits_t;                                 /* 0x0012 */

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ z2_game_t *globalContext;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
} struct_801BD8B0; // size = 0x18

typedef struct {
    /* 0x00 */ PlayerOverlay kaleidoScope; // VRAM: [0x808160A0, 0x8082DA90)
    /* 0x1C */ PlayerOverlay playerActor; // VRAM: [0x8082DA90, 0x80862B70)
    /* 0x38 */ void* start; // RAM start address to use.
    /* 0x3C */ PlayerOverlay* selected; // Points to selected overlay.
} struct_801D0B70; // size = 0x40

/// =============================================================
/// Defines & Prototypes
/// =============================================================

/* Virtual File Addresses */
#define z2_item_texture_file             0xA36C10

/* Data Addresses */
#define z2_arena_addr                    0x8009CD20
#define z2_file_table_addr               0x8009F8B0
#define z2_actor_ovl_table_addr          0x801AEFD0
#define z2_gi_graphic_table_addr         0x801BB170 /* Get-Item graphics table. */
#define z2_gamestate_addr                0x801BD910
#define z2_item_segaddr_table_addr       0x801C1E6C /* Segment address table used for item textures. */
#define z2_object_table_addr             0x801C2740
#define z2_song_notes_addr               0x801CFC98
#define z2_file_addr                     0x801EF670
#define z2_game_arena_addr               0x801F5100
#define z2_segment_addr                  0x801F8180
#define z2_static_ctxt_addr              0x803824D0
#define z2_ctxt_addr                     0x803E6B20
#define z2_game_addr                     z2_ctxt_addr
#define z2_link_addr                     0x803FFDB0

/* Data */
#define z2_actor_ovl_table               ((ActorOverlay*)            z2_actor_ovl_table_addr)
#define z2_ctxt                          (*(z2_ctxt_t*)              z2_ctxt_addr)
#define z2_file                          (*(SaveContext*)            z2_file_addr)
#define z2_file_table                    ((z2_file_table_t*)         z2_file_table_addr)
#define z2_game                          (*(z2_game_t*)              z2_game_addr)
#define z2_gamestate                     (*(GameStateTable*)         z2_gamestate_addr)
#define z2_gi_graphic_table              ((z2_gi_graphic_table_t*)   z2_gi_graphic_table_addr)
#define z2_link                          (*(ActorPlayer*)            z2_link_addr)
#define z2_obj_table                     ((ObjectFileTableEntry*)    z2_object_table_addr)
#define z2_segment                       (*(z2_segment_t*)           z2_segment_addr)
#define z2_song_notes                    (*(SongNotes*)              z2_song_notes_addr)
#define z2_static_ctxt                   (*(z2_static_ctxt_t*)       z2_static_ctxt_addr)

/* Data (non-struct) */
#define z2_item_segaddr_table            ((u32*)                     z2_item_segaddr_table_addr)

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

/* Relocatable Functions (Pause Menu) */
#define z2_PauseDrawItemIcon_vram        0x80821AD4

/* Relocatable Functions (Player Actor) */
#define z2_LinkDamage_vram               0x80833B18
#define z2_LinkInvincibility_vram        0x80833998
#define z2_UseItem_vram                  0x80831990

#define z2_PerformEnterWaterEffects_vram 0x8083B8D0
#define z2_PlayerHandleBuoyancy_vram     0x808475B4

/* Relocatable Types (VRAM) */
#define z2_file_select_ctxt_vram         0x80813DF0

typedef void (*z2_PerformEnterWaterEffects_proc)(z2_game_t *game, ActorPlayer *link);
typedef void (*z2_PlayerHandleBuoyancy_proc)(ActorPlayer *link);

/* Function Prototypes */
typedef int (*z2_CanInteract_proc)(z2_game_t *game);
typedef int (*z2_CanInteract2_proc)(z2_game_t *game, ActorPlayer *link);
typedef void (*z2_DrawButtonAmounts_proc)(z2_game_t *game, u32 arg1, u16 alpha);
typedef void (*z2_DrawBButtonIcon_proc)(z2_game_t *game);
typedef void (*z2_DrawCButtonIcons_proc)(z2_game_t *game);
typedef u32 (*z2_GetFloorPhysicsType_proc)(void *arg0, void *arg1, u8 arg2);
typedef f32* (*z2_GetMatrixStackTop_proc)();
typedef void (*z2_LinkDamage_proc)(z2_game_t *game, ActorPlayer *link, u32 type, u32 arg3);
typedef void (*z2_LinkInvincibility_proc)(ActorPlayer *link, u8 frames);
typedef void (*z2_PlaySfx_proc)(u32 id);
typedef Actor* (*z2_SpawnActor_proc)(z2_actor_ctxt_t *actor_ctx, z2_game_t *game, u16 id,
                                          f32 x, f32 y, f32 z, u16 rx, u16 ry, u16 rz, u16 variable);
typedef void (*z2_UpdateButtonUsability_proc)(z2_game_t *game);
typedef void (*z2_UseItem_proc)(z2_game_t *game, ActorPlayer *link, u8 item);
typedef void (*z2_WriteHeartColors_proc)(z2_game_t *game);
typedef void (*z2_RemoveItem_proc)(u32 item, u8 slot);
typedef void (*z2_ToggleSfxDampen_proc)(int enable);
typedef void (*z2_HandleInputVelocity_proc)(f32 *linear_velocity, f32 input_velocity, f32 increaseBy, f32 decreaseBy);
typedef bool (*z2_SetGetItemLongrange_proc)(Actor *actor, z2_game_t *game, u16 gi_index);

/* Function Prototypes (Scene Flags) */
// TODO parameters
typedef void (*z2_get_generic_flag_proc)();
typedef void (*z2_set_generic_flag_proc)();
typedef void (*z2_remove_generic_flag_proc)(z2_game_t *game, s8 flag);
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
typedef void (*z2_ActorProc_proc)(Actor *actor, z2_game_t *game);
typedef void (*z2_ActorRemove_proc)(z2_actor_ctxt_t *ctxt, Actor *actor, z2_game_t *game);
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
typedef void (*z2_ActorDraw_proc)(Actor *actor, z2_game_t *game);
typedef void (*z2_BaseDrawGiModel_proc)(z2_game_t *game, u32 graphic_id_minus_1);
typedef void (*z2_CallDList_proc)(GraphicsContext *gfx);
typedef void (*z2_PreDraw_proc)(Actor *actor, z2_game_t *game, u32 unknown);

/* Function Prototypes (File Loading) */
typedef s32 (*z2_RomToRam_proc)(u32 src, void *dst, u32 length);
typedef s16 (*z2_GetFileNumber_proc)(u32 vrom_addr);
typedef u32 (*z2_GetFilePhysAddr_proc)(u32 vrom_addr);
typedef z2_file_table_t* (*z2_GetFileTable_proc)(u32 vrom_addr);
typedef void (*z2_LoadFile_proc)(DmaParams *loadfile);
typedef void (*z2_LoadFileFromArchive_proc)(u32 phys_file, u8 index, u8 *dest, u32 length);
typedef void (*z2_LoadVFileFromArchive_proc)(u32 virt_file, u8 index, u8 *dest, u32 length);
typedef void (*z2_ReadFile_proc)(void *mem_addr, u32 vrom_addr, u32 size);

typedef void (*z2_Yaz0_LoadAndDecompressFile_proc)(u32 prom_addr, void *dest, u32 length);

/* Function Prototypes (Get Item) */
typedef void (*z2_SetGetItem_proc)(Actor *actor, z2_game_t *game, s32 unk2, u32 unk3);
typedef void (*z2_GiveItem_proc)(z2_game_t *game, u8 item_id);
typedef void (*z2_GiveMap_proc)(u32 map_index);

/* Function Prototypes (HUD) */
typedef void (*z2_HudSetAButtonText_proc)(z2_game_t *game, u16 text_id);
typedef void (*z2_InitButtonNoteColors_proc)(z2_game_t *game);
typedef void (*z2_ReloadButtonTexture_proc)(z2_game_t *game, u8 idx);
typedef void (*z2_UpdateButtonsState_proc)(u32 state);

/* Function Prototypes (Math) */
typedef f32 (*z2_Math_Sins_proc)(s16 angle);
typedef f32 (*z2_Math_Vec3f_DistXZ_proc)(Vec3f *p1, Vec3f *p2);

/* Function Prototypes (Objects) */
typedef s8 (*z2_GetObjectIndex_proc)(const SceneContext *ctxt, u16 object_id);

/* Function Prototypes (OS) */
typedef void (*z2_memcpy_proc)(void *dest, const void *src, size_t size);

/* Function Prototypes (Pause Menu) */
typedef void (*z2_PauseDrawItemIcon_proc)(GraphicsContext *gfx, u32 seg_addr, u16 width, u16 height, u16 quad_vtx_idx);

/* Function Prototypes (RNG) */
typedef u32 (*z2_RngInt_proc)();
typedef void (*z2_RngSetSeed_proc)(u32 seed);

/* Function Prototypes (Rooms) */
typedef void (*z2_LoadRoom_proc)(z2_game_t *game, RoomContext *room_ctxt, uint8_t room_id);
typedef void (*z2_UnloadRoom_proc)(z2_game_t *game, RoomContext *room_ctxt);

/* Function Prototypes (Sound) */
typedef void (*z2_SetBGM2_proc)(u16 bgm_id);

/* Function Prototypes (Text) */
typedef void (*z2_ShowMessage_proc)(z2_game_t *game, u16 message_id, u8 something); // TODO figure out something?

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

#endif // Z2_H
