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

	HAL_NVIC_SetPriority(KEY0_INT_IRQn, 0, 2);
	HAL_NVIC_EnableIRQ(KEY0_INT_IRQn);

	HAL_NVIC_SetPriority(KEY1_INT_IRQn, 1, 2);
	HAL_NVIC_EnableIRQ(KEY1_INT_IRQn);

	HAL_NVIC_SetPriority(KEY_UP_INT_IRQn, 3, 2);
	HAL_NVIC_EnableIRQ(KEY_UP_INT_IRQn);
}
