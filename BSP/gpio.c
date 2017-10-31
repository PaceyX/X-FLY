#include "gpio.h"




void LED_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(LED_RCC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = LED_RED_PIN | LED_GREEN_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;					//普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;					//推挽输出模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
	GPIO_Init(LED_GPIO, &GPIO_InitStructure);

}

