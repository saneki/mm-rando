;==================================================================================================
; Elegy Speedup
;==================================================================================================

.headersize(G_EN_TORCH2_VRAM - G_EN_TORCH2_FILE)

; Get the speed at which the Elegy statue fades in or out.
; Replaces:
;   sll     a1, v0, 16
;   sra     a1, a1, 16
;   addiu   a0, s0, 0x0192
;   jal     0x800FEF2C
;   addiu   a2, r0, 0x0008
.org 0x808A3400 ; Offset: 0x250
    jal     elegy_speedup_get_statue_fade_speed_hook
    or      a1, v0, r0
    addiu   a0, s0, 0x0192
    jal     0x800FEF2C
    or      a2, v0, r0

.headersize(G_EFF_CHANGE_VRAM - G_EFF_CHANGE_FILE)

; Sync position of Eff_Change effect with the position of the Elegy statue.
; Replaces:
;   sw      s0, 0x0020 (sp)
;   or      s0, a0, r0
;   sw      ra, 0x0024 (sp)
;   sw      a1, 0x002C (sp)
.org 0x80A4C5D0 ; Offset: 0x140
    sw      ra, 0x0024 (sp)
    sw      s0, 0x0020 (sp)
    jal     elegy_speedup_update_effect_position_hook
    sw      a1, 0x002C (sp)

; Handle whether or not to darken the scene during Elegy animation.
; Replaces:
;   jal     0x800FD2B4
.org 0x80A4C734
    jal     elegy_speedup_handle_darken_hook

; Handle whether or not to update the camera during Elegy animation.
; Replaces:
;   jal     0x800F1D84
.org 0x80A4C760
    jal     elegy_speedup_handle_camera_hook

.headersize(G_PLAYER_ACTOR_VRAM - G_PLAYER_ACTOR_FILE)

; Get frames to wait before beginning to despawn current Elegy statue.
; Replaces:
;   lw      v1, 0x004C (sp)
;   lh      t8, 0x00BE (s0)
;   addiu   t9, r0, 0x0014
.org 0x80848684 ; Offset: 0x1ABF4
    jal     elegy_speedup_get_statue_despawn_counter_hook
    lw      v1, 0x004C (sp)
    lh      t8, 0x00BE (s0)

; Get fields regarding how long Link is locked in place, and which frame to handle the Elegy statue.
; Replaces:
;   or      a2, a0, r0
;   or      a3, a1, r0
.org 0x80855A84 ; Offset: 0x27FF4
    jal     elegy_speedup_get_lock_params_hook
    or      a2, a0, r0

; Set how many frames until Link is "unlocked".
; Replaces:
;   slti    v1, v0, 0x005B
.org 0x80855A98
    slt     v1, v0, t0

; Set which frame should call the function to handle the Elegy statue.
; Replaces:
;   addiu   at, r0, 0x000A
.org 0x80855ACC
    addu    at, r0, t1
