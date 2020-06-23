/*To print ascii of extended keys and program ended when user press ESC button*/

/***************************includes*******************************************/
#include<stdio.h>
#include<conio.h>
/******************************************************************************/
void main(void)
{
	char byte1,byte2;
	clrscr();
	do
	{
		printf("enter the char\n");
		byte1=getch();
		/*In case extended Key*/
		if(byte1==0)
		{
			byte2=getch();
			printf("The ascii of this code is %d\n ",byte2);
		}
		/*In case ESC key*/
		else if(byte1==27)
		{
			break;
		}
		/*In case not extended Key*/
		else
			printf("It is not extended\n");
		flushall();
	}while(1);
}