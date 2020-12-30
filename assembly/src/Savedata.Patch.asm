;==================================================================================================
; Savedata Hooks
;==================================================================================================

.headersize(G_CODE_RAM - G_CODE_FILE)

; Hook after loading savedata into z2_file from buffer after flash.
; Replaces:
;   jal     0x800FEC90
.org 0x80145024
    jal     Savedata_AfterLoad_Hook

; Hook after preparing savedata.
; Replaces:
;   lw      s5, 0x0028 (sp)
;   jr      ra
;   addiu   sp, sp, 0x30
.org 0x80144568
    or      a0, s5, r0
    j       Savedata_AfterPrepare_Hook
    lw      s5, 0x0028 (sp)

; Hook after writing savedata to buffer before flash (owl statue).
; Replaces:
;   jal     0x800FEC90
.org 0x80145578
    jal     Savedata_AfterWrite_Owl_Hook

; Hook after writing savedata to buffer before flash (Song of Time).
; Replaces:
;   jal     0x800FEC90
.org 0x80145664
    jal     Savedata_AfterWrite_Sot_Hook

;==================================================================================================
; After File Initialized
;==================================================================================================

.headersize (G_CODE_RAM - G_CODE_FILE)

; Replaces:
;   jr      ra
;   nop
.org 0x80144960
    j       Savedata_AfterFileInit
    lw      a0, 0x0038 (sp)
