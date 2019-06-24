#ifndef _DEF_H
#define _DEF_H



//////// bool ////////
#define false   (0)
#define true    (!false)


//////// typedef ////////
typedef unsigned char   bool_t;
typedef unsigned char   uint8_t;
typedef signed char     int8_t;
typedef unsigned short  uint16_t;
typedef signed short    int16_t;
typedef unsigned long   uint32_t;
typedef signed long     int32_t;
typedef float           float32_t;
typedef double          float64_t;




//////// BIT ////////
#define BIT0    (1<<0u)
#define BIT1    (1<<1u)
#define BIT2    (1<<2u)
#define BIT3    (1<<3u)
#define BIT4    (1<<4u)
#define BIT5    (1<<5u)
#define BIT6    (1<<6u)
#define BIT7    (1<<7u)
#define BIT8    (1<<8u)
#define BIT9    (1<<9u)
#define BIT10   (1<<10u)
#define BIT11   (1<<11u)
#define BIT12   (1<<12u)
#define BIT13   (1<<13u)
#define BIT14   (1<<14u)
#define BIT15   (1<<15u)
#define BIT16   (1<<16u)
#define BIT17   (1<<17u)
#define BIT18   (1<<18u)
#define BIT19   (1<<19u)
#define BIT20   (1<<20u)
#define BIT21   (1<<21u)
#define BIT22   (1<<22u)
#define BIT23   (1<<23u)
#define BIT24   (1<<24u)
#define BIT25   (1<<25u)
#define BIT26   (1<<26u)
#define BIT27   (1<<27u)
#define BIT28   (1<<28u)
#define BIT29   (1<<29u)
#define BIT30   (1<<30u)
#define BIT31   (1<<31u)



//////// function ////////
// 修改寄存器的部分位
// reg	需要修改的寄存器
// pos	寄存器内需要修改的位
// val	需要的值
#define REG_BITS_WRITE(reg, msk, val)		{(reg) = ((reg) & (~(msk))) | (val);}



//////// union 小端模式 ////////
typedef union 
{
    uint8_t     u8[2];
    uint16_t    u16;
} union16_t;

typedef union 
{
    uint8_t     u8[4];
    uint16_t    u16[2];
    uint32_t    u32;
    float32_t   fp32;
} union32_t;

#endif

