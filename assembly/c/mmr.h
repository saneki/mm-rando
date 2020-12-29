#ifndef MMR_H
#define MMR_H

#include <stdbool.h>
#include <z2.h>

#define MMR_ChestTableFileIndex (*(u32*)(0x80144968))
#define MMR_GiTableFileIndex (*(u32*)(0x8014496C))

// MMR get-item table entry.
typedef struct {
    /* 0x0 */ u8 item;
    /* 0x1 */ u8 flag;
    /* 0x2 */ u8 graphic;
    /* 0x3 */ u8 type;
    /* 0x4 */ u16 message;
    /* 0x6 */ u16 object;
} GetItemEntry; // size = 0x8

GetItemEntry* MMR_GetGiEntry(u16 index);
void MMR_Init(void);
u16 MMR_GetNewGiIndex(GlobalContext* ctxt, Actor* actor, u16 giIndex, bool grant);

// Function Addresses.
#define MMR_LoadGiEntry_Addr 0x801449A4
#define MMR_GetGiFlag_Addr   0x80144A28
#define MMR_SetGiFlag_Addr   0x801449D4

// Function Prototypes.
typedef bool(*MMR_GetGiFlag_Func)(u32 giIndex);
typedef bool(*MMR_SetGiFlag_Func)(u32 giIndex);
typedef GetItemEntry*(*MMR_LoadGiEntry_Func)(u32 giIndex);

// Functions.
#define MMR_LoadGiEntry ((MMR_LoadGiEntry_Func) MMR_LoadGiEntry_Addr)
#define MMR_GetGiFlag   ((MMR_GetGiFlag_Func)   MMR_GetGiFlag_Addr)
#define MMR_SetGiFlag   ((MMR_SetGiFlag_Func)   MMR_SetGiFlag_Addr)

// Magic number for MMRConfig: "MMRC"
#define MMR_CONFIG_MAGIC 0x4D4D5243

typedef struct {
    /* 0x000 */ u16 cycleRepeatable[0x80];
    /* 0x100 */ u16 cycleRepeatableLength;
    /* 0x102 */ u16 bottleRedPotion;
    /* 0x104 */ u16 bottleGoldDust;
    /* 0x106 */ u16 bottleMilk;
    /* 0x108 */ u16 bottleChateau;
    /* 0x10A */ u16 swordKokiri;
    /* 0x10C */ u16 swordRazor;
    /* 0x10E */ u16 swordGilded;
    /* 0x110 */ u16 magicSmall;
    /* 0x112 */ u16 magicLarge;
    /* 0x114 */ u16 walletAdult;
    /* 0x116 */ u16 walletGiant;
    /* 0x118 */ u16 bombBagSmall;
    /* 0x11A */ u16 bombBagBig;
    /* 0x11C */ u16 bombBagBiggest;
    /* 0x11E */ u16 quiverSmall;
    /* 0x120 */ u16 quiverLarge;
    /* 0x122 */ u16 quiverLargest;
} MMRLocations; // size = 0x124

typedef struct {
    /* 0x00 */ u8 ids[0x10]; // Probably don't need much more than this, but can increase later if we need to.
    /* 0x10 */ u16 length;
} ExtraStartingItems; // size = 0x12

typedef union {
    struct {
        u8          : 2;
        u8 canyon   : 1;
        u8 ocean    : 1;
        u8 ranch    : 1;
        u8 mountain : 1;
        u8 swamp    : 1;
        u8 town     : 1;
    };
    u8 value;
} ExtraStartingMaps; // size = 0x1

// Data about the MMR Get Item Table
struct MMRConfig {
    /* 0x000 */ u32 magic;
    /* 0x004 */ u32 version;
    /* 0x008 */ MMRLocations locations;
    /* 0x12C */ ExtraStartingMaps extraStartingMaps;
    /* 0x12D */ u8 unused12D; // Padding.
    /* 0x12E */ ExtraStartingItems extraStartingItems;
}; // size = 0x140

extern struct MMRConfig MMR_CONFIG;

#endif // MMR_H
