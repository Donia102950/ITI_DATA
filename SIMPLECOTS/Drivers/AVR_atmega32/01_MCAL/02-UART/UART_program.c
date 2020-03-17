/***********************************************************/
/* Author : Donia Mohamed                                  */ 
/* Date   : 9 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/


/*includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_register.h"
#include "UART_private.h"
#include "UART_config.h"

/*Baud Rate values at single speed U2X=0*/
const u8 BaudRate[3][3]=
{
	/*4800 ,9600  , 115200*/ 
	
	{ 0x67 , 0x33 ,  0x03  },/*at clocksystem0 = 8M*/
	
	{ 154  ,  77  ,   6    },/*at clocksystem1 = 12M*/
	
	{ 0xcf , 0x67 ,  0x08  }/*at clocksystem2 = 16M*/
};

/*Global pointer to function which indicate the end of transmission and end of receive */
void (*EndOfTransmitCB)(void);
void (*EndOfReceiveCB)(u8);

/*description: to set the initial values to USART
 * input  : void
 * output : void
 */
void UART_voidInitialize(void)
{

	/*UCSRA
	 * U2X = 0  ...> no double of speed */
	CLR_BIT(UCSRA,1);

	/*to set some configuration in UCSRB
	 * RXCIE=0  RX complete interrupt enable (disable)
	 * TXCIE=0  TX complete interrupt enable (disable)
	 * UDRIE=0  Data register (UDR) empty interrupt enable (disable)
	 * RXEN=1   Receiver enable (enable)
	 * TXEN=1   Transmitter enable (enable)
	 * UCSZ2=0  character size =8
	 * RXB8=0   receive bit 8
	 * TXB8=0   transmit bit 8
	 */
	UCSRB=0x18;
	

	/*to set some configuration in UCSRC
	 * URSEL =1  register select between UCSRC and UBRRH  (1 to select UCSRC)
	 * UMSEL=0   Asynchronous
	 * UPM1 / UPM0    UART Parity mode
	 * USBS           UART stop mode
	 * UCSZ1/UCSZ2 : character size =8 bit
	 * UCPOL=0  raising edge at tx and falling edge at RX (clock polarity)*/
	UCSRC=(1<<7)|(UART_PARITY<<4)|(UART_STOP<<3)|(3<<1);
	
	/*assign BaudRate from the array and set it in UBRRL*/
	UBRRL=BaudRate[UART_u8_SYS_FREQ][UART_BAUD];
}

/*description: to transmit data synchronous
 * input  : data needed to transmit
 * output : Error
 */
u8 UART_u8TransmitDataSynch  (u8 Copy_u8Data)
{
	/*error*/
	u8 Local_u8Error=ERROR_OK;

	/*timeout if data not received*/
	u32 Local_u32TimeOut =0;

	/*send data on UDR*/
	UDR_T=Copy_u8Data;
	
	/*wait ti1l the flag of TXC in UCSRA is raised and or timeout >thershold*/
	while( (GET_BIT(UCSRA,6) == 0) &&( Local_u32TimeOut < TIMEOUT_THERSHOLD))
	{
		Local_u32TimeOut++;
	}
	/*to check if the loop broken through timeout*/
	if(Local_u32TimeOut>=TIMEOUT_THERSHOLD)
	{
		/*timeout happened*/
		Local_u8Error=ERROR_NOK;
	}
	/*if the flag raised*/
	else
	{
		/*clear flag of TXC in UCSRA*/
		SET_BIT(UCSRA,6);
	}
	return Local_u8Error;
}

/*description: to transmit data Asynchronous
 * input  : data needed to transmit , function of ISR
 * output : void
 */
void UART_voidTransmitDataAsynch (u8 Copy_u8Data , void (*Copy_ptr)(void))
{
	/*enable interrupt of transimtter TXCIE=1 "Tx complete interrupt enable " */
	SET_BIT(UCSRB,6);
	
	/*set received data to UDR*/
	UDR_T=Copy_u8Data;
	
	/*save the callback address*/
	EndOfTransmitCB=Copy_ptr;
}

/*description: to Receive data synchronous
 * input  : pointer to data needed to receive
 * output : error
 *  */
u8 UART_u8ReceiveSynch(u8 *copy_PuData)
{
	/*error*/
	u8 Local_u8Error=ERROR_OK;
	/*timeout*/
	u32 Local_u32TimeOut =0;
	
	/*wait ti1l the flag is raised (RXC =1 receive complete ) and must make timeout*/
	while( (GET_BIT(UCSRA,7) == 0) &&( Local_u32TimeOut < TIMEOUT_THERSHOLD))
	{
		Local_u32TimeOut++;
	}
	if(Local_u32TimeOut>=TIMEOUT_THERSHOLD)
	{
		/*timeout happened*/
		Local_u8Error=ERROR_NOK;
	}
	else
	{
		/*receive data through pointer , and flag is cleared by hardware (RXC =0)*/
		*copy_PuData=UDR_R;
	}
	return Local_u8Error;
}

/*description: to Receive data Asynchronous
 * input  : pointer to function of ISR
 * output : error
 *  */
u8 UART_u8ReceiveASynch(void(*Copy_ptr)(u8))
{
	/*check if there is data to receive*/
	if((GET_BIT(UCSRA,7)) == 1)
	{
		Copy_ptr(UDR_R);
	}
	else{
		/*Enable Rx interrupt*/
		SET_BIT(UCSRB,7);
		
		/*save call back*/
		EndOfReceiveCB=Copy_ptr;
	}
	return 0;
}
		

