/***************************************************************************/
/*                                                                         */
/*    A simple program to set port values and output them                  */
/*                                                                         */
/***************************************************************************/


/***  Include Files  *******************************************************/

#include <t89c51ac3.h>


/***  Set all bits of port 1  **********************************************/

void WriteToPort()
{
  P1_0 = TRUE;
  P1_1 = FALSE;
  P1_2 = TRUE;
  P1_3 = FALSE;
  P1_4 = TRUE;
  P1_5 = FALSE;
  P1_6 = TRUE;
  P1_7 = FALSE; 
}


/**  Main Function  ********************************************************/

void main()
{
	P1 = 0;
 	while (TRUE)
	{	
 		WriteToPort();
	}	
}

