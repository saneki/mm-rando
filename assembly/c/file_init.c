#include <z2.h>
#include "mmr.h"

void file_after_init(GlobalContext *game) {
    // Give extra starting maps.
    for (u8 i = 0; i < 6; i++) {
        if (((MMR_CONFIG.extraStartingMaps.value >> i) & 1) != 0) {
            z2_GiveMap(i);
        }
    }
    // Give extra starting items.
    for (u8 i = 0; i < MMR_CONFIG.extraStartingItems.length; i++) {
        z2_GiveItem(game, MMR_CONFIG.extraStartingItems.ids[i]);
    }
}
