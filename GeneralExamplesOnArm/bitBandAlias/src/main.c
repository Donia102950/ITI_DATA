/***************************************data type typedef**************************************************************/
typedef unsigned long int uint_32t;

/***************************************Trial RCC registers************************************************************/
#define BASE_ADDRESS 0X40021000
typedef struct
{
	uint_32t RCC_CR;
	uint_32t RCC_CFGR;
	uint_32t RCC_CIR;
	uint_32t RCC_APB2RSTR;
	uint_32t RCC_APB1RSTR;
	uint_32t RCC_AHBENR;
	uint_32t RCC_APB2ENR;
	uint_32t RCC_APB1ENR;
	uint_32t RCC_BDCR;
	uint_32t RCC_CSR ;

}RCC_t;

#define RCC_type ((volatile RCC_t *)(BASE_ADDRESS))

/******************************************Equation to get the bitband alias from Cortex M3 Guide ***********************/
#define BITBAND(addr,bitnum) ((addr & 0xF0000000)+0x2000000+((addr & 0xFFFFF)<<5)+(bitnum <<2))

int main(void)
{
	volatile uint_32t *aliasAddress;
	aliasAddress = (uint_32t *)BITBAND((uint_32t)&RCC_type->RCC_APB2ENR , 3);
	/*changing bit to 1 by one instruction direct*/
	*aliasAddress = 1;
	/*changing bit to 0 by one instruction direct*/
	*aliasAddress = 0;
	/*changing bit to 1 by one instruction direct*/
	*aliasAddress = 1;

	return 0;
}
