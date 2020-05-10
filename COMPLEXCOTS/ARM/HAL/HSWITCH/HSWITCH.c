/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 17 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

/*includes*/
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "Sched.h"

#include "HSWITCH.h"
#include "HSWITCH_config.h"

/*create task to debouncing*/
task_t SwitchDebouncing;
static void Hswitch_Runnable(void);
/*state of the switch*/
uint_8t switchState[MAXNUM];
extern switchType_t switchArr[MAXNUM];
extern GPIO_t switchConfig[MAXNUM];

/*description:to initialize switch
 * input:void
 * output : error
 */
uint_8t Hswitch_init(void)
{
	uint_8t local_Error=OK;
	uint_8t switchCount;
	for(switchCount=0;switchCount<MAXNUM;switchCount++)
	{
		local_Error|=GPIO_u8SetConfiguration(&switchConfig[switchCount]);
	}
	return local_Error;
}

/*description: to get the state of any switch
 * input:void
 * output : state of switch
 */
uint_8t Hswitch_getSwitchState(uint_8t switchNum , uint_8t *state)
{
	uint_8t switchCount;
	uint_8t Local_Error=OK;
	if(state)
	{
		*state=switchState[switchNum];
	}
	else
	{
		Local_Error=NOK;
	}
	return Local_Error;
}



/*description: Runnable of debouncing of the switch
 * input: void
 * output : void
 */
static void Hswitch_Runnable(void)
{
	/*defines
	 * 1)counter to check if switch on or not
	 * 2)prestate,current state to check if two same or not
	 */
	static uint_8t prestate[MAXNUM],counter[MAXNUM];
	uint_8t currentstate[MAXNUM];
	uint_8t switchCount;
	/*to get the value from GPIO*/
	for(switchCount=0;switchCount<MAXNUM;switchCount++)
	{
		GPIO_u8getValue(&switchConfig[switchCount],switchArr[switchCount].SwitchPin,&currentstate[switchCount]);

		/*to check if debouncing finshed or not*/
		if(currentstate[switchCount] == prestate[switchCount])
		{
			counter[switchCount]++;
		}
		else
		{
			counter[switchCount]=0;
			prestate[switchCount]=currentstate[switchCount];


		}

		/*if swcounter[switchCount]=0;itch has the same value for 5 times*/
		if(counter[switchCount]==5)
		{
			switchState[switchCount]=currentstate[switchCount];
			counter[switchCount]=0;
		}

	}



}

/*description: to create the task of any switch
 * input:void
 * output :void
 */
void Start_Debouncing(void)
{
	SwitchDebouncing.Runnable=Hswitch_Runnable;
	SwitchDebouncing.periodicity=5;
}

