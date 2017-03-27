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
	char str = 'a';
	string test;
	int n;
	unsigned char cursor;

/**  Main Function  ********************************************************/

void my_init(){
	//***INITILIASING LCD***//
	
	P0 = 0;
	//clearing display
	RS = 0; 
	RW = 0; 
	P0 = 1; 
	EN = TRUE;
	delaya(1000);
	EN = FALSE;
	
	//function set
	P0 = 0;
	RS = 0;
	RW = 0;
	P0 = 0x30;
	EN = TRUE;
	delaya(1000);
	EN = FALSE;
	
	//display on/off control
	P0 = 0;
	RS = 0;
	RW = 0;
	P0 = 0x08;
	EN = TRUE;
	delaya(1000);
	EN = FALSE;
	
	//Entry mode set
	P0 = 0;
	RS = 0;
	RW = 0;
	P0 = 0x03;
	EN = TRUE;
	delaya(1000);
	EN = FALSE; 
	
	//**End of initialisation**//
	
}

void setLCDPos(unsigned char cur){
	//if cursor is less than the first row,
	if(cur < 0x0F){ 
		P0 = cur;
		P0_7 = 1;
		
	} 
	
}

void writeCharLCD(){
	RS = 1;
	if(cur < 0x0F){ 
		P0_7 = 1;
		P0_5 = cur;
		P0_4 = cur;
		P0_3 = cur;
		P0_2 = cur;
		P0_1 = cur;
		P0_0 = cur;
	} 
	
}

void main()
{
	my_init();
	cursor = 0x00;
	while(1){
		setLCDPos(cursor);
		writeCharLCD()
	
	}
	//posSetter(0x80); //bin(1000000) = 2^7 = 0x80 for first cell
	//writeCharLCD(a);
	
}

