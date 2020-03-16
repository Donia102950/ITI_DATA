/*author: donia mohamed
 * version: 1.1
 * type:DIO Driver
 * MC:AVR
 */

/*includes*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "DIO_config.h"

/*description: to set the direction of any pin as input or output
 * input: port: 'A','B','C','D'/Pin: from 0 to 7 /direction:1 or 0
 * output : void
 */
void setPinDirection(u8 port,u8 pin,u8 direction)
{
	/*to check the port*/
	switch(port)
	{
		case 'A':
			if(direction==0)  //input
			{
				//DDRA=DDRA & ~(1<<pin);   to clear bit 
				 CLR_BIT(DDRA,pin); 
			}
			else   //output
			{
				//DDRA=DDRA |(1<<pin);				to set bit 
				 SET_BIT(DDRA,pin); 
			}
			break;
			
		case 'B':
			if(direction==0)  //input
			{
				//DDRB=DDRB & ~(1<<pin);   to clear bit 
				 CLR_BIT(DDRB,pin); 
			}
			else   //output
			{
				//DDRB=DDRB |(1<<pin);   to set bit 
				 SET_BIT(DDRB,pin); 
			}
			break;
			
		case 'C':
			if(direction==0)
			{
				CLR_BIT(DDRC,pin);
			}
			else
			{
				 SET_BIT(DDRC,pin); 
			}
			break;
			
		case 'D':
			if(direction==0)  //input
			{
				//DDRD=DDRD & ~(1<<pin);   to clear bit 
				 CLR_BIT(DDRD,pin); 
			}
			else   //output
			{
				//DDRD=DDRD |(1<<pin);   to set bit
				CLR_BIT(DDRD,pin); 				
			}
			break;
		
	}
	
}	

/*description: to set the value of any pin as high or low
 * input: port: 'A','B','C','D'/Pin: from 0 to 7 /value:1 or 0
 * output : void
 */
void setPinValue(u8 port,u8 pin,u8 val)
{
	switch(port)
	{
		case 'A':
			if(val==0)  //input
			{
				//PORTA=PORTA & ~(1<<pin);   to clear bit 
				 CLR_BIT(PORTA,pin);
			}
			else   //output
			{
				//PORTA=PORTA |(1<<pin);   to set bit 
				 SET_BIT(PORTA,pin);
			}
			break;
			
		case 'B':
			if(val==0)  //input
			{
				//PORTB=PORTB & ~(1<<pin);   to clear bit
				CLR_BIT(PORTB,pin);
			}
			else   //output
			{
				//PORTB=PORTB |(1<<pin);   to set bit 
				 SET_BIT(PORTB,pin);
			}
			break;
			
		case 'C':
			if(val==0)  //input
			{
				//PORTC=PORTC & ~(1<<pin);   to clear bit
				 CLR_BIT(PORTC,pin);
			}
			else   //output
			{
				//PORTC=PORTC |(1<<pin);   to set bit 
				 SET_BIT(PORTC,pin);
			}
			break;
			
		case 'D':
			if(val==0)  //input
			{
				//PORTD=PORTD & ~(1<<pin);   to clear bit
				 CLR_BIT(PORTD,pin);
			}
			else   //output
			{
				//PORTD=PORTD |(1<<pin);   to set bit
					 SET_BIT(PORTD,pin);
			}
			break;
		
	}
	
}	


/*description: to set the direction of any port as high or low
 * input: port: 'A','B','C','D'/value:1 or 0
 * output : void
 */

void setPortDirection(u8 port,u8 direction)
{
	switch(port)
	{
		case 'A':
			if(direction==0)  //input
			{
				DDRA=0x00;
			}
			else   //output
			{
				DDRA=0XFF;
			}
			break;

		case 'B':
			if(direction==0)  //input
			{
				DDRB=0x00;
			}
			else   //output
			{
				DDRB=0XFF;
			}
			break;

		case 'C':
			if(direction==0)
			{
				DDRC=0x00;
			}
			else
			{
				DDRC=0XFF;
			}
			break;

		case 'D':
			if(direction==0)  //input
			{
				DDRD=0x00;
			}
			else   //output
			{
				DDRD=0XFF;
			}
			break;

	}

}

/*description: to set the value of any port as high or low
 * input: port: 'A','B','C','D'/value:1 or 0
 * output : void
 */

void setPortValue(u8 port,u8 val)
{
	switch(port)
	{
		case 'A':
			if(val==0)  //input
			{
				PORTA=0x00;
			}
			else   //output
			{

				PORTA=0xFF;
			}
			break;

		case 'B':
			if(val==0)  //input
			{

				PORTB=0x00;
			}
			else   //output
			{

				PORTB=0xFF;
			}
			break;

		case 'C':
			if(val==0)  //input
			{

				PORTC=0x00;
			}
			else   //output
			{
				PORTC=0xFF;
			}
			break;

		case 'D':
			if(val==0)  //input
			{
				PORTD=0x00;
			}
			else   //output
			{
				PORTD=0xFF;
			}
			break;

	}

}

