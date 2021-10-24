#include "Std_Types.h"
#include "DIO_INIT.h"
#include "DIO_REG.h"
#include "7Seg_INIT.h"
#include "Utilities.h"
#include "avr/delay.h"

int main() {

	u8 num = 12;

	SEVENSEG_INIT();
	Dio_SetPinDirection(GroupD, PIN6, INPUT); // button 1
	Dio_SetPinValue(GroupD, PIN6, LOW);
	Dio_SetPinDirection(GroupD, PIN2, INPUT);	//button 2
	Dio_SetPinValue(GroupD, PIN2, LOW);
	SEVENSEG_DISPLAY(num);

	while (1) {


		if ((Dio_GetPinValue(GroupD, PIN6)) == 1) {
			num ++;
			//SEVENSEG_DISPLAY(num);


		} if ((Dio_GetPinValue(GroupD, PIN2)) == 1) {
			num --;
			//SEVENSEG_DISPLAY(num);

		}
		SEVENSEG_DISPLAY(num);

	}
}
