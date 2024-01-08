/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
/* LED 引脚定义 */
#define LED0_GPIO_PORT GPIOB
#define LED0_GPIO_PIN GPIO_PIN_5
#define LED1_GPIO_PORT GPIOE
#define LED1_GPIO_PIN GPIO_PIN_5
/* LED 时钟使能 */
#define LED0_GPIO_CLK_ENABLE() do { __HAL_RCC_GPIOB_CLK_ENABLE(); } while (0)
#define LED1_GPIO_CLK_ENABLE() do { __HAL_RCC_GPIOE_CLK_ENABLE(); } while (0)
/* LED 控制 */
#define LED0(x) do { x ? \
                    HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_RESET) : \
                    HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_SET); \
                } while (0)
#define LED1(x) do { x ? \
                    HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_RESET) : \
                    HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_SET);\
                } while (0)
/* LED 翻转 */
/* LED0 = !LED0 */
#define LED0_TOGGLE() do { HAL_GPIO_TogglePin(LED0_GPIO_PORT, LED0_GPIO_PIN); } while (0)
/* LED1 = !LED1 */
#define LED1_TOGGLE() do { HAL_GPIO_TogglePin(LED1_GPIO_PORT, LED1_GPIO_PIN); } while (0)
/* 蜂鸣器引脚定义 */
#define BEEP_GPIO_PORT  GPIOB
#define BEEP_GPIO_PIN   GPIO_PIN_8
/* 蜂鸣器时钟使能 */
#define BEEP_GPIO_CLK_ENABLE()  do { __HAL_RCC_GPIOB_CLK_ENABLE(); } while (0)
/* 蜂鸣器控制 */
#define BEEP(x) do { x ? \
                    HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN, GPIO_PIN_SET) : \
                    HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN, GPIO_PIN_RESET); \
                } while (0)
/* 蜂鸣器翻转 */
#define BEEP_TOGGLE() do { HAL_GPIO_TogglePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN); } while (0)

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
void led_init(void);

void beep_init();
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
