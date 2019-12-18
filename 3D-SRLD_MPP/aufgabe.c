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

void aufgabe_A01_1_2(void)
	{
	//Push/Pull - Pull Up	-> nicht sinnvoll, Pull-Widerstände nach PushPull zu verwenden
	//Push/Pull - No Pull   -> sinnvoll - bevorzugt, so können wir eine 0 oder eine 1 ausgeben!
	//OpenDrain - Pull Up	-> nicht sinnvoll, weil es dadurch zu einem Fehlverhalten des Systems kommen kann.
	//OpenDrain - No Pull	-> nicht sinvoll, kann keine 1 ausgeben
	}
*/
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
void init_taste_1_irq(void)
{
	// Hier ein Beispiel um die Portleitungen PC0 und PC3 als
		// Ausgänge im HighSpeed-Mode mit PullUp Widerständen
		// an der Taktquelle RCC_APB2Periph_GPIOC
		// zu programmieren:

		// Taktquelle für die Peripherie aktivieren
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

		// Schaltet Taktsystem zu
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

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


void init_taste_2_irq(void)
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

	// irq ready
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	// Die Freigabe des zugehörigen Interrupts sieht wie fogt aus:
	USART_ClearITPendingBit(USART2, USART_IT_RXNE);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

}
/*
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
*/
void usart_2_print(char* zeichenkette) {
    int i = 0;
    for(i = 0;i < strlen(zeichenkette);i++)
    {
        USART_SendData(USART2, zeichenkette[i]);
        while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET){}
    }
}
/*
void init_iwdg()
{
	// Schreibrechte aktivieren
	    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	// Wir nutzen Prescaler 64 und Reload 2500, um 5 Sekunden zu erreichen
	// den Vorteiler (4, 8 , 16 ,..., 256) setzen
	    IWDG_SetPrescaler(IWDG_Prescaler_64);
	// den Wert (0...4095) einstellen ab dem runtergezählt wird
	    IWDG_SetReload(2500);
	// setzt den Wachdog auf den eingestellten Maximalwert
	    IWDG_ReloadCounter();
	// aktiviert dem IWDG
	    IWDG_Enable();
	// Das Zeitintervall t berechnet sich folgendermaßen
	// t = (1/32000) * 16 * 2500 = 1,25 Sekunden
}
*/

/*
void init_interrupts() {
	//==========================================================
	//========= Interrupt Konfiguration
	//==========================================================
	// Taste 2
	// Bindet Port C Leitung 5 an die EXTI_Line5 Leitung
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource5);

	// Struct anlegen
	EXTI_InitTypeDef EXTI_InitStructure;

	// EXTI_Line zweisen
	EXTI_InitStructure.EXTI_Line = EXTI_Line5;

	// Interrupt Mode setzen
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
		// EXTI_Mode_Interrupt
		// EXTI_Mode_Event

	// Triggerbedingung setzen
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
		// EXTI_Trigger_Rising
		// EXTI_Trigger_Falling
		// EXTI_Trigger_Rising_Falling

	// Interrupt erlauben
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;

	// Regiser aus dem Struct heraus setzen
	EXTI_Init(&EXTI_InitStructure);


	// Taste 1
	// Bindet Port C Leitung 8 an die EXTI_Line8 Leitung
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource8);
	EXTI_InitStructure.EXTI_Line = EXTI_Line8;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

void init_nvic() {
	//==========================================================
	//========= Interruptcontroller Konfiguration
	//==========================================================

	// Anlegen eines NVIC Struct
	NVIC_InitTypeDef NVIC_InitStructure;

	// Festlegung der Interruptquelle
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;

	// Festlegung der Priorität entweder in 5 Gruppen
	//======================================================
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	    // NVIC_PriorityGroup_0 hohe Priorität
		// ...
	    // NVIC_PriorityGroup_4 niedrige Priorität
	//======================================================

	// oder feiner gegliedert in Priorität und Subpriorität
	//======================================================
	//NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	    // 0..15
	//NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	    // 0...15
	//======================================================

	// Interruptkanal Freigabe
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	// Register aus dem Struct heraus schreiben
	NVIC_Init(&NVIC_InitStructure);
}


void dateTimeFilter(char* buf) {
	if(strlen(buf) != 11) {
		usart_2_print("Wrong FORMAT! use xx-xx-xx-xx for Date or xx:xx:xx:xx for time.");
		return;
	}
	int isDate = -1; // 0 for Time und 1 for Date -1 for wrong format

	if(buf[2] == '-' && buf[5] == '-' && buf[8] == '-') {
		isDate = 1;
	}
	else if(buf[2] == ':' && buf[5] == ':' && buf[8] == ':') {
		isDate = 0;
	}
	else {
		usart_2_print("Wrong FORMAT! use xx-xx-xx-xx for Date or xx:xx:xx:xx for time.");
		return;
	}

	int numbers [4];
	char* numInStr [5];
	int c =0;
	int i;
	for (i = 0;  i < strlen(buf); i = i + 3) {
		if( buf[i] >= '0' && buf[i] <= '9' && buf[i+1] >= '0' && buf[i+1] <= '9' ){
			sprintf(numInStr, "%c%c\0", buf[i], buf[i+1]);
			numbers[c] = atoi(numInStr);
			//numbers[c] = strtol(numInStr, NULL, 16);
			c++;
		}
		else {
			usart_2_print("Wrong FORMAT! use xx-xx-xx-xx for Date or xx:xx:xx:xx for time.");
			return;
		}
	}


	if(isDate){
		// ToDo: Validate Date Values.

		RTC_DateTypeDef RTC_Date_Struct;

		RTC_Date_Struct.RTC_Year = numbers[0];
		RTC_Date_Struct.RTC_Month= numbers[1];
		//RTC_Date_Struct.RTC_Month= RTC_Month_August;
		RTC_Date_Struct.RTC_Date= numbers[2];
		RTC_Date_Struct.RTC_WeekDay= numbers[3];

		RTC_SetDate(RTC_Format_BIN, &RTC_Date_Struct);
	}
	else {
		// ToDo: Validate Time Values.


		RTC_TimeTypeDef RTC_Time_Struct;

		RTC_Time_Struct.RTC_Hours = numbers[0];
		RTC_Time_Struct.RTC_Minutes = numbers[1];
		RTC_Time_Struct.RTC_Seconds = numbers[2];
		RTC_Time_Struct.RTC_H12 = numbers[3];

		RTC_SetTime(RTC_Format_BIN, &RTC_Time_Struct);

	}
}*/

void initAlarm30(){
	RTC_AlarmCmd(RTC_Alarm_A, DISABLE);

	// Anlegen der Structs für aktuelle Daten
	RTC_TimeTypeDef RTC_Time_Aktuell; //  Zeit
	RTC_AlarmTypeDef RTC_Alarm_Aktuell; //  Alarm

	RTC_GetTime(RTC_Format_BIN, &RTC_Time_Aktuell);
	RTC_Alarm_Aktuell.RTC_AlarmTime.RTC_Hours = RTC_Time_Aktuell.RTC_Hours;
	RTC_Alarm_Aktuell.RTC_AlarmTime.RTC_Minutes = (RTC_Time_Aktuell.RTC_Minutes + 1) % 60;
	RTC_Alarm_Aktuell.RTC_AlarmTime.RTC_Seconds = 30;


	// Alarmmaske setzen kann auch verodert werden
	RTC_Alarm_Aktuell.RTC_AlarmMask = RTC_AlarmMask_DateWeekDay // Wochentag oder Tag ausgeblendet  
			| RTC_AlarmMask_Hours; // Stunde ausgeblendet   

	RTC_SetAlarm(RTC_Format_BIN, RTC_Alarm_A, &RTC_Alarm_Aktuell);

	// Anlegen der benötigten Structs
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	// EXTI-Line Konfiguration
	EXTI_ClearITPendingBit(EXTI_Line17);
	EXTI_InitStructure.EXTI_Line = EXTI_Line17;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	// NIVC Konfiguration
	NVIC_InitStructure.NVIC_IRQChannel = RTC_Alarm_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	// Konfigurieren des Alarm A
	RTC_ITConfig(RTC_IT_ALRA, ENABLE);

	// RTC Alarm A freigeben
	RTC_AlarmCmd(RTC_Alarm_A, ENABLE);

	// Alarmflag löschen
	RTC_ClearFlag(RTC_FLAG_ALRAF);


	}
//	// Alarm für den Tag oder Wochentag auswählen
//	RTC_Alarm_Struct.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_Date; // Tag (1-31)     
//	// Alarm Tag oder Wochentag setzen
//	RTC_Alarm_Struct.RTC_AlarmDateWeekDay = 0x01; // Tag 0x01...0x31


