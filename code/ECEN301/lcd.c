/***************************************************************************/
/*                                                                         */
/*    Program to put info on LCD display                                   */
/*                                                                         */
/***************************************************************************/


/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include <phys340libkeil.h>
#include <string.h>
#include <stdio.h>

char outputText [33];
char str[15];
int n;
/**  Main Function  ********************************************************/

void main()
{
  // Initialise Display
	initLCD();
	
	//char a = 'a';
	//outputText[0] = 'a';
	//writeLineLCD(outputText);
	
	
	//outputText[0] = '1';
	//outputText[1] = 'h';
	
	//writeLineLCD(outputText);
	n = 0;
  while(1)
    {
      clearLCD();
			sprintf(str,"%d",n);
			writeLineLCD(str);
			delaya(10000);
			n++;
			
      
    }

	
}

