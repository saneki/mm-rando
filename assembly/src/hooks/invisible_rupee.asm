;==================================================================================================
; Invisible Rupee replace item spawn
;==================================================================================================

.headersize(G_EN_INVISIBLE_RUPEE_VRAM - G_EN_INVISIBLE_RUPEE_FILE)

; Replaces:
;   lh      v0, 0x001C (s0)
;   addiu   at, r0, 1
;   andi    v0, v0, 0x0003
;   beqz    v0, 0x80C2595C
.org 0x80C25930
    jal     invisible_rupee_give_item
    nop
    b       0x80C259B8
    lh      a1, 0x0190 (s0)
