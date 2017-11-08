#include "rcc.h"

void Rcc_Config(void)
{
//	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_ClocksTypeDef RCC_ClockFreq;
	
	/* This function fills the RCC_ClockFreq structure with the current
	 frequencies of different on chip clocks (for debug purpose) **************/
	RCC_GetClocksFreq(&RCC_ClockFreq);
	
	/* Enable Clock Security System(CSS): this will generate an NMI exception
	 when HSE clock fails *****************************************************/
	RCC_ClockSecuritySystemCmd(ENABLE);
	
	/* Enable and configure RCC global IRQ channel, will be used to manage HSE ready 
	 and PLL ready interrupts. 
	 These interrupts are enabled in stm32f4xx_it.c file **********************/
	NVIC_InitStructure.NVIC_IRQChannel = RCC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
  
//   /* Output HSE clock on MCO1 pin(PA8) ****************************************/ 
//  /* Enable the GPIOA peripheral */ 
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
//  
//  /* Configure MCO1 pin(PA8) in alternate function */
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
//  GPIO_Init(GPIOA, &GPIO_InitStructure);
//    
//  /* HSE clock selected to output on MCO1 pin(PA8)*/
//  RCC_MCO1Config(RCC_MCO1Source_HSE, RCC_MCO1Div_1);
	
}

