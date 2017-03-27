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
		//get char from hyperterminal
		value = readCharSerial(); 
		//write to LCD
		writeCharLCD(value);
		//write to hyperterminal
		writeCharSerial(value);
	}
}