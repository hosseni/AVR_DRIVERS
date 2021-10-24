#include "I2C_INIT.h"
#include "Dio_Int.h"
#include "Std_Types.h"
#include "Utilities.h"
#include "avr/delay.h"

int main(void) {

	I2C_Master_INIT();
	while (1) {

		I2C_Start_Condition();
		I2C_Send_Slave_Address_With_Read_Req(0x0c);
		I2C_Write_Data(0x33);
		I2C_Write_Data(0x44);
		I2C_Stop_Condition();
		_delay_ms(1000);
	}
}
