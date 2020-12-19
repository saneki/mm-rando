;==================================================================================================
; Blue Bubble color
;==================================================================================================

.headersize (G_EN_BB_VRAM - G_EN_BB_FILE)

; Replaces:
;   lui     t8, 0xFB00
;   ori     t9, r0, 0xFF00
;   addiu   t7, v0, 0x0008
;   sw      t7, 0x02C0 (s0)
;   sw      t9, 0x0004 (v0)
;   sw      t8, 0x0000 (v0)
.org 0x808C361C ; Offset: 0x18DC‬
.area 0x18
    lui     t8, 0xFB00
    addiu   t7, v0, 0x0008
    sw      t7, 0x02C0 (s0)
    jal     WorldColors_GetBlueBubbleColor_Hook
    sw      t8, 0x0000 (v0)
    sw      t9, 0x0004 (v0)
.endarea

;==================================================================================================
; Goron Punching Energy Color
;==================================================================================================

.headersize(G_CODE_RAM - G_CODE_FILE)

@GoronPunchEnergyColor equ (WORLD_COLOR_CONFIG + 0x8)

; Goron punch energy color (SetEnvColor).
; Replaces:
;   andi    t3, t0, 0x00FF
;   lui     at, 0xFF00
.org 0x801274E4
    lui     at, hi(@GoronPunchEnergyColor)
    lw      at, lo(@GoronPunchEnergyColor) (at)

; Replaces:
;   or      t4, t3, at
.org 0x801274F4
    or      t4, t0, at

;==================================================================================================
; Goron Rolling Interior Energy Color
;==================================================================================================

.headersize(G_PLAYER_ACTOR_VRAM - G_PLAYER_ACTOR_FILE)

@GoronInnerEnergyColor equ (WORLD_COLOR_CONFIG + 0xC)

; Goron inner energy color (SetEnvColor).
; Replaces:
;   lui     at, 0x9B00 ;; AT = #9B0000 (color value).
;   addiu   t3, v0, 0x0008
;   sw      t3, 0x02C0 (a1)
.org 0x80846BE4 ; Offset: 0x19154
    lui     at, hi(@GoronInnerEnergyColor)
    lw      at, lo(@GoronInnerEnergyColor) (at)
    nop

; Replaces:
;   lw      v0, 0x02C0 (a1)
.org 0x80846C08 ; Offset: 0x19178
    addiu   v0, v0, 0x0008

;==================================================================================================
; Sword Spin Energy Color
;==================================================================================================

.headersize(G_EN_M_THUNDER_VRAM - G_EN_M_THUNDER_FILE)

@SwordSlashBluePriColor equ (WORLD_COLOR_CONFIG + 0x10)
@SwordSlashRedPriColor  equ (WORLD_COLOR_CONFIG + 0x14)
@SwordSlashEnvColor     equ (WORLD_COLOR_CONFIG + 0x18)
@SwordSlashPriColor     equ (WORLD_COLOR_CONFIG + 0x1C)

; Red prim color (part 1).
; Replaces:
;   addiu   at, r0, 0xAA00
;   ctc1    t5, fcsr
;   or      t9, t7, at
;   sw      t9, 0x0004 (v1)
.org 0x808B6A68 ; Offset: 0x16A8
    lui     at, hi(@SwordSlashRedPriColor)
    lw      at, lo(@SwordSlashRedPriColor) (at)
    or      t9, t7, at
    ctc1    t5, fcsr

; Red prim color (part 2).
; Replaces:
;   sw      t5, 0x02C0 (t0)
.org 0x808B6A88 ; Offset: 0x16C8
    sw      t9, 0x0004 (v1)

; Red prim color (part 3).
; Replaces:
;   lw      v0, 0x02C0 (t0)
.org 0x808B6A94 ; Offset: 0x16D4
    or      v0, t5, r0

; Blue prim color.
; Replaces:
;   lui     at, 0xAAFF
;   ori     at, at, 0xFF00
.org 0x808B6B64 ; Offset: 0x17A4
    lui     at, hi(@SwordSlashBluePriColor)
    lw      at, lo(@SwordSlashBluePriColor) (at)

; Prim color, used for both.
; Replaces:
;   lui     at, 0xAAFF
;   ori     at, at, 0xFF00
.org 0x808B6F90 ; Offset: 0x1BD0
    lui     at, hi(@SwordSlashPriColor)
    lw      at, lo(@SwordSlashPriColor) (at)

; Env color (first half).
; Replaces:
;   lui     t9, 0x0064
.org 0x808B6F68 ; Offset: 0x1BA8
    lui     t9, hi(@SwordSlashEnvColor)

; Env color (second half).
; Replaces:
;   ori     t9, t9, 0xFF80
.org 0x808B6FAC ; Offset: 0x1BEC
    lw      t9, lo(@SwordSlashEnvColor) (t9)

;==================================================================================================
; Fierce Deity Sword Beam Energy Color
;==================================================================================================

.headersize(G_EN_M_THUNDER_VRAM - G_EN_M_THUNDER_FILE)

@SwordBeamEnvColor equ (WORLD_COLOR_CONFIG + 0x20)
@SwordBeamPriColor equ (WORLD_COLOR_CONFIG + 0x24)

; Prim color.
; Replaces:
;   lui     at, 0xAAFF
;   ori     at, at, 0xFF00
.org 0x808B6C64 ; Offset: 0x18A4
    lui     at, hi(@SwordBeamPriColor)
    lw      at, lo(@SwordBeamPriColor) (at)

; Env color (part 1).
; Replaces:
;   lui     t6, 0x0064
.org 0x808B6BE8 ; Offset: 0x1828
    lui     t6, hi(@SwordBeamEnvColor)

; Env color (part 2).
; Replaces:
;   ori     t6, t6, 0xFF80
.org 0x808B6C84 ; Offset: 0x18C4
    lw      t6, lo(@SwordBeamEnvColor) (t6)
