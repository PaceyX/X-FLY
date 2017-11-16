#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "includes.h"



void Bsp_SysTick_Init(void);
uint32_t STD_GetTick(void);
void TimingDelay_Decrement(void);
void Delay_ms(uint32_t n);

















#endif

