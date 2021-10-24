#include "std_types.h"
#include "utilities.h"

#include "LED_INIT.h"

/// led 0
void LED0_Init()
{
	Dio_SetPinDirection(GroupC, PIN2, OUTPUT);
}

void LED0_ON()
{
	Dio_SetPinValue(GroupC, PIN2, HIGH);
}

void LED0_OFF()
{
	Dio_SetPinValue(GroupC, PIN2, LOW);

}

/// led 1
void LED1_Init()
{
	Dio_SetPinDirection(GroupC, PIN7, OUTPUT);
}

void LED1_ON()
{
	Dio_SetPinValue(GroupC, PIN7, HIGH);
}

void LED1_OFF()
{
	Dio_SetPinValue(GroupC, PIN7, LOW);
}

/// led 2
void LED2_Init()
{
	Dio_SetPinDirection(GroupD, PIN3, OUTPUT);
}

void LED2_ON()
{
	Dio_SetPinValue(GroupD, PIN3, HIGH);
}

void LED2_OFF()
{
	Dio_SetPinValue(GroupD, PIN3, LOW);

}

