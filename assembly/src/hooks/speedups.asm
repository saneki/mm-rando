;==================================================================================================
; Check Speedups - Sound Check
;==================================================================================================

.headersize(G_EN_TOTO_VRAM - G_EN_TOTO_FILE)

; Branch to end of function if skipping rest of cutscene.
; This will prevent the function from spawning actors on stage (different Link forms), and prevent
; preparing for the following actor cutscene.
; Replaces:
;   lui     t8, 0x801F
;   lbu     t8, 0xF690 (t8)
;   addiu   s1, s0, 0x0001
;   addu    t9, s5, s0
.org 0x80BA48A0 ; Offset: 0x11E0
    jal     toto_should_skip_formal_replay_hook
    addiu   s1, s0, 0x0001
    bnez    v0, 0x80BA4970
    lbu     t8, 0xF690 (t8)

; Replace function pointer used for advancing actor cutscene when index is 0xC.
; Replaces:
;   .dw 0x80BA407C
.org 0x80BA51A4 ; Offset: 0x1AE4
    .dw toto_prepare_formal_replay

; Remove relocation for function pointer in data section.
; Replaces:
;   .dw 0x820001D4
.org 0x80BA53D4 ; Offset: 0x1D14
    .dw 0x00000000
