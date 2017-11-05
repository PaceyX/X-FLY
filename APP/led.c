#include "led.h"





void Led_Task(void)
{
//	LED_Red(ON);
//	LED_Green(OFF);
	GPIO_ResetBits(LED_GPIO,LED1_PIN);
	
}
