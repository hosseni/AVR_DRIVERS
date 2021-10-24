#include "Std_Types.h"
#include "DIO.h"
#include "Utilities.h"
#include <AVR/delay.h>

int main()  {

	// set output pins
	set_bit(DDRC, 7);
	set_bit(DDRC, 2);
	set_bit(DDRD, 3);

	// set input pins
	clear_bit(DDRD, 6);
	clear_bit(DDRD, 2);

	U8 counter = 0;

	while (1) {

		if (((get_bit(PIND, 2)) == 1) && (counter++ < 7)) {

			while ((get_bit(PIND, 2)) == 1) {
				if ((get_bit(counter, 0)) == 1)
					set_bit(PORTC, 2);
				else
					clear_bit(PORTC, 2);

				if ((get_bit(counter, 1)) == 1)
					set_bit(PORTC, 7);
				else
					get_bit(PORTC, 7);

				if ((get_bit(counter, 2)) == 1)
					set_bit(PORTD, 3);
				else
					clear_bit(PORTD, 3);
			}

		}
		if ((get_bit(PIND,6) == 1) && counter-- > 0) {
			while ((get_bit(PIND, 6)) == 1) {
				if ((get_bit(counter, 0)) == 1)
					set_bit(PORTC, 2);
				else
					clear_bit(PORTC, 2);

				if ((get_bit(counter, 1)) == 1)
					set_bit(PORTC, 7);
				else
					get_bit(PORTC, 7);

				if ((get_bit(counter, 2)) == 1)
					set_bit(PORTD, 3);
				else
					clear_bit(PORTD, 3);

			}
		}
	}
	return 0;
}

