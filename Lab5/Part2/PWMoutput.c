/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include <string.h>
#include <phys340libkeil.h>
#include <stdio.h>

const char BlankString[] = "                               ";
char str[15];
int value;
int duty;


/***  Function to sample an analog voltage  ********************************/

unsigned char PWM()
{
  //setting CR bit to turn PCA counter on, using the CCOM register
	CCON |= 0x40;
	//setting module 0 to be a PWM output, using CCAPM0 register
	//enabling the compare mode ECOM0
	CCAPM0 |= 0x40;
	//enabling PWM mode PWM0
	CCAPM0 |=0x02;
}

/**  Main Function  ********************************************************/

void main()
{
//	duty = 10;
//	PWM();
//	while(1){
//		//setting PWM duty cycle using the CCAP0H register
//		CCAP0H = duty;
//		duty+=10;
//		if(duty > 255){
//			duty = 10;
//		}
//		
//		delaya(1000);		
//	}
	
PWM();
	while(1){
		
		CCAP0H = P0;
	}
}

