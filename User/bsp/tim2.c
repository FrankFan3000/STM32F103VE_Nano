#include "includes.h"
#include "tim2.h"

#define HWTIMER_DEV_NAME    "timer2"
static rt_device_t hw_dev;


static uint32_t TIM2_Cnt = 0;
rt_err_t TIM2_Callback(rt_device_t dev, rt_size_t size)
{
    rt_kprintf("hwtimer 2: %d, %d\n", TIM2_Cnt++, rt_tick_get());
    return 0;
}

void TIM2_Initialize(void)
{
    hw_dev = rt_device_find(HWTIMER_DEV_NAME);
    rt_device_open(hw_dev, RT_DEVICE_OFLAG_RDWR);
    rt_device_set_rx_indicate(hw_dev, TIM2_Callback);


    rt_uint32_t freq = 10000;
    rt_device_control(hw_dev, HWTIMER_CTRL_FREQ_SET, &freq);

    rt_hwtimer_mode_t mode = HWTIMER_MODE_PERIOD;
    rt_device_control(hw_dev, HWTIMER_CTRL_MODE_SET, &mode);

    rt_hwtimerval_t timeout_s;
    timeout_s.sec = 2;
    timeout_s.usec = 0;
    rt_device_write(hw_dev, 0, &timeout_s, sizeof(timeout_s));
}


