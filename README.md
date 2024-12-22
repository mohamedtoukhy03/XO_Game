# XO Game Using Tiva-C LaunchPad and Nokia 5110 Screen

## Overview
This project implements a simple Tic-Tac-Toe (XO) game on the Tiva-C TM4C123GH6PM LaunchPad. The game interface is displayed on a Nokia 5110 LCD screen, and user interaction is facilitated through buttons and LEDs. The project is designed to be compatible with both simulation environments and physical hardware setups.

## Tiva-C LaunchPad Overview
The Tiva-C TM4C123GH6PM LaunchPad is a microcontroller development board by Texas Instruments. It features:
- An ARM Cortex-M4 core running at up to 80 MHz.
- A range of GPIO pins and peripherals, including UART, SPI, and I2C interfaces.
- Built-in debugging capabilities with an on-board In-Circuit Debug Interface (ICDI).
- A compact design suitable for prototyping embedded systems.

This board is ideal for controlling peripheral devices such as the Nokia 5110 screen and other hardware components needed for this project.

## Nokia 5110 Screen Overview
The Nokia 5110 LCD is a low-cost graphical display module originally used in Nokia 5110/3310 phones. It features:
- A resolution of 84x48 pixels.
- A PCD8544 controller that communicates via SPI.
- Low power consumption.
- Compatibility with 3.3V power and logic levels.

This screen is used to display the game interface, including the Tic-Tac-Toe grid and player actions.

## Required Hardware I/O Connections
This project has been developed for use both in simulation environments and with physical hardware. Below is the list of components required when using external hardware:

### Components
- **Tiva-C LaunchPad (TM4C123GH6PM)**
- **Nokia 5110 Screen (Blue)**
- **2 Push Buttons**
- **3 RGB LEDs**
- **Male-Female Jumper Wires (Connectors)**
- **Resistors**
- **Breadboard**
- **Potentiometer**

### Blue Nokia 5110 Connections
| Signal         | Nokia 5110 Pin | LaunchPad Pin |
|----------------|----------------|---------------|
| **Reset**      | RST (Pin 1)    | PA7           |
| **SSI0Fss**    | CE (Pin 2)     | PA3           |
| **Data/Command** | DC (Pin 3)     | PA6           |
| **SSI0Tx**     | Din (Pin 4)    | PA5           |
| **SSI0Clk**    | Clk (Pin 5)    | PA2           |
| **3.3V Power** | Vcc (Pin 6)    | 3.3V          |
| **Backlight**  | BL (Pin 7)     | Not connected (optional) |
| **Ground**     | Gnd (Pin 8)    | Ground        |

RGB LED Connections:

The 3 RGB LEDs are connected to the following pins on Port B:
Pin 2
Pin 3
Pin 4

---

This configuration ensures that the XO game operates smoothly on both simulated and physical environments. Detailed implementation and code are available in the repository.

