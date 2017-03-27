#include <t89c51ac3.h>



/***  Pause program  *******************************************************/

void Delay()
{
  int c = 1, d = 1;
 
   for ( c = 1 ; c <= 100 ; c++ )
       for ( d = 1 ; d <= 1000 ; d++ )
       {}
}


//0,1,2, == lights on lane one from green,orange,red
//2_1 == sensor on lane one
//4,5,6 == lights on lane two from '' ' ' '' '
//2_2 == sensor on lane two

unsigned char ReadInput()
{
	static unsigned char Input;
	Input = P2;
	return Input;
}


void main()
{
	P1 = 0;
	P2 = 0;
	P1_0 = TRUE; //green
	P1_6 = TRUE; //red
	while(TRUE){
		P2 = ReadInput();
		if(P2_2 == TRUE && P1_0 == TRUE){
			P1_0 = FALSE;//green
			Delay();
			P1_1 = TRUE;
			Delay();
			P1_1 = FALSE;//orange
			Delay();
			P1_2 = TRUE;
			Delay();
			//P1_2 = FALSE;//red
			//Delay();
		}
		else if(P2_1 == TRUE && P1_4 == TRUE){
			P1_4 = FALSE;
			Delay();
			P1_5 = TRUE;
			Delay();
			P1_5 = FALSE;
			Delay();
			P1_6 = TRUE;
			Delay();
		}
	}

}