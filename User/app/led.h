#ifndef _LED_H
#define _LED_H
 
#include "includes.h"


//#define LED1_PIN            (GET_PIN(B, 10))
//#define LED1_ON()           {rt_pin_write(LED1_PIN, PIN_LOW);}
//#define LED1_OFF()          {rt_pin_write(LED1_PIN, PIN_HIGH);}
#define LED1_ON()           {HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);}
#define LED1_OFF()          {HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);}


#if 0
#define LED_RED_PIN         (GET_PIN(B, 5))
#define LED_GREEN_PIN       (GET_PIN(B, 0))
#define LED_BLUE_PIN        (GET_PIN(B, 1))

#define LED_RED_ON()        {rt_pin_write(LED_RED_PIN, PIN_LOW);}
#define LED_RED_OFF()       {rt_pin_write(LED_RED_PIN, PIN_HIGH);}
#define LED_GREEN_ON()      {rt_pin_write(LED_GREEN_PIN, PIN_LOW);}
#define LED_GREEN_OFF()     {rt_pin_write(LED_GREEN_PIN, PIN_HIGH);}
#define LED_BLUE_ON()       {rt_pin_write(LED_BLUE_PIN, PIN_LOW);}
#define LED_BLUE_OFF()      {rt_pin_write(LED_BLUE_PIN, PIN_HIGH);}
#endif


extern volatile uint32_t Led_Tick;
void Led_Initialize(void);
void Led_Task(void);




#endif
