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

item00_give_item_hook:
    addiu   sp, sp, -0x20
    sw      ra, 0x0010 (sp)
    sw      a0, 0x0014 (sp)
    sw      a1, 0x0018 (sp)
    sw      a2, 0x001C (sp)

    or      a1, a0, r0
    jal     item00_give_item
    or      a0, s0, r0

    beq     v0, r0, @@displaced_code
    nop

    lui     t3, 0x800A
    b       @@caller_return
    addiu   t3, t3, 0x6FD8

@@displaced_code:
    lhu     t3, 0x001C (s0)
    lui     at, 0x801E
    addu    at, at, t3
    lw      t3, 0xBF24 (at)

@@caller_return:
    lw      a2, 0x001C (sp)
    lw      a1, 0x0018 (sp)
    lw      a0, 0x0014 (sp)
    lw      ra, 0x0010 (sp)
    jr      ra
    addiu   sp, sp, 0x20