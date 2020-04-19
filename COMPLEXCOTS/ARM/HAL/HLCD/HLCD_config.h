/*******************************************************************************************************************************************************/
/*Author: Donia Mohamed Mahmoud*/
/*Version: V1.2*/
/*NAME: HLCD_DRIVER */
/*******************************************************************************************************************************************************/




#include "GPIO_interface.h"

/*******************************************************************************************************************************************************/
/*default configuration of each LCD*/
#define DATA_BUFFER_SIZE	255

#define ONE_LINE  CLEAR
#define TWO_LINES SET

#define SMALL_FONT CLEAR
#define BIG_FONT   SET

#define DATA_DISPLAY_OFF CLEAR
#define DATA_DISPLAY_ON  SET

#define CURSOR_DISPLAY_OFF CLEAR
#define CURSOR_DISPLAY_ON  SET

#define CURSOR_BLINK_OFF CLEAR
#define CURSOR_BLINK_ON  SET

#define LINES_NUMBER   TWO_LINES
#define FONT_SIZE      SMALL_FONT
#define DISPLAY_DATA   DATA_DISPLAY_ON
#define DISPLAY_CURSOR CURSOR_DISPLAY_ON
#define BLINK_CURSOR   CURSOR_BLINK_OFF
/*******************************************************************************************************************************************************/


/*******************************************************************************************************************************************************/
/*pins of each LCD*/
typedef struct {
	GPIO_t RS;
	GPIO_t RW;
	GPIO_t EN;
	GPIO_t DataPins [8];
}LCDPins_t;
/*******************************************************************************************************************************************************/


