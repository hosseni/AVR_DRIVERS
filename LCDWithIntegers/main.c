#include "LCD_INIT.h"
#include "Std_Types.h"
#include <stdio.h>
#include <avr/delay.h>
#include <avr/io.h>

#define Arr_Size 50

int main(int argc, char **argv)    {

	u8 arr[Arr_Size];
	u8 temp;
	for (int var = 0; var < Arr_Size; var++) {

		arr[var] = var;
	}

	LCD_INIT();

	LCD_WORD("interrupt");

	while (1) {

		for (int var = 0; var < Arr_Size; var++) {
			itoa(arr[var],temp,10);
			RowAndColume_SET(ROW1, COLUME0);
			LCD_WORD(temp);
			_delay_ms(400);
			CLEAR_LCD();

		}

	}
}

