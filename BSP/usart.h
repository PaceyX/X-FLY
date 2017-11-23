#ifndef __USART_H__
#define __USART_H__


#include "includes.h"



/*******************************************************************************************/

#define USART1_BUFFERSIZE			100
#define USART1_DMAx_CLK				RCC_AHB1Periph_DMA2
#define USART1_TX_DMA_CHANNEL		DMA_Channel_4
#define USART1_RX_DMA_CHANNEL		DMA_Channel_4
#define USART1_TX_DMA_STREAM		DMA2_Stream7		
#define USART1_RX_DMA_STREAM		DMA2_Stream4
extern uint8_t USART1_aTxBuffer[USART1_BUFFERSIZE];




/*******************************************************************************************/



void USART1_Init(void);











#endif
