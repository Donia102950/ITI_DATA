/********************************************************************************************************************************************************/
/*8bit and 10bit will effect in the resolution*/
#define Mode   EIGHTBITMODE

/*chain struct calling when make new chain
 * APP : chain_t chaint={chainarr,3}*/
typedef struct
{
	u8 *channelArr;
	u8  Chainlength;
}chain_t;


/****************************************************prototypes*************************************************************/
void ADC_VoidInit (void);
u8 ADC_u8GetChannelReadingAsynchronous(u8 Copy_u8Channel , u16 *Copy_Pu16Result, void ((*Copy_PuCallBackNotification)(void)) );
u8 ADC_u8GetChannelReadingSynchronous(u8 Channel , u16 *Copy_u16ADCResult);


/*chain prototype
 * copy_chain: object of structure chain_t empty*/
u8 ADC_u8ChainInit(chain_t *Copy_Chain,u8 *Copy_pu8ChannelArr, u8 ChainLength);
u8 ADC_u8StartChainConversion(chain_t copy_chain, u16*Copy_pu16Result, void ((*Copy_PuCallBackNotification)(void)));

/******************************************************************************************************************************************************/

