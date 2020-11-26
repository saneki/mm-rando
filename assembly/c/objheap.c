#include "extended_objects.h"
#include "linheap.h"
#include "objheap.h"
#include "z2.h"

static void load_object_file(u32 object_id, u8 *buf) {
    z2_obj_file_t *entry = extended_objects_get((s16)object_id);
    u32 vrom_start = entry->vrom_start;
    u32 size = entry->vrom_end - vrom_start;
    z2_ReadFile(buf, vrom_start, size);
}

static size_t get_object_size(u32 object_id) {
    z2_obj_file_t info = *extended_objects_get((s16)object_id);
    return (size_t)(info.vrom_end - info.vrom_start);
}

static void objheap_item_clear(struct objheap_item *obj) {
    obj->buf = NULL;
    obj->object_id = 0;
    obj->room = -1;
}

static void objheap_item_load_object(struct objheap_item *object, u32 object_id) {
    object->object_id = object_id;
    load_object_file(object_id, object->buf);
}

/**
 * Return pointer to data of object by Id tied to specific room, or allocate if necessary.
 **/
struct objheap_item* objheap_allocate(struct objheap *heap, u32 object_id, s8 room) {
    // Sanity check: ensure object is from relevant room.
    if (room == heap->cur_room || room == heap->nex_room) {
        // Do initial pass to check if object is already loaded for the specific room.
        struct objheap_item *unused = NULL;
        for (size_t i = 0; i < heap->count; i++) {
            struct objheap_item *obj = &heap->objs[i];
            if (obj->object_id == object_id && obj->room == room) {
                return obj;
            } else if (obj->object_id == 0 && unused == NULL) {
                // Remember for allocating if object not found.
                unused = obj;
            }
        }
        // If two rooms loaded and allocating object for previous room, prevent allocating object data if not already in heap.
        // This is to ensure that we can safely revert advancing if unloading the new room first, as all new object data will be for the new room.
        // For example, going from: Old room loaded => Old & New rooms loaded => Old room loaded
        // This behavior is relevant to the room transition between Sewers and Astral Observatory.
        if (heap->cur_room != heap->nex_room && room == heap->cur_room) {
            return NULL;
        }
        // If unused object slot was found, use it for allocation.
        if (unused != NULL) {
            struct objheap_item *obj = unused;
            size_t objsize = get_object_size(object_id);
            // Ensure heap could successfully allocate enough space.
            obj->buf = linheap_alloc(&heap->linheap, objsize);
            if (obj->buf != NULL) {
                obj->room = room;
                objheap_item_load_object(obj, object_id);
                return obj;
            }
        }
    }
    return NULL;
}

/**
 * Clear underlying linheap and all objheap item entries.
 **/
void objheap_clear(struct objheap *heap) {
    for (size_t i = 0; i < heap->count; i++) {
        objheap_item_clear(&heap->objs[i]);
    }
    linheap_clear(&heap->linheap);
}

/**
 * Invalidate all object data not in the current room.
 **/
static void objheap_invalidate_items(struct objheap *heap) {
    for (size_t i = 0; i < heap->count; i++) {
        struct objheap_item *obj = &heap->objs[i];
        // Invalidate object data slot if designated for previous room.
        if (obj->room != heap->cur_room) {
            objheap_item_clear(obj);
        }
    }
}

/**
 * Handle room unload, in which case the heap should either finish advance or revert advance.
 **/
void objheap_handle_room_unload(struct objheap *heap, s8 cur_room) {
    if (heap->nex_room == cur_room) {
        // Old room => Old & New rooms => New room
        objheap_finish_advance(heap);
    } else if (heap->cur_room == cur_room) {
        // Old room => Old & New rooms => Old room
        objheap_revert_advance(heap);
    }
}

/**
 * Finish advance on underlying linheap, and clear objheap item entries from previous room.
 **/
void objheap_finish_advance(struct objheap *heap) {
    // Advance room index.
    heap->cur_room = heap->nex_room;
    // Invalidate items for previously-loaded room.
    objheap_invalidate_items(heap);
    // Finish advance in underlying heap.
    linheap_finish_advance(&heap->linheap);
}

/**
 * Initialize objheap with underlying heap buffer and provided item array.
 **/
void objheap_init(struct objheap *heap, void *base, size_t size, struct objheap_item *objs, size_t count) {
    heap->linheap.size = size;
    linheap_init(&heap->linheap, base);
    heap->objs = objs;
    heap->count = count;
    for (size_t i = 0; i < count; i++) {
        objheap_item_clear(&objs[i]);
    }
    heap->cur_room = heap->nex_room = -1;
}

/**
 * Initialize current & next room values when loading scene.
 **/
void objheap_init_room(struct objheap *heap, s8 room) {
    heap->cur_room = heap->nex_room = room;
}

/**
 * Prepare underlying linheap for advance, and update next room value.
 **/
void objheap_prepare_advance(struct objheap *heap, s8 room) {
    heap->nex_room = room;
    linheap_prepare_advance(&heap->linheap);
}

/**
 * Revert advance on underlying heap, and clear objheap item entries from unloaded room.
 **/
void objheap_revert_advance(struct objheap *heap) {
    // Revert room index.
    heap->nex_room = heap->cur_room;
    // Invalidate items for previously-loaded room.
    objheap_invalidate_items(heap);
    // Revert advance on underlying linheap.
    linheap_revert_advance(&heap->linheap);
}
