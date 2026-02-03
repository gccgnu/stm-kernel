/* Including header file */
#include "gpio.h"

/* Enable port clocking */
void 
gpio_enable(uint32_t port)
{
	if (port == GPIOA) 
		RCC_APB2ENR |= (1 << 2);
	if (port == GPIOB) 
		RCC_APB2ENR |= (1 << 3);
	if (port == GPIOC) 
		RCC_APB2ENR |= (1 << 4);
}

/* Configure the pin as an output */
void 
gpio_output(uint32_t port, uint8_t pin)
{
	volatile uint32_t *cr;
    
	if (pin < 8) {
		cr = (volatile uint32_t *)(port + 0x00); // CRL
	} else {
		cr = (volatile uint32_t *)(port + 0x04); // CRH
		pin -= 8;
	}
    
	*cr &= ~(0xF << (pin * 4));
	*cr |= (0x2 << (pin * 4)); // Output 2MHz, Push-Pull
}

/* Set pin to 1 */
void 
gpio_set(uint32_t port, uint8_t pin)
{
	volatile uint32_t *bsrr = (volatile uint32_t *)(port + 0x10);
	*bsrr = (1 << pin);
}

/* Set pin to 0 */
void
gpio_reset(uint32_t port, uint8_t pin)
{
	volatile uint32_t *bsrr = (volatile uint32_t *)(port + 0x10);
	*bsrr = (1 << (pin + 16));
}

/* Switch pin */
void
gpio_toggle(uint32_t port, uint8_t pin)
{
	volatile uint32_t *odr = (volatile uint32_t *)(port + 0x0C);
	*odr ^= (1 << pin);
}