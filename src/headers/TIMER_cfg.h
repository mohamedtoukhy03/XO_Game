/******************************************************************************
 * Module: TIMER_cfg
 *
 * File Name: TIMER_cfg.h
 *
 * Description: Header file for TIMER_cfg
 *
 * Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM
 ******************************************************************************/

#define SYSCLK 80000000
typedef enum RCGC_e
{
	RCGCTIMER,
	RCGCWTIMER,
}RCGC;
  
typedef enum TIMER_e
{
	TIMERA,
	TIMERB,
	BOTH
}TIMER; 

typedef enum GENERAL_MODE_SELECT_e{
 big=0x0,
 small=0x4,
}GENERAL_MODE_SELECT;


typedef enum MODE_SELECT_e{
 One_Shot= 0x1,
 Periodic=0x2,
}MODE_SELECT;

