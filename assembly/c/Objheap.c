#include <z64.h>
#include "ExtendedObjects.h"
#include "Linheap.h"
#include "Objheap.h"

enum ObjheapOp {
    OP_NONE,
    OP_ADVANCE,
    OP_REVERT,
};

static void LoadObjectFile(u32 objectId, u8* buf) {
    ObjectFileTableEntry* entry = ExtendedObjects_Get((s16)objectId);
    u32 vromStart = entry->vromStart;
    u32 size = entry->vromEnd - vromStart;
    z2_ReadFile(buf, vromStart, size);
}

static size_t GetObjectSize(u32 objectId) {
    ObjectFileTableEntry info = *ExtendedObjects_Get((s16)objectId);
    return (size_t)(info.vromEnd - info.vromStart);
}

static void ItemClear(struct ObjheapItem* obj) {
    obj->buf = NULL;
    obj->objectId = 0;
    obj->room = -1;
}

static void ItemLoadObject(struct ObjheapItem* object, u32 objectId) {
    object->objectId = objectId;
    LoadObjectFile(objectId, object->buf);
}

/**
 * Return pointer to data of object by Id tied to specific room, or allocate if necessary.
 **/
struct ObjheapItem* Objheap_Allocate(struct Objheap* heap, u32 objectId, s8 room) {
    // Collectible actors will usually have a room value of -1. These seem to draw regardless of the current room the game has loaded.
    if (room == -1) {
        // Hackily treat as tied to the current room. When transitioning to other room, should allocate new data for that room before current data is freed.
        if (heap->op == OP_ADVANCE) {
            room = heap->nexRoom;
        } else {
            room = heap->curRoom;
        }
    }
    // Sanity check: ensure object is from relevant room.
    if (room == heap->curRoom || room == heap->nexRoom) {
        // Do initial pass to check if object is already loaded for the specific room.
        struct ObjheapItem *other = NULL, *unused = NULL;
        for (size_t i = 0; i < heap->count; i++) {
            struct ObjheapItem* obj = &heap->objs[i];
            if (obj->objectId == objectId && obj->room == room) {
                return obj;
            } else if (obj->objectId == objectId) {
                // Remember same object data allocated for other room, for memcpy if needed.
                other = obj;
            } else if (obj->objectId == 0 && unused == NULL) {
                // Remember for allocating if object not found.
                unused = obj;
            }
        }
        // If two rooms loaded and allocating object for previous room, prevent allocating object data if not already in heap.
        // This is to ensure that we can safely revert advancing if unloading the new room first, as all new object data will be for the new room.
        // For example, going from: Old room loaded => Old & New rooms loaded => Old room loaded
        // This behavior is relevant to the room transition between Sewers and Astral Observatory.
        if (heap->curRoom != heap->nexRoom && room == heap->curRoom) {
            return NULL;
        }
        // If unused object slot was found, use it for allocation.
        if (unused != NULL) {
            struct ObjheapItem* obj = unused;
            size_t objsize = GetObjectSize(objectId);
            // Ensure heap could successfully allocate enough space.
            obj->buf = Linheap_Alloc(&heap->linheap, objsize);
            if (obj->buf != NULL) {
                obj->room = room;
                if (other != NULL) {
                    // Copy existing memory from loaded object data.
                    obj->objectId = other->objectId;
                    z2_memcpy(obj->buf, other->buf, objsize);
                } else {
                    // Load object from file.
                    ItemLoadObject(obj, objectId);
                }
                return obj;
            }
        }
    }
    return NULL;
}

/**
 * Clear underlying Linheap and all objheap item entries.
 **/
void Objheap_Clear(struct Objheap* heap) {
    for (size_t i = 0; i < heap->count; i++) {
        ItemClear(&heap->objs[i]);
    }
    Linheap_Clear(&heap->linheap);
}

/**
 * Invalidate all object data not in the current room.
 **/
static void InvalidateItems(struct Objheap* heap) {
    for (size_t i = 0; i < heap->count; i++) {
        struct ObjheapItem* obj = &heap->objs[i];
        // Invalidate object data slot if designated for previous room.
        if (obj->room != heap->curRoom) {
            ItemClear(obj);
        }
    }
}

/**
 * Flush heap operation, in which case the heap should either finish advance or revert advance.
 * These operations also update the relevant room indexes.
 **/
void Objheap_FlushOperation(struct Objheap* heap) {
    if (heap->op == OP_ADVANCE) {
        // Old room => Old & New rooms => New room
        Objheap_FinishAdvance(heap);
    } else if (heap->op == OP_REVERT) {
        // Old room => Old & New rooms => Old room
        Objheap_RevertAdvance(heap);
    }
    heap->op = OP_NONE;
}

/**
 * Handle room unload, which will determine and store which operation to perform when ready.
 **/
void Objheap_HandleRoomUnload(struct Objheap* heap, s8 curRoom) {
    // Update operation based on room unload.
    if (heap->nexRoom == curRoom) {
        // Advance
        heap->op = OP_ADVANCE;
    } else if (heap->curRoom == curRoom) {
        // Revert
        heap->op = OP_REVERT;
    } else {
        // Should not reach.
        heap->op = OP_NONE;
    }
}

/**
 * Finish advance on underlying Linheap, and clear objheap item entries from previous room.
 **/
void Objheap_FinishAdvance(struct Objheap* heap) {
    // Advance room index.
    heap->curRoom = heap->nexRoom;
    // Invalidate items for previously-loaded room.
    InvalidateItems(heap);
    // Finish advance in underlying heap.
    Linheap_FinishAdvance(&heap->linheap);
}

/**
 * Initialize objheap with underlying heap buffer and provided item array.
 **/
void Objheap_Init(struct Objheap* heap, void* base, size_t size, struct ObjheapItem* objs, size_t count) {
    heap->linheap.size = size;
    Linheap_Init(&heap->linheap, base);
    heap->objs = objs;
    heap->count = count;
    for (size_t i = 0; i < count; i++) {
        ItemClear(&objs[i]);
    }
    heap->curRoom = heap->nexRoom = -1;
    heap->op = OP_NONE;
}

/**
 * Initialize current & next room values when loading scene.
 **/
void Objheap_InitRoom(struct Objheap* heap, s8 room) {
    heap->curRoom = heap->nexRoom = room;
}

/**
 * Prepare underlying Linheap for advance, and update next room value.
 **/
void Objheap_PrepareAdvance(struct Objheap* heap, s8 room) {
    heap->nexRoom = room;
    heap->op = OP_NONE;
    Linheap_PrepareAdvance(&heap->linheap);
}

/**
 * Revert advance on underlying heap, and clear objheap item entries from unloaded room.
 **/
void Objheap_RevertAdvance(struct Objheap* heap) {
    // Revert room index.
    heap->nexRoom = heap->curRoom;
    // Invalidate items for previously-loaded room.
    InvalidateItems(heap);
    // Revert advance on underlying Linheap.
    Linheap_RevertAdvance(&heap->linheap);
}
