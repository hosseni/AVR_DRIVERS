/*
 * Dio_Int.h
 *
 *  Created on: Sep 18, 2021
 *      Author: Mohamed
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "Std_Types.h"

#define GroupA 0
#define GroupB 1
#define GroupC 2
#define GroupD 3
// pins of ports in AVR
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// leds on Kit
#define LED0 0
#define LED1 1
#define LED2 2

//rows of lcd
#define ROW1 1
#define ROW2 2

// columes of lcd
#define COLUME0 0
#define COLUME1 1
#define COLUME2 2
#define COLUME3 3
#define COLUME4 4
#define COLUME5 5
#define COLUME6 6
#define COLUME7 7
#define COLUME8 8
#define COLUME9 9
#define COLUME10 10
#define COLUME11 11
#define COLUME12 12
#define COLUME13 13
#define COLUME14 14
#define COLUME15 15

// pins state
#define INPUT 0
#define OUTPUT 1

// output state
#define HIGH 1
#define LOW 0

// bitwise operation
void Dio_SetPinDirection(u8 GroupNo, u8 PinNo, u8 Direction);
void Dio_SetPinValue(u8 GroupNo, u8 PinNo, u8 Value);
u8 Dio_GetPinValue(u8 GroupNo, u8 PinNo);
u8 Dio_TogglePin(u8 GroupNo, u8 PinNo);

#endif /* DIO_INT_H_ */
