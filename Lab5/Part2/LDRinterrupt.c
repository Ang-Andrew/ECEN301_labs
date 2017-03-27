/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include <string.h>
#include <phys340libkeil.h>
#include <stdio.h>

int counter = 0;
char str[15] = "              ";

/***  Intialise external interrupt  ********************************/

void interruptSetup()
{
	//Enabling all interrupt bit pg 115
	EA = 1;
	
	//enabling external interrupt 0 pg 115
	EX0 = 1;
	
	//specifying the interrupt is to be edge triggered pg 70
	IT0 = 1;
	
	//no need to to set the interrupt flag back to 0, hardware does it
	
}

void MyIntHandler(void) interrupt 0 //address of external interrupt 0
{
	counter++;	
}
/**  Main Function  ********************************************************/

void main()
{
	initLCD();
	interruptSetup();
	while(1)
	{
		clearLCD();
		sprintf(str,"counter = %i",counter);
		writeLineLCD(str);
		delaya(1000);
	}
}
