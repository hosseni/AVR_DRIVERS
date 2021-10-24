/*
 * main.c
 *
 *  Created on: Sep 25, 2021
 *      Author: Mohamed
 */
#include "Std_Types.h"
#include "LCD_Int.h"

void main(void)
{
	LCD_Init();
	//write on first row address 0
	LCD_WriteCommad(0x80);
	LCD_WriteData('M');
	LCD_WriteData('o');
	LCD_WriteData('h');
	LCD_WriteData('a');
	LCD_WriteData('M');
	LCD_WriteData('e');
	LCD_WriteData('d');
	//write on Second row address 0
	LCD_WriteCommad(0xC0);
	LCD_WriteData('A');
	LCD_WriteData('b');
	LCD_WriteData('d');
	LCD_WriteData('e');
	LCD_WriteData('l');
	LCD_WriteData('l');
	LCD_WriteData('a');
	LCD_WriteData('t');
	LCD_WriteData('i');
	LCD_WriteData('f');
	while(1)
	{

	}
}
