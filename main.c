/* Including libraries */
#include <stdint.h>

#include "drivers/gpio/gpio.h"
#include "drivers/uart/uart.h"
#include "drivers/systick/systick.h"
#include "drivers/i2c/i2c.h"

/* Main function */
int 
main(void)
{
	/* Init all components */
	uart_init();
	i2c_init();

	uart_print("Kernel loaded!\n");

	while(1);
    
	return 0;
}