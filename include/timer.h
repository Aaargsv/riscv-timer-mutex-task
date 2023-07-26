#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#define CLINT_BASE 0x02000000
#define MTIME (volatile uint32_t*)(CLINT_BASE + 0xBFF8)
#define MTIMECMP (volatile uint32_t*)(CLINT_BASE + 0x4000)
#define TIMER_STEP 300000

#endif