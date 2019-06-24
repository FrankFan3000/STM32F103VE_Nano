#include "includes.h"
#include "exti.h"


void EXTI_Initialize(void)
{
    //rt_pin_attach_irq(KEY0_PIN_NUM, PIN_IRQ_MODE_FALLING, beep_on, RT_NULL);

    rt_pin_mode(BUTTON2_PIN, PIN_MODE_INPUT);

    rt_pin_attach_irq(BUTTON2_PIN, PIN_IRQ_MODE_RISING, Button2_Callback, RT_NULL);
    rt_pin_irq_enable(BUTTON2_PIN, PIN_IRQ_ENABLE);
}



volatile uint32_t EXTI_Cnt = 0;

void Button2_Callback(void *args)
{
    rt_kprintf("EXTI_Cnt: %d\n", EXTI_Cnt++);

}

