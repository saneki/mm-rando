#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include <z64.h>

bool Player_CanReceiveItem(GlobalContext* ctxt);
void player_pause(GlobalContext *game);
void player_unpause(GlobalContext *game);

#endif // PLAYER_H
