#include "..\\./headers/tm4c123gh6pm.h"
#include "..\\./headers/UART.h"
#include "..\\./headers/XO Game.h"

unsigned char input;
void UART_Init(void){
	SYSCTL_RCGC1_R |= SYSCTL_RCGC1_UART0; // activate UART0
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA; // activate port A
  UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART
  UART0_IBRD_R = 520;                    // IBRD = int(16,000,000 / (16 * 9600)) = int(104.166666666666666)
  UART0_FBRD_R = 53;                     // FBRD = int(0.166667 * 64 + 0.5) = 11
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART0_LCRH_R = (0x3<<5);
  UART0_CTL_R |= UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE;	// enable UART, RX, TX
	UART0_CC_R = UART_CC_CS_SYSCLK;
  GPIO_PORTA_AFSEL_R |= 0x03;           // enable alt funct on PA1-0
  GPIO_PORTA_DEN_R |= (1<<0) |(1<<1);             // enable digital I/O on PA1-0
                                        // configure PA1-0 as UART
  GPIO_PORTA_PCTL_R |= (1<<0)|(1<<4);
  GPIO_PORTA_AMSEL_R &= ~0x03;          // disable analog functionality on PA
	
	UART0_IM_R |= (1 << 4);
	NVIC_EN0_R |= (1 << 5);
}

char UART0_Read(void) {
    while ((UART0_FR_R & 0x10) != 0);  // Wait until RXFE is 0 (not empty)
    return (char)(UART0_DR_R & 0xFF);
}

void UART0_Handler(void){
	if(UART0_RIS_R & (1 << 4)){
		UART0_ICR_R |= (1 << 4);
		input = UART0_Read();
		UART_OutChar(input);
		switch (input) {
            case 'x':
                UARTfunctionX();
                break;

            case 'o':
                UARTfunctionO();
                break;

            default:
                break;
        }
		
	}
}
void UART0_Write(char c) {
    while ((UART0_FR_R & 0x20) != 0);  // Wait until TXFF is 0 (not full)
    UART0_DR_R = c;
}

void UART0_WriteString(const char *str) {
    while (*str) {
        UART0_Write(*str++);
    }
}

unsigned char UART_InChar(void){
  while((UART0_FR_R&UART_FR_RXFE) != 0);
  return((unsigned char)(UART0_DR_R&0xFF));
}

unsigned char UART_InCharNonBlocking(void){
  if((UART0_FR_R&UART_FR_RXFE) == 0){
    return((unsigned char)(UART0_DR_R&0xFF));
  } else{
    return 0;
  }
}

void UART_OutChar(unsigned char data){
  while((UART0_FR_R&UART_FR_TXFF) != 0);
  UART0_DR_R = data;
}

unsigned long UART_InUDec(void){
unsigned long number=0, length=0;
char character;
  character = UART_InChar();
  while(character != CR){ 
    if((character>='0') && (character<='9')) {
      number = 10*number+(character-'0');   
      length++;
      UART_OutChar(character);
    }
    else if((character==BS) && length){
      number /= 10;
      length--;
      UART_OutChar(character);
    }
    character = UART_InChar();
  }
  return number;
}

void UART_OutString(unsigned char buffer[]){
	while(*buffer){
    UART_OutChar(*buffer);
    buffer++;
  }
}

unsigned char String[10];
void UART_ConvertUDec(unsigned long n) {
}


void UART_OutUDec(unsigned long n){
  UART_ConvertUDec(n);     // convert using your function
  UART_OutString(String);  // output using your function
}

void UART_ConvertDistance(unsigned long n) {
}


void UART_OutDistance(unsigned long n){
  UART_ConvertDistance(n);      // convert using your function
  UART_OutString(String);       // output using your function
}






