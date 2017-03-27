#include <t89c51ac3.h>
#include <phys340libkeil.h>
#include <string.h>
#include <stdio.h>

char value;
void myInitSerial()
{
	//configuring timer 1 pg 71
	TMOD = 0x20;	
	//setting SM0 and SM1 to provide an 8 bit serial UART with variable baud rate pg 63
	SM0 = 0;
	SM1 = 1;
	//setting PCON register setting SMOD so that the baud rate is doubled pg 65
	PCON = 0x80;
	//setting TH1 to set the baud rate pg 72
	
	TH1 = 203;
	//turning on timer 1 pg 70
	TR1 = 1;
	//enable serial reception pg 63
	REN = 1;
	
}

void main()
{
	initLCD();
	myInitSerial();
	while(1)
	{
		//get char from hyperterminal
		value = readCharSerial(); 
		//write to LCD
		writeCharLCD(value);
		//write to hyperterminal
		writeCharSerial(value);
	}
}