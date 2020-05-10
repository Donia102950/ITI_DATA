/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 17 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

#include "STD_TYPES.h"

#include "GPIO_interface.h"

#include "HSWITCH.h"
#include "HSWITCH_config.h"

switchType_t switchArr[MAXNUM]={{.SwitchPin=PIN0,.SwitchNum=SWITCHNUM1}};

GPIO_t switchConfig[MAXNUM]={{.mode = MODE_INPUT_INPUTPULLUP , .pin=PIN0 , .port = PORTA , .speed = SPEED_INPUT}};

