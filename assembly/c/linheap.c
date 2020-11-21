#include <stdbool.h>
#include <stddef.h>
#include "linheap.h"

/**
 * Allocate data of given size and return a pointer. If unable, will return NULL.
 **/
void * linheap_alloc(struct linheap *heap, size_t size) {
    // 0x10 byte alignment
    size_t rem = size % 0x10;
    if (rem) {
        size += (0x10 - rem);
    }

    // Check whether allocation should occur at cur1, cur2 or not at all.
    u8* end = heap->buffer + heap->size;
    if ((!heap->advance || heap->cycleable || (heap->advance >= heap->origin)) && (size_t)(end - heap->cur1) >= size) {
        // Allocate from cur1 pointer, up until buffer end.
        void *result = heap->cur1;
        heap->cur1 += size;
        return result;
    } else if ((!heap->advance || heap->cycleable || (heap->advance < heap->origin)) && (size_t)(heap->origin - heap->cur2) >= size) {
        // Allocate from cur2 pointer, up until origin pointer.
        void *result = heap->cur2;
        heap->cur2 += size;
        return result;
    } else {
        return NULL;
    }
}

/**
 * Clear the heap fully, resetting all pointers.
 **/
void linheap_clear(struct linheap *heap) {
    linheap_init(heap, heap->buffer);
}

/**
 * Finish advancing origin pointer.
 **/
void linheap_finish_advance(struct linheap *heap) {
    if (heap->advance <= heap->cur2) {
        // If cur2 was used for advance, place cur1 at cur2 and reset cur2 to start.
        heap->cur1 = heap->cur2;
        heap->cur2 = heap->buffer;
    }
    else if (!heap->cycleable) {
        // If cur1 was used for advance and heap is not cycleable, contiguous region was [cur1, end) and cur2 can be reset to start.
        heap->cur2 = heap->buffer;
    }
    heap->origin = heap->advance;
    heap->advance = NULL;
    heap->cycleable = false;
}

/**
 * Initialize heap, assume size is already set.
 **/
void linheap_init(struct linheap *heap, void *base) {
    heap->buffer = heap->cur1 = heap->cur2 = heap->origin = (u8*)base;
    heap->advance = NULL;
    heap->cycleable = false;
}

/**
 * Check whether or not a given address is within allocated data.
 **/
bool linheap_is_allocated(const struct linheap *heap, void *address) {
    u8 *addr = (u8 *)address;
    return (heap->buffer <= addr && addr < heap->cur2) || (heap->origin <= addr && addr < heap->cur1);
}

/**
 * Prepare to advance origin pointer.
 **/
void linheap_prepare_advance(struct linheap *heap) {
    // Normally while in advance state, would need to only allocate in largest contiguous chunk of available heap memory.
    // This is in order to preserve the linear nature of the buffer: if there is data at buffer start (buffer < cur2), and
    // we mark cur1 as advance, if anything is allocated at cur2 then the data at buffer start would be "junk" after
    // finishing advance.
    //
    // However, if cur2 points to buffer start when preparing for advance, the buffer can "cycle" back to start, allowing
    // allocations at both cur1 and cur2. This is because the area between [advance, end) and [start, origin) can be seen
    // as one contiguous buffer with no risk of junk data being included after finishing advance.
    heap->cycleable = heap->cur2 == heap->buffer;

    u8 *end = heap->buffer + heap->size;
    if (heap->cycleable || (end - heap->cur1) >= (heap->origin - heap->cur2)) {
        heap->advance = heap->cur1;
    } else {
        heap->advance = heap->cur2;
    }
}
