/***********************************************************/
/* Author : Donia Mohamed                                  */ 
/* Date   : 9 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/


#ifndef  _UART_PRIVATE_H
#define  _UART_PRIVATE_H


/*we choose those values related to DAta sheet*/
#define UART_PARITY_DISABLED  0U 
#define UART_PARITY_ODD       2U
#define UART_PARITY_EVEN      3U

#define UART_BAUD_4800    0U
#define UART_BAUD_9600    1U
#define UART_BAUD_115200  2U

#define UART_STOP_1_BIT   0U
#define UART_STOP_2_BIT   1U

#define UART_SYS_8M   0U
#define UART_SYS_12M  1U
#define UART_SYS_16M  2U


#endif