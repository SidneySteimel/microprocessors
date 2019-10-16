#include "aufgabe.h"




void aufgabe_A01_1_1(void)
{
	int i = 0;
	char out[20] = {0};


	// Push/Pull - NoPull
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;  //  Push/Pull Output Setting. P-MOS / N-MOS aktiv.
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_NOPULL; // Pull Up und Pull Down nicht aktiv



	// Push/Pull - PullUp
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;  //  Push/Pull Output Setting. P-MOS / N-MOS aktiv.
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;  // Pull up ist Aktiv, Pull Down nicht

	// Push/Pull - PullDown
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;  //  Push/Pull Output Setting. P-MOS / N-MOS aktiv.
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_DOWN;  // Pull Down ist Aktiv, Pull Up nicht

	// OpenDrain - NoPull
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_OD; // Analoge Signale/Spannung
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_NOPULL; // Pull Up und Pull Down nicht aktiv

	// OpenDrain - PullUp
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_OD; // Analoge Signale/Spannung
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;  // Pull up ist Aktiv, Pull Down nicht

	// OpenDrain - PullDown
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_OD; // Analoge Signale/Spannung
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_DOWN;  // Pull Down ist Aktiv, Pull Up nicht


	while(1)
	{
		i++;
		sprintf(out,"i=%d\r\n",i);
		usart2_send(out);
		if ( i>9){ i=0;}
		wait_mSek(500);
	}
}
