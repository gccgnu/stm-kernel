/* Including header file */
#include "clock.h"

void
system_clock_config(void)
{
	/* Enabling HSE */
	RCC_CR |= RCC_CR_HSEON;
	while (!(RCC_CR & RCC_CR_HSERDY)); // Wait to enabling HSE

  /* Setup flash */
	FLASH_ACR = 0x32;

	/* Setup PLL */
	RCC_CFGR = 0;
	RCC_CFGR |= (0x7 << 18);
	RCC_CFGR |= (1 << 16);
	RCC_CFGR |= (0x4 << 8);
	RCC_CFGR |= (0x0 << 11);
	RCC_CFGR |= (0x0 << 4);
    
  /* Enabling PLL */
	RCC_CR |= RCC_CR_PLLON;
	while (!(RCC_CR & RCC_CR_PLLRDY)); // Wait to enabling PLL

	/* Switching SYSCLK on PLL */
	RCC_CFGR |= 0x2;
	while ((RCC_CFGR & 0xC) != 0x8);  // Check SWS
}