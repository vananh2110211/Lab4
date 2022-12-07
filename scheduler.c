/*
 * scheduler.c
 *
 *  Created on: Nov 24, 2022
 *      Author: ASUS
 */
#include "scheduler.h"

static sTasks SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void){
	uint8_t i;
	for(i = 0; i < SCH_MAX_TASKS; i++){

	}
}

uint8_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	uint8_t index = 0;
	while( (SCH_tasks_G[index].pTask != 0) && (index < SCH_MAX_TASKS) ){
		index++;
	}
	if(index == SCH_MAX_TASKS){
		return SCH_MAX_TASKS;
	}
	SCH_tasks_G[index].pTask 	= pFunction;
	SCH_tasks_G[index].Delay 	= DELAY;
	SCH_tasks_G[index].Period 	= PERIOD;
	SCH_tasks_G[index].RunMe 	= 0;
	return index;
}

void SCH_Update(void){
	uint8_t index;
	for(index = 0; index < SCH_MAX_TASKS; index++){
		if(SCH_tasks_G[index].pTask){
			if(SCH_tasks_G[index].Delay == 0){
				SCH_tasks_G[index].RunMe++;
					SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
			}
			else{
				SCH_tasks_G[index].Delay--;
			}
		}
	}
}

void SCH_Dispatch_Tasks(void){
	uint8_t index;
	for(index = 0; index < SCH_MAX_TASKS; index++){
		if(SCH_tasks_G[index].RunMe > 0){
			(*SCH_tasks_G[index].pTask)();
			SCH_tasks_G[index].RunMe--;
			if(SCH_tasks_G[index].Period == 0){
				SCH_Delete_Task(index);
			}
		}
	}
}


void SCH_Delete_Task(const uint8_t index){
	if(SCH_tasks_G[index].pTask == 0){
		return;
	}
	SCH_tasks_G[index].pTask 	= 0x0000;
	SCH_tasks_G[index].Delay 	= 0;
	SCH_tasks_G[index].Period 	= 0;
	SCH_tasks_G[index].RunMe 	= 0;
}
