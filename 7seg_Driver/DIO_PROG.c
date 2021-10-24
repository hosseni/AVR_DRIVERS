#include "Std_Types.h"
#include "Dio_REG.h"
#include "DIO_INIT.h"
#include "Utilities.h"

void Dio_SetPinDirection(u8 GroupNo, u8 PinNo, u8 Direction) {
	if (GroupNo <= GroupD && PinNo <= PIN7) {
		if (Direction == INPUT) {
			switch (GroupNo) {
			case GroupA:
				CLR_BIT(DDRA, PinNo);
				break;
			case GroupB:
				CLR_BIT(DDRB, PinNo);
				break;
			case GroupC:
				CLR_BIT(DDRC, PinNo);
				break;
			case GroupD:
				CLR_BIT(DDRD, PinNo);
				break;
			}
		}

		if (Direction == OUTPUT) {
			switch (GroupNo) {
			case GroupA:
				SET_BIT(DDRA, PinNo);
				break;
			case GroupB:
				SET_BIT(DDRB, PinNo);
				break;
			case GroupC:
				SET_BIT(DDRC, PinNo);
				break;
			case GroupD:
				SET_BIT(DDRD, PinNo);
				break;
			}
		}
	}

	else {

	}

}

void Dio_SetPinValue(u8 GroupNo, u8 PinNo, u8 Value)
 {
	if (Value == LOW) {
		switch (GroupNo) {
		case GroupA:
			CLR_BIT(PORTA, PinNo);
			break;
		case GroupB:
			CLR_BIT(PORTB, PinNo);
			break;
		case GroupC:
			CLR_BIT(PORTC, PinNo);
			break;
		case GroupD:
			CLR_BIT(PORTD, PinNo);
			break;
		}
	}

	if (Value == HIGH) {
		switch (GroupNo) {
		case GroupA:
			SET_BIT(PORTA, PinNo);
			break;
		case GroupB:
			SET_BIT(PORTB, PinNo);
			break;
		case GroupC:
			SET_BIT(PORTC, PinNo);
			break;
		case GroupD:
			SET_BIT(PORTD, PinNo);
			break;
		}
	}
}



u8 Dio_GetPinValue(u8 GroupNo, u8 PinNo) {
	u8 return_value;

	switch (GroupNo) {
	case GroupA:
		return_value = GET_BIT(PINA, PinNo);
		break;
	case GroupB:
		return_value = GET_BIT(PINB, PinNo);
		break;
	case GroupC:
		return_value = GET_BIT(PINC, PinNo);
		break;
	case GroupD:
		return_value = GET_BIT(PIND, PinNo);
		break;
	}

	return return_value;
}



