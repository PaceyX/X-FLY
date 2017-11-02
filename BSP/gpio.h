#ifndef __GPIO_H__
#define __GPIO_H__


#include "stm32f4xx.h" 

/*******************************************LED Config**************************************/
#define LED1_PIN		GPIO_Pin_3
#define LED2_PIN		GPIO_Pin_4

#define LED_GPIO		GPIOE

#define LED_RCC			RCC_AHB1Periph_GPIOE

/*******************************************************************************************/
void LED_BspInit(void);

#endif




