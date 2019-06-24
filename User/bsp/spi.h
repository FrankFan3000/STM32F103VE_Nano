#ifndef _SPI1_H
#define _SPI1_H
 
#include "includes.h"


// CS   PC0
// CLK  PA5
// DO   PA6
// DIO  PA7



/* 设 置 数 据 传 输 顺 序 是 MSB位 在 前 还 是 LSB位 在 前 */
#define RT_SPI_LSB (0<<2) /* bit[2]: 0-LSB */

#define RT_SPI_MSB (1<<2) /* bit[2]: 1-MSB */
/* 设 置 SPI的 主 从 模 式 */
#define RT_SPI_MASTER (0<<3) /* SPI master device */
#define RT_SPI_SLAVE (1<<3) /* SPI slave device */
/* 设 置 时 钟 极 性 和 时 钟 相 位 */
#define RT_SPI_MODE_0 (0 | 0) /* CPOL = 0, CPHA = 0 */
#define RT_SPI_MODE_1 (0 | RT_SPI_CPHA) /* CPOL = 0, CPHA = 1 */
#define RT_SPI_MODE_2 (RT_SPI_CPOL | 0) /* CPOL = 1, CPHA = 0 */
#define RT_SPI_MODE_3 (RT_SPI_CPOL | RT_SPI_CPHA) /* CPOL = 1, CPHA = 1 */
#define RT_SPI_CS_HIGH (1<<4) /* Chipselect active high */
#define RT_SPI_NO_CS (1<<5) /* No chipselect */
#define RT_SPI_3WIRE (1<<6) /* SI/SO pin shared */
#define RT_SPI_READY (1<<7) /* Slave pulls low to pause */





void SPI_Initialize(void);
void rt_hw_adxl345_config(void);
uint8_t rt_hw_adxl345_run(void);
void SPI_Test(void);


#endif
