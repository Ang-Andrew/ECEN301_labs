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


char str[15];
char test[15];
int output;
int counter;
float average;
float Vt;
float Rt;
float samples[5];
float summer;
float temp;
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
		if(output <= 818 || output >= 797){
			temp = -0.1863*(float)output + 173.39;
		}
		//Vt = output*0.0023;
		//Rt = (1000/(3-Vt))*Vt;
		
		//putting into samples
		samples[counter] = output; 
		
		//displaying  output on LCD
		//sprintf(str,"Output = %i",output);
		//writeLineLCD(str);
		sprintf(str,"temp = %f",temp);
		writeLineLCD(str);
		
		//displaying output on LCD
		setLCDPos(16);
		sprintf(test,"average = %f",average);
		writeLineLCD(test);
		
		counter++;
		
		//average over 5 samples
		if(counter >= 4){
			summer = 0;
			
			//summing
			for(i = 0; i < 5; i++)
			{
				summer = summer + samples[i];
			}
			
			//averaging
			average = summer/4.f;
			
			
			
			//reset counter
			counter = 0;
			
			//reset LCD position
			//setLCDPos(0);
			
			
			
		}
		delaya(1000000);
		
	}
}

