#include <t89c51ac3.h>
#include <phys340libkeil.h>
#include <stdio.h>
#include <string.h>

char outputText[33];

int count0 = 0;
int count1 = 0;
int count2 = 0;

void setup()
{
	// Enable all interrupts
	EA = 1;
	// Enable PCA Interrupts
	EC = 1;
	
	// enable Timer0 control bit
	TR0 = 1;	
	//select T0 mode 2: 8-bit auto-reload
	TMOD = 0x02;
	
	//PCA 0: compare, match, interrupt
	CCAPM0 = 0x49;
	//PCA 1: compare, match, interrupt
	CCAPM1 = 0x49;
	//PCA 2: compare, match, interrupt
	CCAPM2 = 0x49;
	
	CCAP0H = 0;
	//CCAP0L = 0x00;
	
	CCAP1H = 85;
	//CCAP1L = 0x7F;
	
	CCAP2H = 170;
	//CCAP2L = 0xFF;
	
	//EWC Count Pulse Select to Timer0 Overflow
	// and Enable PCA Counter Overflow Interrupt
	CMOD = 0x05;
	
	//Turn timer on
	CR = 1;
	
	// timer overflow speed
	TH0 = 0xFE;
}

void intHandlerPCA() interrupt 6
{
	CF = 0;
	if (CCF0) 
	{
		count0++;
		CCF0 = 0;
	}
	if (CCF1) 
	{
		count1++;
		CCF1 = 0;
	}
	if (CCF2) 
	{
		count2++;
		CCF2 = 0;
	}
}

void main()
{
	setup();
	initLCD();
	while(1)
	{
		clearLCD();
		sprintf(outputText, "%2i %2i %2i", count0, count1, count2);
		writeLineLCD(outputText);
	}
}