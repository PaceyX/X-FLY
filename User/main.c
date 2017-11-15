
#include "stm32f4xx.h"
#include "includes.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t uwTimingDelay;



/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	Rcc_Config();
	LED_BspInit();

	/* Infinite loop */
	while (1)
	{
		Led_Task();
	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
