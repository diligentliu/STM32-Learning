#include "key.h"

void key_init() {
	GPIO_InitTypeDef gpioInitTypeDef;
	KEY0_GPIO_CLK_ENABLE();
	KEY1_GPIO_CLK_ENABLE();
	KEY_UP_GPIO_CLK_ENABLE();

	gpioInitTypeDef.Pin = KEY0_GPIO_PIN;
	gpioInitTypeDef.Mode = GPIO_MODE_INPUT;
	gpioInitTypeDef.Pull = GPIO_PULLUP;
	gpioInitTypeDef.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(KEY0_GPIO_PORT, &gpioInitTypeDef);

	gpioInitTypeDef.Pin = KEY1_GPIO_PIN;
	HAL_GPIO_Init(KEY1_GPIO_PORT, &gpioInitTypeDef);

	gpioInitTypeDef.Pin = KEY_UP_GPIO_PIN;
	gpioInitTypeDef.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(KEY_UP_GPIO_PORT, &gpioInitTypeDef);
}

uint8_t key_scan(uint8_t mode) {
	static uint8_t key_up = 1;
	uint8_t key_val = 0;
	if (mode) {
		key_up = 1;
	}

	if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY_UP == 1)) {
		HAL_Delay(10);
		key_up = 0;
		if (KEY0 == 0) {
			key_val = KEY0_PRES;
		} else if (KEY1 == 0) {
			key_val = KEY1_PRES;
		} else {
			key_val = KEY_UP_PRES;
		}
	} else if (KEY0 == 1 && KEY1 == 1 && KEY_UP == 0) {
		key_up = 1;
	}

	return key_val;
}
