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
    jal     world_colors_get_blue_bubble_color_hook
    sw      t8, 0x0000 (v0)
    sw      t9, 0x0004 (v0)
.endarea

;==================================================================================================
; Goron Rolling Interior Energy Color
;==================================================================================================

.headersize(G_PLAYER_ACTOR_VRAM - G_PLAYER_ACTOR_FILE)

@GoronInnerEnergyColor equ (WORLD_COLOR_CONFIG + 0x8)

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
