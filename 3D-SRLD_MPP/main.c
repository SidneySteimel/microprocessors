#include "main.h"

int main ( void )
{
    // Initialisierung des Systems und des Clocksystems
    SystemInit();

    // SysTick initialisieren
    // jede Millisekunde erfolgt dann der Aufruf
    // des Handlers fuer den Interrupt SysTick_IRQn
    InitSysTick();

    // Initialisierung aller Portleitungen und Schnittstellen
    // Freigabe von Interrupten
    init_board();

    // Start der RTC  falls diese noch
    // nicht initialisiert war wird
    // die RTC mit der LSE-Taktquelle aktiviert
    start_RTC();

    // Anmeldung beim WLAN Access Point
    // SSID: MPP_IoT
    //CC3100_set_in_STA_Mode(0); // WLAN

    // Initialisierung des CoCox Real Time Betriebssystems CoOS
    //CoInitOS ();

    // Anmelden notwendiger Task
    //CoCreateTask (...);

    // Start des Betriebssystems CoOS
    //CoStartOS ();

	// Beispiel für die Loesung einer Aufgabe
    init_leds();
    init_taste_1();
    init_taste_2();
 	uint8_t     Byte_t2 = 1;
 	uint8_t     Byte_t1 = 0;
   	uint8_t     counter = 0;
   	char buff[100];

    while (1)
    {
    	 sprintf(buff,"%.2d\r\n", counter);
    	 usart2_send(buff);
    	 Byte_t2 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8);
    	 if ( Byte_t2 == 0 && counter == 0) {
    			 counter++;
    			 wait_mSek(100);
    		 }

    	 if ( Byte_t2 == 1 && counter == 1) {
    		 	 counter++;
    		 	wait_mSek(100);
    	 }
    	 if ( Byte_t2 == 0 && counter == 2) {
    		LED_GR_ON;
    	    counter++;
    	 }

    	 Byte_t1 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);
    	 if (Byte_t1 == 1){
    		 LED_GR_OFF;
    		 counter = 0;
    		 Byte_t1 = 0;
		 }
    }
}
