/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include <string.h>
#include <phys340libkeil.h>
#include <stdio.h>

int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
char str[15];

/**  Main Function  ********************************************************/

void iniInterrupts()
{
	//Enabling all interrupt bit pg 115
	EA = 1;
	//enabling PCA interrupt pg 115
	EC = 1;
	
	//intialising timer 0 as an 8 bit timer with auto reload pg 71
	TMOD |= 0x02; //pg 71
	//turning on timer 0 
	TR0 = 1; //pg 70
	
	//setting up PCA module 0
	CCAPM0 = 0x49; //pg103
	CCAP0H = 0;
	//CCAP0L = 0x15;
	//setting up PCA module 1
	CCAPM1 = 0x49; //pg103
	CCAP1H = 85;
	//CCAP1L = 0x15;
	//setting up PCA module 2
	CCAPM2 = 0x49; //pg103
	CCAP2H = 170;
	//CCAP2L = 0x15;
	
	//enabling counter overflow interrupt and set PCA EWC count pulse select to use timer 0 overflow
	CMOD = 0x05; //pg100
	
	//turning PCA timer on
	//CCON |= 0x40;
	CR = 1; //pg101
	
	// timer overflow speed
	TH0 = 0x7F;
}

//interrupt method
void MyIntHandler(void) interrupt 6 //PCA interrupt
{
	//writeLineLCD("yoooooo");
	EA = 0;
	
	//checking CCON register for interrupt flags, then clearing the interrupt flags pg101
	if(CCF0 == 1)
	{
		//writeLineLCD("test1");
		counter1++;
		CCF0 = 0;
	}
	if(CCF1 == 1)
	{
		//writeLineLCD("test2");
		counter2++;
		CCF1 = 0;
	}
	if(CCF2 == 1)
	{
		//writeLineLCD("test3");
		counter3++;
		CCF2 = 0;
	}
	if (CF)CF=0;
	EA = 1;
}

void main()
{
	iniInterrupts();
	while(1)
	{
		//EA = 0;
		clearLCD();
		sprintf(str,"%i,%i,%i",counter1,counter2,counter3);
		writeLineLCD(str);
//		setLCDPos(7);
//		sprintf(str,"%i",counter2);
//		writeLineLCD(str);
//		setLCDPos(16);
//		sprintf(str,"%i",counter3);
//		writeLineLCD(str);
		
		//EA = 1;
	}
	
}