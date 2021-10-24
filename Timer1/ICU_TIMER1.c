#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "ICU_TIMER1.h"
#include "Utilities.h"
void Timer_ICU_Init(void) {

	// normal mode
	CLR_BIT(TCCR1A, 4);
	CLR_BIT(TCCR1A, 5);
	CLR_BIT(TCCR1A, 6);
	CLR_BIT(TCCR1A, 7);

	// prescalar
	SET_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	SET_BIT(TCCR1B, 2);

}
