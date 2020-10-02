#include "misc.h"
#include "mmr.h"
#include "util.h"

struct mmr_config MMR_CONFIG = {
    .magic = MMR_CONFIG_MAGIC,
    .version = 1,
    .cycle_repeatable_locations_length = 0x80,
    .location_bottle_red_potion = 0x59,
    .location_bottle_chateau = 0x6F,
    .location_bottle_milk = 0x60,
    .location_bottle_gold_dust = 0x6A,
};

static mmr_gi_t *g_gi_table = NULL;

static void mmr_load_gi_table(void) {
    // Use gi-table file index to get dmadata entry.
    u32 index = mmr_GiTableFileIndex;
    z2_file_table_t entry = z2_file_table[index];
    u32 size = entry.vrom_end - entry.vrom_start;

    // Load the gi-table table from file into buffer.
    g_gi_table = (mmr_gi_t *)heap_alloc(size);
    z2_ReadFile(g_gi_table, entry.vrom_start, size);
}

mmr_gi_t * mmr_get_gi_entry(u16 index) {
    return &g_gi_table[index - 1];
}

bool mmr_CheckBottleAndGetGiFlag(u16 gi_index, u16 *new_gi_index) {
    if (gi_index == MMR_CONFIG.location_bottle_red_potion) {
        gi_index = 0x5B;
    } else if (gi_index == MMR_CONFIG.location_bottle_chateau) {
        gi_index = 0x91;
    } else if (gi_index == MMR_CONFIG.location_bottle_milk) {
        gi_index = 0x92;
    } else if (gi_index == MMR_CONFIG.location_bottle_gold_dust) {
        gi_index = 0x93;
    }
    *new_gi_index = gi_index;
    return mmr_GetGiFlag(gi_index);
}

u16 mmr_GetNewGiIndex(z2_game_t *game, z2_actor_t *actor, u16 gi_index, bool grant) {
    if (z2_file.cutscene_id != 0) {
        return gi_index;
    }
    u16 new_gi_index = gi_index;
    bool flagged = mmr_CheckBottleAndGetGiFlag(gi_index, &new_gi_index);
    if (!flagged) {
        if (grant) {
            mmr_SetGiFlag(new_gi_index);
        }
        new_gi_index = gi_index;
    }
    bool is_cycle_repeatable = false;
    for (u8 i = 0; i < MMR_CONFIG.cycle_repeatable_locations_length; i++) {
        if (MMR_CONFIG.cycle_repeatable_locations[i] == new_gi_index) {
            is_cycle_repeatable = true;
            break;
        }
    }
    if (flagged && !is_cycle_repeatable) {
        new_gi_index = 0x0A; // Recovery Heart
    }
    if (grant) {
        mmr_SetGiFlag(gi_index);
    }
    if (actor == Z2_LINK(game)) {
        Z2_LINK(game)->get_item = new_gi_index;
    }
    return new_gi_index;
}

void mmr_init(void) {
    // If using vanilla layout, gi-table mod file is not included.
    if (!MISC_CONFIG.vanilla_layout) {
        mmr_load_gi_table();
    }
}
