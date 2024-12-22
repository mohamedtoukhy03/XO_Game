/******************************************************************************
 * Module: GPIO
 *
 * File Name: GPIO.c
 *
 * Description: Source file for GPIO
 *
 * Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM
 ******************************************************************************/

#include "..\\./headers/GPIO.h"

volatile unsigned long delay,counter;
unsigned char sw1 = 0, sw2 = 0;

GPIOA_Type * const GPIO_PORTS_REGISTERS_ARR[] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF};
void GPIOClock(Port port){
	volatile unsigned long delay=0;
  SYSCTL->RCGC2 |= (1 << port);
	for (delay = 0; delay < 500000; delay++);
}


void set_direction(Port port,Pin pin,DIR dir){
  if(dir==INPUT) GPIO_PORTS_REGISTERS_ARR[port]->DIR&= ~(1 << pin);
	else GPIO_PORTS_REGISTERS_ARR[port]->DIR|= (1 << pin);
	
}

void DigitalAnalog(Port port,Pin pin,DigitalAnalogSelect x){
 if(x==GPIO_MODE_DIGITAL) {
 GPIO_PORTS_REGISTERS_ARR[port]->AMSEL&=~(1<<pin);
	 GPIO_PORTS_REGISTERS_ARR[port]->DEN|=(1<<pin);
 }
 else{GPIO_PORTS_REGISTERS_ARR[port]->DEN&=~(1<<pin);
	 GPIO_PORTS_REGISTERS_ARR[port]->AMSEL|=(1<<pin);
 
 }
 
}

void Mode_Select(Mode mode,Function f){
 
  if(mode==ALLTERNATIVE&&f==uart0) {
		GPIO_PORTS_REGISTERS_ARR[0]->AFSEL|=(1<<0)|(1<<1);
	  GPIO_PORTS_REGISTERS_ARR[0]->PCTL=(GPIO_PORTS_REGISTERS_ARR[0]->PCTL&0xFFFFFF00)+0x00000011;
	}
	else if(f==Timer2){
		GPIO_PORTS_REGISTERS_ARR[5]->AFSEL|=(1<<0);
		GPIO_PORTS_REGISTERS_ARR[1]->AFSEL|=(1<<0)|(1<<1);
   GPIO_PORTS_REGISTERS_ARR[5]->PCTL=(GPIO_PORTS_REGISTERS_ARR[5]->PCTL&0xFF0FFFFF)+0x00100000;
	 GPIO_PORTS_REGISTERS_ARR[1]->PCTL=(GPIO_PORTS_REGISTERS_ARR[1]->PCTL&0xFFFFFF00)+0x00000011;
	}
 } 

 void GPIO_resistor(Port port,Pin pin,Resistor r){
  if(r==pullup) GPIO_PORTS_REGISTERS_ARR[port]->PUR |= (1 << pin); 
	 else GPIO_PORTS_REGISTERS_ARR[port]->PUR &=~(1 << pin);
 }
 
void GPIOIS(Port port,Pin pin,EDG_LEV x){
	if(x==edge) GPIO_PORTS_REGISTERS_ARR[port]->IS&= ~(1 << pin); 
	else GPIO_PORTS_REGISTERS_ARR[port]->IS |= (1 << pin); 
}

void GPIOIBE(Port port,Pin pin,Edge e,Fall_Rise x){
   if(e==one)  GPIO_PORTS_REGISTERS_ARR[port]->IBE &=~ (1 << pin);
	 else GPIO_PORTS_REGISTERS_ARR[port]->IBE |= (1 << pin);
	 if (x == rise) {
        GPIO_PORTS_REGISTERS_ARR[port]->IEV |= (1 << pin);  
    }else{
        GPIO_PORTS_REGISTERS_ARR[port]->IEV &= ~(1 << pin);  
    } 
}

void Interrupt_clear(Port port,Pin pin){

		GPIO_PORTS_REGISTERS_ARR[port]->ICR &= ~(1 << pin);

}
void Interrupt_acknowledge(Port port,Pin pin){
	
	GPIO_PORTS_REGISTERS_ARR[port]->ICR = (1 << pin);
	
}

char GPIORIS(Port port,Pin pin){
	return (GPIO_PORTS_REGISTERS_ARR[port]->RIS & (1 << pin)) ? 1 : 0;
}

void GPIOIM(Port port,Pin pin,EN_DIS e){
	if(e==En)
	GPIO_PORTS_REGISTERS_ARR[port]->IM|=(1<<pin) ;
	else GPIO_PORTS_REGISTERS_ARR[port]->IM&=~(1<<pin) ;
}

void GPIO_Init(Port port ,Pin pin,DIR dir,DigitalAnalogSelect x){
   GPIOClock(port);
	set_direction(port,pin,dir);
	DigitalAnalog(port,pin,x);
}
void PortF_Enterrupt_inti(){
	 GPIOIM(F,0,En);
   GPIOIM(F,4,En);
	 GPIOIS(F,0,edge);
	 GPIOIS(F,4,edge);
	 GPIOIBE(F,GPIO_PIN_0,one,fall);
	 GPIOIBE(F,GPIO_PIN_4,one,fall);
	 Interrupt_clear(F,0);
	 Interrupt_clear(F,4);
	 NVIC->ISER[0] |= (1 << 30);
   EnableInterrupts();
}

void GPIOenablechange(Port port) {
    GPIO_PORTS_REGISTERS_ARR[port]->LOCK = 0x4C4F434B; // Unlock GPIO
    while ((GPIO_PORTS_REGISTERS_ARR[port]->LOCK & 0x01) != 0) {
        // Wait for unlock
    }
    GPIO_PORTS_REGISTERS_ARR[port]->CR = 0xFF; // Allow changes on all pins
}


void PortB_Init(void) {
    GPIOClock(B);
    GPIOenablechange(B);
    GPIO_PORTS_REGISTERS_ARR[B]->PCTL = 0x00000000;
    for (counter = 0; counter <= 7; counter++) {
        set_direction(B, counter, OUTPUT);
        DigitalAnalog(B, counter, GPIO_MODE_DIGITAL);
    }
}

void PortF_Init(void) {
    GPIOClock(F);
    GPIOenablechange(F);
    GPIO_PORTS_REGISTERS_ARR[F]->PCTL = 0x00000000;
    for (counter = 0; counter <= 4; counter++) {
        if (counter == 0 || counter == 4) {
            set_direction(F, counter, INPUT);
					  GPIO_resistor(F, counter, pullup);
        } else {
            set_direction(F, counter, OUTPUT);
        }
        DigitalAnalog(F, counter, GPIO_MODE_DIGITAL);
    }
 
    PortF_Enterrupt_inti();
}



 void GPIOPortF_Handler(void) {
    uint32_t mis = GPIO_PORTS_REGISTERS_ARR[F]->MIS;  // Read interrupt status

    if (mis & (1 << 4)) {  // Check if SW1 (PF4) caused the interrupt
			    // Delay(0.5);
        if (!(GPIO_PORTS_REGISTERS_ARR[F]->DATA & 0x10)) {  // Confirm button press
            sw1 = 1;  // Set flag for SW1
            sw2 = 0;
        }
        Interrupt_acknowledge(F, 4);  // Acknowledge SW1 interrupt
    }

    if (mis & (1 << 0)) {  // Check if SW2 (PF0) caused the interrupt
			 Delay(1);
        if (!(GPIO_PORTS_REGISTERS_ARR[F]->DATA & 0x01)) {  // Confirm button press
            sw2 = 1;  // Set flag for SW2
            sw1 = 0;
        }
        Interrupt_acknowledge(F, 0);  // Acknowledge SW2 interrupt
    }

    // Clear any remaining interrupts
    GPIO_PORTS_REGISTERS_ARR[F]->ICR = mis;
}



   


