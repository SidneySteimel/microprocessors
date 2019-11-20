#include "main.h"

int main ( void )
{
    // Initialisierung des Systems und des Clocksystems
	//    SystemInit();

    // SysTick initialisieren
    // jede Millisekunde erfolgt dann der Aufruf
    // des Handlers fuer den Interrupt SysTick_IRQn
	//    InitSysTick();

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
	init_usart_2();
	init_leds();
	init_taste_1_irq();
    init_taste_2_irq();
    init_interrupts();
    init_nvic();

	while(1){

	}
}
