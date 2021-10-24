#include "ADC_REG.h"
#include "ADC_INT.h"
#include "Dio_Int.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "Std_Types.h"
#include "Utilities.h"

#include <stdlib.h>

#include "PWM_TIMER1.h"
int main(void) {

	u32 Digital_vlue, Analog_value;

	ADC_INIT();
	Timer1_PWM_Init();

	while (1) {

		Digital_vlue = ADC_Read();

		Analog_value = ((Digital_vlue * 5 * 1000) / 1023);

		Timer1_PWM_SetDuty(512);
	}

}
