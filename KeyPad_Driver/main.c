/*
 * main.c
 *
 *  Created on: Sep 24, 2021
 *      Author: ELKHOLY
 */

#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "KeyPad_INIT.h"
#include "Utilities.h"
#include "Std_Types.h"
#include "LCD_INIT.h"
#include <avr/delay.h>
#include <avr/io.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	u8 retuenButton, temp;

	KeyPad_INIT();
	LCD_INIT();
	while (1) {
		RowAndColume_SET(ROW2, COLUME5);
		retuenButton = KeyPad_GetKey();
		if (retuenButton == 'A' || retuenButton == 'B' || retuenButton == 'C'
				|| retuenButton == 'D' || retuenButton == '*'
				|| retuenButton == '#') {
			if (KeyPad_GetKey() != 0xff)
				LCD_CHAR(retuenButton);
		} else {
			itoa(retuenButton, temp, 10);
			if (KeyPad_GetKey() != 0xff)
				LCD_WORD(temp);
		}
	}
}

