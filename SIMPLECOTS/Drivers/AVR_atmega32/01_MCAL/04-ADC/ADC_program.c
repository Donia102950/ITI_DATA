/******************************************************************includes*****************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "ADC_interface.h"

/***************************************************************registers*******************************************************************/
#define ADMUX  	*((volatile u8*)0x27)
#define ADCSRA  *((volatile u8*)0x26)
#define ADCH  	*((volatile u8*)0x25)
#define ADCL  	*((volatile u8*)0x24)

/*when we need to read 10 bit so we make u16 pointer to get two register high and low*/
#define ADREAD  *((volatile u16*)0x24)

/*ADC TIMEOUT FLAG*/
#define ADC_u32_TIMEOUTCOUNTS  40000UL

/*To check if conversion from ADC_CHAIN or single conversion*/
#define ADC_CHAIN_STATE 0
#define ADC_SINGLE_ASYNCHRONOUS_STATE  1

/**************************************resolution*******************************************************************************************/
#define EIGHTBITMODE  0
#define TENBITMODE    1
/*ADC state*/
#define ADC_IDLE 0
#define ADC_BUSY 1

/*global Variables to used them in ASynchronous Function because we need ISR and ADCASYNC to be able to access these two variables*/
static u16*ADC_pu16Result=NULL;                                   /*the digital result*/
static void(*ADC_puCallBackNotification)(void)=NULL;              /*the ISR function*/

/*to check if adc enable to start another conversion*/
static u8 ADC_u8State=ADC_IDLE;

/******************************************chain configuration**********************************************************************/
/*channels counter in chain*/
static u8 ADC_u8Channel=0;
/*length of the chain*/
static u8 ADC_u8ChainLength;
/*channel array */
static u8 *ADC_u8ChannelArr;
/*to check if ISR used to single asynchronous or for chain*/
static u8 ADC_u8ISRState;

/***********************************************finctions implementation*************************************************************/

/*init ADC function*/
void ADC_VoidInit (void)
{
	/* ADC enable */
	SET_BIT(ADCSRA,7);

	/*AVCC reference voltage in imt kit it connected to 5 v direct*/
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

	/* Activate left adjust mode */
#if Mode==EIGHTBITMODE
	SET_BIT(ADMUX,5);
	/* Deactivate left adjust mode */
#elif Mode==TENBITMODE
	CLR_BIT(ADMUX,5);
#endif
	/*presacller division by 128 to get the ADC in effected range 50KHZ to 200KHZ*/
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
}

/**************Reading digital value synchronous************************/
u8 ADC_u8GetChannelReadingSynchronous(u8 Channel , u16*Copy_u16ADCResult)
{
	u32 Local_u32TimeOutCounter=0;
	u8 Local_u8ErrorStatus=ERROR_OK;

	/********make sure if channel numbers within range*******/
	if(Channel>31 && Copy_u16ADCResult == NULL)
	{
		Local_u8ErrorStatus=ERROR_NOK;
	}

	/*Set the channel in ADMUX*/
	/*clear ADMUX*/
	ADMUX &=0b11100000;
	ADMUX |= Channel;

	/*Start Conversion*/
	SET_BIT(ADCSRA,6);

	/*Polling on the conversion complete flag or TIMEOUT finished*/
	while(((GET_BIT(ADCSRA,4))==0) && (Local_u32TimeOutCounter<ADC_u32_TIMEOUTCOUNTS))
	{
		Local_u32TimeOutCounter++;
	}

	/*check the reason of the conversion ended*/
	if(Local_u32TimeOutCounter == ADC_u32_TIMEOUTCOUNTS)
	{
		/*loop has been broken because timeout*/
		Local_u8ErrorStatus=ERROR_NOK;

	}
	else
	{
		/*loop has been broken because conversion flag is raised */

		/*Clear the Flag */
		SET_BIT(ADCSRA,4);

		/*get the result*/
#if Mode==EIGHTBITMODE
		*Copy_u16ADCResult=ADCH;
#elif Mode==TENBITMODE
		*Copy_u16ADCResult=ADREAD;
#endif
	}

	return Local_u8ErrorStatus;
}

/************************************Conversion using ADC Asynchronous process***********************************************/
u8 ADC_u8GetChannelReadingAsynchronous(u8 Copy_u8Channel , u16 *Copy_Pu16Result, void ((*Copy_PuCallBackNotification)(void)) )
{
	u8 Local_u8ErrorStatus=ERROR_OK;
	if(Copy_u8Channel>31 || Copy_Pu16Result == NULL || Copy_PuCallBackNotification == NULL)
	{
		Local_u8ErrorStatus =ERROR_NOK;
	}
	else
	{
		/*ADC is busy so we cannot able to make another conversion*/
		if(ADC_u8State==ADC_BUSY)
		{
			Local_u8ErrorStatus=ERROR_BUSY;
		}

		/*ADC is ideal*/
		else
		{
			/*make ADC is busy when start conversion and when ISR fired this means that ADC finished so ISR will change the state to ideal*/
			ADC_u8State=ADC_BUSY;

			/*to change ISR state*/
			ADC_u8ISRState=ADC_SINGLE_ASYNCHRONOUS_STATE;

			/*initialize the required objects*/
			ADC_pu16Result=Copy_Pu16Result;
			ADC_puCallBackNotification=Copy_PuCallBackNotification;   /*function has been passed from APPLICATION*/

			/*Set the required Channel*/
			/*clear*/
			ADMUX&=0b11100000;
			/*choose the channel*/
			ADMUX|=Copy_u8Channel;

			/*Start Conversion*/
			SET_BIT(ADCSRA,6);

			/*ADC conversion Complete Interrupt Enable*/
			SET_BIT(ADCSRA,3);

			/*to check there is no another ISR during this conversion to avoid overwrite in ADC register*/
		}
	}
	return Local_u8ErrorStatus;
}

/*ADC chain conversion on different channels
 * ADC_u8ChainInit:to initialize the struct */
u8 ADC_u8ChainInit(chain_t *Copy_Chain,u8 *Copy_pu8ChannelArr, u8 ChainLength)
{
	u8 Local_u8ErrorState=ERROR_OK;
	/*check null pointer*/
	if(Copy_pu8ChannelArr==NULL)
	{
		Local_u8ErrorState=ERROR_NOK;
	}
	else
	{
		/*fill the chain with the required data*/
		Copy_Chain->channelArr=Copy_pu8ChannelArr;
		Copy_Chain->Chainlength=ChainLength;
	}
	return Local_u8ErrorState;
}

/*chain conversion function using passing from value because no change it is used only for reading*/
u8 ADC_u8StartChainConversion(chain_t copy_chain, u16*Copy_pu16Result, void ((*Copy_PuCallBackNotification)(void)))
{
	u8 Local_u8ErrorState=ERROR_OK;
	if(copy_chain.channelArr==NULL ||Copy_pu16Result==NULL || Copy_PuCallBackNotification==NULL )
	{
		Local_u8ErrorState=ERROR_NOK;
	}
	else
	{
		/*to loop on all channels*/
		/*check first ADC state */
		if(ADC_u8State==ADC_BUSY)
		{
			Local_u8ErrorState=ERROR_BUSY;
		}

		/*ADC is ideal*/
		else{
			/*initialize the required objects*/
			ADC_u8State=ADC_BUSY;
			ADC_pu16Result=Copy_pu16Result;
			ADC_puCallBackNotification=Copy_PuCallBackNotification;
			ADC_u8ChainLength=copy_chain.Chainlength;
			ADC_u8ChannelArr=copy_chain.channelArr;
			ADC_u8ISRState=ADC_CHAIN_STATE;
			ADC_u8Channel=0;

			/*set the first channel */
			/*clear*/
			ADMUX&=0b11100000;
			/*choose the channel so if we have many channels 0 become index and will increment it*/
			ADMUX|=copy_chain.channelArr[0];

			/*Start Conversion*/
			SET_BIT(ADCSRA,6);


			/*ADC conversion Complete Interrupt Enable*/
			SET_BIT(ADCSRA,3);

		}
	}
	return Local_u8ErrorState;
}
/*ADC conversion complete ISR*/
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	/*check the mode */
	if(ADC_u8ISRState==ADC_CHAIN_STATE)
	{
#if Mode==EIGHTBITMODE
		/*get result*/
		ADC_pu16Result[ADC_u8Channel]=ADCH;
#elif Mode==TENBITMODE
		ADC_pu16Result[ADC_u8Channel]=ADREAD;
#endif

		/*increment the index*/
		ADC_u8Channel++;

		/*check the counter*/
		if(ADC_u8Channel==ADC_u8ChainLength)
		{
			/*make adc in ideal state*/
			ADC_u8State=ADC_IDLE;

			/*disable the interrupt*/
			CLR_BIT(ADCSRA,3);

			/*INVOKE the call back notification function*/
			ADC_puCallBackNotification();

		}
		else
		{
			/*set the required channel */
			/*clear*/
			ADMUX&=0b11100000;
			/*choose the channel so if we have many channels 0 become index and will increment it*/
			ADMUX|=ADC_u8ChannelArr[ADC_u8Channel];

			/*start conversion*/
			SET_BIT(ADCSRA,6);



		}
	}
	else if(ADC_u8ISRState==ADC_SINGLE_ASYNCHRONOUS_STATE)
	{

#if Mode==EIGHTBITMODE
		*ADC_pu16Result=ADCH;
#elif Mode==TENBITMODE
		*ADC_pu16Result=ADREAD;
#endif

		/*make ADC state to ideal*/
		ADC_u8State=ADC_IDLE;
		/*disable the interrupt*/
		CLR_BIT(ADCSRA,3);
		/*INVOKE the call back notification function*/
		ADC_puCallBackNotification();
	}
	else
	{
	    /*do nothing*/
	}

}
