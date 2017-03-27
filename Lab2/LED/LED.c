/***************************************************************************/
/*                                                                         */
/*    A simple program to read the keypad                                  */
/*                                                                         */
/***************************************************************************/


/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include "..\lib\phys340libkeil.h"

void delay()
{
  int c = 1, d = 1;
 
   for ( c = 1 ; c <= 100 ; c++ )
       for ( d = 1 ; d <= 50 ; d++ )
       {}
}

/**  Main Function  ********************************************************/
void main()
{

	
	while (TRUE)
  {
		P2_0 = TRUE;
		P2_1 = TRUE;
		P2_3 = TRUE;
		
		
		//first row
		P2_0 = FALSE;
		if(!P2_4) P1 = 0x01;
		if(!P2_5) P1 = 0x03;
		if(!P2_6) P1 = 0x07;
		P2_0 = TRUE;
		delay();
		
		
		//second row
		P2_1 = FALSE;
		if(!P2_4) P1 = 0x0F;
		if(!P2_5) P1 = 0x1F;
		if(!P2_6) P1 = 0x3F;
		P2_1 = TRUE;
		delay();
		
		//third row
		P2_2 = FALSE;
		if(!P2_4) P1 = 0x7F;
		if(!P2_5) P1 = 0xFF;
		if(!P2_6) P1 = 0xEE;
		P2_2 = TRUE;
		delay();
		
		//fourth row
		P2_3 = FALSE;
		if(!P2_4) P1 = 0xF1;
		if(!P2_5) P1 = 0x00;
		if(!P2_6) P1 = 0x2a;
		P2_3 = TRUE;
		delay();
		
		
  }
}