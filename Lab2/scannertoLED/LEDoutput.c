/***************************************************************************/
/*                                                                         */
/*    A simple program to read the keypad                                  */
/*                                                                         */
/***************************************************************************/


/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include "..\lib\phys340libkeil.h"



/**  Main Function  ********************************************************/
void main()
{
  unsigned char DepressedKey;
	DepressedKey = sampleKeypad;
  
	while (TRUE)
  {
    if(P2_4 == FALSE) P1 = 0x01;
		
		
  }
}