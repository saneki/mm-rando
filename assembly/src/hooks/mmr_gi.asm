; =========================================================
; File: 0x00B3C000, Address: 0x00C72CD0, Offset: 0x00136CD0
; Name: code
; =========================================================
.headersize (0x800A5AC0 - 0x00B3C000)
; Replaces:
;   .dw 0x6E745F72 ; ldr     s4, 0x5F72(s3)
;   .dw 0x65675B38 ; daddiu  a3, t3, 0x5B38
;   .dw 0x325D0000 ; andi    sp, s2, 0x0000
;   .dw 0x7765656B ; jalx    0x8D9595AC
;   .dw 0x5F657665
.org 0x801DC790
    or      a3, a1, r0
    or      a2, a0, r0
    or      a1, s0, r0
    j       mmr_GetNewGiIndex
    or      a0, s6, r0
