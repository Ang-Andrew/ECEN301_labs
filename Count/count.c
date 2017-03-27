/***************************************************************************/
/*                                                                         */
/*    A simple program to set port values and output them                  */
/*                                                                         */
/***************************************************************************/


/***  Include Files and global variables  **********************************/

#include <t89c51ac3.h>






/***  Pause program  *******************************************************/

void Delay()
{
  int c = 1, d = 1;
 
   for ( c = 1 ; c <= 100 ; c++ )
       for ( d = 1 ; d <= 1000 ; d++ )
       {}
}


/**  Main Function  ********************************************************/

void main()
{
  P1 = 0;
  while (TRUE)
  {
    P1_0 = TRUE;
		P1_1 = TRUE;
		P1_2 = TRUE;
		P1_3 = TRUE;
		P1_4 = FALSE;
		P1_5 = FALSE;
		P1_6 = FALSE;
		P1_7 = FALSE;
		Delay();
		P1_0 = FALSE;
		P1_1 = FALSE;
		P1_2 = FALSE;
		P1_3 = FALSE;
		P1_4 = TRUE;
		P1_5 = TRUE;
		P1_6 = TRUE;
		P1_7 = TRUE;
		Delay();
  }
}

