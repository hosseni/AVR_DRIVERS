/*
 * LCD_Prog.c
 *
 *  Created on: Sep 25, 2021
 *      Author: Mohamed
 */
#include "Std_Types.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "avr/delay.h"

void LCD_Init(void)
{
	//Define Rs, Rw, En pins output
	Dio_SetPinDirection(GroupB, PIN1, OUTPUT);//RS
	Dio_SetPinDirection(GroupB, PIN2, OUTPUT);//RW
	Dio_SetPinDirection(GroupB, PIN3, OUTPUT);//EN
	//Define Data pins output
	Dio_SetPinDirection(GroupA, PIN4, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN5, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN6, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN7, OUTPUT);
	_delay_ms(50);
	LCD_WriteCommad(0x02);
	LCD_WriteCommad(0x2C);
	_delay_ms(1);
	LCD_WriteCommad(0x0C);
	_delay_ms(1);
	LCD_WriteCommad(0x01);
	_delay_ms(1);
	LCD_WriteCommad(0x06);
}
void LCD_WriteCommad(u8 Command)
{
	Dio_SetPinValue(GroupB, PIN1, LOW);//RS command
	Dio_SetPinValue(GroupB, PIN2, LOW);//RW write
	PORTA = (PORTA & 0x0F)|(Command & 0xF0);
	Dio_SetPinValue(GroupB, PIN3, HIGH);//EN High
	_delay_ms(2);
	Dio_SetPinValue(GroupB, PIN3, LOW);//EN LOW

	PORTA = (PORTA & 0x0F)|(Command<<4);
	Dio_SetPinValue(GroupB, PIN3, HIGH);//EN High
	_delay_ms(2);
	Dio_SetPinValue(GroupB, PIN3, LOW);//EN LOW
}
void LCD_WriteData(u8 Data)
{
	Dio_SetPinValue(GroupB, PIN1, HIGH);//RS Data
	Dio_SetPinValue(GroupB, PIN2, LOW);//RW write
	PORTA = (PORTA & 0x0F)|(Data & 0xF0);
	Dio_SetPinValue(GroupB, PIN3, HIGH);//EN High
	_delay_ms(2);
	Dio_SetPinValue(GroupB, PIN3, LOW);//EN LOW

	PORTA = (PORTA & 0x0F)|(Data<<4);
	Dio_SetPinValue(GroupB, PIN3, HIGH);//EN High
	_delay_ms(2);
	Dio_SetPinValue(GroupB, PIN3, LOW);//EN LOW
}
