#include "includes.h"
#include "key.h"



volatile uint32_t Key_Tick = 0;



void Key_Initialize(void)
{
    rt_pin_mode(BUTTON1_PIN, PIN_MODE_INPUT);
    rt_pin_mode(BUTTON2_PIN, PIN_MODE_INPUT);
}


bool_t Button1_IsPressed(void)
{
    bool_t isPressed;
    if (rt_pin_read(BUTTON1_PIN) == PIN_LOW)
    {
        isPressed = false;
    }
    else
    {
        isPressed = true;
    }
    return isPressed;
}

bool_t Button2_IsPressed(void)
{
    bool_t isPressed;
    if (rt_pin_read(BUTTON2_PIN) == PIN_LOW)
    {
        isPressed = false;
    }
    else
    {
        isPressed = true;
    }
    return isPressed;
}



void Key_Task(void)
{
    if (0 == Button1_IsPressed())
    {
        LED_RED_OFF();
    }
    else
    {
        LED_RED_ON();
    }
    

    if (0 == Button2_IsPressed())
    {
        LED_GREEN_OFF();
    }
    else
    {
        LED_GREEN_ON();
    }

    
}



