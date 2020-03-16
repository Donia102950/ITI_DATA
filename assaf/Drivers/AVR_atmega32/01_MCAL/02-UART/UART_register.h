/***********************************************************/
/* Author : Donia Mohamed                                  */ 
/* Date   : 9 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

#ifndef  _UART_REGISTER_H
#define  _UART_REGISTER_H

#define UDR_T   *((u8*)0x2C)
#define UDR_R   *((u8*)0x2C)
#define UCSRA   *((u8*)0x2B)
#define UCSRB  *((u8*)0x2A)
#define UCSRC  *((u8*)0x40)
#define UBRRL   *((u8*)0x29)
#define UBRRH   *((u8*)0x40)


#endif