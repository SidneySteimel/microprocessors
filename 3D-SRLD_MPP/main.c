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

	start_RTC();

	init_leds();
	init_taste_1();
	uint8_t Byte_t1 = 0;
	init_usart_2();

	init_RTC_wakeUp();

	while(1){

		// wenn taste 1 gedrückt, switch in Standby Mode
		Byte_t1 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);
		if ( Byte_t1 == 1 ) {
			LED_GR_ON;

		    // Enable RTC Wakeup
		    RTC_ITConfig(RTC_IT_WUT, ENABLE);   // Bit 14
		    RTC_AlarmCmd(RTC_CR_WUTE, ENABLE);  // Bit 10
		    RTC_WakeUpCmd(ENABLE);

		    usart_2_print("StandBy Mode Start\r\n");
		    SysTick->CTRL  &= ~SysTick_CTRL_TICKINT_Msk;
		    wait_uSek_CC3100(2000000);

		    PWR_EnterSTANDBYMode();
		}
		wait_uSek(650000);
		LED_GR_ON;
		wait_uSek(350000);
		LED_GR_OFF;
	}

	// im Normalen Betrieb verbraucht unser Microcontroller 70 mA
	// im Sleep Mode hat er nur nouch einen Verbrauch von 37 mA
	// es sind also bei uns ca. 33 mA Stromersparnis

	// im Stop Mode sind es sogar nur 22 mA
	// der Stop Mode bietet bei diesem Minimalbeispiel höhere Stromersparnis
	// und nur etwas mehr Overhead im Code und dadurch leicht höhere Aufwachzeit

	// im Standby reduziert sich der Verbrauch noch weiter, und zwar auf nur 18mA
}
