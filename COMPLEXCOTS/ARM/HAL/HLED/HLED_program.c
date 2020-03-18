/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 9 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

/*includes*/
#include"STD_TYPES.h"
#include "GPIO_interface.h"

#include "HLED_interface.h"
#include "HLED_config.h"


/*ErrorState*/
#define Ok 1
#define NOK 0

/*to be able to use the array*/
extern  LedMap_t LedMap[LED_NUMBER];
extern GPIO_t  GPIOT[LED_NUMBER] ;


/*description: initialize the Led function*
 * input  : lednumber in the array
 * output : void
 */
void HLED_init(u8 ledNum)
{
	GPIO_u8SetConfiguration(&GPIOT[ledNum]);
}

/*description: to set the configuration of led and set the state
 * input  : the led number , and led state
 * output :errorstate
 */
char HLED_setLedState(char ledNum,char ledState)
{
	char errorState=Ok;

	/*to check state of any led*/
	if(LedMap[ledNum].ACTIVESTATE == HLED_ACTIVE_HIGH)
	{
		if (ledNum<LED_NUMBER)
		{
			if(ledState==LED_STATE_ON)
				GPIO_u8SetValue(&GPIOT[ledNum],ON);
			else if(ledState==LED_STATE_OFF)
				GPIO_u8SetValue(&GPIOT[ledNum],OFF);
			else
				errorState=NOK;

		}
		else
		{
			errorState=NOK;    }
	}
	else
	{
		if (ledNum<LED_NUMBER)
		{
			if(ledState==LED_STATE_ON)
				GPIO_u8SetValue(&GPIOT[ledNum],OFF);
			else if(ledState==LED_STATE_OFF)
				GPIO_u8SetValue(&GPIOT[ledNum],ON);
			else
				errorState=NOK;

		}
		else
		{
			errorState=NOK;    }

	}
	return errorState;
}
