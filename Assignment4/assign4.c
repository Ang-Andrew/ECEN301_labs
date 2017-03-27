#include <t89c51ac3.h>
#include <string.h>
#include <phys340libkeil.h>
#include <stdio.h>

char outputText [33];//for printing out onto LCD or hyperterm
int rpm; //current averaged RPM of motor
int difference=0; //difference between values in CCAP1H/L in two interrupts
unsigned int hi,lo,prev,curr,period; //varaibles for cacluating RPM
unsigned int overflow; // overflow flag counter Flag counter
int rpm; //average RPM
int currRPM = 0; //current RPM
int samples[5]; //for averaging, storage for RPM
int index = 0; //for averaging
int summer = 0; //to calculate the total of the array of RPM
int fullFlag = 0; //flag set when array is full of values
int i = 0; //for loop increment variable
int wantRPM = 0; //target set RPM
int err = 0; //error between set target RPM and current RPM
float kp = 1.5; //proportional constant
float ki = 0; //integral constant
float kd = 0; //derivative constant
float prop = 0; //proportional control
float intCtrl = 0; //integral control
float derCtrl = 0; //derivative control
float correctionTot = 0;
int errSum = 0; //sum of past errors
int oldErr = 0; //rate of change of error
int errDif = 0;//present error


void MyIntHandler(void) interrupt 6
{
	EA=0;
	EC=0;
	if(CF ==1)
			{
				overflow++;
				CF=0;	
			}	
	if(CCF1 == 1)
		{	
			hi = (unsigned int)(CCAP1H<<8);
			lo =  (unsigned int)(CCAP1L);
			prev = curr;	
			curr = hi + lo +  ((unsigned int)(65536*overflow)); 
			difference = curr-prev;
		}
	CCF1 = 0;
	EA=1;
	EC=1;
	overflow=0;
}


void averaging()
{
	summer = 0;
	//getting the total within the array
	for(i = 0; i < 5; ++i) 
			{
				summer = summer + samples[i];
			}
	//finding the average
	rpm = summer/5;
	
}

void init()
{
	//PCA module 0 as PWM output to motor
	CCAPM0 = 0x42;
	CMOD = 0x01;
	
	//PCA module 1 as capture for optoswitch
	EA=1;
	EC=1;
	CCAPM1 = 0x11; //Capture mode and enable CCFx interrupt bit
	CCON = 0x40; //PCA Counter On
	CF=0;
}

void main()
{
	init();	//initialise function registers
	initLCD(); //initialise LCD
	initSerial(1200); //initialise serial communication with 1200 baud rate
		while(1)
			{
				//PID control
				prop = 0.2*err; //proportional controller
				intCtrl = 0.1*errSum; //integral controller
				derCtrl = 0.25*errDif; //differential controller
				correctionTot = prop+intCtrl+derCtrl; //sum of the P,I and D
				
				//PWM out
				CCAP0H = (393.05-correctionTot)/1.5924; //setting the PWM across the motor
				clearLCD();
				
				currRPM = 300000/difference; //calcualting the currrent RPM
				samples[index] = currRPM; //storing current RPM into array
				index++;//increment array cursor
				if (index == 6) //array of samples is full
				{
					index = 0; //reset array cursor
					fullFlag = 1;//array is now full
				}
				if (fullFlag)
				{
					averaging();
					//prints out current RPM
					sprintf(outputText, "%i",rpm);
					writeLineLCD(outputText);
					writeLineSerial(outputText);
					
					//prints out wanted RPM
					setLCDPos(16);
					wantRPM = (-1.5924*P2)+393.05;
					sprintf(outputText, "wRPM:%i",wantRPM);
					writeLineLCD(outputText);
					
					//prints out error
					oldErr = err; 
					err = wantRPM - rpm; //gets the present error difference
					errDif = oldErr - err; //rate of change of error
					errSum = errSum+err; //sum of all past erros
					setLCDPos(25);
					sprintf(outputText, "e:%i",err);
					writeLineLCD(outputText);
					
					fullFlag = 0;					
				}				
			}
}