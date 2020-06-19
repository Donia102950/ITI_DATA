/****************************************datatypes needed**************************************/
typedef unsigned char uint_8t;
typedef unsigned short int uint_16t;
typedef unsigned long int uint_32t;
typedef unsigned long long uint_64t;
typedef signed char int_8t;
typedef signed short int int_16t;
typedef signed short int int_32t;

#define OK       0
#define NOT_OK   1

/************************************systick clk defines needed*********************************/
#define SYSTICK_CLK_AHB  	   0x00000004
#define SYSTICK_CLK_AHB_DIV_8  0x00000000

/****************************************systick interrupt**************************************/
#define SYSTICK_TICK_INT_ENABLE  0x00000002
#define SYSTICK_TICK_INT_DISABLE 0x00000000

/*************************************pointer to function type**********************************/
typedef void (*systickcbf_t) (void);

/********************************************prototypes*****************************************/
uint_8t SYSTICK_Init (void);
uint_8t SYSTICK_Start (void);
uint_8t SYSTICK_Stop (void);
uint_8t SYSTICK_SetCallback (systickcbf_t cbf);
uint_8t SYSTICK_SetTime (uint_32t timeus,uint_32t clk);
uint_8t SYSTICK_SetPrescale (uint_32t prescale);
