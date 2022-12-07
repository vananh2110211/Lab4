/*
 * timer.c
 *
 *  Created on: Nov 24, 2022
 *      Author: ASUS
 */

#include "timer.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2) {
		SCH_Update();
	}
}
