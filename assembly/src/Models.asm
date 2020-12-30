Models_BeforeStrayFairyMain_Hook:
    ; Store A1 for later usage if needed
    sw      a1, 0x001C (sp)

    addiu   sp, sp, -0x20
    sw      ra, 0x0018 (sp)
    sw      a0, 0x0010 (sp)

    jal     Models_BeforeStrayFairyMain
    sw      a1, 0x0014 (sp)

    lw      a0, 0x0010 (sp)
    lw      a1, 0x0014 (sp)

    ; Displaced code
    lw      t9, 0x022C (a0)

    lw      ra, 0x0018 (sp)
    jr      ra
    addiu   sp, sp, 0x20

Models_DrawStrayFairy_Hook:
    ; Displaced code
    or      s0, a1, r0

    addiu   sp, sp, -0x20
    sw      ra, 0x0018 (sp)
    sw      a0, 0x0010 (sp)

    jal     Models_DrawStrayFairy
    sw      a1, 0x0014 (sp)

    bnez    v0, @@caller_return
    nop

    lw      ra, 0x0018 (sp)
    lw      a0, 0x0010 (sp)
    lw      a1, 0x0014 (sp)

    jr      ra
    addiu   sp, sp, 0x20

@@caller_return:
    ; Will be returning from caller function, so restore S0
    addiu   sp, sp, 0x20
    lw      s0, 0x0028 (sp)

    ; Restore RA from caller's caller function
    lw      ra, 0x002C (sp)

    ; Fix stack for caller and return
    jr      ra
    addiu   sp, sp, 0x40

Models_DrawHeartContainer_Hook:
    addiu   sp, sp, -0x20
    sw      ra, 0x0018 (sp)
    sw      a0, 0x0010 (sp)

    jal     Models_DrawHeartContainer
    sw      a1, 0x0014 (sp)

    bnez    v0, @@caller_return
    nop

    lw      a0, 0x0010 (sp)
    lw      a1, 0x0014 (sp)

    ; Displaced code
    or      a3, r0, r0
    lw      a2, 0x0000 (a1)

    lw      ra, 0x0018 (sp)
    jr      ra
    addiu   sp, sp, 0x20

@@caller_return:
    addiu   sp, sp, 0x20

    ; Restore RA from caller's caller function
    lw      ra, 0x0014 (sp)

    ; Fix stack for caller and return
    jr      ra
    addiu   sp, sp, 0x48

Models_DrawBossRemains_Hook:
    addiu   sp, sp, -0x18
    sw      ra, 0x0010 (sp)

    ; Shift arguments
    or      a2, a1, r0
    or      a1, a0, r0

    jal     Models_DrawBossRemains
    or      a0, s0, r0

    lw      ra, 0x0010 (sp)
    jr      ra
    addiu   sp, sp, 0x18

Models_BeforeMoonsTearMain_Hook:
    addiu   sp, sp, -0x20
    sw      ra, 0x0018 (sp)
    sw      a0, 0x0010 (sp)

    jal     Models_BeforeMoonsTearMain
    sw      a1, 0x0014 (sp)

    ; Displaced code
    lui     at, 0x1000
    ori     at, at, 0x0282

    lw      a0, 0x0010 (sp)
    lw      a1, 0x0014 (sp)
    lw      ra, 0x0018 (sp)
    jr      ra
    addiu   sp, sp, 0x20

Models_DrawMoonsTear_Hook:
    addiu   sp, sp, -0x20
    sw      ra, 0x0018 (sp)
    sw      a0, 0x0010 (sp)
    jal     Models_DrawMoonsTear
    sw      a1, 0x0014 (sp)

    bnez    v0, @@caller_return
    nop

    lw      a0, 0x0010 (sp)
    lw      a1, 0x0014 (sp)

    ; Displaced code
    or      s1, a1, r0

    lw      ra, 0x0018 (sp)
    jr      ra
    addiu   sp, sp, 0x20

@@caller_return:
    addiu   sp, sp, 0x20

    ; Restore RA from caller's caller function
    lw      ra, 0x001C (sp)

    ; Fix stack for caller and return
    jr      ra
    addiu   sp, sp, 0x38

Models_DrawLabFishHeartPiece_Hook:
    ; Displaced code
    sw      a1, 0x0034 (sp)

    addiu   sp, sp, -0x18
    sw      ra, 0x0010 (sp)

    jal     Models_DrawLabFishHeartPiece
    nop

    bnez    v0, @@caller_return
    nop

    lw      ra, 0x0010 (sp)
    jr      ra
    addiu   sp, sp, 0x18

@@caller_return:
    ; Restore S0
    addiu   sp, sp, 0x18
    lw      s0, 0x0018 (sp)

    ; Restore RA from caller's caller function
    lw      ra, 0x001C (sp)

    ; Fix stack for caller and return
    jr      ra
    addiu   sp, sp, 0x30

Models_BeforeSeahorseMain_Hook:
    ; Displaced code
    or      s0, a0, r0

    addiu   sp, sp, 0x18
    sw      ra, 0x0014 (sp)

    jal     Models_BeforeSeahorseMain
    sw      a1, 0x0010 (sp)

    lw      a1, 0x0010 (sp)
    lw      ra, 0x0014 (sp)
    jr      ra
    addiu   sp, sp, -0x18

Models_DrawSeahorse_Hook:
    ; Displaced code
    sw      a1, 0x0054 (sp)

    addiu   sp, sp, -0x18
    sw      ra, 0x0010 (sp)

    jal     Models_DrawSeahorse
    nop

    bnez    v0, @@caller_return
    nop

    lw      ra, 0x0010 (sp)
    jr      ra
    addiu   sp, sp, 0x18

@@caller_return:
    ; Restore S0
    addiu   sp, sp, 0x18
    lw      s0, 0x0028 (sp)

    ; Restore RA from caller's caller function
    lw      ra, 0x002C (sp)

    ; Fix stack for caller and return
    jr      ra
    addiu   sp, sp, 0x50

Models_DrawShopInventory_Hook:
    addiu   sp, sp, -0x18
    sw      ra, 0x0010 (sp)

    ; Shift arguments
    or      a2, a1, r0
    or      a1, a0, r0

    jal     Models_DrawShopInventory
    or      a0, s0, r0

    lw      ra, 0x0010 (sp)
    jr      ra
    addiu   sp, sp, 0x18

Models_BioBabaHeartPieceRotationFix_Hook:
    bnez    at, @@return
    nop
    addiu   at, r0, 0x0017
    beq     v0, at, @@return
    addiu   at, r0, 0x0001
    slti    at, v0, 0x001D
    xori    at, at, 0x0001

@@return:
    jr      ra
    nop
