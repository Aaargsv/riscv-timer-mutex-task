#include "uart.h"
#include "mutex.h"
#include "interrupts.h"
#include "utils.h"
#include <stdint.h>

Mutex m;
int is_interrupt_catched_f = 0;

void timer_output()
{
    // loop for hart 0
    for(;;) {
        if (is_interrupt_catched_f) {
            mutex_lock(&m);
            print_uart("I am printing because a timer interruption occurred\n");
            mutex_unlock(&m);
            is_interrupt_catched_f = 0;
        }
    }
}

int main()
{
    uart_init();
    // loop for hart 1
    for(;;) {
        delay(100000000);
        mutex_lock(&m);
        print_uart("This is the string from main\n");
        mutex_unlock(&m);
    }
	return 0;
}