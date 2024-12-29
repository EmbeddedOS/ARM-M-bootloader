# ARM-M-bootloader

ARM v7 Cortex Mx bootloader & Drivers.

```bash
qemu-system-arm -machine netduinoplus2 -kernel bin/kernel.elf -serial stdio
```

## Run with custom QEMU for STM32f407xx

```bash
git submodule update --init
cd qemu_stm32f407_soc
./install.sh
mkdir build
cd build
../qemu/configure --target-list=aarch64-linux-user,arm-linux-user,arm-softmmu
make -j20
cd ../../
```

```bash
qemu_stm32f407_soc/build/qemu-system-arm -machine stm32f407g_disc -kernel bin/kernel.elf -serial stdio
```
