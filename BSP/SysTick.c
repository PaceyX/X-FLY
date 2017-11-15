#include "SysTick.h"



static __IO uint32_t uwTick;
static __IO uint32_t Timedelay;

/*******************************************************************************
*	SysTick_Init 配置了定时的时间，即想要数一次的时间，或者说机器周期
*	被配置后的始终周期，定时时间为 T = ticks * (1/F), 本处F 为168M
*	T = 168000 * (1 / 168000000) = 1 / 1000Hz = 1ms
*******************************************************************************/


void Bsp_SysTick_Init(void)
{
	/* Enable the SysTick interrupt per 1ms. */
	SysTick_Config(SystemCoreClock / 1000);		//168000000 / 1000 = 168000 * (1/168M) = 1ms
	
	/* Control Systick by register SysTick->CTRL */
//	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Mask;	//Disable the Systick interrupt.
	
}

/**
*	@brief	Get time, 1ms count.
*	@param	none
*	@retval	Get time stamp.
*/
uint32_t STD_GetTick(void)
{
	return uwTick;
}

static void STD_IncTick(void)
{
	uwTick++;
}	

/**
*	@brief	SysTick IRQ function
*	@param	none.
*	@retval none.
*/
void TimingDelay_Decrement(void)
{
	STD_IncTick();
	if(Timedelay != 0) 
	{
		Timedelay--;
	}
}

/** 
*	@brief	delay function.
*	@param	delay count num.
*	@retval none.
*/
void Delay_ms(uint32_t n)
{
	Timedelay = n;
	while(Timedelay != 0);
}

