/***  Include Files and global variables  **********************************/
#include <t89c51ac3.h>
#include <phys340libkeil.h>
#include <stdio.h>
#include <string.h>

char outputText [33];
int rpm;
int flag;
unsigned int H;
unsigned int L;
unsigned int curr;
unsigned int prev;
unsigned int diff;

/** External Interrupt initialisation **/
void interruptInit()
{
	/**PCA interrupt init**/
 IEN0 = 0xC0;
 CF = 0;
	/**set up PCA modules**/
 CCAPM0 = 0x21;
	/**init PCA**/
 CCON = 0x40;
}
/** Interrupt handler **/
void InterruptHandler(void) interrupt 6
{
 IEN0 = 0x00;
if(CF == 1)
 {
	 CF==0;
	 flag++;
 }
if(CCF0 == 1)
{
  prev = curr; 
	H = (unsigned int)(CCAP0H<<8);
  L = (unsigned int)(CCAP0L);
  curr = H+L + ((unsigned int)(65536*flag));
  diff = curr-prev;
  rpm = 300000/diff; 
}
	IEN0 = 0xC0;
  CCF0 = 0;
	flag = 0;
}
/**  Main Function  ********************************************************/

void main()
{
	interruptInit();
	initLCD();
  while (TRUE)
  {
    clearLCD(); 
		sprintf(outputText, "%i", rpm);
    writeLineLCD(outputText);
		delaya(1000);
  }
}