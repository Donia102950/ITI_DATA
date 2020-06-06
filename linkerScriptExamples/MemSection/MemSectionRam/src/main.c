/*This project aim to set the variable in same address every time need to compile */


#include <stdio.h>

/*compiler instruction to force address doniaa to be in dx section*/
__attribute__ ((section(".dx"),used))uint8_t doniaa;
void
main(void)
{

	doniaa = 5 ;

	while (1)
	{

	}
}
