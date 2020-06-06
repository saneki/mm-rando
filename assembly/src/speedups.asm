toto_should_skip_formal_replay_hook:
    addiu   sp, sp, -0x18
    sw      ra, 0x0014 (sp)

    or      a0, s4, r0
    jal     toto_should_skip_formal_replay
    or      a1, s3, r0

    ; Displaced code
    lui     t8, 0x801F
    addu    t9, s5, s0

    lw      ra, 0x0014 (sp)
    jr      ra
    addiu   sp, sp, 0x18

toto_before_advance_formal_replay_hook:
    sw      a1, 0x0024 (sp)

    addiu   sp, sp, -0x18
    sw      ra, 0x0014 (sp)

    jal     toto_before_advance_formal_replay
    sw      a0, 0x0010 (sp)

    lw      a0, 0x0010 (sp)
    lw      ra, 0x0014 (sp)
    jr      ra
    addiu   sp, sp, 0x18

toto_handle_advance_formal_replay_hook:
    lw      a0, 0x0020 (sp)
    lw      a1, 0x0024 (sp)

    addiu   sp, sp, -0x18
    addu    ra, ra, a2
    sw      ra, 0x0014 (sp)

    jal     toto_handle_advance_formal_replay
    nop

    lw      ra, 0x0014 (sp)
    jr      ra
    addiu   sp, sp, 0x18
