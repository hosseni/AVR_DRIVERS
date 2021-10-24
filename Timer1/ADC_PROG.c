#include "ADC_INT.h"
#include "ADC_REG.h"
#include "Utilities.h"
#include "Std_Types.h"

void ADC_INIT() {
	// select v reference
	// external capacitor at AREF pin
	SET_BIT(ADMUX, 6);
	CLR_BIT(ADMUX, 7);

	//right adjust
	CLR_BIT(ADMUX, 5);

	// channel 1
	SET_BIT(ADMUX, 0);
	CLR_BIT(ADMUX, 1);
	CLR_BIT(ADMUX, 2);
	CLR_BIT(ADMUX, 3);
	CLR_BIT(ADMUX, 4);
	//Enable ADC
	SET_BIT(ADCSRA, 7);

	//ADC prescaler 8
	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	CLR_BIT(ADCSRA, 2);

}

u16 ADC_Read(void) {

	u16 readValue = 0;

	// start conversion
	SET_BIT(ADCSRA, 6);

	// looping until conversion complete
	while ((GET_BIT(ADCSRA, 4)) == 0);

	SET_BIT(ADCSRA, 4); // to disable flag : set it bit

	readValue = (u16) ADCL;

	return ((ADCH << 8) | readValue);
}
