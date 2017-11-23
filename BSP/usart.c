#include "usart.h"


/**
*	@brief	Config usart1 peripheral.
*	@param	none.
*	@retval none.
*/
void USART1_Init(void)
{
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef  DMA_InitStructure;
	
	/* Peripheral Clock Enable -------------------------------------------------*/
	/* Enable GPIO clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOA, ENABLE);

	/* Enable USART clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* Enable the DMA clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);

	/* USARTx GPIO configuration -----------------------------------------------*/ 
	/* Connect USART pins to AF7 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

	/* Configure USART Tx and Rx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* USARTx configuration ----------------------------------------------------*/
	/* Enable the USART OverSampling by 8 */
	USART_OverSampling8Cmd(USART1, ENABLE); 

	/* USARTx configured as follows:
	- BaudRate = 5250000 baud
	   - Maximum BaudRate that can be achieved when using the Oversampling by 8
		 is: (USART APB Clock / 8) 
		 Example: 
			- (USART3 APB1 Clock / 8) = (42 MHz / 8) = 5250000 baud
			- (USART1 APB2 Clock / 8) = (84 MHz / 8) = 10500000 baud
	   - Maximum BaudRate that can be achieved when using the Oversampling by 16
		 is: (USART APB Clock / 16) 
		 Example: (USART3 APB1 Clock / 16) = (42 MHz / 16) = 2625000 baud
		 Example: (USART1 APB2 Clock / 16) = (84 MHz / 16) = 5250000 baud
	- Word Length = 8 Bits
	- one Stop Bit
	- No parity
	- Hardware flow control disabled (RTS and CTS signals)
	- Receive and transmit enabled
	*/ 
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	/* When using Parity the word length must be configured to 9 bits */
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);

	/* Configure DMA controller to manage USART TX and RX DMA request ----------*/ 

	/* Configure DMA Initialization Structure */
	DMA_InitStructure.DMA_BufferSize = USART1_BUFFERSIZE ;
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable ;
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull ;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single ;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_PeripheralBaseAddr =(uint32_t) (&(USART1->DR)) ;
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	/* Configure TX DMA */
	DMA_InitStructure.DMA_Channel = DMA_Channel_4 ;
	DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral ;
	DMA_InitStructure.DMA_Memory0BaseAddr =(uint32_t)USART1_aTxBuffer ;
	DMA_Init(DMA1_Stream0,&DMA_InitStructure);
	/* Configure RX DMA */
	DMA_InitStructure.DMA_Channel = DMA_Channel_4 ;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;
	DMA_InitStructure.DMA_Memory0BaseAddr =(uint32_t)USART1_aRxBuffer ; 
	DMA_Init(DMA1_Stream1,&DMA_InitStructure);
	 
	/* Enable USART */
	USART_Cmd(USART1, ENABLE);
}

