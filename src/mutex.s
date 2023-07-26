.global mutex_lock
mutex_lock:
    addi sp, sp, -8
    sw t0, 4(sp)
    sw t1, 8(sp)

    li t0, 1
lock_loop:	
    lw              t1, 0(a0)
    bnez            t1, lock_loop
    amoswap.w.aq    t1, t0, 0(a0)
    bnez            t1, lock_loop
    lw              t0, 4(sp)
    lw              t1, 8(sp)
    addi            sp, sp, 8
    ret

.global mutex_unlock
mutex_unlock:
    amoswap.w.rl zero, zero, 0(a0)
    ret
	