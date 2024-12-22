/******************************************************************************
 * Module: GPIO.h
 *
 * File Name: GPIO.h
 *
 * Description: Header file for GPIO
 *
 *Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM

 ******************************************************************************/
 #include "TM4C123GH6PM.h"
 
 extern GPIOA_Type * const GPIO_PORTS_REGISTERS_ARR[] ;

typedef enum Gpio_Pin_e
{
	GPIO_PIN_0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
}Pin;

typedef enum Gpio_Port_e
{
  A,
  B,
	C,
	D,
	E,
  F,
}Port;


typedef enum Gpio_Dir_e
{
	INPUT,
	OUTPUT,
	none,
}DIR;

typedef enum Gpio_DigitalAnalogSelect_e
{
	GPIO_MODE_DIGITAL,
	GPIO_MODE_ANALOG,
}DigitalAnalogSelect;

typedef enum Resistor_e
{
	pulldown ,
	 pullup,
}Resistor;

typedef enum Gpio_mode{
  GPIO,
	ALLTERNATIVE,
}Mode;

typedef enum f{
  Timer2,
	uart0,
}Function;

typedef enum EDG_LEV_e{
  edge,
	level,
}EDG_LEV;

typedef enum EDGE_e{
  one,
	Both,
}Edge;

typedef enum Edge_e{
  fall,
	rise,
}Fall_Rise;

typedef enum endis_e{
  En,
	Dis,
}EN_DIS;
/*******************************************************************************
 *                      Functions                                 *
 *******************************************************************************/
void PortA_Init(void);
void PortB_Init(void);
void PortC_Init(void);
void PortD_Init(void);
void PortE_Init(void);
void PortF_Init(void);
void GPIOClock(Port);
void set_direction(Port,Pin,DIR);
void DigitalAnalog(Port,Pin,DigitalAnalogSelect);
void Mode_Select(Mode mode,Function f);
void EnableInterrupts(void);
void WaitForInterrupt(void);
void GPIOF_Handler(void);
void GPIO_Init(Port,Pin,DIR,DigitalAnalogSelect);
void PortB_Init(void);
void PortF_Init(void);
void GPIO_resistor(Port,Pin,Resistor);
void PortF_Enterrupt_inti(void);
void GPIOIS(Port,Pin,EDG_LEV);
void GPIOIBE(Port,Pin,Edge,Fall_Rise);
void Interrupt_clear(Port,Pin);
void Interrupt_acknowledge(Port,Pin);
void GPIOIM(Port,Pin,EN_DIS);
void NVIC_PRI(char priority);
void NVIC_EN(Port, Pin);
char GPIORIS(Port,Pin);
void GPIOenablechange(Port);
#ifndef TIMER_H
#define TIMER_H
void Delay(double seconds);
#endif 
