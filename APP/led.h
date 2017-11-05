#ifndef __LED_H__
#define __LED_H__



#include "stm32f4xx.h"
#include "gpio.h"


#define ON		0
#define OFF		1

#define LED_Red(state)		if(state)	\
								GPIO_SetBits(LED_GPIO,LED1_PIN);\
							else	\
								GPIO_ResetBits(LED_GPIO,LED1_PIN)
							
#define LED_Green(state)	if(state)	\
								GPIO_SetBits(LED_GPIO,LED2_PIN);\
							else	\
								GPIO_ResetBits(LED_GPIO,LED2_PIN)
								



void Led_Task(void);







#endif
