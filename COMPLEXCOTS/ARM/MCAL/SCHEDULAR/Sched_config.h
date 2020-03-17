/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 17 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

#ifndef SCHED_CONFIG_H_
#define SCHED_CONFIG_H_

/*Ticks (millisec)*/
#define SCHED_TICK_mSEC 100

/*number of tasks*/
#define MAX_TASKS 2


typedef struct
{
	task_t * AppTask;
	uint_32t FirstDelay;
}TaskBaseInfo_t;


#endif /* SCHED_CONFIG_H_ */
