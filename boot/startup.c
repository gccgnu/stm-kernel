#include <stdint.h>
#include "../drivers/clock/clock.h"

/* From linker file */
extern uint32_t _estack;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sidata;
extern uint32_t _sbss;
extern uint32_t _ebss;

/* Function prototypes */
void Reset_Handler(void);
void Default_Handler(void);
extern int main(void);

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

/* Vector table */
__attribute__((section(".isr_vector")))
void (* const vectors[])(void) = {
	(void (*)(void))((uint32_t)&_estack),
	Reset_Handler,
	NMI_Handler,
	HardFault_Handler,
	MemManage_Handler,
	BusFault_Handler,
	UsageFault_Handler,
	0,
	0,
	0,
	0,
	SVC_Handler,
	0,
	0,
	PendSV_Handler,
	SysTick_Handler
};

void 
Reset_Handler(void)
{
	uint32_t *src, *dst;

	/* Coping .data from FLASH to RAM */
	src = &_sidata;
	dst = &_sdata;
	while (dst < &_edata) {
		*dst++ = *src++;
	}

	/* Clearing .bss */
	dst = &_sbss;
	while (dst < &_ebss) {
		*dst++ = 0;
	}

	/* Setup system clock */
	system_clock_config();

	/* Calling main() */
	main();

	while (1);
}

void 
Default_Handler(void)
{
	while (1);
}