/* Including header file */
#include "i2c.h"

static void
i2c_start(void)
{
	I2C1_CR1 |= (1 << 10);  /* ACK */
	I2C1_CR1 |= (1 << 8);   /* START */
	while (!(I2C1_SR1 & 1));
}

static void
i2c_stop(void)
{
	I2C1_CR1 |= (1 << 9);
	while (I2C1_SR2 & 2);
}

static void
i2c_addr(uint8_t addr, uint8_t rw)
{
	I2C1_DR = (addr << 1) | rw;
	while (!(I2C1_SR1 & 2));
	(void)I2C1_SR1;
	(void)I2C1_SR2;
}

static void
i2c_write(uint8_t data)
{
	while (!(I2C1_SR1 & (1 << 7)));
	I2C1_DR = data;
	while (!(I2C1_SR1 & (1 << 2)));
}

static uint8_t
i2c_read(uint8_t ack)
{
	if (ack) {
		I2C1_CR1 |= (1 << 10);
	} else {
		I2C1_CR1 &= ~(1 << 10);
		I2C1_CR1 |= (1 << 9);
	}
	while (!(I2C1_SR1 & (1 << 6)));
	return I2C1_DR;
}

void
i2c_init(void)
{
	RCC_APB2ENR |= (1 << 3);
	RCC_APB1ENR |= (1 << 21);
    
	GPIOB_CRL &= ~(0xFF << 24);
	GPIOB_CRL |= (0xFF << 24);
    
	I2C1_CR1 |= (1 << 15);
	I2C1_CR1 &= ~(1 << 15);
    
	I2C1_CR2 = 36;
	I2C1_CCR = 180;
	I2C1_TRISE = 37;
	I2C1_CR1 |= 1;
}

void
i2c_write_byte(uint8_t addr, uint8_t reg, uint8_t data)
{
	i2c_start();
	i2c_addr(addr, 0);
	i2c_write(reg);
	i2c_write(data);
	i2c_stop();
}

uint8_t
i2c_read_byte(uint8_t addr, uint8_t reg)
{
	i2c_start();
	i2c_addr(addr, 0);
	i2c_write(reg);
	i2c_start();
	i2c_addr(addr, 1);
	return i2c_read(0);
}

void
i2c_read_bytes(uint8_t addr, uint8_t reg, uint8_t *buf, uint8_t len)
{
	i2c_start();
	i2c_addr(addr, 0);
	i2c_write(reg);
	i2c_start();
	i2c_addr(addr, 1);
    
	for (uint8_t i = 0; i < len; i++) {
		buf[i] = i2c_read(i < len - 1);
	}
}