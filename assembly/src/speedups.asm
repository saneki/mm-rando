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
