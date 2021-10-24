#include "Dio_Int.h"
#include "Std_Types.h"
#include "Utilities.h"
#include "Led_INT.h"
#include "WDG_INIT.h"
#include <avr/delay.h>

int main(int argc, char **argv) {

	LED0_INIT();

	while (1) {

		LED_ON(LED0);
		_delay_ms(100);
		LED_OFF(LED0);

		WDG_INIT(); //WDG INIT
		WDG_Set(2100); // WDG : 2.1 second

		while (1) {

		}
	}
}

