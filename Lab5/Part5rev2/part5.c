#include <t89c51ac3.h>
#include <string.h>
#include <phys340libkeil.h>
#include <stdio.h>


unsigned int currValue = 0;
unsigned int prevValue = 0;
int overflow = 0;
unsigned int hi,lo,prev,curr,period;
int count; 
int rpm;
char str[15];

//initialise interrupt method
void iniInterrupts()
{
	//Enabling all interrupt bit pg 115
	//EA = 1;
	//enabling PCA interrupt pg 115
	//EC = 1;
	
	//specifying the interrupt is to be edge triggered (falling edge active) pg 70
	//IT0 = 1;
	
	//intialising timer 0 as an 8 bit timer with auto reload pg 71
	//TMOD |= 0x02; //pg 71
	//turning on timer 0 
	//TR0 = 1; //pg 70
	
	//enabling timer0 overflow interrupt pg115
	//ET0 = 1;
	
	//enabling external interrupt EX0 pg115
	//EX0 = 1;
	
	//setting up PCA module 0 in capture mode
	//CCAPM0 = 0x11; //pg103
	//enabling counter overflow interrupt and using internal clock
	//CMOD = 0x00;  //pg100
	
	//turning PCA timer on
	//CCON = 0x40;
	//CR = 1; //pg101
	//CF = 0;
	// timer overflow speed
	//TH0 = 0;
	EA=1;
	EC=1;

	CCAPM0 = 0x11; //Capture mode and enable CCFx interrupt bit
	//CMOD = 0x00;
	CCON = 0x40; //PCA Counter On
	CF=0;
}

//interrupt method for timer
void timerInterrupt(void) interrupt 6 //PCA
{

EA=0;
EC=0;

	
if(CCF0 == 1){	
		if(CF ==1){
		CF=0;
			overflow++;
		
		}
		
		hi = CCAP0H;//<<8;
		lo = CCAP0L;
		prev = curr;	
		
		curr = hi + lo +  ((unsigned int)(65536*overflow)); 
		
		
		
		count = curr-prev;
		rpm = 300000/count;
		
		
}
CCF0 = 0;
EA=1;
EC=1;
overflow=0;
}

void main()
{
	initLCD();
	iniInterrupts();
	while(1)
	{

		clearLCD(); 
		sprintf(str,"RPM = %i",rpm);
		writeLineLCD(str);
		delaya(1000);
		
	}
}                                                         
	
