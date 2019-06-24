#include "includes.h"
#include "spi.h"



struct stm32_hw_spi_cs2
{
    rt_uint32_t pin;
};

static struct rt_spi_device spi_dev_adxl345;
static struct stm32_hw_spi_cs2 spi_cs;
#define SPI_BUS_NAME   "spi1"
#define SPI_ADXL_DEVICE_NAME "spi10"
#define CS_PIN  (GET_PIN(C, 0))    //54


void SPI_Initialize(void)
{
	rt_err_t res;
	
	spi_cs.pin = CS_PIN;
	rt_pin_mode(spi_cs.pin,PIN_MODE_OUTPUT);
	
	res = rt_spi_bus_attach_device(&spi_dev_adxl345,SPI_ADXL_DEVICE_NAME,SPI_BUS_NAME,(void*)&spi_cs);
	if (res != RT_EOK)
	{
		rt_kprintf("rt_spi_bus_attach_device!\r\n");
	}
}




void rt_hw_adxl345_config(void)
{
	struct rt_spi_configuration cfg;
	cfg.data_width = 8;
	cfg.mode = RT_SPI_MASTER |RT_SPI_MODE_3 | RT_SPI_MSB;
	cfg.max_hz = 100*1000;
	
	rt_spi_configure(&spi_dev_adxl345,&cfg);
}

uint8_t redata;
uint16_t readdatax;
uint16_t readdatay;
uint16_t readdataz;
uint8_t rt_hw_adxl345_run(void)
{
	rt_size_t len;
	uint8_t cmd = 0x31;
	uint8_t cmd2 = 0x02;
	
	//len = rt_spi_send(&spi_dev_adxl345,&cmd,1);
	
	//cmd = 0x02;
	//len = rt_spi_send(&spi_dev_adxl345,&cmd,1);

	
	len = rt_spi_send_then_send(&spi_dev_adxl345,&cmd,1,&cmd2,1);
	
	cmd = 0xB1;
	//len = rt_spi_send(&spi_dev_adxl345,&cmd,1);
	
	cmd2 = 0x02;
	
	//len = rt_spi_recv(&spi_dev_adxl345,&redata,1);
	
	len = rt_spi_send_then_recv(&spi_dev_adxl345,&cmd,1,&redata,1);
	
	rt_kprintf("0xB1: %d\n", redata);
	
	cmd = 0x2D;
	cmd2 = 0x08;
	len = rt_spi_send_then_send(&spi_dev_adxl345,&cmd,1,&cmd2,1);
	
	cmd = 0x80;
	
	len = rt_spi_send_then_recv(&spi_dev_adxl345,&cmd,1,&redata,1);
	
	rt_kprintf("0x00: %d\n", redata);
	
	/**********/
	cmd = 0xb2;
	
	len = rt_spi_send_then_recv(&spi_dev_adxl345,&cmd,1,&readdatax,2);
	
	rt_kprintf("0x32: %d\n", readdatax);
	/*
	cmd = 0xb3;
	
	len = rt_spi_send_then_recv(&spi_dev_adxl345,&cmd,1,&redata,1);
	
	rt_kprintf("0x33: %d\n", redata);
	*/
	cmd = 0xb4;
	
	len = rt_spi_send_then_recv(&spi_dev_adxl345,&cmd,1,&readdatay,2);
	
	rt_kprintf("0x34: %d\n", readdatay);
	/*
	cmd = 0xb5;
	
	len = rt_spi_send_then_recv(&spi_dev_adxl345,&cmd,1,&redata,1);
	
	rt_kprintf("0x35: %d\n", redata);
	
	*/
	cmd = 0xb6;
	
	len = rt_spi_send_then_recv(&spi_dev_adxl345,&cmd,1,&readdataz,1);
	
	rt_kprintf("0x36: %d\n", readdataz);
	/*
	cmd = 0xb7;
	
	len = rt_spi_send_then_recv(&spi_dev_adxl345,&cmd,1,&redata,1);
	
	rt_kprintf("0x37: %d\n", redata);
	*/
	/*
	cmd = 0xC1;
	
	len = rt_spi_send(&spi_dev_adxl345,&cmd,1);

	len = rt_spi_recv(&spi_dev_adxl345,&redata,1);
	rt_kprintf("spi, redata: %d", redata);
	
	cmd = 0x80;
	
	len = rt_spi_send(&spi_dev_adxl345,&cmd,1);

	len = rt_spi_recv(&spi_dev_adxl345,&redata,1);
	rt_kprintf("spi, redata: %d", redata);
	*/
	//r_spi_recv
	
	if(len != 0)
	{
		rt_kprintf("rt_hw_adxl345_run error!\r\n");
		rt_kprintf("errot:  %d\n", len);
		return -RT_ERROR;
	}
	else
	{
		return RT_EOK;
	}
}



void SPI_Test(void)
{
    static uint16_t SPI_Tick = 0;

    SPI_Tick++;
    if (SPI_Tick >= 1000)
    {
        SPI_Tick = 0;
        //
        rt_kprintf("SPI_Test:\r\n");
        rt_hw_adxl345_run();
    }
    
}


