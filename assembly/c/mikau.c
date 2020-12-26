#include "z2.h"
#include "misc.h"

/**
 * Hook function called to check whether or not to activate the beach cutscene when pushing Mikau to shore.
 **/
bool mikau_should_activate_beach_cutscene(Actor *mikau, GlobalContext *game) {
    if (MISC_CONFIG.mikau_early_beach) {
        f32 difference = mikau->currPosRot.pos.y - mikau->floorHeight;
        return difference < 24.0;
    } else {
        // Vanilla: Check flag which is set when floor height is greater-than-or-equal to Y position.
        return mikau->bgcheckFlags & 1;
    }
}
