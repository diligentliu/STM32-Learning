#include "key_exit.h"

void extix_init() {
	GPIO_InitTypeDef gpioInitTypeDef;

	// KEY0
	gpioInitTypeDef.Pin = KEY0_GPIO_PIN;
	gpioInitTypeDef.Mode = GPIO_MODE_IT_FALLING;
	gpioInitTypeDef.Pull = GPIO_PULLUP;
	gpioInitTypeDef.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(KEY0_GPIO_PORT, &gpioInitTypeDef);

	// KEY1
	gpioInitTypeDef.Pin = KEY1_GPIO_PIN;
	HAL_GPIO_Init(KEY1_GPIO_PORT, &gpioInitTypeDef);

	// KEY_UP
	gpioInitTypeDef.Pin = KEY_UP_GPIO_PIN;
	gpioInitTypeDef.Mode = GPIO_MODE_IT_RISING;
	gpioInitTypeDef.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(KEY_UP_GPIO_PORT, &gpioInitTypeDef);

	// HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
	HAL_NVIC_SetPriority(KEY0_INT_IRQn, 1, 2);
	HAL_NVIC_EnableIRQ(KEY0_INT_IRQn);

	HAL_NVIC_SetPriority(KEY1_INT_IRQn, 2, 2);
	HAL_NVIC_EnableIRQ(KEY1_INT_IRQn);

	HAL_NVIC_SetPriority(KEY_UP_INT_IRQn, 3, 2);
	HAL_NVIC_EnableIRQ(KEY_UP_INT_IRQn);
}

/*
 * 中断服务程序
 */
void KEY0_INT_IRQHandler() {
	/* 调用中断处理公用函数 清除 KEY0 所在中断线 的中断标志位 */
	HAL_GPIO_EXTI_IRQHandler(KEY0_GPIO_PIN);
	/* HAL 库默认先清中断再处理回调，退出时再清一次中断，避免按键抖动误触发 */
	__HAL_GPIO_EXTI_CLEAR_IT(KEY0_GPIO_PIN);
}

void KEY1_INT_IRQHandler() {
	/* 调用中断处理公用函数 清除 KEY1 所在中断线 的中断标志位 */
	HAL_GPIO_EXTI_IRQHandler(KEY1_GPIO_PIN);
	/* HAL 库默认先清中断再处理回调，退出时再清一次中断，避免按键抖动误触发 */
	__HAL_GPIO_EXTI_CLEAR_IT(KEY1_GPIO_PIN);
}

void KEY_UP_INT_IRQHandler() {
	/* 调用中断处理公用函数 清除 KEY_UP 所在中断线 的中断标志位 */
	HAL_GPIO_EXTI_IRQHandler(KEY_UP_GPIO_PIN);
	/* HAL 库默认先清中断再处理回调，退出时再清一次中断，避免按键抖动误触发 */
	__HAL_GPIO_EXTI_CLEAR_IT(KEY_UP_GPIO_PIN);
}

/*
 * 中断服务程序中需要做的事情
 * 在 HAL 库中所有的外部中断服务函数都会调用此函数
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	delay_ms(20); /* 消抖 */
	switch (GPIO_Pin) {
		case KEY0_GPIO_PIN:
			if (KEY0 == 0) {
				LED0_TOGGLE(); /* LED0 状态取反 */
				LED1_TOGGLE(); /* LED1 状态取反 */
			}
			break;
		case KEY1_GPIO_PIN:
			if (KEY1 == 0) {
				LED0_TOGGLE(); /* LED0 状态取反 */
			}
			break;
		case KEY_UP_GPIO_PIN:
			if (KEY_UP == 1) {
				BEEP_TOGGLE(); /* 蜂鸣器状态取反 */
			}
			break;
		default:
			break;
	}
}