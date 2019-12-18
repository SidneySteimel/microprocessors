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

			// Wechsel in den Sleep Mode mit einem der beiden Befehle:
			// __WFI() - wait for Interrupt oder
			// __WFE() - wait for Event
			usart_2_print("\n\rSleep Mode Start");
			__WFI();
			// durch einen Interrupt getriggert und nach Abarbeitung der ISR
			// wird die weitere Programmabarbeitung gestartet
			usart_2_print("\n\rSleep Mode Ende");

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

	// im Sleep Mode hat unser Board einen Verbrauch von 37 mA
	// vorher, bzw danach sind es 69/70 mA
	// es sind also bei uns ca. 33 mA Stromersparnis

}
