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

//unsigned char Sample_ADC()
//{
//  static unsigned char Sample;
//  ADCON = ;
//  while ((ADCON & 0x10) != 0x10)
//    /* Do Nothing */;
//  Sample = ;                    
//  return Sample;
//}

/**  Main Function  ********************************************************/

void main()
{
	initLCD();
	while(1)
	{
		clearLCD();
		value = sampleADC();
		sprintf(str,"Voltage = %i",value);
		writeLineLCD(str);
		delaya(1000);
	}
}

