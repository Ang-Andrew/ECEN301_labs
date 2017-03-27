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
int output;
int counter;
float average = 0;
float temp;
float samples[5];
float summer;
float x;
int i;

/**  Main Function  ********************************************************/

float averaging(float values[])
{
	summer = 0;
	
	//getting the total within the array
	for(i = 0; i < 5; ++i)
			{
				summer = summer + values[i];
			}
	
			//finding the average
	x = summer/5.f;
	return x;
			
}

void main()
{
	initLCD();
	counter = 0;
	
	while(1)
	{
		clearLCD();
		
		//getting output value
		output = sampleADC();
		
		//converting output value to temp
		temp = -0.1103*output+111.88;
		
		//putting into samples array for averaging later
		samples[counter] = temp; 
		
		//displaying current temp on LCD
		sprintf(str,"temp = %.2f",temp);
		writeLineLCD(str);
		
		
		
		counter++;
		
		//average over 5 samples
		if(counter == 5){
			average = averaging(samples);
			
			//displaying average on LCD
			setLCDPos(16);
			sprintf(str,"Average = %.2f",average);
			writeLineLCD(str);
			
			
			counter = 0;
		}
		else{
			setLCDPos(16);
			sprintf(str,"Average = %.2f",average);
			writeLineLCD(str);
		}
		delaya(10000);
		
	}
}

