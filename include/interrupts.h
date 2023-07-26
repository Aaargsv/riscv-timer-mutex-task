#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#define MIE  (1 << 3) // machine interrupt enable
#define MTIE (1 << 7) // machine timer interrupt enable
#define MTIMER_INTERRUPT_CODE 0x7

extern int is_interrupt_catched_f; 
void  __attribute__ ((interrupt ("machine"))) handle_interrupt();
void init_interrupt();

#endif