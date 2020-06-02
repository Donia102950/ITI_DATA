/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 11 feb  2020                                  */
/* Version: V01                                            */
/***********************************************************/

/**********************************************includes***********************************************************************************************/
#include "STD_TYPES.h"

#include "7SEG_config.h"

/*array of enable ports and pins of all sevensegment*/
u8 SEVENSEG_Enable_Ports[MAX_SG_NUMBER]={SevenSeg1_Enable_Port,SevenSeg2_Enable_Port};
u8 SEVENSEG_Enable_Pins[MAX_SG_NUMBER] ={SevenSeg1_Enable_Pin,SevenSeg2_Enable_Pin};
