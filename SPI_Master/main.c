#include "Dio_Int.h"
#include "SPI_INIT.h"
#include "UART_INIT.h"
int main(int argc, char **argv) {

	SPI_INIT_MASTER();
	UART_INIT();
	Dio_SetPinDirection(GroupD, PIN6, INPUT);

	while (1) {

		if (Receive_Data() == 'A') {
			SPI_SEND_DATA(1);
		}
		if (Receive_Data() == 'B') {
			SPI_SEND_DATA(0);
		}

	}

}
