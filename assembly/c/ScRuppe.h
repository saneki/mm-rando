#ifndef SC_RUPPE_H
#define SC_RUPPE_H

#include <z64.h>

u16 ScRuppe_GetDrawGiIndex(Actor* actor);
u16 ScRuppe_GetGiIndex(Actor* actor);
void ScRuppe_SetDrawGiIndex(Actor* actor, u16 drawGiIndex);
void ScRuppe_SetGiIndex(Actor* actor, u16 giIndex);

#endif // SC_RUPPE_H
