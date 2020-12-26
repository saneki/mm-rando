#ifndef _Z64DMA_H_
#define _Z64DMA_H_

#include <n64.h>
#include "types.h"

typedef struct {
    /* 0x00 */ u32 vromAddr;
    /* 0x04 */ void* dramAddr;
    /* 0x08 */ u32 size;
} DmaParams;

typedef struct {
    /* 0x00 */ u32 vromAddr; // VROM address (source)
    /* 0x04 */ void* dramAddr; // DRAM address (destination)
    /* 0x08 */ u32 size; // File Transfer size
    /* 0x0C */ char* filename; // Filename for debugging
    /* 0x10 */ s32 line; // Line for debugging
    /* 0x14 */ s32 unk14;
    /* 0x18 */ OSMesgQueue* notifyQueue; // Message queue for the notification message
    /* 0x1C */ OSMesg notifyMsg; // Completion notification message
} DmaRequest; // size = 0x20

#endif // _Z64DMA_H_
