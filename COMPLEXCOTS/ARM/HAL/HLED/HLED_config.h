/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 18 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

/*configuration structure of any led*/
typedef struct
{
	char GPIO_Pin_Num;
	char  GPIO_Port;
	char ACTIVESTATE;

}LedMap_t;
