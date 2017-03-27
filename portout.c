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
  P2_0 = TRUE;
  P2_1 = FALSE;
  P2_2 = TRUE;
  P2_3 = FALSE;
  P2_4 = TRUE;
  P2_5 = FALSE;
  P2_6 = TRUE;
  P2_7 = FALSE; 
}


/**  Main Function  ********************************************************/

void main()
{
	P2 = 0;
 	while (TRUE)
	{	
 		//WriteToPort();
		P2 = 0x01;
	}	
}

