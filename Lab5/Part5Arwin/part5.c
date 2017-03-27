/***********************************************************************************/ 
/*ECEN301 Lab 5 and 6; Part 4: Capture Interrupts
/* Arwin Sinnathambi
/***********************************************************************************/


#include <t89c51ac3.h>
#include <string.h>
#include <phys340libkeil.h>
#include <stdio.h>

char outputText [33];
int rpm;
int count=0;
unsigned int hi,lo,prev,curr,period;
int f; //Flag counter
int rpm;
void MyIntHandler(void) interrupt 6
{
	EA=0;
	EC=0;
	
if(CCF0 == 1){	
		if(CF ==1){
		CF=0;
			f++;
		
		}
		
		hi = (unsigned int)(CCAP0H<<8);
		lo =  (unsigned int)(CCAP0L);
		prev = curr;	
		
		curr = hi + lo +  ((unsigned int)(65536*f)); 
		
		count = curr-prev;
		rpm = 300000/count;
		
		
}
CCF0 = 0;
EA=1;
EC=1;
f=0;
}


void main(){
	EA=1;
	EC=1;

	CCAPM0 = 0x11; //Capture mode and enable CCFx interrupt bit
	//CMOD = 0x00;
	CCON = 0x40; //PCA Counter On
	CF=0;
	
	
	initLCD();
	
	
	while(1){
		clearLCD();
		sprintf(outputText, "RPM: %i",rpm);
		writeLineLCD(outputText);
		delaya(1000);
		}


}