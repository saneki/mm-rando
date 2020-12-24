#include "z2.h"
#include "item00.h"

z2_en_item00_t *soft_soil_prize_item_spawn(z2_game_t *game, z2_actor_t *actor, u16 type) {
    z2_en_item00_t* item = z2_fixed_drop_spawn(game, &actor->pos_2, type);
    if (item == NULL) { // TODO items should be made to spawn regardless of inventory
        return item;
    }
    u16 gi_index = 0;
    u8 flag = actor->variable & 0x7F;
    switch (game->scene_index) {
        case 0x07: // Grottos
            gi_index = 0x362; // Bean Grotto
            break;
        case 0x27: // Swamp Spider House
            if (flag == 0) {
                gi_index = 0x37D; // Rock
            } else {
                gi_index = 0x37E; // Gold Room
            }
            break;
        case 0x2B: // Deku Palace
            gi_index = 0x370;
            break;
        case 0x2D: // Termina Field
            if (flag == 0xE) {
                gi_index = 0x37F; // Stump
            } else if (flag == 0x5) {
                gi_index = 0x380; // Observatory
            } else if (flag == 0x14) {
                gi_index = 0x381; // South Wall
            } else {
                gi_index = 0x382; // Pillar
            }
            break;
        case 0x35: // Romani Ranch
            if (z2_file.day <= 1) {
                gi_index = 0x37A;
            } else {
                gi_index = 0x374;
            }
            break;
        case 0x37: // Great Bay Coast
            gi_index = 0x372;
            break;
        case 0x41: // Doggy Racetrack
            gi_index = 0x371;
            break;
        case 0x59: // Stone Tower (Inverted)
            if (flag == 0) {
                gi_index = 0x37B; // Lower
            } else {
                gi_index = 0x37C; // Upper
            }
            break;
        case 0x60: // Secret Shrine
            gi_index = 0x373;
            break;
    }
    if (gi_index > 0) {
        item00_check_and_set_gi_index(item, game, gi_index);
    }
    return item;
}
