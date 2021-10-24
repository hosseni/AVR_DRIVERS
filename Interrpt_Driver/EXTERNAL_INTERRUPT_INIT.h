/*
 * INTERRUPT0_INIT.h
 *
 *  Created on: Oct 1, 2021
 *      Author: ELKHOLY
 */
#ifndef INT_INIT_H_
#define INT_INIT_H_

#include <avr/interrupt.h>

void EXTERNAL_INTERRUPT_INIT();
ISR(INT0_vect);

#endif
