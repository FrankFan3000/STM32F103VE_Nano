#include "includes.h"
#include "led.h"



volatile uint32_t Led_Tick = 0;



void Led_Initialize(void)
{
    #if 0
    LED1_OFF();
    LED_RED_OFF();
    //LED_GREEN_OFF();
    //LED_BLUE_OFF();
    
    rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LED_RED_PIN, PIN_MODE_OUTPUT);
    //rt_pin_mode(LED_GREEN_PIN, PIN_MODE_OUTPUT);
    //rt_pin_mode(LED_BLUE_PIN, PIN_MODE_OUTPUT);
    #endif
}




void Led_Task(void)
{
    #if 0
    switch (Led_Tick)
    {
        case 0:
            LED_RED_ON();
            break;
        case 200:
            LED_RED_OFF();
            break;

        case 1000:
            LED_GREEN_ON();
            break;
        case 1200:
            LED_GREEN_OFF();
            break;

        case 2000:
            LED_BLUE_ON();
            break;
        case 2200:
            LED_BLUE_OFF();
            break;

        default:
            break;

    }


    if (Led_Tick < 3000 - 1)
    {
        Led_Tick++;
    }
    else
    {
        Led_Tick = 0;
    }
    #endif
    
}



