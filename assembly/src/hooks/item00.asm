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

