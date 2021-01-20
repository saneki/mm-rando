ScRuppe_GiveItem_Hook:
    addiu   sp, sp, -0x20
    sw      ra, 0x0010 (sp)

    mtc1    r0, f4
    sh      r0, 0x0194 (a2)
    swc1    f4, 0x0074 (a2)

    jal     ScRuppe_GiveItem
    nop

    addiu   a1, r0, 0x4803
    lw      ra, 0x0010 (sp)
    jr      ra
    addiu   sp, sp, 0x20

ScRuppe_Constructor_Hook:
    or      a0, s0, r0
    j       ScRuppe_Constructor
    lw      a1, 0x0004 (sp)
