;==================================================================================================
; After crow has spawned a rupee
;==================================================================================================

.headersize (G_EN_RUPPECROW_VRAM - G_EN_RUPPECROW_FILE)

; Replaces:
;   jr	    ra
.org 0x80BE2B78
    j       rupeecrow_after_rupee_spawn_hook
