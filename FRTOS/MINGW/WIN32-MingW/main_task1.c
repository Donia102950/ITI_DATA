/*
 * FreeRTOS Kernel V10.3.1
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/******************************************************************************
 * NOTE 1: Windows will not be running the FreeRTOS demo threads continuously, so
 * do not expect to get real time behaviour from the FreeRTOS Windows port, or
 * this demo application.  Also, the timing information in the FreeRTOS+Trace
 * logs have no meaningful units.  See the documentation page for the Windows
 * port for further information:
 * http://www.freertos.org/FreeRTOS-Windows-Simulator-Emulator-for-Visual-Studio-and-Eclipse-MingW.html
 *
 * NOTE 2:  This project provides two demo applications.  A simple blinky style
 * project, and a more comprehensive test and demo application.  The
 * mainCREATE_SIMPLE_BLINKY_DEMO_ONLY setting in main.c is used to select
 * between the two.  See the notes on using mainCREATE_SIMPLE_BLINKY_DEMO_ONLY
 * in main.c.  This file implements the simply blinky version.  Console output
 * is used in place of the normal LED toggling.
 *
 * NOTE 3:  This file only contains the source code that is specific to the
 * basic demo.  Generic functions, such FreeRTOS hook functions, are defined
 * in main.c.
 ******************************************************************************
 *
 * main_blinky() creates one queue, one software timer, and two tasks.  It then
 * starts the scheduler.
 *
 * The Queue Send Task:
 * The queue send task is implemented by the prvQueueSendTask() function in
 * this file.  It uses vTaskDelayUntil() to create a periodic task that sends
 * the value 100 to the queue every 200 milliseconds (please read the notes
 * above regarding the accuracy of timing under Windows).
 *
 * The Queue Send Software Timer:
 * The timer is an auto-reload timer with a period of two seconds.  The timer's
 * callback function writes the value 200 to the queue.  The callback function
 * is implemented by prvQueueSendTimerCallback() within this file.
 *
 * The Queue Receive Task:
 * The queue receive task is implemented by the prvQueueReceiveTask() function
 * in this file.  prvQueueReceiveTask() waits for data to arrive on the queue.
 * When data is received, the task checks the value of the data, then outputs a
 * message to indicate if the data came from the queue send task or the queue
 * send software timer.
 *
 * Expected Behaviour:
 * - The queue send task writes to the queue every 200ms, so every 200ms the
 *   queue receive task will output a message indicating that data was received
 *   on the queue from the queue send task.
 * - The queue send software timer has a period of two seconds, and is reset
 *   each time a key is pressed.  So if two seconds expire without a key being
 *   pressed then the queue receive task will output a message indicating that
 *   data was received on the queue from the queue send software timer.
 *
 * NOTE:  Console input and output relies on Windows system calls, which can
 * interfere with the execution of the FreeRTOS Windows port.  This demo only
 * uses Windows system call occasionally.  Heavier use of Windows system calls
 * can crash the port.
 */

//* Standard includes. */
#include <stdio.h>
#include <conio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

/*******************new task priority*************************/
#define PRINT_ONE_PRIORITY                   (tskIDLE_PRIORITY+2)
#define PRINT_TWO_PRIORITY                   (tskIDLE_PRIORITY+1)


/***********************new peridicity **************************************/
#define PERIODICTIY_PRINT_ONE   500
#define PERIODICITY_PRINT_TWO  1000

/*-----------------------------------------------------------*/
/*
 * The tasks as described in the comments at the top of this file.
 */
/*************************************************************/
static void print_one( void *PVP );
static void print_two( void *PVP );

/*** SEE THE COMMENTS AT THE TOP OF THIS FILE ***/
void main_task1( void )
{
	xTaskCreate( print_one,			/* The function that implements the task. */
			"print_one", 							/* The text name assigned to the task - for debug only as it is not used by the kernel. */
			configMINIMAL_STACK_SIZE, 		/* The size of the stack to allocate to the task. */
			NULL, 							/* The parameter passed to the task - not used in this simple case. */
			PRINT_ONE_PRIORITY,/* The priority assigned to the task. */
			NULL );

	xTaskCreate( print_two,			/* The function that implements the task. */
			"print_two", 							/* The text name assigned to the task - for debug only as it is not used by the kernel. */
			configMINIMAL_STACK_SIZE, 		/* The size of the stack to allocate to the task. */
			NULL, 							/* The parameter passed to the task - not used in this simple case. */
			PRINT_TWO_PRIORITY,/* The priority assigned to the task. */
			NULL );		/* The task handle is not required, so NULL is passed. */

	vTaskStartScheduler();

	/* If all is well, the scheduler will now be running, and the following
		line will never be reached.  If the following line does execute, then
		there was insufficient FreeRTOS heap memory available for the idle and/or
		timer tasks	to be created.  See the memory management section on the
		FreeRTOS web site for more details. */
	while(1);


}
static void print_one( void *PVP )
{
	/* Prevent the compiler warning about the unused parameter. */
	( void ) PVP;

	while(1)
	{

		printf("Hello from print one\n");
		fflush( stdout );
		vTaskDelay(PERIODICTIY_PRINT_ONE);

	}
}


static void print_two( void *PVP )
{
	/* Prevent the compiler warning about the unused parameter. */
	( void ) PVP;

	while(1)
	{


		printf("Hello from print two\n");
		fflush( stdout );
		vTaskDelay(PERIODICITY_PRINT_TWO);
	}
}
