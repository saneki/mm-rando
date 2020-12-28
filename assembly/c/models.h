#ifndef MODELS_H
#define MODELS_H

#include "z2.h"

struct Model {
    u16 objectId;
    u8 graphicId;
};

void Models_AfterActorDtor(Actor* actor);
void Models_AfterPrepareDisplayBuffers(GraphicsContext* gfx);
void Models_ClearObjectHeap(void);
void Models_Init(void);
void Models_PrepareAfterRoomUnload(GlobalContext* ctxt);
void Models_PrepareBeforeRoomLoad(RoomContext* roomCtx, s8 roomIndex);

#endif // MODELS_H
