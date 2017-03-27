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
	
//char str[1];
//string test;
int secondLine;
int n;
int i;
char str[15];

unsigned char cursor;
Sbit(EN,0xC0,2);//setting EN to bit 2
Sbit(RW,0xC0,1); //setting RW to bit 1
Sbit(RS,0xC0,0);//setting RS to bit 0

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
	
	//turning lcd back on
	P0 = 0x0c;
	EN = TRUE;
	delaya(1000);
	EN = FALSE; 
	//**End of initialisation**//
	
}

void setCursor(unsigned char cur){
	//if the cursor is greater is now on the second line
	if (cur >= 0x10){
		RS = 0;
		RW = 0;
		
		P0 = 0x80+cur+0x30;
		EN = TRUE;
		delaya(1000);
		EN = FALSE;
		
	}
	//if the cursor is on the first line
	else{
	//setting DDRAM address
	RS = 0;
	RW = 0;
	
//	P0_0 = a0;
//	P0_1 = a1;
//	P0_2 = a2;
//	P0_3 = a3;
//	P0_4 = a4;
//	P0_5 = a5;
//	P0_6 = a6;
//	P0_7 = 1;
	
	P0 = 0x80+cur;
	
	EN = TRUE;
	delaya(1000);
	EN = FALSE;
	}
	

	
}

void writerCharacterLCD(unsigned char character){
	//using dataregister
	RS = 1; 
	RW = 0;
	
	//putting the character into the DDRAM
	P0 = character;
	
	EN = TRUE;
	delaya(1000);
	EN = FALSE;
	
	//back to the instruction register
	RS = 0;
}

void writeArrayLCD(unsigned char array[])
{
	for(i = 0; i < 15; i++)
	{
		
		if(array[i] == 0){
			break;
		}
		writerCharacterLCD(array[i]);
		
	}	



}


void main()
{
//	my_init();
//	cursor = 31;
//	
//	n = 1;
//	secondLine = 0;
//	
//	clearLCD();
//	setCursor(cursor);
//	sprintf(str,"%d",n);
//	writeLineLCD(str);
//	delaya(10000);
	
	my_init();
	cursor = 0;
	str[0] = 'h';
	str[1] = 'i';
	
	
	
		n = 1;
		clearLCD();
		setCursor(cursor);
//		sprintf(str,"%d",n);
//		writeLineLCD(str);
		writeArrayLCD(str);		
		//writerCharacterLCD('z');
		delaya(10000);
//		cursor++;
//		if(cursor > 31){
//			cursor = 0;
//		}
	
	
	
	
	

		
		
	
	}

	


