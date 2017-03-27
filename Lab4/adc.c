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
int output;
int counter;
float average;
float Vt;
float Rt;
float samples[5];
float summer;
int i;

/**  Main Function  ********************************************************/

void main()
{
	initLCD();
	counter = 0;
	
	while(1)
	{
		clearLCD();
		
		//calculating Rt
		output = sampleADC();
		Vt = output*0.0023;
		Rt = (1000/(3-Vt))*Vt;
		
		//putting into samples
		samples[counter] = Rt; 
		
		//displaying on LCD
		sprintf(str,"Resistance = %i",Rt);
		writeLineLCD(str);
		
		//average over 5 samples
		if(counter == 4){
			summer = 0;
			
			//summing
			for(i = 0; i < 5; i++)
			{
				summer = summer + samples[i];
			}
			
			//averaging
			average = summer/5;
			
			//displaying on LCD
			setLCDPos(0x40);
			sprintf(str,"Average = %i",average);
			writeLineLCD(str);
			
			//reset counter
			counter = 0;
			
			//reset LCD position
			setLCDPos(0x00);
		}
		delaya(10000);
	}
}

