#include "led.h"





void Led_Task(void)
{
	LED_Blue(ON);
	Delay_ms(100);
	LED_Blue(OFF);
	Delay_ms(100);
	LED_Green(ON);
	Delay_ms(100);
	LED_Green(OFF);
	Delay_ms(100);
	
}
