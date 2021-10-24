#include "Std_Types.h"
#include "LCD_INIT.h"
#include "Dio_Int.h"
#include "Utilities.h"
#include <avr/delay.h>
#include <stdio.h>
#define ArraySize 50
int main(int argc, char **argv) {

	LCD_INIT();
	u8 RowNo = ROW1;
	u8 ColumeNo = COLUME0;

	u8 *ptr = "Hello";


	while (1) {


		while (RowNo == ROW1 && ColumeNo <= COLUME15) {

			RowAndColume_SET(RowNo, ColumeNo);
			LCD_WORD(ptr);
			_delay_ms(250);
			CLEAR_LCD();
			ColumeNo++;

		}

		RowNo = ROW2;
		ColumeNo = COLUME0;

		while (RowNo == ROW2 && ColumeNo <= COLUME15) {
			RowAndColume_SET(RowNo, ColumeNo);
			LCD_WORD(ptr);
			_delay_ms(250);
			CLEAR_LCD();
			ColumeNo++;

		}

		RowNo = ROW1;
		ColumeNo = COLUME0;
	}

}

