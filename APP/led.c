#include "led.h"



void Led_Task(void)
{
//	LED_Blue(ON);
//	Delay_ms(100);
//	LED_Blue(OFF);
//	Delay_ms(100);
//	LED_Green(ON);
//	Delay_ms(100);
//	LED_Green(OFF);
//	Delay_ms(100);
	
	if(RunFlag.Ms500)
	{
		Led_Toggle();
	}
}

void Led_Toggle(void)
{
	LED_GPIO->ODR ^= GPIO_Pin_3;	
	LED_GPIO->ODR ^= GPIO_Pin_4;	
}
