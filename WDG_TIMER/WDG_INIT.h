#ifndef WDG_INIT_H_
#define WDG_INIT_H_

#define MCUCSR *((volatile u8 *)0x54)
#define WDTCR *((volatile u8 *)0x41)

#include "Std_Types.h"

void WDG_INIT(void);
void WDG_Set(u16 time);

#endif
