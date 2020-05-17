#include "STD_TYPES.h"

#include "flashdriver.h"

/*******************global values******************/
static uint_16t written_value;
static uint_32t erased_value;

typedef struct
{
	uint_32t FLASH_ACR;
	uint_32t FLASH_KEYR;
	uint_32t FLASH_OPTKEYA;
	uint_32t FLASH_SR;
	uint_32t FLASH_CR;
	uint_32t FLASH_AR;
	uint_32t RESERVED;
	uint_32t FLASH_OBR;
	uint_32t FLASH_WRPR;
}flash_t;

/***********locksequencence***************/
#define KEY1_LOCK 0x45670123
#define KEY2_LOCK 0xCDEF89AB

/*************flash cr lock***********/
#define FLASH_CR_LOCK   0x00000080
#define FLASH ((volatile flash_t*)(0x40022000))

/*************erased value************/
#define ERASE_FOUR_BYTE 0xFFFFFFFF

/***************bit to make program process*****/
#define PROGRAM_PG      0x00000001
/***************bit to make erase 1K***************/
#define ERASE_PER       0x00000002

/***************bit to make erase flash***************/
#define ERASE_MER       0x00000004

/*********************busyflag*****************/
#define BUSY_FLAG       0x00000001

/*****************start bit of erase***********/
#define ERASE_START     0x00000040

/****************sector size*******************/
#define SECTOR_SIZE     1024

uint_8t flash_Erase(uint_32t pageAddress)
{
	uint_8t Local_Error=OK;

	/*first check if flash locked or not */
	if(FLASH->FLASH_CR &FLASH_CR_LOCK)
	{
		Local_Error=lock_Error;
	}
	else
	{
		FLASH->FLASH_CR |= ERASE_PER;
		FLASH->FLASH_AR=pageAddress;
		FLASH->FLASH_CR |=ERASE_START;

		/*we will looping until busyflag cleared*/
		while(FLASH->FLASH_SR & BUSY_FLAG);
		erased_value= *((volatile uint_32t*)pageAddress);
		FLASH->FLASH_CR &= ~(ERASE_PER);
	}
	return Local_Error;
}
uint_8t flash_MassErase(void)
{
	uint_8t Local_Error=OK;

	/*first check if flash locked or not */
	if(FLASH->FLASH_CR &FLASH_CR_LOCK)
	{
		Local_Error=lock_Error;
	}
	else
	{
		FLASH->FLASH_CR |= ERASE_MER;
		FLASH->FLASH_CR |=ERASE_START;
	}
	return Local_Error;
}
uint_8t flash_WriteHalfWord(uint_32t pageAddress , uint_16t data)
{
	uint_8t Local_Error=OK;

	/*first check if flash locked or not */
	if(FLASH->FLASH_CR &FLASH_CR_LOCK)
	{
		Local_Error=lock_Error;
	}
	else
	{
		/*first check if we make erased or not*/
		if(*((volatile uint_32t*)pageAddress)==ERASE_FOUR_BYTE)
		{
			FLASH->FLASH_CR|=PROGRAM_PG;
			*((volatile uint_16t*)pageAddress) = data;

			/*we will looping until busyflag cleared*/
			while(FLASH->FLASH_SR & BUSY_FLAG);
			written_value=*((volatile uint_16t*)pageAddress);

			/*must make clear after finish*/
			FLASH->FLASH_CR &= ~(PROGRAM_PG);
		}
		else
		{
			Local_Error=erase_Error;
		}
	}
	return Local_Error;
}

uint_8t flash_WriteProgram(void * sourceAddress , void *DestinationAddress , uint_16t NumberofBytes)
{
	uint_8t Local_Error=OK;
	uint_8t counter=0;
	uint_8t flashcounter;
	uint_16t programCount;

	/*first check if flash locked or not */
	if(FLASH->FLASH_CR &FLASH_CR_LOCK)
	{
		Local_Error=lock_Error;
	}
	else
	{
		if ((sourceAddress==NULL)||(DestinationAddress==NULL))
		{
			Local_Error=NULLPOINTER;
		}
		else
		{
			/*we will check the size of program to make erasing*/
			if(NumberofBytes>1024)
			{
				counter=NumberofBytes/SECTOR_SIZE;
				if((NumberofBytes%SECTOR_SIZE)==1)
				{
					counter++;
				}
				for(flashcounter=0; flashcounter<counter; flashcounter++)
				{
					Local_Error|= flash_Erase((uint_32t )DestinationAddress);
					DestinationAddress+=1024;
				}
			}
			else
			{
				Local_Error|=flash_Erase((uint_32t )DestinationAddress);
			}

			/*to start the flashing*/
			FLASH->FLASH_CR|=PROGRAM_PG;

			/*we will flash every two bytes together*/
			for(programCount = 0; programCount < NumberofBytes/2 ;programCount++)
			{
				*((uint_16t *)DestinationAddress+programCount) = *((uint_16t *)sourceAddress+programCount);
				while(FLASH->FLASH_SR & BUSY_FLAG);
			}

			/*must make clear after finish*/
			FLASH->FLASH_CR &= ~(PROGRAM_PG);
		}

	}
	return Local_Error;
}
void flash_Lock(void)
{
	/*to lock the registers of flash driver*/
	FLASH->FLASH_CR|=FLASH_CR_LOCK;
}
void Flash_Unlock(void)
{
	/*to unlock the registers of flash*/
	FLASH->FLASH_KEYR=KEY1_LOCK;
	FLASH->FLASH_KEYR=KEY2_LOCK;
}
