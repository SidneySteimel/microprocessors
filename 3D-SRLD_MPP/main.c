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

	// Beispiel für die Loesung einer Aufgabe
    // init_PC09();
    // init_taste_1();
    // init_taste_2();

    // mit SystemInit wird ein takt von 168 MHz genutzt
    // die LED blinkt im gewünschten Sekundentakt
    // Stromverbrauch liegt bei 77 mA

    // ohne SystemInit wird niedrigerer interner system takt verwendet
    // der takt der LED ist entsprechend ca. um x10 verlangsamt
    // und gemessene taktfrequenz liegt bei 16 MHz
    // Stromverbrauch von 33 mA, da sämtliche geräte langsamer (bzw. nicht so häufig) arbeiten
    // und weniger hardware/geräte initialisiert worden sind

    // slowMode:
    // Stromverbrauch nur 31 mA
    // Taktfrequenz 24 MHz

    // fastMode:
    // Stromverbrauch 68 mA
    // Taktfrequenz 168 MHz

    // ohne init_PC09():
    // hier wird natürlich nichts gemessen, da der Pin ohne diese Konfigurierung nicht aktiv ist
    // und kein Signal ausgibt
    // -> was auffällt ist, dass ohne diese Pin-Konfiguration 3mA Stromverbrauch eingespart werden
    // -> alles braucht Energie, man sollte nichts initialisieren,
    //		was man gerade nicht mit Sicherheit braucht


    // TeilAufgabe 1
    /*
    init_usart_2_tx();
    while(1)
    {
    	usart2_send_test("0123456789");
    }*/


    // TeilAufgabe 2
    /*
    init_usart_2_tx();
    int counter = 0;
    char zeichenkette[50];
    while(1)
    {
    	sprintf(zeichenkette, "Hello World!%d\r\n", counter);
    	counter++;
    	usart_2_print(zeichenkette);
    	wait_mSek(500);

    }*/

    //TeilAufgabe 3
    /*
    init_leds();
    init_usart_2();
    char input;
    char usart2_tx_buffer[50];
    int wait_time = 0;
    while(1) {
    	// Zeichen lesen und auf ein char casten
    	input = (char)USART_ReceiveData(USART2);
    	if (input == '1'){
    		wait_time = 1000;
    		sprintf(usart2_tx_buffer, "gruene LED im 1 Sekundentakt\r\n");
    		usart_2_print(usart2_tx_buffer);
    	}
    	else if (input == '2') {
    		wait_time = 2000;
			sprintf(usart2_tx_buffer, "gruene LED im 2 Sekundentakt\r\n");
    		usart_2_print(usart2_tx_buffer);
		}
    	else if (input == '4') {
			wait_time = 4000;
			sprintf(usart2_tx_buffer, "gruene LED im 4 Sekundentakt\r\n");
    		usart_2_print(usart2_tx_buffer);
    	}
    	LED_GR_TOGGLE;
    	wait_mSek(wait_time);
    }
    */
    init_leds();
    while (1) {
    	LED_GR_ON;
    }
}
