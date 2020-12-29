#include "models.h"
#include "z2.h"

void Room_AfterLoad(GlobalContext* ctxt, RoomContext* roomCtxt, u32 roomIdx) {
}

void Room_AfterUnload(GlobalContext* ctxt, RoomContext* roomCtxt) {
    // Prepare object data heap for previous room unload.
    Models_PrepareAfterRoomUnload(ctxt);
}

void Room_beforeLoad(GlobalContext* ctxt, RoomContext* roomCtxt, u32 roomIdx) {
    // Prepare object data heap for new room load.
    Models_PrepareBeforeRoomLoad(roomCtxt, (s8)roomIdx);
}

void Room_BeforeUnload(GlobalContext* ctxt, RoomContext* roomCtxt) {
}
