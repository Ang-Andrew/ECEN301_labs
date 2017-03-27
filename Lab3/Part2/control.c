/***************************************************************************/
/*                                                                         */
/*    Program to put info on LCD display                                   */
/*                                                                         */
/***************************************************************************/


/***  Include Files  *******************************************************/

#include <t89c51ac3.h>
#include <phys340libkeil.h>
#include <string.h>
#include <stdio.h>




//setting the control lines to bits 0 to 2 of port 4
	Sbit(EN,0xC0,2);//setting EN to bit 2
	Sbit(RW,0xC0,1); //setting RW to bit 1
	Sbit(RS,0xC0,0);//setting RS to bit 0
char str[15];
int n;

/**  Main Function  ********************************************************/

void my_init(){
	//***INITILIASING LCD***//
	
	P0 = 0;
	//clearing display
	RS = 0; 
	RW = 0; 
	P0 = 0x01; 
	EN = TRUE;
	delaya(1000);
	EN = FALSE;
	
	//function set
	P0 = 0;
	RS = 0;
	RW = 0;
//	P0_5 = 1; 
//	P0_4 = 1; //8bit interface data 
//	P0_3 = 0; //1-line display
//	P0_2= 0; //5x8 dot character font
	P0 = 0x38;
	EN = TRUE;
	delaya(1000);
	EN = FALSE;
	
	//display on/off control
	P0 = 0;
	RS = 0;
	RW = 0;
//	P0_3 = 1; 
//	P0_2 = 0; //display off
//	P0_1 = 0; //cursor off
//	P0_0 = 0; //blinking off
	P0 = 0x08;
	EN = TRUE;
	delaya(1000);
	EN = FALSE;
	
	//Entry mode set
	P0 = 0;
	RS = 0;
	RW = 0;
//	P0_2 = 1; 
//	P0_1 = 1; //increment by 1
//	P0_0 = 0; //no shift
	P0 = 0x06;
	EN = TRUE;
	delaya(1000);
	EN = FALSE; 
	
	P0 = 0x0c;
	EN = TRUE;
	delaya(1000);
	EN = FALSE; 
	//**End of initialisation**//
	
}

void main()
{
	
	
  my_init();
	//initLCD();
	n = 0;
  while(1)
    {
			clearLCD();
			sprintf(str,"%d",n);
			writeLineLCD(str);
			delaya(10000);
			n++;
		}
	
}

