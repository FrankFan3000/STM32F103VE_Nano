#include "includes.h"



int main(void)
{
    Led_Initialize();
    //Key_Initialize();

    UART2_Initialize();
    

    //EXTI_Initialize();

    //TIM2_Initialize();
    //TIM3_Initialize();
    //TIM6_Initialize();
    //RTC_Initialize();


    rt_thread_mdelay(100);
    SPI_Initialize();
    rt_hw_adxl345_config();


    while (1)
    {
        rt_thread_mdelay(1);
        //
        //Led_Task();
        //Key_Task();



        //UART2_Test();
        //TIM3_Test();
        //RTC_Test();

        SPI_Test();
    }

}
