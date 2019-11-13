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

//    init_usart_2();
//    init_taste_1();
//    init_iwdg();
//    uint8_t taste;
//
//    char zeichenkette[50];
//    sprintf(zeichenkette, "\r\nNeustart\r\n");
//    usart_2_print(zeichenkette);
//
//    while(1)
//    {
//    	sprintf(zeichenkette, "\r\nSchleife\r\n");
//    	usart_2_print(zeichenkette);
//
//    	// hier wird der Abwärtszähler jede halbe Sekunde resetet.
//    	wait_uSek(500000);
//    	IWDG_ReloadCounter();
//
//    	if ( GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5) == 1) {
//    		usart_2_print("\r\nTaste2 gedrückt\r\n");
//    		// hier warten wir mehr als 5 Sekunden und zwar 6, damit der Watchdog nach 5 Sekunden
//    		// die Schleife unterbricht.
//    		wait_uSek(6000000);
//    	}
//    }
		char usart2_tx_buffer[50];
		unsigned char value_watchdog_counter = 0x7f;
	    unsigned char window_value = 0x50;
	    unsigned char window_value_refresh = 0x50;
	    unsigned char cnt_i = 0;
	    unsigned char cnt_j = 0;

	    SystemInit();

	    init_usart_2();

	    sprintf(usart2_tx_buffer,"\r\nNeustart\r\n");
	    usart_2_print(usart2_tx_buffer);

	    RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);

	    WWDG_SetPrescaler(WWDG_Prescaler_8);
	    WWDG_SetWindowValue(window_value);
	    WWDG_Enable(value_watchdog_counter);

	    cnt_i = (unsigned char) (value_watchdog_counter + 1);

	    while(1){

	        cnt_j = (unsigned char) ((WWDG->CR) & 0x7F) ;

	        if (cnt_j  < cnt_i ) {

	            sprintf(usart2_tx_buffer,"i = %u\r\n",cnt_j);
	            usart_2_print(usart2_tx_buffer);

	            cnt_i = cnt_j;

	            if (cnt_i == window_value_refresh ) {

	                WWDG_SetCounter(value_watchdog_counter);

	                sprintf(usart2_tx_buffer,"####### neu geladen\r\n");
	                usart_2_print(usart2_tx_buffer);

	                cnt_i = (unsigned char) (value_watchdog_counter + 1);
	            }
	        }
	    }
	    /*
	     * value_watchdog_counter zählt runter von 7f bis 3f (127, 63)
	     * window_value bestimmt das Fenster, in dem der zähler nicht resetet werden darf.
	     * window_value_refresh bestimmt der Punkt, an dem der Zähler resetet wird.
	     * window_value und window_value_refresh sind nur sinnvoll zwischen (127, 63)
	     * ----------
	     * ist der Wert von window_value_refresh > window_value wird das reseten von dem Zähler blockiert und es wird sofort neugestartet.
	     * ist der Wert von window_value_refresh < window_value wird das reseten von dem Zähler durchgeführt und nicht neugestartet.
	     * sollten die werte außerhalb des Zählerbereiches liegen, startet der Watchdog das System nach dem runterzählen neu
	     */
}
