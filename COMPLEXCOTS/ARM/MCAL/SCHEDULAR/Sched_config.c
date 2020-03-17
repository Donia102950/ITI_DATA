/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 17 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

/*includes*/
#include "Sched.h"
#include "Sched_config.h"

/*extern task from the main*/
extern task_t task1;
extern task_t task2;

/*the information of each task*/
const TaskBaseInfo_t SysTask_info[MAX_TASKS]={
		{.AppTask=&task1,.FirstDelay=500},
		{.AppTask=&task2,.FirstDelay=0}
};
