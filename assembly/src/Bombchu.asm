Bombchu_GetTrailEffectParams_Hook_0:
    or      a1, a0, r0 ; A1 = Effect Index
    or      a0, s0, r0 ; A0 = Actor
    j       Bombchu_GetTrailEffectParams
    ori     a2, r0, 0  ; A2 = 0

Bombchu_GetTrailEffectParams_Hook_1:
    or      a1, a0, r0 ; A1 = Effect Index
    or      a0, s0, r0 ; A0 = Actor
    j       Bombchu_GetTrailEffectParams
    ori     a2, r0, 1  ; A2 = 1
