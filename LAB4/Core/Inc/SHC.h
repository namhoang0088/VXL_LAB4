/*
 * SHC.h
 *
 *  Created on: Nov 8, 2022
 *      Author: ACER
 */

#ifndef INC_SHC_H_
#define INC_SHC_H_

typedef struct {
	void ( * pTask ) ( void ) ;
    uint32_t Delay;
    uint32_t Period;
    uint8_t RunMe;
    uint32_t TaskID ;
} sTask ;

extern int current_index_task;
extern char str[50];
void SCH_Update ( void );
void SCH_Add_Task ( void ( * pFunction ) ( ) , unsigned int DELAY,unsigned int PERIOD);
void SCH_Dispatch_Tasks ( void );
void SCH_Delete_Task ( const uint32_t TASK_INDEX);

#endif /* INC_SHC_H_ */
