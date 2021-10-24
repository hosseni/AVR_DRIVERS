#include "UART_INIT.h"
#include "Utilities.h"

void UART_INIT(void) {
// enable RX and TX
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);

	// a sync
	CLR_BIT(UCSRC, 6);

	// disable parity
	CLR_BIT(UCSRC, 4);
	CLR_BIT(UCSRC, 5);

	//stop bit  1
	CLR_BIT(UCSRC, 3);

	// 8 bit data
	SET_BIT(UCSRC, 1);
	SET_BIT(UCSRC, 2);
	CLR_BIT(UCSRB, 2);

	//baud rate at 16 MHZ 9600
	UBRRH = 0;
	UBRRL = 103;

}
void Send_Data(u8 data) {
	// wait for transmission
	//while(GET_BIT(UCSRA,5) == 0); bit 5 USART data register empty automatically cleared
	while (GET_BIT(UCSRA,6) == 0); // bit 6 not automatically cleared
	CLR_BIT(UCSRA, 6);
	UDR = data;
}
u8 Receive_Data(void) {
	// wait for receiving
	while (GET_BIT(UCSRA,7) == 0) ;
	return UDR;
}
