#include "aufgabe.h"


/*

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
*/
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
/*
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

void init_PC09(void) {
	// SYSCLK-Clocksignal direkt auf Pin PC9 ausgeben:
	// struct anlegen
	GPIO_InitTypeDef GPIO_InitStructure;
	// schalte GPIOC clock an
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	// setze PIN auf PIN 9
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	// setze PIN operation mode auf alternate function mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	// setze output type auf PushPull
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	// setze PullUp/PullDown auf PullUp
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	// setze geschwindigkeit des pins auf 50 MHz, da ein Pin immer eine Betriebsgeschwindigkeit haben muss
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// initialisiere GPIOC mit soeben getroffenen Konfigurationen
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	// mappe die alternative funktion 'microcontroller clock output' auf GPIOC pin 9
	GPIO_PinAFConfig(GPIOC,GPIO_Pin_9,GPIO_AF_MCO);
	// set clock source to systemclock and do not prescale it again
	RCC_MCO2Config(RCC_MCO2Source_SYSCLK,RCC_MCO2Div_1);

}

// PLLStartUp Hilfsfunktion
void RCC_WaitForPLLStartUp(void) {
    while ( (RCC->CR & RCC_CR_PLLRDY) == 0 ) {
        __NOP();
    }
}


//==== Taktfrequenz 16MHz ohne HSE-OSC
void defaultMode() {
    RCC_DeInit();
}

//==== Taktfrequenz 24MHz mit HSE-OSC=16MHz
void slowMode(void) {
    RCC_DeInit();

    RCC_HSEConfig(RCC_HSE_ON);
    if (RCC_WaitForHSEStartUp() == ERROR) {
        return;
    }
    // HSEOSC=16MHz SYSCLK=24MHz HCLK=24MHz
    // PCLK1=24 PCLK2=24MHz
    RCC_PLLConfig(RCC_PLLSource_HSE,    //RCC_PLLSource
                                16,     //PLLM
                                192,    //PLLN
                                8,      //PLLP
                                4       //PLLQ
                                );
    RCC_PLLCmd(ENABLE);
    RCC_WaitForPLLStartUp();

    // Configures the AHB clock (HCLK)
    RCC_HCLKConfig(RCC_SYSCLK_Div1);
    // Low Speed APB clock (PCLK1)
    RCC_PCLK1Config(RCC_HCLK_Div1);
    // High Speed APB clock (PCLK2)
    RCC_PCLK2Config(RCC_HCLK_Div1);

    // select system clock source
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

    LED_GR_ON;
    wait_mSek(1000);
    LED_GR_OFF;
}


//==== Taktfrequenz 168MHz mit HSE-OSC=16MHz
void fastMode(void) {
    RCC_DeInit();

    RCC_HSEConfig(RCC_HSE_ON);
    if (RCC_WaitForHSEStartUp() == ERROR) {
        return;
    }
    // HSEOSC=16MHz SYSCLK=168MHz HCLK=168MHz
    // PCLK1=42MHz PCLK2=84MHz
    RCC_PLLConfig(RCC_PLLSource_HSE,    //RCC_PLLSource
                                16,     //PLLM
                                336,    //PLLN
                                2,      //PLLP
                                7       //PLLQ
                                );
    RCC_PLLCmd(ENABLE);
    RCC_WaitForPLLStartUp();

    // Configures the AHB clock (HCLK)
    RCC_HCLKConfig(RCC_SYSCLK_Div1);
    // High Speed APB clock (PCLK1)
    RCC_PCLK1Config(RCC_HCLK_Div4);
    // High Speed APB clock (PCLK2)
    RCC_PCLK2Config(RCC_HCLK_Div2);


    // select system clock source
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

    LED_GR_ON;
    wait_mSek(1000);
    LED_GR_OFF;
}
*/

void init_usart_2() {
	// Struct Anlegen
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	// Taktsystem für die USART2 freigeben
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);


	// GPIO Port A Taktsystem freigeben
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	// USART2 TX an PA2 mit Alternativfunktion Konfigurieren
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// USART2 TX mit PA2 verbinden
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

	// Datenprotokoll der USART einstellen
	USART_InitStructure.USART_BaudRate = 921600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init(USART2, &USART_InitStructure);

	// USART2 freigeben
	USART_Cmd(USART2, ENABLE); // enable USART2

	// Falls ein DMA Transfer genutzt werden soll muß hier das
	// DMA Interface aktiviert werden
	USART_DMACmd(USART6, USART_DMAReq_Tx, ENABLE);
}

void init_usart_2_tx() {
	// Struct Anlegen
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	// Taktsystem für die USART2 freigeben
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);


	// GPIO Port A Taktsystem freigeben
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	// USART2 TX an PA2 mit Alternativfunktion Konfigurieren
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// USART2 TX mit PA2 verbinden
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);

	// Datenprotokoll der USART einstellen
	USART_InitStructure.USART_BaudRate = 921600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure);

	// USART2 freigeben
	USART_Cmd(USART2, ENABLE); // enable USART2

	// Falls ein DMA Transfer genutzt werden soll muß hier das
	// DMA Interface aktiviert werden
	USART_DMACmd(USART6, USART_DMAReq_Tx, ENABLE);
}
void usart2_send_test(char* chars)
{
    int i = 0;
    for(i = 0;i < strlen(chars);i++)
    {
        USART_SendData(USART2, chars[i]);
        wait_mSek(1000);
        while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET){}
    }
}

void usart_2_print(char* zeichenkette) {
    int i = 0;
    for(i = 0;i < strlen(zeichenkette);i++)
    {
        USART_SendData(USART2, zeichenkette[i]);
        while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET){}
    }
}
