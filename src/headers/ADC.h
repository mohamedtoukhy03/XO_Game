/******************************************************************************
 * Module: ADC
 *
 * File Name: ADC.H
 *
 * Description: Header file for ADC
 *
 * Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM
 ******************************************************************************/

#include <stdint.h>

/*******************************************************************************
 *                           Function                                     *
 *******************************************************************************/
void ADC_Init(void);
uint16_t ADC_Read(void);
