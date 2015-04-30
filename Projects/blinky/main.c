/*
 * Ref: https://github.com/Malkavian/tuts/blob/master/stm/blinky/main.c
*/

#include "main.h"

#define ORANGE LED3_PIN
#define GREEN  LED4_PIN
#define RED    LED5_PIN
#define BLUE   LED6_PIN

#define ALL_LEDS (GREEN | ORANGE | RED | BLUE)

#define PAUSE_LONG  400
#define PAUSE_SHORT 100

#define LEDS_GPIO_PORT (GPIOD)


/* LEDn is defined in stm32f4_discovery.h */
static uint16_t leds[LEDn] = {GREEN, ORANGE, RED, BLUE};

/* GPIO pins are declared in stm32f4xx_hal_gpio.h */
GPIO_InitTypeDef GPIO_InitStructure;


static void setup_leds(void)
{
  __GPIOD_CLK_ENABLE();
  GPIO_InitStructure.Pin   = ALL_LEDS;
  GPIO_InitStructure.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
  GPIO_InitStructure.Pull  = GPIO_PULLUP;
  HAL_GPIO_Init(LEDS_GPIO_PORT, &GPIO_InitStructure);
}


static void led_round(void)
{
  int i;
  for (i = 0; i < LEDn; i++) {
    HAL_GPIO_WritePin(LEDS_GPIO_PORT, leds[i], GPIO_PIN_SET);
    HAL_Delay(PAUSE_LONG);
    HAL_GPIO_WritePin(LEDS_GPIO_PORT, leds[i], GPIO_PIN_RESET);
  }
}


/* Turn all leds on and off 4 times. */
static void flash_all_leds(void)
{
  int i;
  for (i = 0; i < 4; i++) {
    HAL_GPIO_WritePin(LEDS_GPIO_PORT, ALL_LEDS, GPIO_PIN_SET);
    HAL_Delay(PAUSE_SHORT);

    HAL_GPIO_WritePin(LEDS_GPIO_PORT, ALL_LEDS, GPIO_PIN_RESET);
    HAL_Delay(PAUSE_SHORT);
  }
}


/* The main function is called from startup_stm32f407xx.s */
int main(void)
{
  HAL_Init();

  setup_leds();

  while (1) {
    led_round();
    flash_all_leds();
  }

  return 0;
}
