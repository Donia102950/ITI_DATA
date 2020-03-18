/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 9 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

#include"STD_TYPES.h"

/*to define the leds in my application*/
#define LED1   0

/*to define the state of leds (active high or active low)*/
#define LED_STATE_ON 0
#define LED_STATE_OFF 1

/*to configure the LED numbers*/
#define LED_NUMBER  1

/*the led state */
#define HLED_ACTIVE_HIGH 0
#define HLED_ACTIVE_LOW  1

/*Function to set the value of the led*/

/*description: to set the configuration of led and set the state
 * input  : the led number , and led state
 * output : error
 */
char HLED_setLedState(char ledNum,char ledState);

/*description: initialize the Led function*
 * input  : lednumber in the array
 * output : void
 */
void HLED_init(u8 ledNum);
