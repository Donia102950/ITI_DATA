/*************************************************includes***********************************/
#include "DSYSTICK.h"
#include "DSYSTICK_config.h"

/*************************************Special registers of systick***************************/
#define STK_CTRL	*((volatile uint_32t*)0xE000E010)
#define STK_LOAD	*((volatile uint_32t*)0xE000E014)
#define STK_VAL		*((volatile uint_32t*)0xE000E018)

/******************************pointer to function********************************************/
systickcbf_t APPcbf ;

/*************************************defines*************************************************/
#define SYSTICK_ENABLE   0x00000001
#define SYSTICK_DISABLE  0xFFFFFFFE

/*init function to set the clk src and interrupt*/
uint_8t SYSTICK_Init (void)
{
	/*
	 * set the clk source to AHB/8
	 * enable interrupt pf systick
	 * we can set nvic here for systick and we can make it in main
	 */
	STK_CTRL |= SYSTICK_CLK_SRC | SYSTICK_TICK_INT;
	return OK;
}

/*start function to start the timer*/
uint_8t SYSTICK_Start (void)
{
	STK_CTRL |= SYSTICK_ENABLE;
	return OK;
}

/*start function to stop the timer*/
uint_8t SYSTICK_Stop (void)
{
	STK_CTRL &= SYSTICK_DISABLE;
	return OK;
}

/*to set the callbackfunction*/
uint_8t SYSTICK_SetCallback (systickcbf_t cbf)
{
	if(cbf)
	{
		APPcbf = cbf;
		return OK;
	}
	else
	{
		return NOT_OK;
	}
}

/*to set the reload value due to time in macro*/
uint_8t SYSTICK_SetTime (uint_32t timeus,uint_32t clk)
{
	/*in case clk AHB*/
	if (STK_CTRL & SYSTICK_CLK_AHB)
	{
		STK_LOAD=(timeus * clk)/1000000;
	}

	/*in case clk AHB/8*/
	else if (!(STK_CTRL & SYSTICK_CLK_AHB))
	{
		STK_LOAD=((uint_64t)timeus * (uint_64t)clk)/8000000ULL;
	}
	else
	{
		return NOT_OK;
	}
	return OK;
}

/*systick handler*/
void SysTick_Handler(void)
{
	if (APPcbf)
	{
		APPcbf();
	}
	else
	{
		asm ("NOP");
	}
}
