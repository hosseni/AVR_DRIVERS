#include "Dio_Int.h"
#include "Led_INT.h"
#include "Dio_Reg.h"
#include "TIMER0_INIT.h"
#include "Utilities.h"
#include "avr/interrupt.h"

u16 counter = 0;

void Timer0_INIT(void)  {

	// enable global  interrupt
	SET_BIT(SREG, 7);

	// normal mode
	CLR_BIT(TCCR0, 3);
	CLR_BIT(TCCR0, 6);

	// prescaler 64
	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);

	// set init value for tcnt0
	TCNT0 = 250; // num of counts =m 256 - 250

	// PIE
	SET_BIT(TIMSK, 0);

	// led2
	LED2_INIT();
}

ISR( TIMER0_OVF_vect) {

	counter++;

	if (counter == 1) {
		counter = 0;
		TOGGLE_BIT(PORTD, PIN3);
		TCNT0 = 250;
	}
}
