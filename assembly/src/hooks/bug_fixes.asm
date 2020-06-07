;==================================================================================================
; Fix Igos softlock
;==================================================================================================

.headersize (G_EN_KNIGHT_VRAM - G_EN_KNIGHT_FILE)

; Get initial magic consume state for elemental arrows.
; Replaces (vanilla):
;   jal     0x800F1BE4
;   lb      a0, 0x0038 (s0)
;   beq     v0, r0, 0x0007
;   or      a1, s0, r0
;   jal     0x800F1C68
;   lb      a0, 0x0038 (s0)
; Replaces (MMR):
;   jal     0x801DC650
;   addiu   a2, r0, 0x0076
;   nop
;   nop
;   nop
;   nop
.org 0x809B5868
    jal     player_can_receive_item
    lw      a0, 0x0054 (sp)
    beq     v0, r0, 0x809B58C0
    nop
    jal     0x801DC650
    addiu   a2, r0, 0x0076
