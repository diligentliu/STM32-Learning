#ifndef STM32_CLION_TEMPLATE_KEY_H
#define STM32_CLION_TEMPLATE_KEY_H

#include "main.h"

/*
 * Some defines
 */
/* 引脚 定义 */
#define KEY0_GPIO_PORT  GPIOE
#define KEY0_GPIO_PIN   GPIO_PIN_4
#define KEY1_GPIO_PORT  GPIOE
#define KEY1_GPIO_PIN   GPIO_PIN_3
#define KEY_UP_GPIO_PORT  GPIOA
#define KEY_UP_GPIO_PIN   GPIO_PIN_0
/* 时钟使能 */
#define KEY0_GPIO_CLK_ENABLE() do { __HAL_RCC_GPIOE_CLK_ENABLE(); } while (0)
#define KEY1_GPIO_CLK_ENABLE() do { __HAL_RCC_GPIOE_CLK_ENABLE(); } while (0)
#define KEY_UP_GPIO_CLK_ENABLE() do { __HAL_RCC_GPIOA_CLK_ENABLE(); } while (0)
/* 读取键值 */
#define KEY0 HAL_GPIO_ReadPin(KEY0_GPIO_PORT, KEY0_GPIO_PIN)    /* 读取 KEY0 引脚 */
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_PORT, KEY1_GPIO_PIN)    /* 读取 KEY1 引脚 */
#define KEY_UP HAL_GPIO_ReadPin(KEY_UP_GPIO_PORT, KEY_UP_GPIO_PIN)   /* 读取 KEY_UP 引脚 */
#define KEY0_PRES 1     /* KEY0 按下 */
#define KEY1_PRES 2     /* KEY1 按下 */
#define KEY_UP_PRES 3     /* KEY_UP 按下(即 WK_UP) */

void key_init();

uint8_t key_scan(uint8_t mode);

#endif //STM32_CLION_TEMPLATE_KEY_H
