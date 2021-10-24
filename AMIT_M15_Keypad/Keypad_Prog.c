/*
 * Keypad_Prog.c
 *
 *  Created on: Sep 24, 2021
 *      Author: Mohamed
 */
#include "Std_Types.h"
#include "Dio_Int.h"

void Keypad_Init(void)
{
	//coloums outputs
	Dio_SetPinDirection(GroupC, PIN0, OUTPUT);
	Dio_SetPinDirection(GroupC, PIN1, OUTPUT);
	Dio_SetPinDirection(GroupC, PIN2, OUTPUT);
	//rows input
	Dio_SetPinDirection(GroupD, PIN0, INPUT);
	Dio_SetPinDirection(GroupD, PIN1, INPUT);
	Dio_SetPinDirection(GroupD, PIN2, INPUT);
	Dio_SetPinDirection(GroupD, PIN3, INPUT);
	//define rows as internal pull-up
	Dio_SetPinValue(GroupD, PIN0, HIGH);
	Dio_SetPinValue(GroupD, PIN1, HIGH);
	Dio_SetPinValue(GroupD, PIN2, HIGH);
	Dio_SetPinValue(GroupD, PIN3, HIGH);
}

u8 Keypad_GetKey(void)
{
	u8 Pressed_Key=0xff;
	//First Iteration
	Dio_SetPinValue(GroupC, PIN0, LOW);
	Dio_SetPinValue(GroupC, PIN1, HIGH);
	Dio_SetPinValue(GroupC, PIN2, HIGH);
	if(Dio_GetPinValue(GroupD, PIN0)==0)
		Pressed_Key = 1;
	if(Dio_GetPinValue(GroupD, PIN1)==0)
		Pressed_Key = 4;
	if(Dio_GetPinValue(GroupD, PIN2)==0)
		Pressed_Key = 7;
	if(Dio_GetPinValue(GroupD, PIN3)==0)
		Pressed_Key = '*';
	//Second Iteration
	Dio_SetPinValue(GroupC, PIN0, HIGH);
	Dio_SetPinValue(GroupC, PIN1, LOW);
	Dio_SetPinValue(GroupC, PIN2, HIGH);
	if(Dio_GetPinValue(GroupD, PIN0)==0)
		Pressed_Key = 2;
	if(Dio_GetPinValue(GroupD, PIN1)==0)
		Pressed_Key = 5;
	if(Dio_GetPinValue(GroupD, PIN2)==0)
		Pressed_Key = 8;
	if(Dio_GetPinValue(GroupD, PIN3)==0)
		Pressed_Key = 0;
	//Third Iteration
	Dio_SetPinValue(GroupC, PIN0, HIGH);
	Dio_SetPinValue(GroupC, PIN1, HIGH);
	Dio_SetPinValue(GroupC, PIN2, LOW);
	if(Dio_GetPinValue(GroupD, PIN0)==0)
		Pressed_Key = 3;
	if(Dio_GetPinValue(GroupD, PIN1)==0)
		Pressed_Key = 6;
	if(Dio_GetPinValue(GroupD, PIN2)==0)
		Pressed_Key = 9;
	if(Dio_GetPinValue(GroupD, PIN3)==0)
		Pressed_Key = '#';

return Pressed_Key;
}
