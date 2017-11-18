#ifndef __LED_H__
#define __LED_H__

#include "includes.h"


#define ON		0
#define OFF		1

#define LED_Green(state)	if(state)	\
								GPIO_SetBits(LED_GPIO,LED1_PIN);\
							else	\
								GPIO_ResetBits(LED_GPIO,LED1_PIN)
							
#define LED_Blue(state)		if(state)	\
								GPIO_SetBits(LED_GPIO,LED2_PIN);\
							else	\
								GPIO_ResetBits(LED_GPIO,LED2_PIN)
								
#define LED_Toggle()


void Led_Task(void);
void Led_Toggle(void);






#endif
