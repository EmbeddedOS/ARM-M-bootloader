TOOLCHAIN_PREFIX=./toolchain/bin/arm-none-eabi-
CC=$(TOOLCHAIN_PREFIX)gcc
LD=$(TOOLCHAIN_PREFIX)ld
OBJCPOPY=$(TOOLCHAIN_PREFIX)objcopy

MACH=cortex-m4
CFLAGS= -c -g -mcpu=$(MACH) -std=gnu11 -o0 -Wall
LDFLAGS= -mcpu=$(MACH) -T linker_stm32f407xx.ld -Wl,-Map=memory.map

OBJS+= 	./main.o \
		./startup_stm32f407xx.o \
		./syscalls.o

all: boot.elf boot.bin
	@echo "Built final executable file done."

boot.elf: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

boot.bin: boot.elf
	$(OBJCPOPY) -O binary boot.elf boot.bin

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf
