;==================================================================================================
; Bombchu Trail Effect Colors
;==================================================================================================

.headersize G_EN_BOM_CHU_DELTA

; Replaces:
;   jal     0x800AF720
.org 0x808F85A8 ; Offset: 0x10F8
    jal     Bombchu_GetTrailEffectParams_Hook_0

; Replaces:
;   jal     0x800AF720
.org 0x808F85D4 ; Offset: 0x1124
    jal     Bombchu_GetTrailEffectParams_Hook_1
