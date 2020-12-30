#include <stdbool.h>
#include <stddef.h>
#include "Linheap.h"

/**
 * Allocate data of given size and return a pointer. If unable, will return NULL.
 **/
void* Linheap_Alloc(struct Linheap* heap, size_t size) {
    // 0x10 byte alignment
    size_t rem = size % 0x10;
    if (rem) {
        size += (0x10 - rem);
    }

    // Check whether allocation should occur at cur1, cur2 or not at all.
    u8* end = heap->buffer + heap->size;
    if ((!heap->advance || heap->cycleable || (heap->advance >= heap->origin)) && (size_t)(end - heap->cur1) >= size) {
        // Allocate from cur1 pointer, up until buffer end.
        void* result = heap->cur1;
        heap->cur1 += size;
        return result;
    } else if ((!heap->advance || heap->cycleable || (heap->advance < heap->origin)) && (size_t)(heap->origin - heap->cur2) >= size) {
        // Allocate from cur2 pointer, up until origin pointer.
        void* result = heap->cur2;
        heap->cur2 += size;
        return result;
    } else {
        return NULL;
    }
}

/**
 * Clear the heap fully, resetting all pointers.
 **/
void Linheap_Clear(struct Linheap* heap) {
    Linheap_Init(heap, heap->buffer);
}

/**
 * Finish advancing origin pointer.
 **/
void Linheap_FinishAdvance(struct Linheap* heap) {
    // Three possibilities when advancing:
    // - Advance was placed on cur1, not cycleable. cur2 could not have allocated and may be reset to base.
    // - Advance was placed on cur2, not cycleable. Can replace cur2 with cur1 and reset cur2 to base.
    // - Advance was placed on cur1, is cycleable. Both cur1 and cur2 should remain as is.
    if (heap->advance < heap->origin) {
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
    // If heap is completely empty after finish, can clear it.
    if (Linheap_IsEmpty(heap)) {
        Linheap_Clear(heap);
    }
}

/**
 * Initialize heap, assume size is already set.
 **/
void Linheap_Init(struct Linheap* heap, void* base) {
    heap->buffer = heap->cur1 = heap->cur2 = heap->origin = (u8*)base;
    heap->advance = NULL;
    heap->cycleable = false;
}

/**
 * Check whether or not a given address is within allocated data.
 **/
bool Linheap_IsAllocated(const struct Linheap* heap, void* address) {
    u8* addr = (u8*)address;
    return (heap->buffer <= addr && addr < heap->cur2) || (heap->origin <= addr && addr < heap->cur1);
}

/**
 * Check whether or not the heap contains any allocated data.
 **/
bool Linheap_IsEmpty(const struct Linheap* heap) {
    return (heap->cur1 == heap->origin) && (heap->cur2 == heap->buffer);
}

/**
 * Prepare to advance origin pointer.
 **/
void Linheap_PrepareAdvance(struct Linheap* heap) {
    // Normally while in advance state, would need to only allocate in largest contiguous chunk of available heap memory.
    // This is in order to preserve the linear nature of the buffer: if there is data at buffer start (buffer < cur2), and
    // we mark cur1 as advance, if anything is allocated at cur2 then the data at buffer start would be "junk" after
    // finishing advance.
    //
    // However, if cur2 points to buffer start when preparing for advance, the buffer can "cycle" back to start, allowing
    // allocations at both cur1 and cur2. This is because the area between [advance, end) and [start, origin) can be seen
    // as one contiguous buffer with no risk of junk data being included after finishing advance.
    heap->cycleable = heap->cur2 == heap->buffer;

    u8* end = heap->buffer + heap->size;
    if (heap->cycleable || (end - heap->cur1) >= (heap->origin - heap->cur2)) {
        heap->advance = heap->cur1;
    } else {
        heap->advance = heap->cur2;
    }
}

/**
* Revert to previous state before preparing advance.
**/
void Linheap_RevertAdvance(struct Linheap* heap) {
    if (heap->origin <= heap->advance) {
        heap->cur1 = heap->advance;
        // If cycleable, cur2 was 0 before prepare and can revert.
        if (heap->cycleable) {
            heap->cur2 = heap->buffer;
        }
    }
    else {
        // cur1 should have not moved since prepare, revert cur2.
        heap->cur2 = heap->advance;
    }
    heap->advance = NULL;
}
