#ifndef STM32_LEARNING_KEY_EXIT_H
#define STM32_LEARNING_KEY_EXIT_H

#include "gpio.h"
#include "key.h"
#include "main.h"

/* EXIT 外部中断使能 */
#define KEY0_INT_IRQn           EXTI4_IRQn
#define KEY0_INT_IRQHandler     EXTI4_IRQHandler
#define KEY1_INT_IRQn           EXTI3_IRQn
#define KEY1_INT_IRQHandler     EXTI3_IRQHandler
#define KEY_UP_INT_IRQn         EXTI0_IRQn
#define KEY_UP_INT_IRQHandler   EXTI0_IRQHandler

void extix_init();

#endif //STM32_LEARNING_KEY_EXIT_H
