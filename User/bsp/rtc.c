#include "includes.h"
#include "rtc.h"
#include <time.h>

void RTC_Initialize(void)
{
    set_date(2019, 6, 12);  // 年月日
    set_time(12, 1, 0);     // 时分秒
}


time_t time_now;
struct tm *ptm_now;
struct tm tm_now;
void RTC_Test(void)
{
    static uint32_t RTC_Tick = 0;

    if (900 == RTC_Tick)
    {
        time_now = time(RT_NULL);
        rt_kprintf("%d\n", time_now);
        rt_kprintf("%s", ctime(&time_now));

        ptm_now = localtime(&time_now);                 // 返回一个静态变量地址
        memcpy(&tm_now, ptm_now, sizeof(struct tm));    // 如果指针不会指向别处，可以不用复制到其他变量中
        rt_kprintf("%d,%d,%d,%d,%d,%d, %d,%d,%d\n\n", 
            tm_now.tm_year +1900,
            tm_now.tm_mon +1,
            tm_now.tm_mday,
            tm_now.tm_hour,
            tm_now.tm_min,
            tm_now.tm_sec,

            tm_now.tm_wday,
            tm_now.tm_yday,
            tm_now.tm_isdst
            );

        //free(ptm_now);
    }

    if (RTC_Tick < 1000 - 1)    // 1秒运行一次
    {
        RTC_Tick++;
    }
    else
    {
        RTC_Tick = 0;
    }
    
    
}
