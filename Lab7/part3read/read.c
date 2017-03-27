#include <t89c51ac3.h>
#include <phys340libkeil.h>
#include <string.h>
#include <stdio.h>

char value;


void main()
{
	initLCD();
	initSerial(1200);
	while(1)
	{
		//checking for RI interrupt flag
		if(RI)
			{
				//get char from hyperterminal
				value = SBUF; 
				//write to LCD
				writeCharLCD(value);
				//write to hyperterminal
				//writeCharSerial(value);
				//clear RI interrupt flag
				RI = 0;
			}
	}
}