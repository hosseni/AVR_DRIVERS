#include "LCD_INIT.h"


int main(int argc, char **argv) {
	LCD_INIT();

	while(1)
	{
		RowAndColume_SET(ROW1, COLUME3);
		LCD_WORD("temp");
	}

}
