/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"
#define LAUNCHPAD_S1 BIT1            //defines the bit of launchpad S1
#define LAUNCHPAD_LED1 BIT0              //defines the bit of launchpad LED1
#define LAUNCHPAD_LED2_RED BIT0       //defines the bit of launchpad led2 red
#define LAUNCHPAD_LED2_GREEN BIT1     //defines the bit of launchpad LED2 Green
#define LAUNCHPAD_LED2_BLUE BIT2       //defines the bit of launchpad LED2 Blue
#define LAUNCHPAD_S2 BIT4             //defines the bit of launchpad S2
#define BOOSTERPACK_S1 BIT1             //defines the bit of boosterpack S1
#define BOOSTERPACK_S2 BIT5             //defines the bit of boosterpack S2
#define BOOSTERPACK_LED_RED BIT6       //defines the bit of boosterpack LED RED
#define BOOSTERPACK_LED_GREEN BIT4        //defines the bit of boosterpack LED Green
#define BOOSTERPACK_LED_BLUE BIT6        //defines the bit of boosterpack led blue
#define PRESSED 0

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    P1DIR &= ~LAUNCHPAD_S1;
    P1REN |= LAUNCHPAD_S1;
    P1OUT |= LAUNCHPAD_S1;
    // Launchpad S2
    P1DIR &= ~LAUNCHPAD_S2;
    P1REN |= LAUNCHPAD_S2;
    P1OUT |= LAUNCHPAD_S2;
    // Boosterpack S1
    P5DIR &= BOOSTERPACK_S1;
    P5REN |= BOOSTERPACK_S1;
    P5OUT |= BOOSTERPACK_S1;
    // Boosterpack S2
    P3DIR &= BOOSTERPACK_S2;
    P3REN |= BOOSTERPACK_S2;
    P3OUT |= BOOSTERPACK_S2;
    // Launchpad LED1
    P1DIR |= LAUNCHPAD_LED1;
    // Launchpad LED2 Red
    P2DIR |= LAUNCHPAD_LED2_RED;
    // Launchpad LED2 Green
    P2DIR |= LAUNCHPAD_LED2_GREEN;
    // Launchpad LED2 Blue
    P2DIR |= LAUNCHPAD_LED2_BLUE;
    // Boosterpack LED Red
    P2DIR |= BOOSTERPACK_LED_RED;
    // Boosterpack LED Green
    P2DIR |= BOOSTERPACK_LED_GREEN;
    // Boosterpack LED Blue
    P5DIR |= BOOSTERPACK_LED_BLUE;

    // Turn off all LEDs at the start.
}
void turnoff_allLaunchpadLED(){     //function for turning off all LEDS
    turnOff_LaunchpadLED2Green();
    turnOff_LaunchpadLED2Red();
    turnOff_LaunchpadLED2Blue();
    turnOff_LaunchpadLED1();
}


void turnoff_allBoosterpackLED(){     //function for turning off all LEDS
    turnOff_BoosterpackLEDRed();
    turnOff_BoosterpackLEDGreen();
    turnOff_BoosterpackLEDBlue();

}



// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & LAUNCHPAD_S1) == PRESSED);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & LAUNCHPAD_S2) == PRESSED);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & BOOSTERPACK_S1) == PRESSED);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P3IN & BOOSTERPACK_S2) == PRESSED);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT |= LAUNCHPAD_LED1;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT &= ~LAUNCHPAD_LED1;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT |= LAUNCHPAD_LED2_RED;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT &= ~LAUNCHPAD_LED2_RED;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT |= LAUNCHPAD_LED2_GREEN;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT &= ~LAUNCHPAD_LED2_GREEN;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT |= LAUNCHPAD_LED2_BLUE;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT &= ~LAUNCHPAD_LED2_BLUE;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT |= BOOSTERPACK_LED_RED;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT &= ~BOOSTERPACK_LED_RED;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT |= BOOSTERPACK_LED_GREEN;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT &= ~BOOSTERPACK_LED_GREEN;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT |= BOOSTERPACK_LED_BLUE;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT &= ~BOOSTERPACK_LED_BLUE;
}
