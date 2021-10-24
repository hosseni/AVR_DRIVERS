/*
 * INTERRUPT_PROG.c
 *
 *  Created on: Oct 1, 2021
 *      Author: ELKHOLY
 */

#include "EXTERNAL_INTERRUPT_INIT.h"
#include "EXTERNAL_INITERRUPTS_REG.h"
#include "Utilities.h"
#include "Dio_Int.h"
#include "avr/interrupt.h"
void EXTERNAL_INTERRUPT_INIT() {

	SET_BIT(GICR, 6);  // set PIE = 1 : to enable interrupt 0

	SET_BIT(SREG, 7);   // set GIE = 1

	SET_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);  // rising

	Dio_SetPinDirection(GroupC, PIN2, OUTPUT);

}

ISR(INT0_vect) {

	CLR_BIT(SREG, 7); // to deny any interrupt occur during this interrupt
	TOGGLE_BIT(PORTC, 2);
	SET_BIT(SREG, 7); //
}

