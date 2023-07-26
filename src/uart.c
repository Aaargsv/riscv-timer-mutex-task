#include <stdint.h>
#include "uart.h"

void uart_init()
{
    UART->DIV = BAUD_RATE_DIV;
    UART->TXCTRL = TX_ENABLE;
}

void uart_transmit_byte(char data)
{	
    while ((UART->TXDATA & UART_FULL)); // while it's full
    UART->TXDATA = data;
} 

void print_uart(const char *str)
{
    for (int i = 0; *str != '\0'; i++)
        uart_transmit_byte(*str++);
}

void print_uart_i(int x) {
    if (x < 0) {
        print_uart("-");
        x = -x;
    }
    if (x >= 10) {
        print_uart_i(x / 10);
    } 
    uart_transmit_byte(x % 10 + '0');
}

