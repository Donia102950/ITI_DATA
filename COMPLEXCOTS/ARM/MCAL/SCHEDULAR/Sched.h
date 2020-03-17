/***********************************************************/
/* Author : Donia Mohamed                                  */
/* Date   : 17 March  2020                                  */
/* Version: V01                                            */
/***********************************************************/

#ifndef SCHED_H_
#define SCHED_H_

/*standard types*/
typedef unsigned char uint_8t;
typedef unsigned short int uint_16t;
typedef unsigned long int uint_32t;
typedef unsigned long long uint_64t;
typedef signed char int_8t;
typedef signed short int int_16t;
typedef signed short int int_32t;

/*errordefine*/
#define OK       0
#define NOT_OK   1


typedef void (* Runnable_t)(void);
typedef struct {
	Runnable_t Runnable;
	uint_32t periodicity;
}task_t;

/*description: to initialize our schedular
 * input: port: void
 * output : Error state
 */
uint_8t Sched_Init(void);

/*description: to start our schedular
 * input: port: void
 * output : Error state
 */
uint_8t Sched_Start(void);

/*description: to suspend any task
 * input: port: void
 * output : Error state
 */
void Sched_Suspend(void);



#endif /* SCHED_H_ */
