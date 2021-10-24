/*
 * main.c
 *
 *  Created on: Sep 24, 2021
 *      Author: Mohamed
 */

#include "Std_Types.h"
#include "Keypad_Int.h"
#include "Dio_Reg.h"

void main(void)
{
	//initilization
	Keypad_Init();
	DDRA=0xFF;
	u8 var;

	while(1)
	{
		var=Keypad_GetKey();
		if(var!=0xff)
			PORTA=var;
	}
}
