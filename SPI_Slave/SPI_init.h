/*
 * SPI_init.h
 *
 *  Created on: Oct 22, 2021
 *      Author: Ammar
 */

#ifndef SPI_INIT_H_
#define SPI_INIT_H_

#include "std_types.h"
#include "utilities.h"
#include "DIO_Reg.h"
#include "Dio_Int.h"

#define SPCR *((volatile u8 *)0x2D)
#define SPSR *((volatile u8 *)0x2E)
#define SPDR *((volatile u8 *)0x2F)


void SPI_INIT_MASTER(void);

void SPI_INIT_SLAVE(void);

void SPI_SEND_DATA(u8 data);

u8 SPI_RECIVE_DATA(void);

#endif /* SPI_INIT_H_ */
