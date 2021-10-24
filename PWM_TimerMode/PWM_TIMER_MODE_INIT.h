#ifndef PWM_INIT_H_
#define PWM_INIT_H_

#include "Std_Types.h"

#define SREG *((volatile u8 *)0x5f)
#define TCCR0 *((volatile u8 *)0x53)
#define TCNT0 *((volatile u8 *)0x52)
#define TIMSK *((volatile u8 *)0x59)
#define OCR0 *((volatile u8 *)0x5C)


void Timer_PWM_init(void);
void Timer_PWM_SetDuty(u8 Duty);

#endif
