#ifndef __SYS_FLAG__
#define __SYS_FLAG__


#include "includes.h"





typedef struct{
	u32 Ms1Cnt;
	u32 Ms3Cnt;
    u32 Ms4Cnt;
	u32 Ms20Cnt;
	u32 Ms80Cnt;
    u32 Ms100Cnt;
    u32 Ms250Cnt;
    u32 Ms500Cnt;
    u32 Ms1000Cnt;
    u8 Ms1;
	u8 Ms3;
    u8 Ms4;
    u8 Ms20;
	u8 Ms80;
    u8 Ms100;
    u8 Ms250;
    u8 Ms500;
    u8 Ms1000;
}SYSFlagType;
extern SYSFlagType RunFlag;

void RunFlagInit(void);
void RunFlagHandleTask(void);















#endif
