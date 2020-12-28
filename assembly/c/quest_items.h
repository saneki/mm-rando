#ifndef QUEST_ITEMS_H
#define QUEST_ITEMS_H

#include <stdbool.h>
#include "z2.h"

// Check if an item is a quest item.
#define QuestItems_IsQuestItem(Item) (Z2_ITEM_MOON_TEAR <= (Item) && (Item) <= Z2_ITEM_PENDANT)

// Check if an inventory slot is a quest items slot.
#define QuestItems_IsQuestSlot(Slot) ((Slot) == Z2_SLOT_QUEST1 || (Slot) == Z2_SLOT_QUEST2 || (Slot) == Z2_SLOT_QUEST3)

void QuestItems_AfterReceive(u8 item);
void QuestItems_AfterRemoval(u8 item, u8 slot);
void QuestItems_AfterSongOfTimeClear(void);
bool QuestItems_GetSlot(int* slot, u8 item);
bool QuestItems_Remove(u8 item);

#endif // QUEST_ITEMS_H
