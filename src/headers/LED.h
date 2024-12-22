/******************************************************************************
 * Module: LED.h
 *
 * File Name: LED.h
 *
 * Description: Header file for LED
 *
 *Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM

 ******************************************************************************/

#define PORTB_LED1_PIN 2

#define PORTB_LED2_PIN 3

#define PORTB_LED3_PIN 4

/*******************************************************************************
 *                      Functions                                  *
 *******************************************************************************/

void Set_Led_Pin(void);
void Set_Led_2(void);
void Set_Led_3(void);
void Clear_Led_2(void);
void Clear_Led_3(void);
void Clear_Led_Pin(void);

void Blink_LEDS_3(void);
void Blink_LEDS(void);
void Blink_LEDS_2(void);
