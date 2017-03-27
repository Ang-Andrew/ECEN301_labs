/***************************************************************************/
/*                                                                         */
/*    A simple program to set port values and output them                  */
/*                                                                         */
/***************************************************************************/


/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include <string.h>
#include <phys340libkeil.h>
#include <stdio.h>

const char BlankString[] = "                               ";
char str[15];
int value;


/***  Function to sample an analog voltage  ********************************/

unsigned char Sample_ADC()
{
  //Using standard
	
	static unsigned char Sample;
  
	//~~configure P1.0 in ADC channels~~
	//configure for channel to .0
	ADCF = 0x01;
	
	//Enable the ADC
	ADCON = 0x20;
  
	//~~Start a standard conversion~~
	//clear the field SCH[2:0]
	ADCON &= 0xF8;
	
	//Select Channel
	ADCON |= 0x00;
	
	//Start convCCersion in standard mode
	ADCON |= 0x08;
	
	//Wait flag end of conversion
	while ((ADCON & 0x10) != 0x10){}
    /* Do Nothing */;
	
	//Clear the end of conversion flag
	ADCON &= 0xEF;
	
  Sample = (ADDH<<2)+(ADDL);                    
  return Sample;
}

/**  Main Function  ********************************************************/

void main()
{
	initLCD();
	while(1)
	{
		clearLCD();
		//value = sample_ADC();
		//BlankString = Sample_ADC()
		//sprintf(str,"Voltage = %i",BlankSt
		value = sample_ADC();
		sprintf(str,"Voltage = %i",value);
		writeLineLCD(str);
		delaya(1000);
	}
}

