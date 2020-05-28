/************************************************************includes*************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC.h"

/***********************************************************Registers*************************************************************************************/
 #define BASE_ADDRESS 0X40021000

#define RCC_CR       ((u32 *)(BASE_ADDRESS + 0x00))
#define RCC_CFGR     ((u32 *)(BASE_ADDRESS + 0x04))
#define RCC_CIR      ((u32 *)(BASE_ADDRESS + 0x08))
#define RCC_APB2RSTR ((u32 *)(BASE_ADDRESS + 0x0C))
#define RCC_APB1RSTR ((u32 *)(BASE_ADDRESS + 0x10))
#define RCC_AHBENR   ((u32 *)(BASE_ADDRESS + 0x14))
#define RCC_APB2ENR  ((u32 *)(BASE_ADDRESS + 0x18))
#define RCC_APB1ENR  ((u32 *)(BASE_ADDRESS + 0x1C))
#define RCC_BDCR     ((u32 *)(BASE_ADDRESS + 0x20))
#define RCC_CSR      ((u32 *)(BASE_ADDRESS + 0x24))

/************************************************************General defines******************************************************************************/
#define CLKRDY           1
#define CLKNRDY          0
#define MCO_CLEAR        0xF8FFFFFF
#define PLL_MUL_CLEAR    0xFFC3FFFF
#define SW_CLEAR         0xFFFFFFFC
#define PLL_SOURCE_CLEAR 0xFFFEFFFF

#define PLL_FACTOR       0x00010000
#define PLL_DIFACTOR     0x00020000
#define SW_READ          0x0000000C
#define PLL_MULT_MASK    0x003c0000

/*read sys clock mask  (RCC_CFGR)*/
#define PLL_MASK_READ 0x00000008
#define HSE_MASK_READ 0X00000004
#define HSI_MASK_READ 0x00000000


#define HSI_CLOCK_SW 8000000
#define HSE_CLOCK_SW 8000000

/*clear prescaler buses*/
#define PPRE2_PRESCALER_CLEAR 0xffffC7ff
#define PPRE1_PRESCALER_CLEAR 0xfffff8ff
#define HPRE_PRESCALER_CLEAR  0xffffff0f
#define PLL_MULTIPLY_CLEAR    0xff3cffff

/*error*/
#define OK 1
#define NOK 0

/***************static functions********/
static u32 check_PLLMultiply(void);
static u32 PLL_FUN(u32 clock);

/**********************************************************Functions implementation***********************************************************************/
/* Description: to set the clock 
CLock can be :HSI_CLOCK / HSE_CLOCK/PLL_CLOCK
STATUS: CLOCK_ON/CLOCK_OFF */
void Control_Clock(u32 clock,u8 status)
{
	switch(status)
	{
	case CLOCK_ON :
		*RCC_CR |=clock;
		break;
	case CLOCK_OFF:
		*RCC_CR &= ~clock;
	}
	//*RCC_CR=0x00010000;
}


/* Description: to check the status of the clock 
CLock can be :HSI_RDY/HSE_RDY/PLL_RDY*/
u8 CHECK_ClockStatus(u32 clock)
{
	u8 clock_State;
	if((*RCC_CR & clock) == clock)
	{
		clock_State=CLKRDY;
	}
	else
	{
		clock_State=CLKNRDY;
	}
	return clock_State;
}

/* Description: to set clock output pin MCO
CLock can be :SYS_MCO/ HSI_MCO/HSE_MCO /PLL_MCO*/
void Set_ClockOutput(u32 clock)
{
	*RCC_CFGR=((*RCC_CFGR&MCO_CLEAR)|clock);
}

/* Description: to close pll source
*/
void Close_pllClk(void)
{
	*RCC_CR&=~PLL_CLOCK;
}

/* Description: to set PLL multiplication factor
CLock can be :PLLMUL_2/PLLMUL_3/PLLMUL_4 ....... /PLLMUL_16*/
void Set_PLLMul(u32 clock)
{

	*RCC_CFGR=((*RCC_CFGR&PLL_MUL_CLEAR)|clock);
}


/* Description: to set the system clock 
CLock can be :HSI_CLOCK / HSE_CLOCK/PLL_CLOCK
STATUS: CLOCK_ON/CLOCK_OFF */
u8 SYS_clock(u32 clock)
{
	u8 check;
	u8 state;
	check=CHECK_ClockStatus(clock);
	if (check==CLKRDY)
	{
		*RCC_CFGR=((*RCC_CFGR&SW_CLEAR)|clock);
		state= SETSW;
	}
	else 
	{
		state= NSETSW;
	}
	//*RCC_CFGR=0x00000001;
	return state;
}

/* Description: to set the PLL source
CLock can be :PLL_HSI /PLL_HSE */
u8 PLLsource_clock(u32 clock)
{
	u8 state;
	if((*RCC_CR & PLL_CLOCK)==PLL_CLOCK)
	{
		state= NSET;
	}
	else
	{
		switch(clock)
		{
		case PLL_HSI:
			*RCC_CFGR &= ~PLL_FACTOR;
			break;
		case PLL_HSE:
			*RCC_CFGR |=PLL_FACTOR;
			break;
		}
		state =SET;
	}
	return state;
}

/* Description: to set the PLL_HSE division
CLock can be :PLL_HSE_DIV /PLL_HSE_NDIV */
u8 PLLHSE_Division(u32 clock)
{
	u8 state;
	if((*RCC_CR & PLL_SWCLOCK)==PLL_SWCLOCK)
	{
		state= NSET;
	}
	else
	{
		switch(clock)
		{
		case PLL_HSE_NDIV:
			*RCC_CFGR &= ~PLL_DIFACTOR;
			break;
		case PLL_HSE_DIV:
			*RCC_CFGR |=PLL_DIFACTOR;
			break;
		}
		state= SET;
	}
	return state;
}


/* Description:to unable or disable the peripheral
Bus can be :RCC_AHBENR /RCC_APB2ENR /RCC_APB1ENR 
prepheral: RCC_AHBENR_peripherals / RCC_APB2ENR_peripherals / RCC_APB1ENR_peripherals 
state :STATE_OF /STATE_ON */
void RCC_StateOFPrepheralClock(u8 Bus ,u32 prepheral,u8 state)
{

	switch(state)
	{
	case STATE_ON:
		switch(Bus)
		{
		case RCC_AHBENR_BUS :
			*RCC_AHBENR|=prepheral;
			break;
		case RCC_APB2ENR_BUS :
			*RCC_APB2ENR|=prepheral;
			break;
		case RCC_APB1ENR_BUS :
			*RCC_APB1ENR|=prepheral;
			break;
		}
		break;
		case STATE_OFF:
			switch(Bus)
			{
			case RCC_AHBENR_BUS :
				*RCC_AHBENR&=~prepheral;
				break;
			case RCC_APB2ENR_BUS :
				*RCC_APB2ENR&=~prepheral;
				break;
			case RCC_APB1ENR_BUS :
				*RCC_APB1ENR&=~prepheral;
				break;
			}
			break;

	}
}

/* Description:to set prescaler of bus
input :bus and prescalervalue
output : error
 */
u8 SetPrescaler_Bus(u8 Bus,u32 Prescaler)
{
	u8 Local_u8Error=OK;
	if(Bus == PPRE2_PRESCALER)
	{
		*RCC_CFGR=((*RCC_CFGR&PPRE2_PRESCALER_CLEAR)|Prescaler);

	}
	else if (Bus == PPRE1_PRESCALER)
	{
		*RCC_CFGR=((*RCC_CFGR&PPRE1_PRESCALER_CLEAR)|Prescaler);
	}
	else if (Bus == HPRE_PRESCALER)
	{
		*RCC_CFGR=((*RCC_CFGR&HPRE_PRESCALER_CLEAR)|Prescaler);
	}
	else
	{
		Local_u8Error=NOK;
	}
	return Local_u8Error;
}


/* Description: to read the  the system clock
CLock can be :HSI_CLOCK / HSE_CLOCK/PLL_CLOCK
STATUS: CLOCK_ON/CLOCK_OFF */
u32 GETSYS_clock(void)
{
	u32 clock=0;
	if(((*RCC_CFGR) & SW_READ )== PLL_MASK_READ)
	{
		clock=check_PLLMultiply();
	}
	else if(((*RCC_CFGR) & SW_READ) == HSE_MASK_READ)
	{
		clock=HSE_CLOCK_SW;
	}
	else if (((*RCC_CFGR) & SW_READ)== HSI_MASK_READ)
	{
		clock=HSI_CLOCK_SW;
	}

	return clock;
}

static u32 check_PLLMultiply(void)
{
	u32 clock;
	if ((*RCC_CFGR & PLL_FACTOR)==PLL_FACTOR)
	{
		if ((*RCC_CFGR & PLL_DIFACTOR)==PLL_DIFACTOR)
		{
			clock = HSE_CLOCK_SW/2;
		}
		else
		{
			clock = HSE_CLOCK_SW;
		}
	}
	else
	{
		clock = HSI_CLOCK_SW;
	}
	clock=PLL_FUN(clock);
	return clock;
}

static u32 PLL_FUN(u32 clock)
{
	if ((*RCC_CFGR & PLL_MULT_MASK)==PLLMUL_2)
	{
		clock=clock*2;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_3)
	{
		clock=clock*3;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_4)
	{
		clock=clock*4;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_5)
	{
		clock=clock*5;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_6)
	{
		clock=clock*6;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_7)
	{
		clock=clock*7;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_8)
	{
		clock=clock*8;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_9)
	{
		clock=clock*9;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_10)
	{
		clock=clock*10;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_11)
	{
		clock=clock*11;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_12)
	{
		clock=clock*12;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_13)
	{
		clock=clock*13;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_14)
	{
		clock=clock*14;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_15)
	{
		clock=clock*15;
	}
	else if ((*RCC_CFGR &PLL_MULT_MASK)==PLLMUL_16)
	{
		clock=clock*16;
	}
	return clock;
}
/**************************************************************END***************************************************************************************/
