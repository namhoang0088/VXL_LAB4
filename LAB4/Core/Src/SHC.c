/*
 * SHC.c
 *
 *  Created on: Nov 8, 2022
 *      Author: ACER
 */
#include "main.h"
#include "SHC.h"
#include "stdio.h"
#include "string.h"
#include "toggleLED.h"
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0
sTask SCH_tasks_G[SCH_MAX_TASKS];
int current_index_task = 1;
char str[50];
void SCH_Update ( void ){
	unsigned char Index ;
	for( Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if( SCH_tasks_G [Index].pTask ) {
			if ( SCH_tasks_G[Index].Delay == 0 ) {
				SCH_tasks_G [Index] .RunMe += 1;
				if( SCH_tasks_G[Index].Period ) {
					SCH_tasks_G [Index].Delay = SCH_tasks_G [Index].Period ;
				}
			}else{
				SCH_tasks_G[Index].Delay -= 1;
			}
		}
	}
}

void SCH_Add_Task ( void ( * pFunction ) ( ) , unsigned int DELAY,unsigned int PERIOD){
	if(current_index_task < SCH_MAX_TASKS){
			SCH_tasks_G[current_index_task].pTask = pFunction;
			SCH_tasks_G[current_index_task].Delay = DELAY;
			SCH_tasks_G[current_index_task].Period =  PERIOD;
			SCH_tasks_G[current_index_task].RunMe = 0;
			SCH_tasks_G[current_index_task].TaskID = current_index_task;
			current_index_task++;
		}
}

void SCH_Dispatch_Tasks ( void ){
	unsigned char Index ;
	for( Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if ( SCH_tasks_G [Index].RunMe > 0 ) {
			(*SCH_tasks_G [Index].pTask)();
			SCH_tasks_G[Index].RunMe -= 1;
			sprintf(str, "Task %d has Dispatch at Tick %ld ms \r\n",flag, HAL_GetTick());
			if(SCH_tasks_G[Index].Period == 0)
			{
				SCH_Delete_Task ( Index ) ;
			}
		}
	}
}
void SCH_Delete_Task ( uint32_t TASK_INDEX){
	//unsigned char Return_code ;
	if(SCH_tasks_G[TASK_INDEX].pTask == 0 ) {
	//Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK
		//Return_code = RETURN_ERROR;
	} else{
		//Return_code = RETURN_NORMAL;
	}
	SCH_tasks_G[TASK_INDEX].pTask = 0x0000 ;
	SCH_tasks_G [TASK_INDEX].Delay = 0;
	SCH_tasks_G [TASK_INDEX].Period = 0;
	SCH_tasks_G [TASK_INDEX].RunMe = 0;
	//return Return_code ;
}


