// reset clock control
#include <libopencm3/stm32/rcc.h>

// gpio libraries
#include <libopencm3/stm32/gpio.h>

int main(void) {
  // enable the reset and clock control on port c
  // which is the gpio bus that led pin is tied to
  // doing this is required for doing gpio
  rcc_periph_clock_enable(RCC_GPIOC);

  // pin 13 led
  // push pull io pin toggleable
  // up to 2 MHZ
  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL,
                GPIO13);

  while (1) {
    for (int i = 0; i < 1000000; i++) {
      __asm__("nop");
    }

    gpio_toggle(GPIOC, GPIO13);
  }
}