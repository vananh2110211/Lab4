/*
 * led.c
 *
 *  Created on: Dec 1, 2022
 *      Author: ASUS
 */
#include "led.h"


void ToggleLed_0(void){
	HAL_GPIO_TogglePin(LED_0_GPIO_Port, LED_0_Pin);
}
void ToggleLed_1(void){
	HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
}
void ToggleLed_2(void){
	HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
}
void ToggleLed_3(void){
	HAL_GPIO_TogglePin(LED_3_GPIO_Port, LED_3_Pin);
}
void ToggleLed_4(void){
	HAL_GPIO_TogglePin(LED_4_GPIO_Port, LED_4_Pin);
}


