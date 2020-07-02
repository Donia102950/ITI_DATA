/********************************************************includes**************************************************************/
#include "STD_TYPES.h"

#include "NVIC_interface.h"

/* offset address of NVIC*/
#define NVIC_BASE_ADDRESS   0xE000E100

/*Global Value of BASEPRI*/
u32 BaseValue;

/*the addresses of NVIC registers*/
#define REGISTER_OFFSET  3
#define RESERVED    29
#define IPR_OFFSET   84
#define PASSWORD_MASK  0X5FA00000

/*defines of the Enablefunction */
#define DIVIDER_VALUE 32
#define REG_ONE    0
#define REG_TWO    1
#define REG_THREE  2

/*define the ErrorState*/
#define OK 1
#define NOK 0

/*define the max n.reg*/
#define NUM_REG  3

/*struct of all registers in NVIC*/
typedef struct
{
	u32 ISER[REGISTER_OFFSET];                                /*register offset will change according the number of interrupts will be covered*/
	u32 res1[RESERVED];                                       /*to avoid gap addresses between ever register*/
	u32 ICER[REGISTER_OFFSET];
	u32 res2[RESERVED];                                       /*to avoid gap addresses between ever register*/
	u32 ISPR[REGISTER_OFFSET];
	u32 res3[RESERVED];                                       /*to avoid gap addresses between ever register*/
	u32 ICPR[REGISTER_OFFSET];
	u32 res4[RESERVED];                                       /*to avoid gap addresses between ever register*/
	u32 IABR[REGISTER_OFFSET];
	u32 res5[RESERVED];                                       /*to avoid gap addresses between ever register*/
	u8  IPR[IPR_OFFSET];
}NVIC_Register;

/*systemControlBlock*/
#define SCB_AIRCR *((volatile u32*) 0XE000ED0C)

/*the offset is different so i will make it #define alone*/
#define STIR    ((volatile u32 *)(NVIC_BASE_ADDRESS+E00))

/*pointer to struct NVIC_Register*/
#define NVIC_Register_t ((volatile NVIC_Register*)(NVIC_BASE_ADDRESS))


/*enable function */
u8 NVIC_uint8enableInterrupt(u8 Interrupt_Number)
{
	u8 errorStatus=OK;
	u8 Check,offset;
	Check = Interrupt_Number/DIVIDER_VALUE;

	if(Check==REG_ONE)
	{
		offset=Interrupt_Number%DIVIDER_VALUE;
		NVIC_Register_t->ISER[REG_ONE]=(1<<offset);
	}
	else if(Check==REG_TWO)
	{
		offset=Interrupt_Number%DIVIDER_VALUE;
		NVIC_Register_t->ISER[REG_TWO]=(1<<offset);
	}
	else if(Check==REG_THREE)
	{
		offset=Interrupt_Number%DIVIDER_VALUE;
		NVIC_Register_t->ISER[REG_THREE]=(1<<offset);
	}
	else
	{
		errorStatus=NOK;
	}
	return errorStatus;
}

/*Disable function */
u8 NVIC_uint8disableInterrupt(u8 Interrupt_Number)
{
	u8 errorStatus=OK;
	u8 Check,offset;
	Check = Interrupt_Number/DIVIDER_VALUE;

	if(Check==REG_ONE)
	{
		offset=Interrupt_Number%DIVIDER_VALUE;
		NVIC_Register_t->ICER[REG_ONE]=(1<<offset);
	}
	else if(Check==REG_TWO)
	{
		offset=Interrupt_Number%DIVIDER_VALUE;
		NVIC_Register_t->ICER[REG_TWO]=(1<<offset);
	}
	else if(Check==REG_THREE)
	{
		offset=Interrupt_Number%DIVIDER_VALUE;
		NVIC_Register_t->ICER[REG_THREE]=(1<<offset);
	}
	else
	{
		errorStatus=NOK;
	}
	return errorStatus;
}

/*to set the pending flag*/
u8 NVIC_uint8setPending(u8 Interrupt_Number)
{
	u8 errorStatus=OK;
	if(Interrupt_Number/DIVIDER_VALUE <= NUM_REG)
	{
		NVIC_Register_t->ISPR[Interrupt_Number/DIVIDER_VALUE]=(1<<Interrupt_Number%DIVIDER_VALUE);
	}
	else
	{
		errorStatus=NOK;
	}

	return errorStatus;
}

/*to reset the pending flag*/
u8 NVIC_uint8clearPending(u8 Interrupt_Number)
{
	u8 errorStatus=OK;
	if(Interrupt_Number/DIVIDER_VALUE <= NUM_REG)
	{
		NVIC_Register_t->ICPR[Interrupt_Number/DIVIDER_VALUE]=(1<<Interrupt_Number%DIVIDER_VALUE);
	}
	else
	{
		errorStatus=NOK;
	}

	return  errorStatus;
}

/*to get the Active bit*/
u8 NVIC_uint8getActive(u8 Interrupt_Number , u8 *value)
{
	u8 errorStatus=OK;
	if(Interrupt_Number/DIVIDER_VALUE <= NUM_REG)
	{
		(*value)=(NVIC_Register_t->IABR[Interrupt_Number/DIVIDER_VALUE]>>Interrupt_Number%DIVIDER_VALUE)&0x01;
	}
	else
	{
		errorStatus=NOK;
	}

	return errorStatus;
}

/*to get the pending flag*/
u8 NVIC_uint8getPending(u8 Interrupt_Number ,u8 *value)
{
	u8 errorStatus=OK;
	if(Interrupt_Number/DIVIDER_VALUE <= NUM_REG)
	{
		(*value)=(NVIC_Register_t->ISPR[Interrupt_Number/DIVIDER_VALUE]>>Interrupt_Number%DIVIDER_VALUE)&0x01;
	}
	else
	{
		errorStatus=NOK;}

	return errorStatus;
}

/*to set the Priority Group*/
u8 NVIC_uint8setPriorityGroup(u32 Priority)
{
	u8 Local_Error=OK;
	if (Priority == PREEMPTION_ONLY || Priority == THREE_PREEMPTION_ONE_SUBGROUP || Priority == TWO_PREEMPTION_TWO_SUBGROUP || Priority == ONE_PREEMPTION_THREE_SUBGROUP || Priority == SUBGROUP_ONLY)
	{
		SCB_AIRCR=Priority|PASSWORD_MASK;
	}
	else
	{
		Local_Error=NOK;
	}
	return Local_Error;
}

/*to set the Priority of any Interrupt*/
u8 NVIC_uint8setPriority(u8 Interrupt_Number , u8 Priority)
{
	u8 Local_Error=OK;
	if(Interrupt_Number/DIVIDER_VALUE <= NUM_REG)
	{
		if(Priority<16)
		{
			NVIC_Register_t->IPR[Interrupt_Number] = Priority<<4;
		}
		else
		{
			Local_Error=NOK;
		}
	}
	else
	{
		Local_Error=NOK;
	}
	return Local_Error;
}

/*to get the Priority of any Interrupt*/
u8 NVIC_uint8getPriority(u8 Interrupt_Number , u8 *Priority)
{
	u8 Local_Error=OK;
	if(Interrupt_Number/DIVIDER_VALUE <= NUM_REG)
	{

		*Priority=(NVIC_Register_t->IPR[Interrupt_Number] >>4);
	}
	else
	{
		Local_Error=NOK;
	}
	return Local_Error;
}

/*special registers*/

/*Disables Peripheral Interrupts (GIE = 0)*/
void NVIC_voiddisablePeripheralInterrupt(void)
{
	asm("MOV r0, #1 ");
	asm("MSR PRIMASK, r0");

	return;
}

/*Enable Peripheral Interrupts*/
void NVIC_voidenablePeripheralInterrupt(void)
{
	asm("MOV r0, #0 ");
	asm("MSR PRIMASK, r0");

	return;
}

/*Disable fault interrupts*/
void NVIC_voiddisbaleFaultInterrupt(void)
{
	asm("MOV r0, #1 ");
	asm("MSR FAULTMASK, r0");

	return;
}

/*to enable any all fault interrupt*/
void NVIC_voidenableFaultInterrupt(void)
{
	asm("MOV r0, #0 ");
	asm("MSR FAULTMASK, r0");

	return;
}

/*Description: Disables Interrupts with lower priority (Higher Written Value)*/
/*still has a problem so it will be available as soon as possible*/
/*void NVIC_uint8setPioritybase(u32 Copy_PriorityIndex) {

	BaseValue = Copy_PriorityIndex ;
	__asm volatile
	(
			"LDR  r3,BaseValue   \n"
			"MOV r2 , r3       \n"
			"MSR BASEPRI, r2     \n"
	);
	//asm("LDR  r3,BaseValue");
	//asm("MOV r1,r3");
	//asm("MSR BASEPRI, r1");
	return;
}*/






