/***********************************************************/
/* Author : Donia Mohamed                                  */ 
/* Date   : 9 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/


#ifndef  _UART_INTERFACE_H
#define _UART_INTERFACE_H

/*description: to set the initial values to USART
 * input  : void
 * output : void
 */
void UART_voidInitialize(void);

/*description: to transmit data synchronous
 * input  : data needed to transmit
 * output : Error
 */
u8 UART_u8TransmitDataSynch  (u8 Copy_u8Data);

/*description: to transmit data Asynchronous
 * input  : data needed to transmit , function of ISR
 * output : void
 */
void UART_voidTransmitDataAsynch (u8 Copy_u8Data , void (*Copy_ptr)(void));

/*description: to Receive data synchronous
 * input  : pointer to data needed to receive
 * output : error
 *  */
u8 UART_u8ReceiveSynch(u8 *copy_PuData);

/*description: to Receive data Asynchronous
 * input  : pointer to function of ISR
 * output : error
 *  */
u8 UART_u8ReceiveASynch(void(*Copy_ptr)(u8));

#endif
