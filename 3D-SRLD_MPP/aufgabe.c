#include "aufgabe.h"




void aufgabe_A01_1_1(void)
{
//	// Push/Pull - NoPull
//	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;  //  Push/Pull Output Setting. P-MOS / N-MOS aktiv.
//	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_NOPULL; // Pull Up und Pull Down nicht aktiv
//	//Output wird von P-MOS oder N-MOS bestimmt
//	//und von PullUp oder PullDown nicht reguliert
//
//	// Push/Pull - PullUp
//	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;  //  Push/Pull Output Setting. P-MOS / N-MOS aktiv.
//	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;  // Pull up ist Aktiv, Pull Down nicht
//	//Output wird von P-MOS oder N-MOS bestimmt
//	//und von PullUp auf 1 reguliert, wenn nicht N-MOS angeschaltet ist (0 ausgibt)
//
//	// Push/Pull - PullDown
//	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;  //  Push/Pull Output Setting. P-MOS / N-MOS aktiv.
//	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_DOWN;  // Pull Down ist Aktiv, Pull Up nicht
//	//Output wird von P-MOS oder N-MOS bestimmt
//	//und von PullDown auf 0 reguliert, wenn nicht P-MOS angeschaltet ist (1 ausgibt)
//
//	// OpenDrain - NoPull
//	GPIO_InitStructure.GPIO_OType   = GPIO_OType_OD; // nur N-MOS wird genutzt, P-MOS nicht - bleibt immer offen
//	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_NOPULL; // Pull Up und Pull Down nicht aktiv
//	//Output wird nur von N-MOS bestimmt
//	//und von PullUp oder PullDown nicht reguliert
//
//	// OpenDrain - PullUp
//	GPIO_InitStructure.GPIO_OType   = GPIO_OType_OD; // nur N-MOS wird genutzt, P-MOS nicht - bleibt immer offen
//	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;  // Pull up ist Aktiv, Pull Down nicht
//	//Output wird nur von N-MOS bestimmt
//	//und von PullUp auf 1 reguliert, wenn P-MOS nicht angeschaltet ist (keine 0 ausgibt)
//
//	// OpenDrain - PullDown
//	GPIO_InitStructure.GPIO_OType   = GPIO_OType_OD; // nur N-MOS wird genutzt, P-MOS nicht - bleibt immer offen
//	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_DOWN;  // Pull Down ist Aktiv, Pull Up nicht
//	//Output wird nur von N-MOS bestimmt
//	//und von PullDown auf 0 reguliert, wenn N-MOS angeschaltet ist (keine 0 ausgibt) <- widerspricht sich
}

void aufgabe_A01_1_2(void)
	{
	//Push/Pull - Pull Up	-> nicht sinnvoll, Pull-Widerstände nach PushPull zu verwenden
	//Push/Pull - No Pull   -> sinnvoll - bevorzugt, weil ist so!
	//OpenDrain - Pull Up	-> sinnvoll
	//OpenDrain - No Pull	-> nicht sinvoll, kann keine 1 ausgeben
	}

// aufgabe_A01_1_3
void init_leds(void)
{
	// Taktquelle für die Peripherie aktivieren
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	// Struct anlegen
	GPIO_InitTypeDef GPIO_InitStructure;

	// Struct Initialisieren setzt alle Leitungen auf
	// Eingang ohne PushPull
	GPIO_StructInit(&GPIO_InitStructure);

	// Die Funktionalität der Portleitungen festlegen

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;

	GPIO_InitStructure.GPIO_Mode =
	    // Auswahl des I/O Mode
	    //  GPIO_Mode_IN;       //GPIO Input Mode
	      GPIO_Mode_OUT;        //GPIO Output Mode
	    //  GPIO_Mode_AF;       //GPIO Alternate function Mode
	    //  GPIO_Mode_AN;       //GPIO Analog Mode

	GPIO_InitStructure.GPIO_Speed =
	    // Auswahl der Speed
	        GPIO_Speed_2MHz;    //  Low speed
	    //  GPIO_Speed_25MHz;   //  Medium speed
	    //  GPIO_Speed_50MHz;   //  Fast speed
	    //  GPIO_Speed_100MHz;  //  High speed

	GPIO_InitStructure.GPIO_OType =
	    // Auswahl des Output Typs
	        GPIO_OType_PP;      //  PushPull
	    //  GPIO_OType_OD;      //  OpenDrain

	GPIO_InitStructure.GPIO_PuPd =
	    // Auswahl des Push/Pull Typs
	        GPIO_PuPd_NOPULL;   //  NoPull
	    //  GPIO_PuPd_UP;       //  PullUp
	    //  GPIO_PuPd_DOWN;     //  PullDown

	// PortLeitungen initialisieren
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//GPIO_ResetBits(GPIOB, GPIO_Pin_2);
}

// aufgabe_A01_2_2
void init_taste_1(void)
{
	// Hier ein Beispiel um die Portleitungen PC0 und PC3 als
		// Ausgänge im HighSpeed-Mode mit PullUp Widerständen
		// an der Taktquelle RCC_APB2Periph_GPIOC
		// zu programmieren:

		// Taktquelle für die Peripherie aktivieren
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

		// Struct anlegen
		GPIO_InitTypeDef GPIO_InitStructure;

		// Struct Initialisieren setzt alle Leitungen auf
		// Eingang ohne PushPull
		GPIO_StructInit(&GPIO_InitStructure);

		//Pin 5
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;

		// I/O-Typ soll hier Input sein
		GPIO_InitStructure.GPIO_Mode =
		    // Auswahl des I/O Mode
		      GPIO_Mode_IN;       //GPIO Input Mode
		    //  GPIO_Mode_OUT;        //GPIO Output Mode
		    //  GPIO_Mode_AF;       //GPIO Alternate function Mode
		    //  GPIO_Mode_AN;       //GPIO Analog Mode

		GPIO_InitStructure.GPIO_Speed =
		    // Auswahl der Speed
		    //  GPIO_Speed_2MHz;    //  Low speed
		      GPIO_Speed_25MHz;   //  Medium speed
		    //  GPIO_Speed_50MHz;   //  Fast speed
		    //   GPIO_Speed_100MHz;  //  High speed

		// Port als Input verwendet, keine Output-Konfiguration nötig
		GPIO_InitStructure.GPIO_OType =
		    // Auswahl des Output Typs
		       GPIO_OType_PP;      //  PushPull
		    //  GPIO_OType_OD;      //  OpenDrain

		GPIO_InitStructure.GPIO_PuPd =
		    // Auswahl des Push/Pull Typs
		      GPIO_PuPd_NOPULL;   //  NoPull
		    //  GPIO_PuPd_UP;       //  PullUp
		    //  GPIO_PuPd_DOWN;     //  PullDown

		// PortLeitungen initialisieren
		GPIO_Init(GPIOC, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);
}

void init_taste_2(void)
{
	// Hier ein Beispiel um die Portleitungen PC0 und PC3 als
	// Ausgänge im HighSpeed-Mode mit PullUp Widerständen
	// an der Taktquelle RCC_APB2Periph_GPIOC
	// zu programmieren:

	// Taktquelle für die Peripherie aktivieren
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	// Struct anlegen
	GPIO_InitTypeDef GPIO_InitStructure;

	// Struct Initialisieren setzt alle Leitungen auf
	// Eingang ohne PushPull
	GPIO_StructInit(&GPIO_InitStructure);

	//Pin 8
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;

	// I/O-Typ soll hier Input sein
	GPIO_InitStructure.GPIO_Mode =
	    // Auswahl des I/O Mode
	      GPIO_Mode_IN;       //GPIO Input Mode
	    //  GPIO_Mode_OUT;        //GPIO Output Mode
	    //  GPIO_Mode_AF;       //GPIO Alternate function Mode
	    //  GPIO_Mode_AN;       //GPIO Analog Mode

	GPIO_InitStructure.GPIO_Speed =
	    // Auswahl der Speed
	    //  GPIO_Speed_2MHz;    //  Low speed
	      GPIO_Speed_25MHz;   //  Medium speed
	    //  GPIO_Speed_50MHz;   //  Fast speed
	    //   GPIO_Speed_100MHz;  //  High speed

	// Port als Input verwendet, keine Output-Konfiguration nötig
	GPIO_InitStructure.GPIO_OType =
	    // Auswahl des Output Typs
	       GPIO_OType_PP;      //  PushPull
	    //  GPIO_OType_OD;      //  OpenDrain

	GPIO_InitStructure.GPIO_PuPd =
	    // Auswahl des Push/Pull Typs
	      GPIO_PuPd_NOPULL;   //  NoPull
	    //  GPIO_PuPd_UP;       //  PullUp
	    //  GPIO_PuPd_DOWN;     //  PullDown

	// PortLeitungen initialisieren
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
}
