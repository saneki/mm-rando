#include <z2.h>
#include "Misc.h"
#include "MMR.h"
#include "Util.h"

struct MMRConfig MMR_CONFIG = {
    .magic = MMR_CONFIG_MAGIC,
    .version = 1,
    .locations = {
        .cycleRepeatableLength = 0x80,
        .bottleRedPotion = 0x59,
        .bottleChateau = 0x6F,
        .bottleMilk = 0x60,
        .bottleGoldDust = 0x6A,
        .swordKokiri = 0x37,
        .swordRazor = 0x38,
        .swordGilded = 0x39,
        .magicSmall = 0x12C,
        .magicLarge = 0x12E,
        .walletAdult = 0x08,
        .walletGiant = 0x09,
        .bombBagSmall = 0x1B,
        .bombBagBig = 0x1C,
        .bombBagBiggest = 0x1D,
        .quiverSmall = 0x22,
        .quiverLarge = 0x23,
        .quiverLargest = 0x24,
    },
};

static GetItemEntry* gGiTable = NULL;

static void LoadGiTable(void) {
    // Use gi-table file index to get dmadata entry.
    u32 index = MMR_GiTableFileIndex;
    DmaEntry entry = dmadata[index];
    u32 size = entry.vromEnd - entry.vromStart;
    // Load the gi-table table from file into buffer.
    gGiTable = (GetItemEntry*)Util_HeapAlloc(size);
    z2_ReadFile(gGiTable, entry.vromStart, size);
}

GetItemEntry* MMR_GetGiEntry(u16 index) {
    return &gGiTable[index - 1];
}

bool MMR_CheckBottleAndGetGiFlag(u16 giIndex, u16* newGiIndex) {
    if (giIndex == MMR_CONFIG.locations.bottleRedPotion) {
        giIndex = 0x5B;
    } else if (giIndex == MMR_CONFIG.locations.bottleChateau) {
        giIndex = 0x91;
    } else if (giIndex == MMR_CONFIG.locations.bottleMilk) {
        giIndex = 0x92;
    } else if (giIndex == MMR_CONFIG.locations.bottleGoldDust) {
        giIndex = 0x93;
    }
    *newGiIndex = giIndex;
    return MMR_GetGiFlag(giIndex);
}

u16 MMR_CheckProgressiveUpgrades(u16 giIndex) {
    if (giIndex == MMR_CONFIG.locations.swordKokiri || giIndex == MMR_CONFIG.locations.swordRazor || giIndex == MMR_CONFIG.locations.swordGilded) {
        if (gSaveContext.perm.unk4C.equipment.sword == 0) {
            return MMR_CONFIG.locations.swordKokiri;
        }
        if (gSaveContext.perm.unk4C.equipment.sword == 1) {
            return MMR_CONFIG.locations.swordRazor;
        }
        return MMR_CONFIG.locations.swordGilded;
    }
    if (giIndex == MMR_CONFIG.locations.magicSmall || giIndex == MMR_CONFIG.locations.magicLarge) {
        if (gSaveContext.perm.unk24.hasMagic == 0) {
            return MMR_CONFIG.locations.magicSmall;
        }
        return MMR_CONFIG.locations.magicLarge;
    }
    if (giIndex == MMR_CONFIG.locations.walletAdult || giIndex == MMR_CONFIG.locations.walletGiant) {
        if (gSaveContext.perm.inv.upgrades.wallet == 0) {
            return MMR_CONFIG.locations.walletAdult;
        }
        return MMR_CONFIG.locations.walletGiant;
    }
    if (giIndex == MMR_CONFIG.locations.bombBagSmall || giIndex == MMR_CONFIG.locations.bombBagBig || giIndex == MMR_CONFIG.locations.bombBagBiggest) {
        if (gSaveContext.perm.inv.upgrades.bombBag == 0) {
            return MMR_CONFIG.locations.bombBagSmall;
        }
        if (gSaveContext.perm.inv.upgrades.bombBag == 1) {
            return MMR_CONFIG.locations.bombBagBig;
        }
        return MMR_CONFIG.locations.bombBagBiggest;
    }
    if (giIndex == MMR_CONFIG.locations.quiverSmall || giIndex == MMR_CONFIG.locations.quiverLarge || giIndex == MMR_CONFIG.locations.quiverLargest) {
        if (gSaveContext.perm.inv.upgrades.quiver == 0) {
            return MMR_CONFIG.locations.quiverSmall;
        }
        if (gSaveContext.perm.inv.upgrades.quiver == 1) {
            return MMR_CONFIG.locations.quiverLarge;
        }
        return MMR_CONFIG.locations.quiverLargest;
    }
    return giIndex;
}

u16 MMR_GetNewGiIndex(GlobalContext* ctxt, Actor* actor, u16 giIndex, bool grant) {
    if (gSaveContext.perm.cutscene != 0) {
        grant = false;
    }
    u16 newGiIndex = giIndex;
    bool flagged;
    if (gSaveContext.extra.titleSetupIndex != 0) {
        flagged = false;
        grant = false;
    } else {
        flagged = MMR_CheckBottleAndGetGiFlag(giIndex, &newGiIndex);
    }
    if (!flagged) {
        if (grant) {
            MMR_SetGiFlag(newGiIndex);
        }
        newGiIndex = giIndex;
        if (MISC_CONFIG.flags.progressiveUpgrades) {
            newGiIndex = MMR_CheckProgressiveUpgrades(newGiIndex);
        }
    } else {
        bool isCycleRepeatable = false;
        for (u8 i = 0; i < MMR_CONFIG.locations.cycleRepeatableLength; i++) {
            if (MMR_CONFIG.locations.cycleRepeatable[i] == newGiIndex) {
                isCycleRepeatable = true;
                break;
            }
        }
        if (!isCycleRepeatable) {
            newGiIndex = 0x0A; // Recovery Heart
        }
    }
    if (grant) {
        MMR_SetGiFlag(giIndex);
    }
    if (actor == (Actor*)GET_PLAYER(ctxt)) {
        GET_PLAYER(ctxt)->getItem = newGiIndex;
    }
    return newGiIndex;
}

void MMR_Init(void) {
    // If using vanilla layout, gi-table mod file is not included.
    if (!MISC_CONFIG.internal.vanillaLayout) {
        LoadGiTable();
    }
}
