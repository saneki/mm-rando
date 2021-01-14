#include <z64.h>
#include "Item00.h"

ActorEnItem00* SwordSchoolGong_RupeeSpawn(GlobalContext* ctxt, Vec3f* position, u16 type) {
    ActorEnItem00* item = z2_fixed_drop_spawn(ctxt, position, type);
    Item00_CheckAndSetGiIndex(item, ctxt, 0x360);
    return item;
}
