#include "aufgabe.h"

void aufgabe_A01_1_1(void) {
	usart2_init();
	int i = 0;
	char out[20] = { 0 };

	while (1) {
		i++;
		sprintf(out, "i=%d\r\n", i);
		usart2_send(out);
		if (i > 9) {
			i = 0;
		}
		wait_mSek(500);
	}
}

void init_taste_2(void) {
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
			GPIO_Mode_IN; //GPIO Input Mode
	//  GPIO_Mode_OUT;        //GPIO Output Mode
	//  GPIO_Mode_AF;       //GPIO Alternate function Mode
	//  GPIO_Mode_AN;       //GPIO Analog Mode

	GPIO_InitStructure.GPIO_Speed =
	// Auswahl der Speed
	//  GPIO_Speed_2MHz;    //  Low speed
			GPIO_Speed_25MHz; //  Medium speed
	//  GPIO_Speed_50MHz;   //  Fast speed
	//   GPIO_Speed_100MHz;  //  High speed

	// Port als Input verwendet, keine Output-Konfiguration nötig
	GPIO_InitStructure.GPIO_OType =
	// Auswahl des Output Typs
			GPIO_OType_PP; //  PushPull
	//  GPIO_OType_OD;      //  OpenDrain

	GPIO_InitStructure.GPIO_PuPd =
	// Auswahl des Push/Pull Typs
			GPIO_PuPd_NOPULL; //  NoPull
	//  GPIO_PuPd_UP;       //  PullUp
	//  GPIO_PuPd_DOWN;     //  PullDown

	// PortLeitungen initialisieren
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);

}

void init_taste_1(void) {
	// Taktquelle für die Peripherie aktivieren
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	// Struct anlegen
	GPIO_InitTypeDef GPIO_InitStructure;

	// Struct Initialisieren setzt alle Leitungen auf
	// Eingang ohne PushPull
	GPIO_StructInit(&GPIO_InitStructure);

	// I/O-Typ soll hier Input sein
	GPIO_InitStructure.GPIO_Mode =
	// Auswahl des I/O Mode
			GPIO_Mode_IN; //GPIO Input Mode
	//  GPIO_Mode_OUT;        //GPIO Output Mode
	//  GPIO_Mode_AF;       //GPIO Alternate function Mode
	//  GPIO_Mode_AN;       //GPIO Analog Mode

	GPIO_InitStructure.GPIO_Speed =
	// Auswahl der Speed
	//  GPIO_Speed_2MHz;    //  Low speed
			GPIO_Speed_25MHz; //  Medium speed
	//  GPIO_Speed_50MHz;   //  Fast speed
	//   GPIO_Speed_100MHz;  //  High speed

	// Port als Input verwendet, keine Output-Konfiguration nötig
	GPIO_InitStructure.GPIO_OType =
	// Auswahl des Output Typs
			GPIO_OType_PP; //  PushPull
	//  GPIO_OType_OD;      //  OpenDrain

	GPIO_InitStructure.GPIO_PuPd =
	// Auswahl des Push/Pull Typs
			GPIO_PuPd_NOPULL; //  NoPull
	//  GPIO_PuPd_UP;       //  PullUp
	//  GPIO_PuPd_DOWN;     //  PullDown

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;

	// PortLeitungen initialisieren
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
}

void init_taste_1_1(void) {
	// Taktsystem für den Port C Freigeben
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	// Struktur anlegen
	GPIO_InitTypeDef GPIO_InitStructure;

	// Portleitung in der Struktur Konfigurieren
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;

	// Werte aus der Struktur in die Register schreiben
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
}



void aufgabe_A8_1_1(void) {

	usart2_init();

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Prescaler = 8400 - 1; // 100µs = 8400 * 1/84000000Hz
	TIM_TimeBaseStructure.TIM_Period = 10000 - 1; // 1s = 10000 * 100µs
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);

	TIM_SetCounter(TIM7, 0);

	// Interruptflag löschen
	TIM_ClearITPendingBit(TIM7, TIM_IT_Update);

	// Interrupt erlauben
	TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);

	TIM_Cmd(TIM7, ENABLE);

}

void aufgabe_A8_1_2(void) {

	usart2_init();

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Prescaler = 8400 - 1; // 100µs = 8400 * 1/84000000Hz
	TIM_TimeBaseStructure.TIM_Period = 10 - 1; // 1 ms = 10 * 100µs
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);

	TIM_SetCounter(TIM7, 0);

	// Interruptflag löschen
	TIM_ClearITPendingBit(TIM7, TIM_IT_Update);

	// Interrupt erlauben
	TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);

	TIM_Cmd(TIM7, ENABLE);
}

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

void aufgabe_A8_1_3(void) {

	init_taste_1_1();

	// Alternativfunktion der Portleitung Freigeben
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);

	// Taktsystem für Timer TIM3 Freigeben
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	// Erkennen steigender Flanke an TI1
	TIM3->CCMR1 |= TIM_CCMR1_CC1S_0;
	TIM3->CR2 |= TIM_CR2_TI1S;

	// Polarität
	TIM3->CCER |= TIM_CCER_CC1P;

	// Slave Mode, external Clock Mode1, TI1FP1 Signalquelle
	TIM3->SMCR |= TIM_SMCR_SMS + TIM_SMCR_TS_2 + TIM_SMCR_ETF_0; //TIM_SMCR_TS_0 ;

	// Konfiguration der Interruptcontrollers
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	// Struktur anlegen
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	// TIM3 in der Struktur konfigurieren
	TIM_TimeBaseStructure.TIM_Prescaler = 2;
	TIM_TimeBaseStructure.TIM_Period = 10 - 1; // Grenzwert Tastenbetätigungen
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	// TIM3 Register aus der Struktur Schreiben
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	// TIM3 Interrupt erlauben
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	// Counter auf 0 setzen
	TIM_SetCounter(TIM3, 0x00);

	// Timer TIM3 Freigeben
	TIM_Cmd(TIM3, ENABLE);
}

void check_reactions(void) {
	init_taste_1();
	uint32_t start_time = 0;
	uint32_t dauer = 0;
	uint8_t taster_counter = 0;
	uint8_t Byte_t1 = 0;
	uint32_t max = 0;
	uint32_t min = 0xFFFF;
	uint32_t sum_dauer = 0;
	extern int seconds_counter;
	int i;
	uint32_t zahl = 0;
	usart2_printf("Game Starting...");
	for (i = 0; i < 10; i++) {
		usart2_printf("\n\rround %d\n\r", i+1);
		zahl = Zufallszahl() % 9 + 2;
		wait_mSek(zahl * 1000);
		LED_GR_ON;
		start_time = seconds_counter;
		Byte_t1 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8);
		while (Byte_t1 != 0) {
			Byte_t1 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8);
		}
		dauer = seconds_counter - start_time;
		usart2_printf("Reaction time for try %d is: %dms\n\r", i + 1, dauer);
		LED_GR_OFF;
		if (dauer > max) {
			max = dauer;
		}
		if (dauer < min){
			min = dauer;
		}
		sum_dauer += dauer;
	}
	usart2_printf("Min Reaction time was: %dms\n\r", min);
	usart2_printf("Max Reaction time was: %dms\n\r", max);
	usart2_printf("AVG Reaction time was: %dms\n\r", sum_dauer/10);



}
