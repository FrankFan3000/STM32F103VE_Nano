#include "includes.h"
#include "tim3.h"



struct rt_device_pwm *pwm_dev;


#define TIM3_PWM_TOP    (1000)

void TIM3_Initialize(void)
{
    pwm_dev = (struct rt_device_pwm *)rt_device_find("pwm3");

    rt_pwm_set(pwm_dev, 3, TIM3_PWM_TOP, TIM3_PWM_TOP);
    rt_pwm_set(pwm_dev, 4, TIM3_PWM_TOP, TIM3_PWM_TOP);

    rt_pwm_enable(pwm_dev, 3);
    rt_pwm_enable(pwm_dev, 4);
}



void TIM3_Test(void)
{
    static uint16_t TIM3_Tick = 0;

    switch (TIM3_Tick % 1000)
    {
        case 0:
        case 300:
            LED1_ON();
            break;

        case 100:
        case 400:
            LED1_OFF();
            break;

        default:
            break;
    }



    if (TIM3_Tick <= 2000)
    {
        if ((TIM3_Tick == 0) || (TIM3_Tick == 500) || (TIM3_Tick == 1000) || (TIM3_Tick == 1500))
        {
            LED_RED_ON();
        }
        else if ((TIM3_Tick == 100) || (TIM3_Tick == 600) || (TIM3_Tick == 1100) || (TIM3_Tick == 1600))
        {
            LED_RED_OFF();
        }
    }
    else
    {
        LED_RED_OFF();
    }
    


    if (TIM3_Tick <= 2000)
    {
        rt_pwm_set(pwm_dev, 3, TIM3_PWM_TOP, TIM3_PWM_TOP);
    }
    else if (TIM3_Tick <= 3000) // 2000~3000
    {
        rt_pwm_set(pwm_dev, 3, TIM3_PWM_TOP, 3000 - TIM3_Tick);
    }
    else if (TIM3_Tick <= 4000) // 3000~4000
    {
        rt_pwm_set(pwm_dev, 3, TIM3_PWM_TOP, TIM3_Tick - 3000);
    }
    else
    {
        rt_pwm_set(pwm_dev, 3, TIM3_PWM_TOP, TIM3_PWM_TOP);
    }
    


    if (TIM3_Tick <= 4000)
    {
        rt_pwm_set(pwm_dev, 4, TIM3_PWM_TOP, TIM3_PWM_TOP);
    }
    else if (TIM3_Tick <= 5000) // 4000~5000
    {
        rt_pwm_set(pwm_dev, 4, TIM3_PWM_TOP, 5000 - TIM3_Tick);
    }
    else                        // 5000~6000
    {
        rt_pwm_set(pwm_dev, 4, TIM3_PWM_TOP, TIM3_Tick - 5000);
    }
    


    if (TIM3_Tick < 6000 - 1)
    {
        TIM3_Tick++;
    }
    else
    {
        TIM3_Tick = 0;
    }
    
}

