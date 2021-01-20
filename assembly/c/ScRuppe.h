#ifndef SC_RUPPE_H
#define SC_RUPPE_H

#include <z64.h>

u16 ScRuppe_GetDrawGiIndex(ActorEnScRuppe* actor);
u16 ScRuppe_GetGiIndex(ActorEnScRuppe* actor);
void ScRuppe_SetDrawGiIndex(ActorEnScRuppe* actor, u16 drawGiIndex);
void ScRuppe_SetGiIndex(ActorEnScRuppe* actor, u16 giIndex);

#endif // SC_RUPPE_H
