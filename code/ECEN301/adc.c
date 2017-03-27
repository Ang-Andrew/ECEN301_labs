/***************************************************************************/
/*                                                                         */
/*    A simple program to set port values and output them                  */
/*                                                                         */
/***************************************************************************/


/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include <string.h>
#include "..\lib\phys340libkeil.h"

const char BlankString[] = "                               ";


/***  Function to sample an analog voltage  ********************************/

unsigned char Sample_ADC()
{
  static unsigned char Sample;
  ADCON = ;
  while ((ADCON & 0x10) != 0x10)
    /* Do Nothing */;
  Sample = ;                    
  return Sample;
}

/**  Main Function  ********************************************************/

void main()
{


}

