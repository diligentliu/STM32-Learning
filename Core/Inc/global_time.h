#ifndef STM32_LEARNING_GLOBAL_TIME_H
#define STM32_LEARNING_GLOBAL_TIME_H

#include "main.h"

#define GTIM_TIMX_INT               TIM3
#define GTIM_TIMX_INT_IRQn          TIM3_IRQn
#define GTIM_TIMX_INT_IRQHandler    TIM3_IRQHandler
/* TIM3 时钟使能 */
#define GTIM_TIMX_INT_CLK_ENABLE()  do { __HAL_RCC_TIM3_CLK_ENABLE(); } while (0)

/**
 * TIMX PWM 输出定义
 * 这里输出的 PWM 控制 LED0(RED)的亮度
 * 默认是针对 TIM2~TIM5
 * 注意: 通过修改这几个宏定义,可以支持 TIM1~TIM8 任意一个定时器,任意一个 IO 口输出 PWM
 */
#define GTIM_TIMX_PWM_CHY_GPIO_PORT         GPIOB
#define GTIM_TIMX_PWM_CHY_GPIO_PIN          GPIO_PIN_5
#define GTIM_TIMX_PWM_CHY_GPIO_CLK_ENABLE() do { __HAL_RCC_GPIOB_CLK_ENABLE(); } while (0) /* PB 口时钟使能 */

/**
 * TIMX REMAP 设置
 * 因为我们 LED0 接在 PB5 上, 必须通过开启 TIM3 的部分重映射功能, 才能将 TIM3_CH2 输出到 PB5 上
 * 因此, 必须实现 GTIM_TIMX_PWM_CHY_GPIO_REMAP
 * 对那些使用默认设置的定时器 PWM 输出脚, 不用设置重映射, 是不需要该函数的!
 */
#define GTIM_TIMX_PWM_CHY_GPIO_REMAP() do { __HAL_RCC_AFIO_CLK_ENABLE(); \
											__HAL_AFIO_REMAP_TIM3_PARTIAL(); \
									   } while (0)

#define GTIM_TIMX_PWM                   TIM3
#define GTIM_TIMX_PWM_CHY               TIM_CHANNEL_2                                    /* 通道 Y, 1<= Y <=4 */
#define GTIM_TIMX_PWM_CHY_CCRX          TIM3->CCR2                                       /* 通道 Y 的输出比较寄存器 */
#define GTIM_TIMX_PWM_CHY_CLK_ENABLE()  do { __HAL_RCC_TIM3_CLK_ENABLE(); } while (0)    /* TIM3 时钟使能 */

void gtim_timx_int_init(uint16_t arr, uint16_t psc);
void gtim_timx_pwm_chy_init(uint16_t arr,uint16_t psc);
void pwm_set_compare(uint16_t compare);
void breathing_light();

#endif //STM32_LEARNING_GLOBAL_TIME_H
