#ifndef _KEY_H
#define _KEY_H
 
#include "includes.h"


#define BUTTON1_PIN         (GET_PIN(A, 0))
#define BUTTON2_PIN         (GET_PIN(C, 13))


extern volatile uint32_t Key_Tick;
void Key_Initialize(void);
void Key_Task(void);



#endif
