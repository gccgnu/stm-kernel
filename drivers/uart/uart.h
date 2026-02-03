#ifndef UART_H
#define UART_H

/* Including libraries */
#include <stdint.h>

/* Defines */
#define USART1_SR		(*(volatile uint32_t *)0x40013800)
#define USART1_DR		(*(volatile uint32_t *)0x40013804)
#define USART1_BRR		(*(volatile uint32_t *)0x40013808)
#define USART1_CR1		(*(volatile uint32_t *)0x4001380C)

#define RCC_APB2ENR		(*(volatile uint32_t *)0x40021018)

#define GPIOA_CRH		(*(volatile uint32_t *)0x40010804)

#define USART_SR_TXE	(1 << 7)
#define USART_SR_RXNE	(1 << 5)
#define USART_CR1_TE	(1 << 3)
#define USART_CR1_RE	(1 << 2)
#define USART_CR1_UE	(1 << 13)

/* Function prototypes */
void uart_init(void);
void uart_putc(char c);
void uart_print(const char *str);
char uart_getc(void);

#endif /* UART_H */