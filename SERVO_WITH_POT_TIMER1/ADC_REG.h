#ifndef ADC_REG
#define ADC_REG

#define GICR *((volatile u8 *)0x5B)
#define GIFR *((volatile u8 *)0x5A)
#define SREG *((volatile u8 *)0x5f)
#define ADMUX *((volatile u8 *)0x27)
#define ADCSRA *((volatile u8 *)0x26)
#define ADCH *((volatile u8 *)0x25)
#define ADCL *((volatile u8 *)0x24)




#endif
