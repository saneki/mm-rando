#include "z2.h"
#include "mmr.h"

void file_after_init() {
    for (u8 i = 0; i < 6; i++) {
        if (((MMR_CONFIG.extra_starting_maps.byte >> i) & 1) != 0) {
            z2_GiveMap(i);
        }
    }
}