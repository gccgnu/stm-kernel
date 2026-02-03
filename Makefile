# Compilers and utilities
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

# Project name
PROJECT = stmkernel

# Flags
LDSCRIPT = boot/linker.ld
CFLAGS = -mcpu=cortex-m3 -mthumb -Os -Wall -ffunction-sections -fdata-sections
LDFLAGS = -T$(LDSCRIPT) -nostartfiles -Wl,--gc-sections

# Sources
SOURCES = $(shell find . -name '*.c')
ASM_SOURCES = $(shell find . -name '*.S')
OBJECTS = $(SOURCES:.c=.o) $(ASM_SOURCES:.S=.o)

# Default target
all: $(PROJECT).elf $(PROJECT).bin

# Linking
$(PROJECT).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	$(SIZE) $@

# Creating .bin file
$(PROJECT).bin: $(PROJECT).elf
	$(OBJCOPY) -O binary $< $@

# Compile .c files
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Compile .S files
.S.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	find . -name '*.o' -delete
	rm -f $(PROJECT).elf $(PROJECT).bin

# Flashing
flash: $(PROJECT).bin
	st-flash write $(PROJECT).bin 0x8000000

.SUFFIXES: .c .S .o
.PHONY: all clean flash