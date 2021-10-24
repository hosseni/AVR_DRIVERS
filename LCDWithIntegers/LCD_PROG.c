/*
 * LCD_PROG.c
 *
 *  Created on: Sep 25, 2021
 *      Author: ELKHOLY
 */
#ifndef LCD_PROG
#define LCD_PROG

#include "Std_Types.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "LCD_INIT.h"
#include "avr/delay.h"

void LCD_INIT(void)  {
	// set RS, RW, EN
	Dio_SetPinDirection(GroupB, PIN1, OUTPUT);	// RS
	Dio_SetPinDirection(GroupB, PIN2, OUTPUT);	// RW
	Dio_SetPinDirection(GroupB, PIN3, OUTPUT);	// EN

	// set pin data
	Dio_SetPinDirection(GroupA, PIN4, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN5, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN6, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN7, OUTPUT);

	//function set
	_delay_ms(40);

	LCD_COMMAND(0x02); // high
	LCD_COMMAND(0x0B); //

	//display on/off
	_delay_us(40);

	LCD_COMMAND(0x00);
	LCD_COMMAND(0x0B);

	//display clear
	_delay_us(40);

	LCD_COMMAND(0x00);
	LCD_COMMAND(0x01);

	//Enter mode set
	_delay_ms(2);

	LCD_COMMAND(0x00);
	LCD_COMMAND(0x06);

}

void LCD_COMMAND(u8 cmd) {

	Dio_SetPinValue(GroupB, PIN2, LOW); // RW = 0 to write command
	Dio_SetPinValue(GroupB, PIN1, LOW); // RS = 0 to set command

	PORTA = (PORTA & 0x0f) | (cmd & 0xf0);

	Dio_SetPinValue(GroupB, PIN3, HIGH); // EN = 1 to Enable LCD

	_delay_ms(2);

	Dio_SetPinValue(GroupB, PIN3, LOW); // EN = 0 to disable LCD

	PORTA = (PORTA & 0x0f) | (cmd << 4);
	Dio_SetPinValue(GroupB, PIN3, HIGH); // EN = 1 to Enable LCD

	_delay_ms(2);

	Dio_SetPinValue(GroupB, PIN3, LOW); // EN = 0 to disable LCD

}

void LCD_CHAR(u8 data) {

	Dio_SetPinValue(GroupB, PIN1, LOW); // RW = 0 to write data
	Dio_SetPinValue(GroupB, PIN1, HIGH); // RS = 1 to set data

	PORTA = (PORTA & 0x0f) | (data & 0xf0);

	Dio_SetPinValue(GroupB, PIN3, HIGH); // EN = 1 to Enable LCD

	_delay_ms(2);

	Dio_SetPinValue(GroupB, PIN3, LOW); // EN = 0 to disable LCD

	PORTA = (PORTA & 0x0f) | (data << 4);
	Dio_SetPinValue(GroupB, PIN3, HIGH); // EN = 1 to Enable LCD

	_delay_ms(2);

	Dio_SetPinValue(GroupB, PIN3, LOW); // EN = 0 to disable LCD

}

void LCD_WORD(u8 * ptr) {
	u8 i = 0;

	while (ptr[i] != 0) {
		LCD_CHAR(ptr[i++]);

	}
}

void CLEAR_LCD(void) {

	LCD_COMMAND(0x00);
	LCD_COMMAND(0x01);
}

void RowAndColume_SET(u8 RowNo, u8 ColumeNo) {
u8 Location;
if (RowNo == ROW1)
{
	Location = 0x80;
}
else if (RowNo == ROW2)
{
	Location = 0xc0;
}
Location += ColumeNo;

LCD_COMMAND(Location);

}


#endif
