#include "LCD_INIT.h"
#include "ADC_INT.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "Std_Types.h"
#include "Utilities.h"
#include <stdlib.h>

int main(void) {

	u32 Digital_vlue = 0, Analog_value = 0;
	u8 temperature[8];

	LCD_INIT();
	ADC_INIT();
	Dio_SetPinDirection(GroupA, PIN3, OUTPUT);

	RowAndColume_SET(ROW1, COLUME0);
	LCD_WORD("temperature:");

	while (1) {

		Digital_vlue = ADC_Read();

		Analog_value = ((Digital_vlue * 5 * 100) / 1023);

		itoa(Analog_value, temperature, 10);

		RowAndColume_SET(ROW1, COLUME13);
		LCD_WORD(temperature);
		_delay_ms(500);

		if ((Analog_value > 29) && (Analog_value < 31)) {
			Dio_SetPinValue(GroupA, PIN3, HIGH);
			_delay_ms(500);
			Dio_SetPinValue(GroupA, PIN3, LOW);
			_delay_ms(500);
		} else if ((Analog_value > 31) && (Analog_value < 33)) {
			Dio_SetPinValue(GroupA, PIN3, HIGH);
			_delay_ms(250);
			Dio_SetPinValue(GroupA, PIN3, LOW);
			_delay_ms(250);
		} else if ((Analog_value > 33) && (Analog_value < 35)) {
			Dio_SetPinValue(GroupA, PIN3, HIGH);
			_delay_ms(100);
			Dio_SetPinValue(GroupA, PIN3, LOW);
			_delay_ms(100);
		} else if ((Analog_value > 35)) {
			Dio_SetPinValue(GroupA, PIN3, HIGH);
		}

	}
}
