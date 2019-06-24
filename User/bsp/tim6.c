#include "includes.h"
#include "tim6.h"

#define HWTIMER_DEV_NAME    "timer6"
static rt_device_t hw_dev;


static rt_err_t timeout_cb(rt_device_t dev, rt_size_t size)
{
    rt_kprintf("this is hwtimer 6 timeout callback fucntion!\n");
    rt_kprintf("tick is :%d !\n", rt_tick_get());
    return 0;
}

void TIM6_Initialize(void)
{
    hw_dev = rt_device_find(HWTIMER_DEV_NAME);
    rt_device_open(hw_dev, RT_DEVICE_OFLAG_RDWR);
    rt_device_set_rx_indicate(hw_dev, timeout_cb);


    rt_uint32_t freq = 10000;
    rt_device_control(hw_dev, HWTIMER_CTRL_FREQ_SET, &freq);

    rt_hwtimer_mode_t mode = HWTIMER_MODE_PERIOD;
    rt_device_control(hw_dev, HWTIMER_CTRL_MODE_SET, &mode);

    rt_hwtimerval_t timeout_s;
    timeout_s.sec = 1;
    timeout_s.usec = 0;
    rt_device_write(hw_dev, 0, &timeout_s, sizeof(timeout_s));
}


