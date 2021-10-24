
#include "Dio_Int.h"
#include "Dio_Reg.h"


#ifndef Led_INIT
#define Led_INIT


void LED0_INIT ();
void LED1_INIT ();
void LED2_INIT ();
void LED_ON (u8 LedNo);
void LED_OFF (u8 LedNo);
void toggle_led(u8 LedNo);

#endif

