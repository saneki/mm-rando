#include <stdbool.h>
#include <z2.h>
#include "quest_item_storage.h"

void QuestItemStorage_Clear(struct QuestItemStorage* storage) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            storage->slots[i][j] = 0;
        }
    }
}

bool QuestItemStorage_GetSlot(int* slot, int* idx, u8 item) {
    switch (item) {
        case Z2_ITEM_MOON_TEAR:
        case Z2_ITEM_TOWN_DEED:
        case Z2_ITEM_SWAMP_DEED:
        case Z2_ITEM_MOUNTAIN_DEED:
        case Z2_ITEM_OCEAN_DEED:
            *slot = 0;
            *idx = item - Z2_ITEM_MOON_TEAR;
            return true;
        case Z2_ITEM_ROOM_KEY:
        case Z2_ITEM_MAMA_LETTER:
            *slot = 1;
            *idx = item - Z2_ITEM_ROOM_KEY;
            return true;
        case Z2_ITEM_KAFEI_LETTER:
        case Z2_ITEM_PENDANT:
            *slot = 2;
            *idx = item - Z2_ITEM_KAFEI_LETTER;
            return true;
        default:
            return false;
    }
}

bool QuestItemStorage_Has(const struct QuestItemStorage* storage, u8 item) {
    int idx, slot;
    if (QuestItemStorage_GetSlot(&slot, &idx, item)) {
        return storage->slots[slot][idx] == item;
    } else {
        return false;
    }
}

u8 QuestItemStorage_Next(const struct QuestItemStorage* storage, u8 item) {
    int idx, slot;
    if (QuestItemStorage_GetSlot(&slot, &idx, item)) {
        for (int i = 1; i < 6; i++) {
            int nextIdx = (idx + i) % 6;
            u8 next = storage->slots[slot][nextIdx];
            if (next != 0) {
                return next;
            }
        }
    }
    return Z2_ITEM_NONE;
}

bool QuestItemStorage_Put(struct QuestItemStorage* storage, u8 item) {
    int idx, slot;
    if (QuestItemStorage_GetSlot(&slot, &idx, item)) {
        storage->slots[slot][idx] = item;
        return true;
    } else {
        return false;
    }
}

bool QuestItemStorage_Remove(struct QuestItemStorage* storage, u8 item) {
    int idx, slot;
    if (QuestItemStorage_GetSlot(&slot, &idx, item)) {
        storage->slots[slot][idx] = 0;
        return true;
    } else {
        return false;
    }
}
