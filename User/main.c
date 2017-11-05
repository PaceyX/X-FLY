
#include "stm32f4xx.h"
#include "gpio.h"
#include "led.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t uwTimingDelay;
RCC_ClocksTypeDef RCC_Clocks;



/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{

  
     
  /* Infinite loop */
  while (1)
  {
	  Led_Task();
  }
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
