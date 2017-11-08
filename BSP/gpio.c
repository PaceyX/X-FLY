#include "gpio.h"




void LED_BspInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(LED_RCC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = LED1_PIN | LED2_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;					//普通输出
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;					//普通推挽输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
	GPIO_Init(LED_GPIO, &GPIO_InitStructure);

}

