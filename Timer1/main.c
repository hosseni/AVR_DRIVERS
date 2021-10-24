#include "ADC_REG.h"
#include "ADC_INT.h"
#include "Dio_Int.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "Std_Types.h"
#include "Utilities.h"
#include "LCD_INIT.h"

#include <stdlib.h>

#include "ICU_TIMER1.h"
#define size 8
int main(void) {

	u32 T_on = 0, T_off = 0, freq = 0, period = 0, duty = 0;
	u8 freq_Assamble[size];
	u8 duty_assamble[size];

	// calling Input capture unit in
	Timer_ICU_Init();

	//LCD_INIT
	LCD_INIT();
	/*
	 // set pin pd6 as input
	 Dio_SetPinDirection(GroupD, PIN6, INPUT);*/

	RowAndColume_SET(ROW1, COLUME0);
	LCD_WORD("Freq : ");
	RowAndColume_SET(ROW2, COLUME0);
	LCD_WORD("Duty : ");

	while (1) {

		TCNT1 = 0;

		// start at rising
		SET_BIT(TCCR1B, 6);

		// wait until rising
		while ((GET_BIT(TIFR, 5)) == 0);

		// clear flag
		SET_BIT(TIFR,5);

		TCNT1 = 0;

		// start at falling
		CLR_BIT(TCCR1B, 6);

		// wait until rising
		while ((GET_BIT(TIFR, 5)) == 1);


		// capture value
		T_on = ICR1;


		// clear flag
		SET_BIT(TIFR,5);

		TCNT1 = 0;

		// start at rising
		SET_BIT(TCCR1B, 6);

		// wait until rising
		while ((GET_BIT(TIFR, 5)) == 0);

		T_off = ICR1;

		// clear flag
		SET_BIT(TIFR,5);

		TCNT1 = 0;

		period = T_on + T_off;
		freq = (16000000/1024) / period;

		duty = (T_on  / (T_on + T_off) ) *100;

		itoa(freq, freq_Assamble, 10);
		itoa(duty, duty_assamble, 10);


		RowAndColume_SET(ROW1, COLUME8);
		LCD_WORD(freq_Assamble);


		RowAndColume_SET(ROW2, COLUME8);
		LCD_WORD(duty_assamble);

	}
}
