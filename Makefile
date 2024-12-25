# Toolchain.
TOOLCHAIN_PREFIX=./toolchain/bin/arm-none-eabi-
CC=$(TOOLCHAIN_PREFIX)gcc
LD=$(TOOLCHAIN_PREFIX)ld
OBJCPOPY=$(TOOLCHAIN_PREFIX)objcopy
AR=$(TOOLCHAIN_PREFIX)ar

# Build directory.
BUILD_DIR=./bin/

# Terminal color.
GREEN=\033[0;32m
NC=\033[0m

# Input objects.
BSP_INC=./bsp/inc
DRIVER_INC=./drivers/inc
DRIVER_OBJS+= $(BUILD_DIR)drivers/stm32f407xx_gpio.o \
	$(BUILD_DIR)drivers/stm32f407xx_nvic.o \
	$(BUILD_DIR)drivers/stm32f407xx_usart.o \
	$(BUILD_DIR)drivers/stm32f407xx_rcc.o \
	$(BUILD_DIR)bsp/stm32f407xx_led.o

OBJS+= 	$(BUILD_DIR)main.o \
		$(BUILD_DIR)boot/startup_stm32f407xx.o \
		$(BUILD_DIR)boot/syscalls.o

# Output objects.
DRIVER_LIB=$(BUILD_DIR)driver.a
KERNEL_ELF=$(BUILD_DIR)kernel.elf
KERNEL_BIN=$(BUILD_DIR)kernel.bin
MEM_MAP=$(BUILD_DIR)memory.map

# Flags.
MACH=cortex-m4
CFLAGS= -c -g -mcpu=$(MACH) -std=gnu11 -o0 -Wall -I$(DRIVER_INC) -I$(BSP_INC)
LDFLAGS= -mcpu=$(MACH) -T ./boot/linker_stm32f407xx.ld -Wl,-Map=$(MEM_MAP)

all: $(DRIVER_LIB) $(KERNEL_ELF) $(KERNEL_BIN)
	@echo "Built: ${GREEN}$^${NC}"

$(DRIVER_LIB): $(DRIVER_OBJS)
	$(AR) rcs $@ $^

$(KERNEL_ELF): $(OBJS) $(DRIVER_LIB)
	$(CC) $(LDFLAGS) $^ $(DRIVER_LIB) -o $@

$(KERNEL_BIN): $(KERNEL_ELF)
	$(OBJCPOPY) -O binary $(KERNEL_ELF) $(KERNEL_BIN)

$(BUILD_DIR)%.o: %.c
	 @mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf bin
