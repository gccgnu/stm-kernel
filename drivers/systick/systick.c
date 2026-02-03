/* Including header file */
#include "systick.h"

void
delay_ms(uint32_t ms)
{
	/* 72MHz / 1000 = 72000 ticks per ms */
	const uint32_t ticks_per_ms = 72000;
    
	while (ms--) {
		/* Load value */
		SYSTICK_RVR = ticks_per_ms - 1;
        
		/* Clear current value */
		SYSTICK_CVR = 0;
        
		/* Enable, use processor clock */
		SYSTICK_CSR = SYSTICK_ENABLE | SYSTICK_CLKSOURCE;
        
		/* Wait for COUNTFLAG */
		while (!(SYSTICK_CSR & SYSTICK_COUNTFLAG));
        
		/* Disable */
		SYSTICK_CSR = 0;
	}
}