
#include "7Seg_INIT.h"
#include "KeyPad_INIT.h"

int main(int argc, char **argv) {
	KeyPad_INIT();
	SEVENSEG_INIT();
	u8 returnButton ;


	while(1)
	{
		u8 returnButton = KeyPad_GetKey();
		if (returnButton == 0xff);



			SEVENSEG_DISPLAY(returnButton);

	}
}
