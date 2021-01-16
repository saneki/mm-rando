#ifndef ITEM00_H
#define ITEM00_H

#include <z64.h>

void Item00_CheckAndSetGiIndex(ActorEnItem00* actor, GlobalContext* ctxt, u16 giIndex);
u16 Item00_GetDrawGiIndex(ActorEnItem00* actor);
u16 Item00_GetGiIndex(ActorEnItem00* actor);
void Item00_SetDrawGiIndex(ActorEnItem00* actor, u16 drawGiIndex);
void Item00_SetGiIndex(ActorEnItem00* actor, u16 giIndex);

#endif // ITEM00_H
