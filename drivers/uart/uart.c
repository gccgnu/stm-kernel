/* Including header file */
#include "uart.h"

void
uart_init(void)
{
	// Enable GPIOA and USART1 clocking
	RCC_APB2ENR |= (1 << 2);   
	RCC_APB2ENR |= (1 << 14);  
    
	// Configuring pins TX and RX
	GPIOA_CRH &= ~(0xF << 4);
	GPIOA_CRH |= (0xB << 4);
    
	GPIOA_CRH &= ~(0xF << 8);
	GPIOA_CRH |= (0x4 << 8);
    
	/* Setup baudrate 115200 */
	/* BRR = SYSCLK / baudrate = 72000000 / 115200 = 625 = 0x271 */
	USART1_BRR = 0x271;
    
	/* Enabling USART, TX and RX */
	USART1_CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

void
uart_putc(char c)
{
	while (!(USART1_SR & USART_SR_TXE));
	USART1_DR = c;
}

void
uart_print(const char *str)
{
	while (*str) {
		if (*str == '\n') {
			uart_putc('\r');
		}
		uart_putc(*str++);
	}
}

char
uart_getc(void)
{
	while (!(USART1_SR & USART_SR_RXNE));
	return USART1_DR;
}