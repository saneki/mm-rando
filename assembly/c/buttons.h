#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdbool.h>
#include "z2.h"

bool buttons_check_c_item_usable(GlobalContext *game, u8 c);
void buttons_check_item_usability(bool *dest, GlobalContext *game, u8 b, u8 c1, u8 c2, u8 c3);

#endif // BUTTONS_H
