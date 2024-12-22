/******************************************************************************
 * Module: LED
 *
 * File Name: LED.c
 *
 * Description: Source file for LED
 *
 * Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM
 ******************************************************************************/

//#include "..\\./headers/TM4C123GH6PM.h"
#include "..\\./headers/LED.h"
#include "..\\./headers/Timer.h"
//#include "..\\./headers/GPIO.h"

int i;
/*******************************************************************************
 *                           Function                                     *
 *******************************************************************************/

void Set_Led_Pin(void)
{
	GPIO_PORTS_REGISTERS_ARR[B]->DATA |= (1 << PORTB_LED1_PIN); // PB2
	Delay(0.5);
	GPIO_PORTS_REGISTERS_ARR[B]->DATA |= (1 << PORTB_LED2_PIN); // PB3
	Delay(0.5);
	GPIO_PORTS_REGISTERS_ARR[B]->DATA |= (1 << PORTB_LED3_PIN); // PB4
}

void Set_Led_2(void)
{
	GPIO_PORTS_REGISTERS_ARR[B]->DATA  |= (1 << PORTB_LED2_PIN); // PB3
}
void Clear_Led_2(void)
{
	GPIO_PORTS_REGISTERS_ARR[B]->DATA &= ~(1 << PORTB_LED2_PIN); // PB3
}

void Set_Led_3(void)
{
	GPIO_PORTS_REGISTERS_ARR[B]->DATA |= (1 << PORTB_LED3_PIN); // PB4
}

void Clear_Led_3(void)
{
	GPIO_PORTS_REGISTERS_ARR[B]->DATA  &= ~(1 << PORTB_LED3_PIN); // PB4
}

void Clear_Led_Pin(void)
{
	GPIO_PORTS_REGISTERS_ARR[B]->DATA  &= ~(1 << PORTB_LED1_PIN); // PB2
	GPIO_PORTS_REGISTERS_ARR[B]->DATA &= ~(1 << PORTB_LED2_PIN); // PB3
	GPIO_PORTS_REGISTERS_ARR[B]->DATA &= ~(1 << PORTB_LED3_PIN); // PB4
}

void Blink_LEDS(void)
{
	for (i = 0; i < 3; i++)
	{
		GPIO_PORTS_REGISTERS_ARR[B]->DATA  |= (1 << PORTB_LED1_PIN); // PB2
		Delay(0.5);
		GPIO_PORTS_REGISTERS_ARR[B]->DATA  &= ~(1 << PORTB_LED1_PIN); // PB2
	  Delay(0.5);
	}
}

void Blink_LEDS_2(void)
{
	for (i = 0; i < 3; i++)
	{
		GPIO_PORTS_REGISTERS_ARR[B]->DATA  |= (1 << PORTB_LED2_PIN); // PB3
		Delay(0.5);
		GPIO_PORTS_REGISTERS_ARR[B]->DATA  &= ~(1 << PORTB_LED2_PIN); // PB3
		Delay(0.5);
	}
}
void Blink_LEDS_3(void)
{
	for (i = 0; i < 3; i++)
	{
		GPIO_PORTS_REGISTERS_ARR[B]->DATA |= (1 << PORTB_LED3_PIN); // PB4
		Delay(0.5);
		GPIO_PORTS_REGISTERS_ARR[B]->DATA &= ~(1 << PORTB_LED3_PIN); // PB4
	Delay(0.5);
	}
}


