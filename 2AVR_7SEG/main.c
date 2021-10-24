#include "Std_Types.h"
#include "DIO.h"
#include  "Utilities.h"

#include  <avr/delay.h>

void main(void)  {

	// decoder input
	set_bit(DDRA, 4);
	set_bit(DDRA, 5);
	set_bit(DDRA, 6);
	set_bit(DDRA, 7);

	// transistor enable
	set_bit(DDRB, 1);
	set_bit(DDRB, 2);

	while (1) {
		U8 i, j;

		for (i = 0; i <= 20; i++) {

			for (j = 0; j < 50; j++) {

				//enable digit 1
				set_bit(PORTB, 2);
				clear_bit(PORTB, 1);
				PORTA = (i / 10) << 4;
				_delay_ms(10);

				// enable digit 2
				set_bit(PORTB, 1);
				clear_bit(PORTB, 2);
				PORTA = (i % 10) << 4;
				_delay_ms(10);

			}

		}
	}
}
