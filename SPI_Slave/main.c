#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"
#include "Dio_Int.h"

#include <stdlib.h>

int main(void)
{

	SPI_INIT_SLAVE();

	LED0_Init();

	u8 charr = 0;

	while(1){

		charr = SPI_RECIVE_DATA();

		if(charr == 1){
			LED0_ON();
		}

		if(charr == 0){
			LED0_OFF();
		}

	}
}

