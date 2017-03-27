/***************************************************************************/
/*                                                                         */
/*    A program to generate a sine wave using the DAC module               */
/*                                                                         */
/***************************************************************************/


/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include <math.h>
#include <stdio.h>
#define PI 3.141592

/**  Main Function  ********************************************************/

void main()
{
  unsigned char values[1000];
	unsigned char y;
  float x;
  float step;
	int n = 0;
  step = 0.01;
	
	//making sin function lookup table
	for (n =0;n < 1000; n++){
		values[n] = (unsigned char)(sin(10*PI*x)*127.5+127.5);
		x+=step;
	}
	

	  
	
	
  while (TRUE)
  {
   
		n = 0;
		for(n = 0; n <1000; n++){
			P1 = values[n];
		}
      
  }
}
