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
	InitSysTick();
	init_usart_2();


	while(1){
		wait_mSek(1000);
		// Anlegen der Structs für aktuelle Daten
		RTC_TimeTypeDef RTC_Time_Aktuell; //  Zeit
		RTC_DateTypeDef RTC_Date_Aktuell; //  Datum

		char data[50] = {0};

		// Datum aus der RTC in das Struct laden
		RTC_GetDate(RTC_Format_BIN, &RTC_Date_Aktuell);
		sprintf(data,"\r\n\nDatum: %.2d-%.2d-%.2d, Tag: %.2d",RTC_Date_Aktuell.RTC_Year, RTC_Date_Aktuell.RTC_Month, RTC_Date_Aktuell.RTC_Date, RTC_Date_Aktuell.RTC_WeekDay);
		usart_2_print(data);
		// Zeit aus der RTC in das Struct laden
		RTC_GetTime(RTC_Format_BIN, &RTC_Time_Aktuell);
		sprintf(data,"\r\nUhrzeit: %.2d:%.2d:%.2d:%.2d",RTC_Time_Aktuell.RTC_Hours, RTC_Time_Aktuell.RTC_Minutes, RTC_Time_Aktuell.RTC_Seconds, RTC_Time_Aktuell.RTC_H12);
		usart_2_print(data);
	}
}
