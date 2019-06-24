#include "includes.h"
#include "uart2.h"


const char Ascii_Num[] = "0123456789ABCDEF";


#define SAMPLE_UART_NAME        "uart2"
static rt_device_t serial;

char str1[] = "Hello RT-Thread 1";
char str2[] = "Hello RT-Thread 2";

static rt_err_t UART2_Tx_Callback(rt_device_t dev, void *buffer)
{
    rt_kprintf("UART2 Tx Success!\n", 2);
    return RT_EOK;
}

static rt_err_t UART2_Rx_Callback(rt_device_t dev, rt_size_t size)
{
    rt_kprintf("%d", size);

    char ch;
    rt_device_read(serial, -1, &ch, 1);
    rt_kprintf("%c", ch);
    return RT_EOK;
}


void UART2_Initialize(void)
{
    serial = rt_device_find(SAMPLE_UART_NAME);
    rt_device_open(serial, RT_DEVICE_FLAG_INT_TX | RT_DEVICE_FLAG_INT_RX);
    //rt_device_open(serial, RT_DEVICE_FLAG_INT_TX | RT_DEVICE_FLAG_DMA_RX);
    //rt_device_open(serial, RT_DEVICE_FLAG_DMA_TX | RT_DEVICE_FLAG_DMA_RX);

    rt_device_set_tx_complete(serial, UART2_Tx_Callback);
    rt_device_set_rx_indicate(serial, UART2_Rx_Callback);
}





volatile uint16_t UART2_Cnt = 0;
void UART2_Test(void)
{
    static uint32_t UART2_Tick = 0;
    

    switch (UART2_Tick)
    {
        case 0:
            //rt_kprintf("UART2: %d\r\n", UART2_Cnt++);
            rt_device_write(serial, 0, str1, (sizeof(str1) - 1));
            rt_device_write(serial, 0, str2, (sizeof(str1) - 1));
            break;

        case 1000:
            rt_device_write(serial, 0, Ascii_Num, (sizeof(Ascii_Num) - 1));
            break;

        default:
            break;
    }


    if (UART2_Tick < 2000 - 1)
    {
        UART2_Tick++;
    }
    else
    {
        UART2_Tick = 0;
    }
    
}



