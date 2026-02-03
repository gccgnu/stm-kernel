#ifndef SYSTICK_H
#define SYSTICK_H

/* Including libraries */
#include <stdint.h>

/* Defines */

/* SysTick registers */
#define SYSTICK_BASE		0xE000E010

#define SYSTICK_CSR			(*(volatile uint32_t *)(SYSTICK_BASE + 0x00))
#define SYSTICK_RVR			(*(volatile uint32_t *)(SYSTICK_BASE + 0x04))
#define SYSTICK_CVR			(*(volatile uint32_t *)(SYSTICK_BASE + 0x08))

/* CSR bits */
#define SYSTICK_ENABLE		(1 << 0)
#define SYSTICK_TICKINT		(1 << 1)
#define SYSTICK_CLKSOURCE	(1 << 2)
#define SYSTICK_COUNTFLAG	(1 << 16)

/* Function prototypes */
void delay_ms(uint32_t ms);

#endif /* SYSTICK_H */