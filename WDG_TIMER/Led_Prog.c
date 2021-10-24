/*
 * Led_Prog.c
 *
 *  Created on: Sep 18, 2021
 *      Author: ELKHOLY
 */
#include "Std_Types.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilities.h"
#include  "Led_INT.h"

void LED0_INIT() {
	Dio_SetPinDirection(GroupC, PIN2, OUTPUT);
}
void LED1_INIT() {
	Dio_SetPinDirection(GroupC, PIN7, OUTPUT);
}
void LED2_INIT() {
	Dio_SetPinDirection(GroupD, PIN3, OUTPUT);
}

void LED_ON(u8 LedNo) {

	switch (LedNo) {
	case LED0:
		Dio_SetPinValue(GroupC, PIN2, HIGH);
		break;
	case LED1:
		Dio_SetPinValue(GroupC, PIN7, HIGH);
		break;
	case LED2:
		Dio_SetPinValue(GroupD, PIN3, HIGH);
		break;
	}

}
void LED_OFF(u8 LedNo) {
	switch (LedNo) {
	case LED0:
		Dio_SetPinValue(GroupC, PIN2, LOW);
		break;
	case LED1:
		Dio_SetPinValue(GroupC, PIN7, LOW);
		break;
	case LED2:
		Dio_SetPinValue(GroupD, PIN3, LOW);
		break;
	}

}
void toggle_led(u8 LedNo) {
	switch (LedNo) {
	case LED0:
		TOGGLE_BIT(PORTC, 2);
		break;
	case LED1:
		TOGGLE_BIT(PORTC, 7);
		break;
	case LED2:
		TOGGLE_BIT(PORTD, 7);
		break;
	}

}
