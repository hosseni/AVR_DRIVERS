#ifndef UART_INIT_H_
#define UART_INIT_H_

#include "Std_Types.h"


#define UDR *((volatile u8 *)0x2C)
#define UCSRA *((volatile u8 *)0x2B)
#define UCSRB *((volatile u8 *)0x2A)
#define UCSRC *((volatile u8 *)0x40)
#define UBRRH *((volatile u8 *)0x40)
#define UBRRL *((volatile u8 *)0x29)

void UART_INIT(void);
void Send_Data(u8 data);
u8 Receive_Data (void);

#endif
