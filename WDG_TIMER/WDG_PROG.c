#include "WDG_INIT.h"
#include "Utilities.h"

void WDG_INIT(void)
{
	SET_BIT(WDTCR,3); //Enable WDG
}
void WDG_Set(u16 time)
{
	switch (time) {
	case 16 : CLR_BIT(WDTCR, 0); CLR_BIT(WDTCR, 1);  CLR_BIT(WDTCR, 2); break; // 16 ms WDG timer
	case 32 : SET_BIT(WDTCR, 0); CLR_BIT(WDTCR, 1);  CLR_BIT(WDTCR, 2); break; // 32 ms WDG timer
	case 65: CLR_BIT(WDTCR, 0); SET_BIT(WDTCR, 1);  CLR_BIT(WDTCR, 2); break; //  65 ms WDG timer
	case 130 : SET_BIT(WDTCR, 0); SET_BIT(WDTCR, 1);  CLR_BIT(WDTCR, 2); break; // 130 ms WDG timer
	case 260 : CLR_BIT(WDTCR, 0); CLR_BIT(WDTCR, 1);  SET_BIT(WDTCR, 2); break; // 260 ms WDG timer
	case 520 : SET_BIT(WDTCR, 0); CLR_BIT(WDTCR, 1);  SET_BIT(WDTCR, 2); break; // 520 ms WDG timer
	case 1000 : CLR_BIT(WDTCR, 0); SET_BIT(WDTCR, 1);  SET_BIT(WDTCR, 2); break; // 1000 ms WDG timer
	case 2100 : SET_BIT(WDTCR, 0); SET_BIT(WDTCR, 1);  SET_BIT(WDTCR, 2); break; // 2100 ms WDG timer
	}
}
