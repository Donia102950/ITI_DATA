#include "STD_TYPES.h"

/**********************************************************user configuration***********************************************************************/
/*(RCC_CR)*/
/*select source*/
#define HSI_CLOCK              0x00000001
#define HSE_CLOCK              0x00010000
#define PLL_CLOCK              0x01000000
/*ready state of each clk*/
#define HSI_RDY                0x00000002
#define HSE_RDY                0x00020000
#define PLL_RDY                0x02000000
/*to set hse from output source*/
#define HSE_PYPASS             0x00040000
/*to trigger HSE*/
#define CSS_ON                 0x00080000

/* (RCC_CFGR)*/
/*system clock*/
#define HSI_SWCLOCK            0x00000000
#define HSE_SWCLOCK            0x00000001
#define PLL_SWCLOCK            0x00000002
/*AHB prescaler*/
#define AHB_NOT_DIVIDED        0x00000000
#define AHB_DIVIDED_BY_2       0x00000080
#define AHB_DIVIDED_BY_4       0x00000090
#define AHB_DIVIDED_BY_8       0x000000A0
#define AHB_DIVIDED_BY_16      0x000000B0
#define AHB_DIVIDED_BY_64      0x000000C0
#define AHB_DIVIDED_BY_128     0x000000D0
#define AHB_DIVIDED_BY_256     0x000000E0
#define AHB_DIVIDED_BY_512     0x000000F0
/*APB1 prescaler*/
#define APB1_NOT_DIVIDED        0x00000000
#define APB1_DIVIDED_BY_2       0x00000400
#define APB1_DIVIDED_BY_4       0x00000500
#define APB1_DIVIDED_BY_8       0x00000600
#define APB1_DIVIDED_BY_16      0x00000700
/*APB2 prescaler*/
#define APB2_NOT_DIVIDED        0x00000000
#define APB2_DIVIDED_BY_2       0x00002000
#define APB2_DIVIDED_BY_4       0x00002800
#define APB2_DIVIDED_BY_8       0x00003000
#define APB2_DIVIDED_BY_16      0x00003800
/*pll source*/
#define PLL_HSI                 0

#define PLL_HSE                 1

/*pll_HSE division*/
#define PLL_HSE_DIV             0
#define PLL_HSE_NDIV            1
/*pll multipleFactor*/
#define PLLMUL_2                0x00000000
#define PLLMUL_3                0x00040000
#define PLLMUL_4                0x00080000
#define PLLMUL_5                0x000C0000
#define PLLMUL_6                0x00100000
#define PLLMUL_7                0x00140000
#define PLLMUL_8                0x00180000
#define PLLMUL_9                0x001C0000
#define PLLMUL_10               0x00200000
#define PLLMUL_11               0x00240000
#define PLLMUL_12               0x00280000
#define PLLMUL_13               0x002C0000
#define PLLMUL_14               0x00300000
#define PLLMUL_15               0x00340000
#define PLLMUL_16               0x00380000
/*#define PLLMUL_16 0x003C0000*/
/*MCO output pin*/
#define SYS_MCO                 0x04000000
#define HSI_MCO                 0x05000000
#define HSE_MCO                 0x06000000
#define PLLdivided_2__MCO       0x07000000


#define RCC_AHBENR_BUS  0
#define RCC_APB2ENR_BUS 1
#define RCC_APB1ENR_BUS 2

/*RCC_AHBENR_peripherals*/
#define DMA1EN  0x00000001
#define DMA2EN  0x00000002
#define SRAMEN  0x00000004
#define FLITFEN 0x00000010
#define FSMCEN  0x00000100
#define SDIOEN  0x00000400

/*RCC_APB2ENR_peripherals*/
#define AFIOEN    0x00000001
#define IOPAEN    0x00000004
#define IOPBEN    0x00000008
#define IOPCEN    0x00000010	
#define IOPDEN    0x00000020
#define IOPEEN    0x00000040
#define IOPFEN    0x00000080
#define IOPGEN    0x00000100
#define ADC1EN    0x00000200
#define ADC2EN    0x00000400
#define TIM1EN 	  0x00000800
#define SPI1EN    0x00001000
#define TIM8EN    0x00002000
#define USART1EN  0x00004000
#define ADC3EN    0x00008000
#define TIM9EN    0x00080000
#define TIM10EN   0x00100000
#define TIM11EN   0x00200000


/*RCC_APB1ENR_peripherals*/
#define TIM2EN    0x00000001
#define TIM3EN    0x00000002
#define TIM4EN    0x00000004
#define TIM5EN    0x00000008
#define TIM6EN    0x00000010	
#define TIM7EN    0x00000020
#define TIM12EN   0x00000040
#define TIM13EN   0x00000080
#define TIM14EN   0x00000100
#define WWDGEN 	  0x00000800
#define SPI2EN    0x00004000
#define SPI3EN    0x00008000
#define USART2EN  0x00020000
#define USART3EN  0x00040000
#define UART4EN   0x00080000
#define UART5EN   0x00100000
#define I2C1EN    0x00200000
#define I2C2EN    0x00400000
#define USBEN     0x01000000
#define CANEN     0x04000000
#define BKPEN     0x08000000
#define PWREN     0x10000000
#define DACEN     0x20000000

#define STATE_OFF 0
#define STATE_ON 1

#define SETSW  1
#define NSETSW 0

#define NSET 0
#define SET  1

#define CLOCK_ON   ((u8)1)
#define CLOCK_OFF  ((u8)0)

/*prescaler of each bus*/
/*PPRE2_PRESCALER*/
#define PPRE2_PRESCALER 1

/*PPRE2_PRESCALER*/
#define PPRE1_PRESCALER 2

/*PPRE2_PRESCALER*/
#define HPRE_PRESCALER 3

/*clock to be checked*/
#define HSI_CHECK  0
#define HSE_CHECK  1
#define PLL_CHECK  2

/**********************************************************Functions prototypes***********************************************************************/
/* Description: to set the clock 
CLock can be :HSI_CLOCK / HSE_CLOCK/PLL_CLOCK
STATUS: CLOCK_ON/CLOCK_OFF */
void Control_Clock(u32 clock,u8 status);

/* Description: to check the status of the clock 
CLock can be :HSI_CHECK,HSE_CHECK,PLL_CHECK*/
u8 CHECK_ClockStatus(u32 clock);

/* Description: to set clock output pin MCO
CLock can be :SYS_MCO/ HSI_MCO/HSE_MCO /PLL_MCO*/
void Set_ClockOutput(u32 clock);

/* Description: to set PLL multiplication factor
CLock can be :PLLMUL_2/PLLMUL_3/PLLMUL_4 ....... /PLLMUL_16*/
void Set_PLLMul(u32 clock);

/* Description: to set the system clock 
CLock can be :HSI_CLOCK / HSE_CLOCK/PLL_CLOCK
return value  SETSW/NSETSW
*/
u8 SYS_clock(u32 clock);

/* Description: to set the PLL source
CLock can be :PLL_HSI /PLL_HSE 
return value NSET/SET*/
u8 PLLsource_clock(u32 clock);

/* Description: to set the PLL_HSE division
CLock can be :PLL_HSE_DIV /PLL_HSE_NDIV 
return value NSET/SET*/
u8 PLLHSE_Division(u32 clock);

/* Description:to unable or disable the peripheral
Bus can be :RCC_AHBENR /RCC_APB2ENR /RCC_APB1ENR 
prepheral: RCC_AHBENR_peripherals_BUS / RCC_APB2ENR_peripherals_BUS / RCC_APB1ENR_peripherals_BUS 
state :STATE_OF /STATE_ON */
void RCC_StateOFPrepheralClock(u8 Bus ,u32 prepheral,u8 state);


/*adding Prescaler function to each bus*/
//uint32_t RCC_setPrescaler(uint8_t bus,uint8_t prescaler);

/* Description:to know th sys clock
input :sysclk
output : error
*/
u32 GETSYS_clock(void);

/* Description:to st prescaler of bus
input :bus and prescalervalue
output : error
*/
u8 SetPrescaler_Bus(u8 Bus,u32 Prescaler);

/*to close pll before any changes*/
void Close_pllClk(void);
