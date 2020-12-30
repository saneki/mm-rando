#ifndef OBJHEAP_H
#define OBJHEAP_H

#include <z2.h>
#include "Linheap.h"

struct ObjheapItem {
    u8* buf;
    u16 objectId;
    s8 room;
};

struct Objheap {
    struct Linheap linheap;
    struct ObjheapItem* objs;
    size_t count;
    s8 curRoom;
    s8 nexRoom;
    u8 op; // Prepared operation when data is safe to free.
};

struct ObjheapItem * Objheap_Allocate(struct Objheap* heap, u32 objectId, s8 room);
void Objheap_Clear(struct Objheap* heap);
void Objheap_FinishAdvance(struct Objheap* heap);
void Objheap_FlushOperation(struct Objheap* heap);
void Objheap_HandleRoomUnload(struct Objheap* heap, s8 curRoom);
void Objheap_Init(struct Objheap* heap, void* base, size_t size, struct ObjheapItem* objs, size_t count);
void Objheap_InitRoom(struct Objheap* heap, s8 room);
void Objheap_PrepareAdvance(struct Objheap* heap, s8 room);
void Objheap_RevertAdvance(struct Objheap* heap);

#endif // OBJHEAP_H
