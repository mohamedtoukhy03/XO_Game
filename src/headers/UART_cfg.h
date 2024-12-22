/******************************************************************************
 * Module: UART_cfg
 *
 * File Name: UART_cfg.h
 *
 * Description: Header file for UART_cfg
 *
 *Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM

 ******************************************************************************/
#define SYSCLK 80000000
 typedef enum Datalength_e
{
	 bits_5=0x00000000,
	 bits_6=0x00000020,
	 bits_7=0x00000040,
	 bits_8=0x00000060,
}Datalength;

typedef enum MODE
{
	 Enable ,
	 disable,
}MODE;



typedef enum stop_bit_e
{ 
	bits_1=1,
	bits_2=2,
	
}STOP_BIT;

typedef enum clock_source_e
{ 
	 System_Clock=0x0,
	 PIOSC=0x5,
	
}CLOCK_SOURCE;

typedef enum LEVEL_e
{ 
	FEFO_DIS=-1,
	RXlevel0=0,
  RXlevel1=1,
  RXlevel2=2,  //defult
  RXlevel3=3,
  RXlevel4=4,
	TXlevel0=5,
  TXlevel1=6,
  TXlevel2=7,  //defult
  TXlevel3=8,
  TXlevel4=9,
 	EOT=10,
	
}LEVEL;

typedef enum RX_TX_e
{
	 RX,
	 TX,
	 RT,
	 no=-1,
}RX_TX;

typedef enum SPEED_E
{
	 low=16,
	 high=8,
}SPEED;
