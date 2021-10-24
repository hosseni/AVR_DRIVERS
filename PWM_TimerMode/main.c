#include "PWM_TIMER_MODE_INIT.h"
#include <avr/delay.h>

int main(int argc, char **argv) {

	Timer_PWM_init();

	while (1) {

		Timer_PWM_SetDuty(15);
		_delay_ms(3000);
		Timer_PWM_SetDuty(24);
		_delay_ms(3000);
		Timer_PWM_SetDuty(32);
		_delay_ms(3000);

	}
}
