#include "main.h"

int main ( void )
{
    // Initialisierung des Systems und des Clocksystems
    SystemInit();

    // SysTick initialisieren
    // jede Millisekunde erfolgt dann der Aufruf
    // des Handlers fuer den Interrupt SysTick_IRQn
    //InitSysTick();

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
    init_leds();
    init_taste_1();
    init_taste_2();

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

	usart2_init();

    while(1)
    {
    	if ( GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8) == 0) {
    		slowMode();
    		wait_mSek(100);
    		usart2_send("SlowMode On!\r\n");
    	}

    	if ( GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5) == 1) {
    		fastMode();
    		wait_mSek(100);
    		usart2_send("FastMode On!\r\n");
    	}

    }

}
