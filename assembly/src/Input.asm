Input_BeforePlayUpdate_Hook:
    addiu   sp, sp, -0x18
    sw      t9, 0x0010 (sp)
    sw      ra, 0x0014 (sp)
    sw      a0, 0x0018 (sp)

    jal     Input_BeforePlayUpdate
    or      a0, t6, r0

    ; Displaced code


    lw      a0, 0x0018 (sp)
    lw      ra, 0x0014 (sp)
    lw      t9, 0x0010 (sp)
    addiu   sp, sp, 0x18
    jr      ra
    lw      v0, 0x0024 (sp)
