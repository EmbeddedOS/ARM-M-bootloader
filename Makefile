TOOLCHAIN_PATH=./toolchain
CC=$(TOOLCHAIN_PATH)/bin/arm-none-eabi-gcc
LD=$(TOOLCHAIN_PATH)/bin/arm-none-eabi-ld
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -o0 -Wall
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T linker_stm32f407xx.ld -Wl,-Map=memory.map

OBJS+= 	./main.o \
		./startup_stm32f407xx.o
SYSCALLS_OBJ=syscalls.o

all: final.elf
	@echo "BUild final executable file done."

final.elf: $(OBJS) $(SYSCALLS_OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf
