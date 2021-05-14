#include <z64.h>
#include "HueCycle.h"

static const bool gRainbow = true;

/**
 * Hook function to update trail effect colors before returning effect structure pointer.
 **/
EffectBlure* Bombchu_GetTrailEffectParams(ActorEnBomChu* actor, s32 index, int side) {
    EffectBlure* params = (EffectBlure*)z2_Effect_GetParams(index);
    if (gRainbow) {
        // Shift hue of trail effect colors by specific percentage.
        static const f32 hueShiftAmount = 0.04;
        params->p1StartColor = HueCycle_Color_AddPercent(params->p1StartColor, hueShiftAmount);
        params->p2StartColor = HueCycle_Color_AddPercent(params->p2StartColor, hueShiftAmount);
        params->p1EndColor = HueCycle_Color_AddPercent(params->p1EndColor, hueShiftAmount);
        params->p2EndColor = HueCycle_Color_AddPercent(params->p2EndColor, hueShiftAmount);
    }
    return params;
}
