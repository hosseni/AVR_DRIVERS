#include "PWM_TIMER_MODE_INIT.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilities.h"
void Timer_PWM_init(void)   {

	// prescalar 1024
	SET_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);

	// PWM mode
	SET_BIT(TCCR0, 3);
	SET_BIT(TCCR0, 6);

	// to select inverting mode
	CLR_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);

	// set pin 3 at portb as output
	Dio_SetPinDirection(GroupB, PIN3, OUTPUT);
}

void Timer_PWM_SetDuty(u8 Duty)  {
	OCR0 = Duty;
}
