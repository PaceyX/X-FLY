#ifndef  __INCLUDES_H__
#define  __INCLUDES_H__




#include "stm32f4xx.h" 


/*
************************************************************************************************************
*										C99 STD libraries												   *
************************************************************************************************************
*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
************************************************************************************************************
*											  APP														   *
************************************************************************************************************
*/
#include "led.h"



/*
************************************************************************************************************
*											BSP 														   *
************************************************************************************************************
*/
#include "gpio.h"
#include "rcc.h"

/*
************************************************************************************************************
*											  OS														   *
************************************************************************************************************
*/




/*
************************************************************************************************************
*											Priority			 NVIC_PriorityGroup_4				       *
************************************************************************************************************
*/
#define	NVIC_TIME2_P		0							/* 抢占优先级	*/
#define NVIC_TIME2_S		0							/* 响应优先级	*/

#define NVIC_USART1_P		1
#define NVIC_USART1_S		0

#define NVIC_USART2_P		2
#define NVIC_USART2_S		0

#define NVIC_USART3_P		3
#define NVIC_USART3_S		3

#define NVIC_USART5_P		4
#define NVIC_USART5_S		0 




#endif

