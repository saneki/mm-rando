#ifndef WORLD_COLORS_H
#define WORLD_COLORS_H

#include <z2.h>

#define WORLD_COLOR_CONFIG_MAGIC 0x57524C44

struct WorldColorConfig {
    u32 magic;
    u32 version;
    Color goronEnergyPunch;
    Color goronEnergyRolling;
    Color swordChargeEnergyBluEnv;
    Color swordChargeEnergyBluPri;
    Color swordChargeEnergyRedEnv;
    Color swordChargeEnergyRedPri;
    Color swordChargeSparksBlu;
    Color swordChargeSparksRed;
    Color swordSlashEnergyBluPri;
    Color swordSlashEnergyRedPri;
    Color swordBeamEnergyEnv;
    Color swordBeamEnergyPri;
    Color swordBeamDamageEnv;
    Color blueBubble;
};

void WorldColors_Init(void);

#endif // WORLD_COLORS_H
