/***********************************************************/
/* Author : Donia Mohamed                                  */ 
/* Date   : 9 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/


#ifndef  _UART_CONFIG_H
#define  _UART_CONFIG_H

/*options: UART_PARITY_DISABLED
           UART_PARITY_EVEN
		   UART_PARITY_ODD */
#define UART_PARITY  UART_PARITY_DISABLED


/*options :UART_BAUD_4800
           UART_BAUD_9600
           UART_BAUD_115200 */
#define UART_BAUD  UART_BAUD_9600

/*options :UART_STOP_1_BIT
           UART_STOP_2_BIT */
#define UART_STOP UART_STOP_1_BIT

/*options :UART_SYS_8M
           UART_SYS_12M
           UART_SYS_16M */
#define UART_u8_SYS_FREQ  UART_SYS_8M

/*timeout*/
#define TIMEOUT_THERSHOLD  40000

#endif
