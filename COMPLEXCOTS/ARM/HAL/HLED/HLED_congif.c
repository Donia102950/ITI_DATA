/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 9 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

/*includes*/
#include "HLED_interface.h"
#include "HLED_config.h"
#include "GPIO_interface.h"

/*struct which configure my LED */

/*to define the array of leds*/
const LedMap_t LedMap[LED_NUMBER]={
		{.GPIO_Pin_Num=PIN13,.GPIO_Port=PORTC,.ACTIVESTATE=HLED_ACTIVE_LOW},
};

/*to configure the GPIO pin*/
const GPIO_t  GPIOT[LED_NUMBER] ={
		{PIN13,MODE_GENERALOUTPUT_PUSHPULL,SPEED_10MHZ,PORTC},
};
