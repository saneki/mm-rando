;==================================================================================================
; Give Item right before the Boss Warp warps you.
;==================================================================================================

.headersize G_DOOR_WARP1_DELTA

; Replaces:
;   LH	    T6, 0x01CE (A0)
;   ADDIU	T7, T6, 0xFFFF
;   SH	    T7, 0x01CE (A0)
.org 0x808B9EE0
    jal     DoorWarp_GiveItem
    nop
    nop
