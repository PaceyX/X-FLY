
#include "stm32f4xx.h"
#include "includes.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t uwTimingDelay;

uint16_t data_send = 2;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	Rcc_Config();
	Bsp_GPIO_Init();
	Bsp_SysTick_Init();
	RunFlagInit();
	USART1_Init();
	
	Delay_ms(500);
	USART_SendData(USART1,data_send);
	/* Infinite loop */
	while (1)
	{
		RunFlagHandleTask();
		Led_Task();

	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
