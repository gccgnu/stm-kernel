#ifndef GPIO_H
#define GPIO_H

/* Including libraries */
#include <stdint.h>

/* Defines */
#define RCC_APB2ENR (*(volatile uint32_t *)0x40021018)

/* Base address ports */
#define GPIOA 0x40010800
#define GPIOB 0x40010C00
#define GPIOC 0x40011000

/* Function prototypes */
void gpio_enable(uint32_t port);
void gpio_output(uint32_t port, uint8_t pin);
void gpio_set(uint32_t port, uint8_t pin);
void gpio_reset(uint32_t port, uint8_t pin);
void gpio_toggle(uint32_t port, uint8_t pin);

#endif /* GPIO_H */