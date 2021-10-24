#include "PWM_TIMER_MODE_INIT.h"
#include "ADC_REG.h"
#include "ADC_INT.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "Std_Types.h"
#include "Utilities.h"
#include <stdlib.h>
#include "Dio_Int.h"
#include "Dio_Reg.h"

int main(void) {

	u32 Digital_vlue, Analog_value;

	ADC_INIT();
	Timer_PWM_init();
	Dio_SetPinDirection(GroupB, PIN7, OUTPUT);
	while (1) {
		Dio_SetPinValue(GroupB, PIN7, HIGH);
		Digital_vlue = ADC_Read();

		Analog_value = ((Digital_vlue * 5 * 1000) / 1023);

		Timer_PWM_SetDuty(Analog_value/100 );

}
}
