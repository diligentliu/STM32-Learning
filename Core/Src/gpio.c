/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/

/* USER CODE BEGIN 2 */
void led_init(void) {
	GPIO_InitTypeDef gpioInitTypeDef;
	LED0_GPIO_CLK_ENABLE();
	LED1_GPIO_CLK_ENABLE();

	gpioInitTypeDef.Pin = LED0_GPIO_PIN;
	gpioInitTypeDef.Mode = GPIO_MODE_OUTPUT_PP;
	gpioInitTypeDef.Pull = GPIO_PULLUP;
	gpioInitTypeDef.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(LED0_GPIO_PORT, &gpioInitTypeDef);

	gpioInitTypeDef.Pin = LED1_GPIO_PIN;
	HAL_GPIO_Init(LED1_GPIO_PORT, &gpioInitTypeDef);

	LED0(0);
	LED1(0);
}

void beep_init() {
	GPIO_InitTypeDef gpioInitTypeDef;
	BEEP_GPIO_CLK_ENABLE();

	gpioInitTypeDef.Pin = BEEP_GPIO_PIN;
	gpioInitTypeDef.Mode = GPIO_MODE_OUTPUT_PP;
	gpioInitTypeDef.Pull = GPIO_PULLUP;
	gpioInitTypeDef.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(BEEP_GPIO_PORT, &gpioInitTypeDef);

	BEEP(0);
}
/* 蜂鸣器控制 */


/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
