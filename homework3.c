#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

typedef enum {NO_COLOR, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE} color_state_t;
int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    char buttonhistory;
    bool pressed;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);
    turnoff_allLaunchpadLED();
    turnoff_allBoosterpackLED();
    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);

        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if(timer0Expired()){
            count0 = count0 + 1;
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if(timer1Expired()){
            if(checkStatus_BoosterpackS1()){
                buttonhistory = buttonhistory << 1;
                buttonhistory |= BIT0;
            }
            else
            {
                buttonhistory = buttonhistory << 1;
            }
        }


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.

        pressed = fsmBoosterpackButtonS1(buttonhistory);


        // TODO: If a completed, debounced button press has occurred, increment count1.
        if (pressed)
        {
            count1++;

        }


    }
}


void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    //static color_state_t currentState = NO_COLOR;
    switch(count % 8){
    case NO_COLOR:

            turnoff_allLaunchpadLED();

        break;
    case RED:
        //if(count == 1)
            turnoff_allLaunchpadLED();

            turnOn_LaunchpadLED2Red();
        break;
    case YELLOW:
        //if(count == 2)
            turnoff_allLaunchpadLED();

            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
        break;
    case GREEN:
        //if(TIMER0_COUNT == 3)
        turnoff_allLaunchpadLED();
            turnOn_LaunchpadLED2Green();
        break;
    case BLUE:
        //if(TIMER0_COUNT == 4)
        turnoff_allLaunchpadLED();
            turnOn_LaunchpadLED2Blue();
        break;
    case MAGENTA:
        //if(TIMER0_COUNT == 5)
            turnoff_allLaunchpadLED();
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Blue();
        break;
    case CYAN:
        //if(TIMER0_COUNT == 6)
            turnoff_allLaunchpadLED();
            turnOn_LaunchpadLED2Blue();
            turnOn_LaunchpadLED2Green();
        break;
    case WHITE:
            turnoff_allLaunchpadLED();
            turnOn_LaunchpadLED2Blue();
            turnOn_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Red();
        break;
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
        switch(count % 8){
        case NO_COLOR:

                turnoff_allBoosterpackLED();
            break;
        case RED:
            turnoff_allBoosterpackLED();
                turnOn_BoosterpackLEDRed();
            break;
        case YELLOW:
            turnoff_allBoosterpackLED();
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            break;
        case GREEN:
            turnoff_allBoosterpackLED();
                turnOn_BoosterpackLEDGreen();
            break;
        case BLUE:
            turnoff_allBoosterpackLED();
                turnOn_BoosterpackLEDBlue();
            break;
        case MAGENTA:
            turnoff_allBoosterpackLED();
                turnOn_BoosterpackLEDRed();
                turnOn_BoosterpackLEDBlue();
            break;
        case CYAN:
            turnoff_allBoosterpackLED();
                turnOn_BoosterpackLEDBlue();
                turnOn_BoosterpackLEDGreen();
            break;
        case WHITE:
            turnoff_allBoosterpackLED();
                turnOn_BoosterpackLEDBlue();
                turnOn_BoosterpackLEDGreen();
                turnOn_BoosterpackLEDRed();
            break;
        }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
    bool pressed;
    typedef enum {up, down} buttonstate;
    static buttonstate currentState = up;
    switch(currentState)
    {
    case up:
        if(buttonhistory & BIT0){  // at the moment that you press the button
            pressed = true;
        currentState = down;}
        else // at the moment you hold the button unpressed
        {
            pressed = false;
            currentState = up;
        }
        break;
    case down:
        if(buttonhistory & BIT0)
        {// at the moment when you keep pressing
            pressed = false;
            currentState = down;
        }
        else
        { // at the moment when you release the button
            pressed = false;
            currentState = up;
        }
        break;
    }
    return pressed;
}

