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
  
	while (TRUE)
  {
    DepressedKey = sampleKeypad();
    P1 = DepressedKey;
		
  }
}