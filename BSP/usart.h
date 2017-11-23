#ifndef __USART_H__
#define __USART_H__


#include "includes.h"



/*******************************************************************************************/

#define USART1_BUFFERSIZE			100
#define USART1_DMAx_CLK				RCC_AHB1Periph_DMA1
#define USART1_TX_DMA_CHANNEL		DMA_Channel_0
#define USART1_RX_DMA_CHANNEL		DMA_Channel_1
#define USART1_TX_DMA_STREAM		DMA1_Stream7		
#define USART1_RX_DMA_STREAM		DMA1_Stream4
uint8_t USART1_aTxBuffer[USART1_BUFFERSIZE] = "sssssssssssssssssssss";
uint8_t USART1_aRxBuffer[USART1_BUFFERSIZE];




/*******************************************************************************************/



void USART1_Init(void);











#endif
