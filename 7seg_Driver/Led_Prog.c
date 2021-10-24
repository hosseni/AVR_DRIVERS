/*
 * Led_Prog.c
 *
 *  Created on: Sep 18, 2021
 *      Author: ELKHOLY
 */
#include "Std_Types.h"
#include "DIO_INIT.h"
#include "DIO_REG.h"
#include "Led_INIT.h"
#include "Utilities.h"

void LED0_INIT() {
	Dio_SetPinDirection(GroupC, PIN2, OUTPUT);
}
void LED1_INIT() {
	Dio_SetPinDirection(GroupC, PIN7, OUTPUT);
}
void LED2_INIT() {
	Dio_SetPinDirection(GroupD, PIN3, OUTPUT);
}
void LED0_ON() {
	Dio_SetPinValue(GroupC, PIN2, HIGH);
}
void LED0_OFF() {
	Dio_SetPinValue(GroupC, PIN2, LOW);

}
void LED1_ON() {
	Dio_SetPinValue(GroupC, PIN7, HIGH);
}
void LED1_OFF() {
	Dio_SetPinValue(GroupC, PIN7, LOW);

}
void LED2_ON() {
	Dio_SetPinValue(GroupD, PIN3, HIGH);
}
void LED2_OFF() {
	Dio_SetPinValue(GroupD, PIN3, LOW);

}

