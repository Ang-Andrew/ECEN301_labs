/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include <string.h>
#include <phys340libkeil.h>
#include <stdio.h>

int holes = 0;
char str[15];
int flag = 0;
float time = 0;
int overflow = 0;
unsigned int hi8,lo8,prev,curr,count;
int rpm;

/***  Intialise external interrupt  ********************************/

void initialise()
{
  //PWM~~~~~~~~~~~~
	//setting CR bit to turn PCA counter on, using the CCOM register
	//CCON = 0x40;
	//setting module 0 to be a PWM output, using CCAPM0 register
	//enabling the compare mode ECOM0
	CCAPM0 = 0x42;
	CMOD = 0x01;
	
	//LDR~~~~~~~~~~~~
	//Enabling all interrupt bit pg 115
	EA = 1;
	EC = 1;
	//enabling external interrupt 0 pg 115
	EX0 = 1;
	//specifying the interrupt is to be edge triggered pg 70
	IT0 = 1;
	
	//PCA~~~~~~~~~~~~
	//Capture mode and enable CCFx interrupt bit 
	CCAPM1 = 0x21;
	//PCA Counter On
	CCON = 0x40; 
	CF=0;
	flag = 0;
	
}

void LDRinterrupt(void) interrupt 0 //address of external interrupt 0 LDR
{
	if(!flag){
		flag = 1;
		
	}	
}

void PCAinterrupt(void) interrupt 6
{
	EA = 0;
	EC = 0;
	if(flag)
	{
		if(CF)
		{
			CF=0;
			overflow++;
			time = overflow/15.26;
			if(time >= 5)
				{
					flag = 0;
					overflow = 0;
					holes = 0; 
				}
		}
		if(CCF1) 
			{
				holes++; //increment # of holes each time and print it out
				hi8 = (unsigned int)(CCAP1H<<8);
				lo8 =  (unsigned int)(CCAP1L);
				prev = curr;	
				curr = hi8 + lo8 +  ((unsigned int)(65536*overflow)); 
				count = curr-prev;
				rpm = 300000/count;
				CCF1 = 0;
			}
	}
	CF = 0;
	CCF1 = 0;
	EA = 1;
	EC = 1;

}

/**  Main Function  ********************************************************/

void main()
{
	initLCD();
	initialise();
	while(1)
	{
		clearLCD();
		if(flag)
		{
			//turn on LED and motor
			P2 = 0x01;
			EA = 0;
			CCAP0H = 0x7F;
			sprintf(str,"t=%.1f",time);
			writeLineLCD(str);
			setLCDPos(8);
			sprintf(str,"h=%i",holes); 
			writeLineLCD(str);
			setLCDPos(16);
			sprintf(str,"RPM=%i",rpm);
			writeLineLCD(str);
			delaya(1000);
			EA = 1;

			//writeCharLCD('t');
			//sprintf(str,"RPM=%i",overflow);
			//writeLineLCD(str);
//			sprintf(str,"%i",time);
//			setLCDPos(16);
//			writeLineLCD(str);
		}
		else
		{
			P2 = 0x00;
			CCAP0H = 0xFF;
			writeCharLCD('f');
		}
		
	}
}
