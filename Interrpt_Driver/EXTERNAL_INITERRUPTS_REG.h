/*
 * EXTERNAL_INITERRUPTS_REG.h
 *
 *  Created on: Oct 1, 2021
 *      Author: ELKHOLY
 */

#ifndef INTER_REG
#define INTER_REG

#define MCUCR *((volatile u8 *)0x55)
#define MCUCSR *((volatile u8 *)0x54)
#define GICR *((volatile u8 *)0x5B)
#define GIFR *((volatile u8 *)0x5A)
#define SREG *((volatile u8 *)0x5f)


#endif



