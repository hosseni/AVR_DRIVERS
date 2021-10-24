#ifndef PWM_INIT_H_
#define PWM_INIT_H_

#include "Std_Types.h"

#define TCCR1A *((volatile u8 *)0x4F)
#define TCCR1B *((volatile u8 *)0x4E)
#define TCNT1 *((volatile u16 *)0x4C)
#define TIMSK *((volatile u8 *)0x59)
#define OCR1B *((volatile u16 *)0x48)
#define ICR1 *((volatile u16 *)0x46) // casting ICRL + ICRH  as ICR1 (u16)
#define TIFR *((volatile u8 *)0x58)
#define OCR1A *((volatile u16 *)0x58)

void Timer1_PWM_Init(void);
void Timer1_PWM_SetDuty(u16 Duty);

#endif
