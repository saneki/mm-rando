;==================================================================================================
; Item00 Constructor after collectable flag has been checked and processed.
;==================================================================================================

.headersize G_CODE_DELTA

; Replaces:
;   lh      t4, 0x001C (s0)
;   addiu   at, r0, 0x0015
.org 0x800A5E1C
    jal     Item00_Constructor_Hook
    nop

; Replaces:
;   lui     at, 0x801E
;   addu    at, at, t3
;   lw      t3, 0xBF24 (at)
.org 0x800A6E1C
    jal     Item00_GiveItem_Hook
    nop
    nop
