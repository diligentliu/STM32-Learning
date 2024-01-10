#include "global_time.h"

TIM_HandleTypeDef g_timx_handle;
TIM_HandleTypeDef g_timx_pwm_chy_handle;
TIM_OC_InitTypeDef g_timx_oc_pwm_chy_handle;

void gtim_timx_int_init(uint16_t arr, uint16_t psc) {
	GTIM_TIMX_INT_CLK_ENABLE();

	g_timx_handle.Instance = GTIM_TIMX_INT;
	g_timx_handle.Init.Prescaler = psc;
	g_timx_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	g_timx_handle.Init.Period = arr;
	HAL_TIM_Base_Init(&g_timx_handle);
	__HAL_TIM_CLEAR_FLAG(&g_timx_handle, TIM_FLAG_UPDATE);

	HAL_NVIC_SetPriority(GTIM_TIMX_INT_IRQn, 1, 3);
	HAL_NVIC_EnableIRQ(GTIM_TIMX_INT_IRQn);

	HAL_TIM_Base_Start_IT(&g_timx_handle);
}

void GTIM_TIMX_INT_IRQHandler() {
	if (__HAL_TIM_GET_FLAG(&g_timx_handle, TIM_FLAG_UPDATE) != RESET) {
		LED1_TOGGLE();
		__HAL_TIM_CLEAR_FLAG(&g_timx_handle, TIM_FLAG_UPDATE);
	}
}

/**
 * @brief 通用定时器 TIMX 通道 Y PWM 输出 初始化函数（使用 PWM 模式 1）
 * @note
 * 通用定时器的时钟来自 APB1,当 D2PPRE1≥2 分频的时候
 * 通用定时器的时钟为 APB1 时钟的 2 倍, 而 APB1 为 36M, 所以定时器时钟 = 72Mhz
 * 定时器溢出时间计算方法: Tout = ((arr + 1) * (psc + 1)) / Ft us.
 * Ft=定时器工作频率,单位:Mhz
 * @param arr: 自动重装值。
 * @param psc: 时钟预分频数
 * @retval 无
 */
void gtim_timx_pwm_chy_init(uint16_t arr, uint16_t psc) {
	GPIO_InitTypeDef gpioInitTypeDef;
	GTIM_TIMX_PWM_CHY_GPIO_CLK_ENABLE();
	GTIM_TIMX_PWM_CHY_CLK_ENABLE();

	gpioInitTypeDef.Pin = GTIM_TIMX_PWM_CHY_GPIO_PIN;
	gpioInitTypeDef.Mode = GPIO_MODE_AF_PP;     // 复用推挽输出
	gpioInitTypeDef.Pull = GPIO_PULLUP;
	gpioInitTypeDef.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GTIM_TIMX_PWM_CHY_GPIO_PORT, &gpioInitTypeDef);
	GTIM_TIMX_PWM_CHY_GPIO_REMAP();

	g_timx_pwm_chy_handle.Instance = GTIM_TIMX_PWM;
	g_timx_pwm_chy_handle.Init.Prescaler = psc;
	g_timx_pwm_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	g_timx_pwm_chy_handle.Init.Period = arr;
	HAL_TIM_PWM_Init(&g_timx_pwm_chy_handle);

	g_timx_oc_pwm_chy_handle.OCMode = TIM_OCMODE_PWM1;
	g_timx_oc_pwm_chy_handle.Pulse = 90;
	g_timx_oc_pwm_chy_handle.OCPolarity = TIM_OCPOLARITY_HIGH;
	HAL_TIM_PWM_ConfigChannel(&g_timx_pwm_chy_handle, &g_timx_oc_pwm_chy_handle,
							  GTIM_TIMX_PWM_CHY);
	HAL_TIM_PWM_Start(&g_timx_pwm_chy_handle, GTIM_TIMX_PWM_CHY);
}

/**
 * @brief 定时器底层驱动，时钟使能，引脚配置
 * 此函数会被 HAL_TIM_PWM_Init()调用
 * @param htim:定时器句柄
 * @retval 无
 */
// void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim) {
// 	if (htim->Instance == GTIM_TIMX_PWM) {
//
// 	}
// }

void pwm_set_compare(uint16_t compare) {
	__HAL_TIM_SET_COMPARE(&g_timx_pwm_chy_handle, GTIM_TIMX_PWM_CHY, compare);
}