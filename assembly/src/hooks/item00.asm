;==================================================================================================
; Item00 Constructor after collectable flag has been checked and processed.
;==================================================================================================

.headersize (G_CODE_RAM - G_CODE_FILE)

; Replaces:
;   LH	    T4, 0x001C (S0)
;   ADDIU	AT, R0, 0x0015
.org 0x800A5E1C
    jal     item00_constructor_hook
    nop

; Replaces:
;   lui     at, 0x801E
;   addu    at, at, t3
;   lw      t3, 0xBF24 (at)
.org 0x800A6E1C
    jal     item00_give_item_hook
    nop
    nop
