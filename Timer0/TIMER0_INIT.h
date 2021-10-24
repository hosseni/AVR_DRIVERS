#ifndef TIMER0_INIT_T
#define TIMER0_INIT_T

#define SREG *((volatile u8 *)0x5f)
#define TCCR0 *((volatile u8 *)0x53)
#define TCNT0 *((volatile u8 *)0x52)
#define TIMSK *((volatile u8 *)0x59)


void Timer0_INIT(void);

#endif
