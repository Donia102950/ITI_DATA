/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 17 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

/**********************************************defines************************************/
#define MAXNUM 1
#define SWITCHNUM1 0


/*description:to initialize switch
 * input:void
 * output : error
 */
uint_8t Hswitch_init(void);

/*description: to get the state of any switch
 * input:switch number , state
 * output : error
 */
uint_8t Hswitch_getSwitchState(uint_8t switchNum , uint_8t *state);


/*description: to create the task of any switch
 * input:void
 * output :void
 */
void Start_Debouncing(void);



