#ifndef UART_H
#define UART_H

#include <stdint.h>

typedef struct {
    volatile uint32_t TXDATA; // 0x00
    volatile uint32_t RXDATA; // 0x04
    volatile uint32_t TXCTRL; // 0x08
    volatile uint32_t RXCTRL; // 0x0C
    volatile uint32_t IE;     // 0x10
    volatile uint32_t IP;     // 0x14
    volatile uint32_t DIV;    // 0x18
} sUART;

#define UART_BASE 0x10010000
#define UART ((sUART*) UART_BASE)
#define TX_ENABLE 0x1
#define BAUD_RATE_DIV 2000
#define UART_FULL (1 << 31)

void uart_init();
void uart_transmit_byte(char data);
void print_uart(const char *str);
void print_uart_i(int x);

#endif 
