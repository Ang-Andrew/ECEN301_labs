/***************************************************************************/
/*                                                                         */
/*    A program to generate a sine wave using the DAC module               */
/*                                                                         */
/***************************************************************************/


/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include <math.h>

#define PI 3.141592

/**  Main Function  ********************************************************/

void main()
{
  float y;
  float x, step;
  float z;

  //angle = 0.0;
  step = 0.01;
	
  while (TRUE)
  {
   
	 y = sin(10*x);
	 P1 = (unsigned char)(y*127.5+127.5);
	 x += step;
      
  }
}
