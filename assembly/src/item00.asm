item00_constructor_hook:
    addiu   sp, sp, -0x1C
    sw      ra, 0x0010 (sp)
    sw      a0, 0x0014 (sp)
    sw      a1, 0x0018 (sp)
    or      a0, s0, r0
    jal     item00_constructor
    lw      a1, 0x0068 (sp)
    
    ; Displaced code
    lh      t4, 0x001C (s0)
    addiu   at, r0, 0x0015

    lw      a1, 0x0018 (sp)
    lw      a0, 0x0014 (sp)
    lw      ra, 0x0010 (sp)

    jr      ra
    addiu   sp, sp, 0x1C