#ifndef I2C_H
#define I2C_H

/* Including libraries */
#include <stdint.h>

/* Defines */
#define I2C1_BASE       0x40005400

#define I2C1_CR1        (*(volatile uint32_t *)(I2C1_BASE + 0x00))
#define I2C1_CR2        (*(volatile uint32_t *)(I2C1_BASE + 0x04))
#define I2C1_DR         (*(volatile uint32_t *)(I2C1_BASE + 0x10))
#define I2C1_SR1        (*(volatile uint32_t *)(I2C1_BASE + 0x14))
#define I2C1_SR2        (*(volatile uint32_t *)(I2C1_BASE + 0x18))
#define I2C1_CCR        (*(volatile uint32_t *)(I2C1_BASE + 0x1C))
#define I2C1_TRISE      (*(volatile uint32_t *)(I2C1_BASE + 0x20))

#define RCC_APB1ENR     (*(volatile uint32_t *)0x4002101C)
#define RCC_APB2ENR     (*(volatile uint32_t *)0x40021018)
#define GPIOB_CRL       (*(volatile uint32_t *)0x40010C00)

/* Function prototypes */
void i2c_init(void);
void i2c_write_byte(uint8_t addr, uint8_t reg, uint8_t data);
uint8_t i2c_read_byte(uint8_t addr, uint8_t reg);
void i2c_read_bytes(uint8_t addr, uint8_t reg, uint8_t *buf, uint8_t len);

#endif /* I2C_H */