#include "interrupts.h"
#include "timer.h"

 __attribute__ ((interrupt ("machine")))
void handle_interrupt() 
{
    int mcause;
    asm volatile("csrr %0, mcause" :"=r"(mcause));
    if (mcause == MTIMER_INTERRUPT_CODE) {
       *MTIMECMP = *MTIME + TIMER_STEP;	
        is_interrupt_catched_f = 1; 
    }
}

void init_interrupt()
{
    int mstatus;
    int mie;
    asm volatile("csrw mtvec, %0" ::"r"(handle_interrupt));
    *MTIMECMP = *MTIME + TIMER_STEP;
    asm volatile("csrr %0, mstatus" : "=r"(mstatus));
    asm volatile("csrw mstatus, %0" ::"r"(mstatus | MIE)); // machine interrupts
    asm volatile("csrr %0, mie" : "=r"(mie));
    asm volatile("csrw mie, %0" ::"r"(mie | MTIE)); // enable timer interrupts
}