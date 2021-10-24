#include "I2C_INIT.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilities.h"

void I2C_Master_INIT(void) {

	// set CLK rate
	TWBR = 0X0c;

	SET_BIT(TWCR, 2); // Enable I2C
}
void I2C_Slave_INIT(void) {
	TWAR = 0x06;
	SET_BIT(TWCR, 2); // Enable I2C

}

void I2C_Start_Condition(void) {

	SET_BIT(TWCR, 7); // added
	SET_BIT(TWCR, 2); // Enable I2C
	SET_BIT(TWCR, 5); // start I2C

	while ((GET_BIT(TWCR, 7)) == 0); // wait until CLK is Low
	while ((TWDR & 0xf8) != 0x08); // check start status

}
void I2C_Stop_Condition(void) {

	SET_BIT(TWCR, 4); // Enable stop bit

}
void I2C_Repeat_Start(void) {

	SET_BIT(TWCR, 7); // added
	SET_BIT(TWCR, 2); // Enable I2C
	SET_BIT(TWCR, 5); // start I2C

	while ((GET_BIT(TWCR, 7)) == 0); // wait until CLK is Low
	while ((TWDR & 0xf8) != 0x10); // check repeated start status

}

void I2C_Send_Slave_Address_With_Write_Req(u8 Slave_Address) {

	TWAR = Slave_Address;
	CLR_BIT(TWAR, 0);

	SET_BIT(TWCR, 7); // added
	SET_BIT(TWCR, 2); // Enable I2C
	SET_BIT(TWCR, 5); // start I2C

	while ((GET_BIT(TWCR, 7)) == 0); // wait until CLK is Low
	while ((TWDR & 0xf8) != 0x18); // check ACK status
	SET_BIT(TWCR, 7);

}
void I2C_Send_Slave_Address_With_Read_Req(u8 Slave_Address) {
	SET_BIT(TWCR, 7); // added
	SET_BIT(TWCR, 2); // Enable I2C
	SET_BIT(TWCR, 5); // start I2C

	TWAR = Slave_Address;
	SET_BIT(TWAR, 0);
	while ((GET_BIT(TWCR, 7)) == 0); // wait until CLK is Low
	while ((TWDR & 0xf8) != 0x40); // check ACK status
}

void I2C_Write_Data(u8 data) {

	TWDR = data;
	while ((GET_BIT(TWCR, 7)) == 0); // wait until CLK is Low
	while ((TWDR & 0xf8) != 0x28); // check ACK status

}
u8 I2C_Read_Data(void) {

	while ((TWDR & 0xf8) != 0x58); // check ACK status

	return TWDR;
}
