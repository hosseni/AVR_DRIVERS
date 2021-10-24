#ifndef SPI_INIT_H_
#define SPI_INIT_H_

#define SPCR *((volatile u8 *)0x2D)
#define SPDR *((volatile u8 *)0x2F)
#define SPSR *((volatile u8 *)0x2E)

#include "Std_Types.h"

void SPI_INIT_MASTER(void);
void SPI_INIT_SLAVE(void);

void SPI_SEND_DATA(u8 data);
u8 SPI_RECIEVE_DATA(void);

#endif
