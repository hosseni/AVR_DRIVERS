#include "SPI_INIT.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilities.h"
#include "Std_Types.h"
void SPI_INIT_MASTER(void) {

	// MOSI, CLK, CS as output
	Dio_SetPinDirection(GroupB, PIN4, OUTPUT); //CS
	Dio_SetPinDirection(GroupB, PIN5, OUTPUT); //MOSI
	Dio_SetPinDirection(GroupB, PIN7, OUTPUT); //CLK

	Dio_SetPinDirection(GroupB, PIN6, INPUT); // MISO input

	SET_BIT(SPCR, 4); // MASTER

	SET_BIT(SPCR, 6); //enable SPI

	CLR_BIT(SPCR, 3); // raising

}
void SPI_INIT_SLAVE(void) {
	// MOSI, CLK, CS as input
	Dio_SetPinDirection(GroupB, PIN4, INPUT); //CS
	Dio_SetPinDirection(GroupB, PIN5, INPUT); //MOSI
	Dio_SetPinDirection(GroupB, PIN7, INPUT); //CLK

	Dio_SetPinDirection(GroupB, PIN6, OUTPUT); // MISO input

	CLR_BIT(SPCR, 4); // SLAVE

	SET_BIT(SPCR, 6); //enable SPI

}

void SPI_SEND_DATA(u8 data) {

	SPDR = data;
	while ((GET_BIT(SPSR, 7)) == 0); // wait until sending

}
u8 SPI_RECIEVE_DATA(void) {

	while ((GET_BIT(SPSR, 6)) == 0) ; // wait until receiving
	return SPDR;
}
