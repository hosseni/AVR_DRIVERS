/*
 * main.c
 *
 *  Created on: Sep 24, 2021
 *      Author: ELKHOLY
 */

#include "Std_Types.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Led_INT.h"
#include "Utilities.h"
#include "avr/delay.h"

int main(int argc, char **argv) {
	LED0_INIT();
	while (1) {
		LED0_ON(LED0);

	}
}
