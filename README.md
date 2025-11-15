# STM32F103

SWD: Serial Wire Debug

package: stlink-tools gcc-arm-none-eabi

libopencm3: api for the peripherals on standard implementations of the Cortex M3 processor

1. git clone https://github.com/libopencm3/libopencm3-template.git
2. cd libopencm3-template
3. git submodule init
4. git submodule update
5. cd libopencm3
6. make

cmd: ls /dev | grep st, st-info, st-info --version, st-info --probe, st-flash --reset write blink-led.bin(bin_file) 0x8000000(address)
