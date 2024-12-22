/******************************************************************************
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for ADC
 *
 * Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM
 ******************************************************************************/

#include <stdlib.h>

#include "..\\./headers/tm4c123gh6pm.h"
#include "..\\./headers/TExaS.h"
#include "..\\./headers/ADC.h"
#include "..\\./headers/Nokia5110.h"

/*******************************************************************************
 *                           Function                                     *
 *******************************************************************************/

// Function to map ADC value to grid position (0-8)
int MapADCToGridPosition(uint16_t adcValue) {
    // Scale ADC value (0-4095) to a range of 0-8
    return (adcValue * 9) / 4096;
}

// ADC initialization using bitwise operations
volatile int delayADC = 0;
void ADC_Init(void) {
    SYSCTL_RCGCADC_R |= (1 << 0);             // Enable ADC0 clock
    SYSCTL_RCGCGPIO_R |= (1 << 4);            // Enable clock for Port E

    delayADC += 4;                               // Stabilization delay

    GPIO_PORTE_AFSEL_R |= (1 << 3);           // Enable alternate function on PE3
    GPIO_PORTE_DEN_R &= ~(1 << 3);            // Disable digital function on PE3
    GPIO_PORTE_AMSEL_R |= (1 << 3);           // Enable analog functionality on PE3

    ADC0_ACTSS_R &= ~(1 << 3);                // Disable Sample Sequencer 3
    ADC0_EMUX_R &= ~(0xF << 12);              // Configure as software trigger
    ADC0_SSMUX3_R = 0;                        // Set input channel to AIN0 (PE3)
    ADC0_SSCTL3_R = (1 << 1) | (1 << 2);      // Single-ended, end-of-sequence
    ADC0_ACTSS_R |= (1 << 3);                 // Enable Sample Sequencer 3
}

// Read ADC value using bitwise operations
uint16_t ADC_Read(void) {
    uint16_t result;
    ADC0_PSSI_R |= (1 << 3);                  // Initiate SS3
    while ((ADC0_RIS_R & (1 << 3)) == 0);     // Wait for conversion to complete
    result = ADC0_SSFIFO3_R & 0xFFF;          // Read 12-bit result
    ADC0_ISC_R |= (1 << 3);                   // Clear interrupt flag
    return result;
}




