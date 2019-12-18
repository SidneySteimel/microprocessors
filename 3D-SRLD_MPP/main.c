#include "main.h"

int main ( void )
{
    // Initialisierung des Systems und des Clocksystems
	//    SystemInit();
    // SysTick initialisieren
    // jede Millisekunde erfolgt dann der Aufruf
    // des Handlers fuer den Interrupt SysTick_IRQn

    // Initialisierung aller Portleitungen und Schnittstellen
    // Freigabe von Interrupten
    //init_board();

    // Start der RTC  falls diese noch
    // nicht initialisiert war wird
    // die RTC mit der LSE-Taktquelle aktiviert
    //start_RTC();

    // Anmeldung beim WLAN Access Point
    // SSID: MPP_IoT
    //CC3100_set_in_STA_Mode(0); // WLAN

    // Initialisierung des CoCox Real Time Betriebssystems CoOS
    //CoInitOS ();

    // Anmelden notwendiger Task
    //CoCreateTask (...);

    // Start des Betriebssystems CoOS
    //CoStartOS ();


	SystemInit();
	//InitSysTick();
	init_leds();
	init_taste_1();
	init_taste_2();
		uint8_t Byte_t2 = 1;
		uint8_t previous = 1;
	init_interrupts();
	init_nvic();
	init_usart_2();

	while(1){

		// wenn taste 2 gedrückt, switch in Sleep Mode
		Byte_t2 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8);
		if ( Byte_t2 == 0 && previous == 1) {
			// LED an
			LED_GR_ON;
			usart_2_print("\n\rStop Mode Start");

			// nach Bedarf alle Peripherieeinheiten ausschalten
			// ...
			// interne oder externe EXTI-Line IRQ Quellen
			// für die Wakeup Funktion initalisieren
			// ...
			// SysTick-IRQ Off
			SysTick->CTRL  &= ~SysTick_CTRL_TICKINT_Msk;

			// FLASH Deep Power Down Mode
			PWR_FlashPowerDownCmd(ENABLE);

			// Stop-Mode aktivieren
			// durch __WFI() wird hier gewartet bis die Rückkehr aus dem
			// Stop-Mode durch die Wakup-Quellen angestossen wird
			PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);

			// FLASH Deep Power Down Mode
			PWR_FlashPowerDownCmd(DISABLE);

			// hier sollte das Clocksystem neu initialisiert werden.
			// ansonsten läuft der Mikrocontroller mit ca. 16MHz!!
			SystemInit();

			// SysTick-IRQ On
			SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;

			// weitere Programmabarbeitung

			usart_2_print("\n\rStop Mode Ende");

		} else if ( Byte_t2 == 1 ) {
			previous = 1;
		}


		wait_uSek(2650000);
		// LED an
		LED_GR_ON;

		wait_uSek(350000);
		// LED aus
		LED_GR_OFF;
	}

	// im Normalen Betrieb verbraucht unser Microcontroller 70 mA
	// im Sleep Mode hat er nur nouch einen Verbrauch von 37 mA
	// es sind also bei uns ca. 33 mA Stromersparnis

	// im Stop Mode sind es sogar nur 22 mA
	// der Stop Mode bietet bei diesem Minimalbeispiel höhere Stromersparnis
	// und keine erkennbaren Nachteile außer etwas mehr Overhead im Code


}
