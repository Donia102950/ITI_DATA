#ifndef FLASHDRIVER_H_
#define FLASHDRIVER_H_

typedef enum{
	lock_Error,
	erase_Error,
}flashError;

/*to erase the sector  */
extern uint_8t flash_Erase(uint_32t pageAddress);

/*to erase the flash memory*/
extern uint_8t flash_MassErase(void);

/*to write 2bytes of data (page)*/
extern uint_8t flash_WriteHalfWord(uint_32t pageAddress , uint_16t data);

/******erase function done automatically in this function and write specific bytes***********/
extern uint_8t flash_WriteProgram(void * sourceAddress , void *DestinationAddress , uint_16t NumberofBytes);

/*to lock the flash*/
extern void flash_Lock(void);

/*to unlock the flash*/
extern void Flash_Unlock(void);


#endif
