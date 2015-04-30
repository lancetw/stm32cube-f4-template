/*
 * Ref: https://github.com/Malkavian/tuts/blob/master/stm/blinky/main.c
*/

#include "main.h"

#define PAUSE_LONG  400
#define PAUSE_SHORT 100

/* BSP_LED_Init is defined in stm32f4_discovery.h */
static void setup_leds(void)
{
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED6);
}


static void led_round(void)
{
  int i;
  for (i = 0; i < 4; i++) {
    BSP_LED_On(i);
    HAL_Delay(PAUSE_LONG);

    BSP_LED_Off(i);
  }
}


/* Turn all leds on and off 4 times. */
static void flash_all_leds(void)
{
  int i;
  for (i = 0; i < 4; i++) {
    BSP_LED_Toggle(LED3);
    BSP_LED_Toggle(LED4);
    BSP_LED_Toggle(LED5);
    BSP_LED_Toggle(LED6);
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
