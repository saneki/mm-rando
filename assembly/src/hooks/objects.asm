;==================================================================================================
; Object Heap Size
;==================================================================================================

.headersize(G_CODE_RAM - G_CODE_FILE)

; Replaces:
;   or      a2, a1, r0
;   lh      v0, 0x00A4 (s0) ;; V0 = Scene Id
;   addiu   at, r0, 0x006F
;   addiu   v1, r0, 0x0003  ;; V1 = 3
;   beq     v0, at, 0x8012F410
;   addiu   a0, r0, 0x0023  ;; A0 = 0x23
;   addiu   at, r0, 0x006C
.org 0x8012F3E0
.area 0x1C
    jal     objects_get_heap_size
    sw      a1, 0x0010 (sp)
    lw      a2, 0x0010 (sp) ;; A2 = arg1
    or      a3, v0, r0      ;; A3 = Heap size
    addiu   a0, r0, 0x0023  ;; A0 = 0x23
    b       0x8012F44C      ;; Branch past vanilla code for determining object heap size.
    addiu   v1, r0, 0x0003  ;; V1 = 3
.endarea
