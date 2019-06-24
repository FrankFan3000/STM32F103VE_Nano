#include "includes.h"
#include "user.h"

void User_Initialize(void)
{
    Led_Initialize();
}

void User_Loop(void)
{
    rt_thread_delay(1);
    Led_Task();
}




