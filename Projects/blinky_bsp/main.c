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
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED6);
}


static void led_round(void)
{
  int i;
  for (i = 0; i < LEDn; i++)
  {
    BSP_LED_On(i);
    HAL_Delay(PAUSE_LONG);

    BSP_LED_Off(i);
   }
}


/* Turn all leds on and off 4 times. */
static void flash_all_leds(void)
{
  int i;
  for (i = 0; i < 4; i++)
  {
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




