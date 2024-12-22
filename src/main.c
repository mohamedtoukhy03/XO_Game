/******************************************************************************
 * Module: MAIN
 *
 * File Name: MAIN.c
 *
 * Description: Source file for MAIN
 *
 * Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM
 ******************************************************************************/

#include "./headers/Nokia5110.h"
#include "./headers/TExaS.h"
#include "./headers/GPIO.h"
#include "./headers/XO Game.h"
#include "./headers/ADC.h"
#include "./headers/UART.h"

extern unsigned char sw1, sw2;
int main(void){
	TExaS_Init(SSI0_Real_Nokia5110_Scope);
	UART_Init();
	PortF_Init();
	PortB_Init();
	Nokia5110_Init();
	Nokia5110_ClearBuffer();
	Nokia5110_DisplayBuffer();
	initScreen();
	resetGame();
	drawGameCells();
	ADC_Init();
	while (1){ // main logic of the game.
		if (sw1 || sw2)
				runGame(); // start game
			else {
				MoveCursorWithPotentiometer();
			}
	}
}




