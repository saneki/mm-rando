;==================================================================================================
; Check Speedups - Sound Check (Actor Cutscene Index 0xC)
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

;==================================================================================================
; Check Speedups - Sound Check (Actor Cutscene Index 0xD)
;==================================================================================================

; Call hook before beginning of function which may advance Toto cutscene state.
; Replaces:
;   sw      s0, 0x0018 (sp)
;   sw      a1, 0x0024 (sp)
.org 0x80BA4A08 ; Offset: 0x1348
    jal     toto_before_advance_formal_replay_hook
    sw      s0, 0x0018 (sp)

; Update behavior when advancing Toto cutscene state (1).
; Replaces:
;   b       0x80BA4B10
;   addiu   v0, r0, 0x0001
.org 0x80BA4AE0 ; Offset: 0x1420
    jal     toto_handle_advance_formal_replay_hook
    addiu   a2, r0, 0x0028

; Update behavior when advancing Toto cutscene state (2).
; Replaces:
;   b       0x80BA4B10
;   addiu   v0, r0, 0x0001
.org 0x80BA4AF4 ; Offset: 0x1434
    jal     toto_handle_advance_formal_replay_hook
    addiu   a2, r0, 0x0014

; Update behavior when advancing Toto cutscene state (3).
; Replaces:
;   b       0x80BA4B10
;   addiu   v0, r0, 0x0001
.org 0x80BA4B04 ; Offset: 0x1444
    jal     toto_handle_advance_formal_replay_hook
    addiu   a2, r0, 0x0004
