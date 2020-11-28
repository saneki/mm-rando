;==================================================================================================
; Skullwalltula Path
;==================================================================================================

.headersize(G_EN_SW_VRAM - G_EN_SW_FILE)

; Replaces:
;   jal     0x8013BEDC ;; Calls: z2_Scene_GetPathEntry
.org 0x808DB57C ;; Offset: 0x2C3C
    jal     world_skulltula_get_path_override
