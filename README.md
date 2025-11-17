# STM32F103

SWD: Serial Wire Debug

package: stlink-tools gcc-arm-none-eabi openocd gdb-multiarch

libopencm3: api for the peripherals on standard implementations of the Cortex M3 processor

1. git clone https://github.com/libopencm3/libopencm3-template.git
2. cd libopencm3-template
3. git submodule init
4. git submodule update
5. cd libopencm3
6. make

cmd: ls /dev | grep st, st-info, st-info --version, st-info --probe, st-flash --reset write blink-led.bin 0x8000000

PWR: power led
PC13: port c pin 13

openocd: Open On-Chip Debugger
a program that takes input in the form of files that describe to open ocd how to talk to the interface(the tool used to talk to the target chip) which
is the debugger that we're going to use and then the target(the chip that we'd like to debug)

1. openocd -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32f1x.cfg
   cfg: configuration
   that's basically going to tell the debugger how to talk to the st-link v2
   using these two files here the chip will know to go to the st-link v2 and using the st-link v2 try to talk to an stm32f1x and remember our blue pill is an f103 so this config file(stm32f1x.cfg) will work
   there is one slight change you may need to use if you're like me and you accidentally bought a cheep chinese knockoff of the chip
   I had to actually change this number here(vim /usr/share/openocd/scripts/target/stm32f1x.cfg)
   set \_CPUTAPID 0x1ba01477(정품) 0x2ba01477(가품) 0(칩 아이디를 특정하지 않음)
   정품 chipid: 0x410(확인 방법: st-info --probe)

2. netstat -tulpn | grep openocd
   port: 4444 telnet, 3333 gdb

3. gdb-multiarch ./blink-led.elf
   install gdb-multiarch to be able to debug files that are multiple architectures in gdb
   so gdb by default will only be able to debug intel programs. we need arm programs
   so I install that.

4. target extended-remote localhost:3333
5. lay next
6. break main
7. c (continue)
8. b 24 (breakpoint line number)
9. d 24 (delete breakpoint)
10. info registers
    pc: program counter
    r0, r5: value
11. refresh

## troubleshooting

Mac: https://developer.arm.com/downloads/-/gnu-rm 맥 버전 다운
sudo mkdir -p /opt/gcc-arm
sudo tar -xjf gcc-arm-none-eabi-\*-mac.tar.bz2 -C /opt/gcc-arm --strip-components=1
echo 'export PATH="/opt/gcc-arm/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc
