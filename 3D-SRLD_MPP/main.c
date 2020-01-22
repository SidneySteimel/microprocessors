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

	extern int start_game;

	aufgabe_A8_1_2();
	usart2_printf("\n\rTo start a game click s\n\r");
	char input;
	while (1) {
		if (start_game != 0) {
			check_reactions();
			start_game = 0;
		}
	}
}
