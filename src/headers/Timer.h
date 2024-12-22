/******************************************************************************
 * Module: TIMER
 *
 * File Name: TIMER.h
 *
 * Description: Header file for TIMER
 *
 * Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM
 ******************************************************************************/

#include "TIMER_cfg.h"
#include "GPIO.h"


/*******************************************************************************
 *                           Function                                     *
 *******************************************************************************/


void Timer2_Init(unsigned long ,RCGC ,TIMER ,GENERAL_MODE_SELECT ,MODE_SELECT);

void EnableTimer2Clock(RCGC);

void Timer2_general_mode(GENERAL_MODE_SELECT);

void Timer2_mode(TIMER t,MODE_SELECT);

void Timer2_Interval(TIMER t,double period);

void Timer2_ICR_clear(TIMER);

void Timer2_interrupt_akcnowlage(TIMER);

void Timer2_Interrupt_Inti(TIMER t);

void Timer2_interrupt_Mask(TIMER);

void Timer2_CTL_Mode(TIMER,EN_DIS);

void Timer1A_Handler (void);

void Timer1B_Handler (void);

//void Delay(double seconds);
