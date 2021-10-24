#include "PWM_TIMER1.h"

#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilities.h"
void Timer1_PWM_Init(void) {

	// prescalar 1024
	SET_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	SET_BIT(TCCR1B, 2);
	// PWM mode
	CLR_BIT(TCCR1A, 4);
	CLR_BIT(TCCR1A, 6);
	SET_BIT(TCCR1A, 5);
	SET_BIT(TCCR1A, 7);
	// to select inverting mode

	SET_BIT(TCCR1A, 3);
	SET_BIT(TCCR1A, 4);

	// set pin
	Dio_SetPinDirection(GroupD, PIN7, OUTPUT);

}

void Timer1_PWM_SetDuty(u16 Duty) {
	OCR1A = Duty;
	OCR1B = Duty;
}

