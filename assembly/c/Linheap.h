#ifndef LINHEAP_H
#define LINHEAP_H

#include <stdbool.h>
#include <stddef.h>
#include <z2.h>

/**
 * "Revolving linear heap" implementation.
 **/
struct Linheap {
    u8* advance;
    u8* buffer;
    u8* cur1; // Pointer to next write between: [origin, end)
    u8* cur2; // Pointer to next write between: [0, origin)
    u8* origin;
    size_t size;
    bool cycleable; // Whether or not heap can allocate at both buffer end and start during advance state.
};

void* Linheap_Alloc(struct Linheap* heap, size_t size);
void Linheap_Clear(struct Linheap* heap);
void Linheap_FinishAdvance(struct Linheap* heap);
void Linheap_Init(struct Linheap* heap, void* base);
bool Linheap_IsAllocated(const struct Linheap* heap, void* address);
bool Linheap_IsEmpty(const struct Linheap* heap);
void Linheap_PrepareAdvance(struct Linheap* heap);
void Linheap_RevertAdvance(struct Linheap* heap);

#endif // LINHEAP_H
