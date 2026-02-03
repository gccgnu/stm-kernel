#ifndef CLOCK_H
#define CLOCK_H

/* Including libraries */
#include <stdint.h>

/* Defines */
#define RCC_CR			(*(volatile uint32_t *)0x40021000)
#define RCC_CFGR		(*(volatile uint32_t *)0x40021004)
#define FLASH_ACR		(*(volatile uint32_t *)0x40022000)

#define RCC_CR_HSEON	(1 << 16)
#define RCC_CR_HSERDY	(1 << 17)
#define RCC_CR_PLLON	(1 << 24)
#define RCC_CR_PLLRDY	(1 << 25)

/* Function prototypes */
void system_clock_config(void);

#endif /* CLOCK_H */