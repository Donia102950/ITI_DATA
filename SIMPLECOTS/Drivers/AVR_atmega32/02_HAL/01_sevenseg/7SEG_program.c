/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 11 feb  2020                                  */
/* Version: V01                                            */
/***********************************************************/

/*includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "7SEG_interface.h"
#include "7SEG_config.h"

/*last value on sevensegment after poweroff*/
u8 LastValue;

/*array of enable ports and pins of all sevensegment*/
u8 SEVENSEG_Enable_Ports[2]={SevenSeg1_Enable_Port,SevenSeg2_Enable_Port};
u8 SEVENSEG_Enable_Pins[2]={SevenSeg1_Enable_Pin,SevenSeg2_Enable_Pin};


/*description: to display the number on sevensegment
 * input  : number of sevensegment
 * output : void
 */
void SevenSeg_setnumber(u8 number)
{
	/*array of each number on seven segment for common cathode*/
	u8 SevenSeg_Arr[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b11101111};

	/*check if common cathode or common anode*/
	/*if common cathode so it will use array direct*/
#if SevenSeg_Mode==1
	setPinValue(SevenSeg_Pin_A_Port,SevenSeg_Pin_A_Number,GET_BIT(SevenSeg_Arr[number],0));
	setPinValue(SevenSeg_Pin_B_Port,SevenSeg_Pin_B_Number,GET_BIT(SevenSeg_Arr[number],1));
	setPinValue(SevenSeg_Pin_C_Port,SevenSeg_Pin_C_Number,GET_BIT(SevenSeg_Arr[number],2));
	setPinValue(SevenSeg_Pin_D_Port,SevenSeg_Pin_D_Number,GET_BIT(SevenSeg_Arr[number],3));
	setPinValue(SevenSeg_Pin_E_Port,SevenSeg_Pin_E_Number,GET_BIT(SevenSeg_Arr[number],4));
	setPinValue(SevenSeg_Pin_F_Port,SevenSeg_Pin_F_Number,GET_BIT(SevenSeg_Arr[number],5));
	setPinValue(SevenSeg_Pin_G_Port,SevenSeg_Pin_G_Number,GET_BIT(SevenSeg_Arr[number],6));

	/*if common cathode so we will xor value of array */
#elif SevenSeg_Mode==0
	setPinValue(SevenSeg_Pin_A_Port,SevenSeg_Pin_A_Number,GET_BIT(SevenSeg_Arr[number],0)^0x01);
	setPinValue(SevenSeg_Pin_B_Port,SevenSeg_Pin_B_Number,GET_BIT(SevenSeg_Arr[number],1)^0x01);
	setPinValue(SevenSeg_Pin_C_Port,SevenSeg_Pin_C_Number,GET_BIT(SevenSeg_Arr[number],2)^0x01);
	setPinValue(SevenSeg_Pin_D_Port,SevenSeg_Pin_D_Number,GET_BIT(SevenSeg_Arr[number],3)^0x01);
	setPinValue(SevenSeg_Pin_E_Port,SevenSeg_Pin_E_Number,GET_BIT(SevenSeg_Arr[number],4)^0x01);
	setPinValue(SevenSeg_Pin_F_Port,SevenSeg_Pin_F_Number,GET_BIT(SevenSeg_Arr[number],5)^0x01);
	setPinValue(SevenSeg_Pin_G_Port,SevenSeg_Pin_G_Number,GET_BIT(SevenSeg_Arr[number],6)^0x01);
#endif

	/*to set the last value*/
	LastValue=number;
}


/*description: to enable the sevensegment
 * input  : sevensegment number
 * output : void
 */
void SevenSeg_Enable(u8 SEVENSEG_number)
{


	/*check if common anode or cathode*/
#if SevenSeg_Mode==1
	setPinValue(SEVENSEG_Enable_Ports[SEVENSEG_number],SEVENSEG_Enable_Pins[SEVENSEG_number],0);
#elif SevenSeg_Mode==0
	setPinValue(SEVENSEG_Enable_Ports[SEVENSEG_number],SEVENSEG_Enable_Pins[SEVENSEG_number],1);
#endif

	SevenSeg_setnumber(LastValue);
}

/*description: to disable the sevensegment
 * input  : sevensegment number
 * output : void
 */
void SevenSeg_Disable(u8 SEVENSEG_number2)
{
	/*check if common anode or cathode*/
#if SevenSeg_Mode==1
	setPinValue(SEVENSEG_Enable_Ports[SEVENSEG_number2],SEVENSEG_Enable_Pins[SEVENSEG_number2],1);
#elif SevenSeg_Mode==0
	setPinValue(SEVENSEG_Enable_Ports[SEVENSEG_number2],SEVENSEG_Enable_Pins[SEVENSEG_number2],0);
#endif

}
