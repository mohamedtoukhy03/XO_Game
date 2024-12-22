/******************************************************************************
 * Module: Timer
 *
 * File Name: Timer.c
 *
 * Description: Source file for Timer
 *
 * Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM
 ******************************************************************************/
#include "..\\./headers/TIMER.h"
//#include "..\\./headers/GPIO.h"
#define TIMER_NVIC_EN0    (*(volatile unsigned long *)0xE000E100)
#define NVIC_PRI5         (*((volatile unsigned long *)0xE000E414)) 

/*******************************************************************************
 *                           Function                                     *
 *******************************************************************************/

void EnableTimer2Clock(RCGC	R){
	int i;
	SYSCTL->RCGCTIMER|=(1<<2);
	i=SYSCTL->RCGCTIMER|=(1<<2);
}

void Timer2_general_mode(GENERAL_MODE_SELECT M){   
 TIMER2->CFG=M;
}

void Timer2_Interval(TIMER t,double period){
  if(t==TIMERB) TIMER2->TBILR=(SYSCLK * period) - 1; 
	else TIMER2->TAILR=(SYSCLK * period) - 1; 
}

void Timer2_mode(TIMER t,MODE_SELECT m){
 if(t==TIMERB)TIMER2->TBMR=m;
 else TIMER2->TAMR=m;
 
}
void Timer2_ICR_clear(TIMER t){
  if(t==TIMERB)TIMER2->ICR&=~(1<<8);
	else if (t==TIMERA)TIMER2->ICR&=~(1<<0);
	else TIMER2->ICR&=~((1<<8)|(1<<0));
}

void Timer2_interrupt_akcnowlage(TIMER t){
  if(t==TIMERB)TIMER2->ICR|=(1<<8);
	else if (t==TIMERA)TIMER2->ICR|=(1<<0);
	else TIMER2->ICR|=(1<<8)|(1<<0);
}

void Timer2_interrupt_Mask(TIMER t){
  if(t==TIMERB)TIMER2->IMR|=(1<<8);
	else if (t==TIMERA)TIMER2->IMR|=(1<<0);
	else TIMER2->IMR|=(1<<8)|(1<<0);
}

void Timer2_CTL_Mode(TIMER t,EN_DIS m){
	if(m==Dis){
	 if(t ==TIMERB)  TIMER2->CTL&=0x00FF;
	else if(t==TIMERA) TIMER2->CTL&=0xFF00;
	else if(t==BOTH)TIMER2->CTL=0x00000000; 
	}
	else {
	if(t ==TIMERB)  TIMER2->CTL|=(1<<8);
	else if(t==TIMERA) TIMER2->CTL|=(1<<0);
	else if(t==BOTH)TIMER2->CTL|=(1<<8)|(1<<0); 
	}
}

void Timer2_Interrupt_Inti(TIMER t){
	Timer2_interrupt_akcnowlage(t);
	}

void Timer2_Init(unsigned long period,RCGC R,TIMER t,GENERAL_MODE_SELECT M,MODE_SELECT mode){
	 EnableTimer2Clock(R);
	Timer2_CTL_Mode(t,Dis);
	Timer2_general_mode(M);
	Timer2_mode(t,mode);
	Timer2_Interval(t,period); 
	Timer2_Interrupt_Inti(t);
	Timer2_CTL_Mode(t,En);
}


void Delay(double seconds) {

   Timer2_Init(seconds,RCGCTIMER,TIMERA,big,Periodic);
    while ((TIMER2->RIS & 0x01) == 0); // Wait for timeout flag

    Timer2_interrupt_akcnowlage(TIMERA);          // Clear the timeout flag
}




