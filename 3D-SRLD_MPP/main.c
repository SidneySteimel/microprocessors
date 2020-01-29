#include "main.h"


int main(void) {
	SystemInit();
	InitSysTick();
	start_RTC();
	usart2_init();
	init_LED();

//    aufgabe_A8_1_2();
//
//    uint8_t Byte_t1 = 0;
//    uint8_t Byte_t2 = 0;
//    uint32_t  start_time = 0;
//    uint32_t  end_time = 0;
//    uint32_t  dauer = 0;
//    uint8_t taster_counter = 0;
//    extern int seconds_counter;
//
//    while (1)
//    {
//    	Byte_t1 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8);
//    	Byte_t2 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);
//    	if ( Byte_t1 == 0 && taster_counter == 0) {
//    		taster_counter++;
//    		start_time = seconds_counter;
//    	}
//    	if (Byte_t2 == 1 && taster_counter == 1){
//    		end_time = seconds_counter;
//    		dauer = (end_time -start_time);
//    		usart2_printf("total time: %u \r\n", dauer);
//    		taster_counter = 0;
//    	}
//    }
//}

//	extern int start_game;
//
//	aufgabe_A8_1_2();
//	usart2_printf("\n\rTo start a game click s\n\r");
//	char input;
//	while (1) {
//		if (start_game != 0) {
//			check_reactions();
//			start_game = 0;
//		}
//	}
float messwert = 0;
float wert = 0;
float Spannungswert = 0;
float Temperatur = 0;
while(1){
	spannung_ADC();
	ADC_SoftwareStartConv(ADC1);
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)==RESET);
	messwert=ADC_GetConversionValue(ADC1);
	wert = (messwert/4095.0f) * 3.3f;
	usart2_printf("Spannung: %.4f V\r\n", wert);
	if (wert > 1.4){
		LED_GR_ON;
	}
	else {
		LED_GR_OFF;
	}

	batterie_ADC();
	ADC_SoftwareStartConv(ADC1);
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)==RESET);
		// Ergebnis auswerten
	messwert=ADC_GetConversionValue(ADC1);
	wert = 2.0f * (float) messwert * (3.3f / 4096.0f) ;
	usart2_printf("VBAT = %.4f V\r\n",wert);

	temp_ADC();
	ADC_SoftwareStartConv(ADC1);
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)==RESET);
	messwert = ADC_GetConversionValue(ADC1);
	Spannungswert = (float)(messwert/4095.0f) * 3.3f;

	Temperatur = (float) ((Spannungswert - 0.76f)/0.0025f) + 25.0f;
	usart2_printf("TEMP = %3.1f C\r\n",Temperatur);
	wait_mSek(1000);
}
}
