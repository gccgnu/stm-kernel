# STM32F103 simple kernel

Simple kernel for STM32F103 (Blue Pill) without HAL and external dependencies.

## Features

- GPIO: input/output, toggle, set/reset
- UART: send and receive data (115200 baud)
- I2C: read and write devices
- SysTick: delay_ms, delay_us

## Build
```BASH
make
```

## Flashing with ST-Link v2
```BASH
make flash
```

## Note
The kernel was written using other sources and guides.

## License
MIT
