.global _start

_start:
    csrr    t0, mhartid             # read current hart id
    beq     t0, zero, timer_thread  # hart 0 execute timer_output
    la      sp, _estack1            
    la      t1, 1
    bne     t0, t1, park
    j main
	
timer_thread:
    la  sp, _estack0 
    jal init_interrupt
    j   timer_output

park:
    wfi
    j park
	

	
