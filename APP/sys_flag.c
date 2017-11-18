#include "sys_flag.h"


static u8 PriorityFlag;
static u32 RunTick;
SYSFlagType RunFlag;

#define SYS_RUN_FLAG(time)	do{\
	RunFlag.Ms##time = 0;	\
	RunFlag.Ms##time##Cnt = tick;	\
}while(0)

#define TIME_FLAG(time)		TimeCalc(time, &(RunFlag.Ms##time),&(RunFlag.Ms##time##Cnt))
void TimeCalc(u32 time_factor, u8 * p_flag, u32 * p_cnt)
{
	if(!PriorityFlag && RunTick - *p_cnt >= time_factor)
	{
		*p_flag = 1;
		*p_cnt += time_factor;
		PriorityFlag = 1;
	}
	else
	{
		*p_flag = 0;
	}
}

void RunFlagInit(void)
{
	u32 tick = STD_GetTick();			//Get current time.
	
	SYS_RUN_FLAG(1);			//init value.
	SYS_RUN_FLAG(3);
	SYS_RUN_FLAG(4);
	SYS_RUN_FLAG(20);
	SYS_RUN_FLAG(80);
	SYS_RUN_FLAG(100);
	SYS_RUN_FLAG(250);
	SYS_RUN_FLAG(500);
	SYS_RUN_FLAG(1000);
}

void RunFlagHandleTask(void)
{
	PriorityFlag = 0;
	RunTick = STD_GetTick();
	
	TIME_FLAG(1);
	TIME_FLAG(3);
	TIME_FLAG(4);
	TIME_FLAG(20);
	TIME_FLAG(80);
	TIME_FLAG(100);
	TIME_FLAG(250);
	TIME_FLAG(500);
	TIME_FLAG(1000);
}
