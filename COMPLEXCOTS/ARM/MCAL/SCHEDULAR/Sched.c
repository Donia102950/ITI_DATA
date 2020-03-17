/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 17 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

/*includes*/
#include "DRCC.h"
#include "DSYSTICK.h"
#include "Sched.h"
#include "Sched_config.h"

/*the options to task state*/
#define TASK_READY 1
#define TASK_SUSPEND 2

/*struct to each task*/
typedef struct
{
	/*pointer to struct TaskBase*/
	TaskBaseInfo_t * TaskInfo;

	/*state ready or suspend*/
	uint_32t state;

	/*ticks to execute*/
	uint_32t PeriodTicks;
	uint_32t TicksToExec;

}systask_t;

/*to make sched run in thread mode and flag set only in handling mode*/
uint_32t OSFlag;

/*uint_32t TickFreq;*/

/*array of struct*/
systask_t SysTask [MAX_TASKS];

/*idx of each task*/
uint_8t idx;

/*extern the array in config.c*/
extern  TaskBaseInfo_t SysTask_info [MAX_TASKS];


/*description: to set the OS flag to avoid the sched run in handling mode
 * input: port: void
 * output : void
 */
static void Sched_SetOSFlag (void)
{
	OSFlag++;
}

/*description: which looping on the array of tasks and execute the target one
 * input: port: void
 * output : void
 */
static void Sched(void)
{
	/*looping on each element in the array*/
	for (idx=0;idx<MAX_TASKS;idx++)
	{
		/*check if this the time to execute and if state of task is ready*/
		if (SysTask[idx].TicksToExec==0 && SysTask[idx].state==TASK_READY)
		{
			/*execute the task*/
			SysTask[idx].TaskInfo->AppTask->Runnable();
			/*add the tickstoexecute*/
			SysTask[idx].TicksToExec=SysTask[idx].PeriodTicks;
		}
		SysTask[idx].TicksToExec--;
	}
}


/*description: to initialize our schedular
 * input: port: void
 * output : Error state
 */
uint_8t Sched_Init(void)
{
	uint_8t i;
	uint_8t localError;
	/*uint_32t STKPre;*/
	uint_32t BusFreq;

	/*get AHB bus*/
	localError=RCC_GetBusClock(AHB_BUS,&BusFreq);
	if (!localError)
	{
		/*calculate tick msec*/
		/*localError=SYSTICK_GetPrescale(&STKPre);*/
		if (!localError)
		{
		/*	TickFreq=BusFreq/STKPre;
			TickFreq/=1000;*/
		}
		else
		{
			localError=NOT_OK;
		}
	}
	else
	{
		localError=NOT_OK;
	}

	/*initialize systick*/
	SYSTICK_Init();

	/*set call back for the systick*/
	SYSTICK_SetCallback(&Sched_SetOSFlag);

	/*Setting time for systick in microseconds,
	 *Converting time from milli to micro
	 */
	SYSTICK_SetTime(SCHED_TICK_mSEC*1000,BusFreq);

	/*looping to set the initial value of each task*/
	for (i=0;i<MAX_TASKS;i++)
	{
		SysTask[i].TaskInfo=&SysTask_info[i];
		SysTask[i].state=TASK_READY;
		SysTask[i].PeriodTicks=(SysTask[i].TaskInfo->AppTask->periodicity)/SCHED_TICK_mSEC;
		SysTask[i].TicksToExec=(SysTask[i].TaskInfo->FirstDelay)/SCHED_TICK_mSEC;
	}
	return localError;
}

/*description: to start our schedular
 * input: port: void
 * output : Error state
 */
uint_8t Sched_Start(void)
{
	SYSTICK_Start();
	while (1)
	{
		if (OSFlag)
		{
			OSFlag--;
			Sched();
		}
	}
}

/*description: to suspend any task
 * input: port: void
 * output : Error state
 */
void Sched_Suspend(void)
{
	SysTask[idx].state=TASK_SUSPEND;
}

