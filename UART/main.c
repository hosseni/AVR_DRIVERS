#include "Dio_Int.h"
#include "Led_INT.h"
#include "Utilities.h"
#include "UART_INIT.h"
#include <avr/delay.h>

int main(int argc, char **argv) {

	u8 test = 0;

	// UART initialization
	UART_INIT();

	LED0_INIT();

	Dio_SetPinDirection(GroupD, PIN6, OUTPUT);
	while (1) {
		/*
		 if (Dio_GetPinValue(GroupD, PIN6) == 1)
		 {
		 Send_Data(1);
		 }
		 if (Dio_GetPinValue(GroupD, PIN6) == 0)
		5{
		 Send_Data(0);
		 }
		 */
		test = Receive_Data();
		if (test == 'a') {
			LED_ON(LED0);
		}
		if (test == 'b') {
			LED_OFF(LED0);
		}

	}
}
