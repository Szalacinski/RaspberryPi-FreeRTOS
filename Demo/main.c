#include <FreeRTOS.h>
#include <task.h>

#include "interrupts.h"
#include "gpio.h"
#include "uart.h"

void task1(void *pParam) {

	int i = 0;
	while(1) {
		i++;
		set_gpio(ACT_LED, 1);
		uart_print("Light on!\r\n");
		vTaskDelay(200);
	}
}

void task2(void *pParam) {

	int i = 0;
	while(1) {
		i++;
		vTaskDelay(100);
		set_gpio(ACT_LED, 0);
		uart_print("Light off!\r\n");
		vTaskDelay(100);
	}
}

void main(void) {

	DisableInterrupts();
	InitInterruptController();
	uart_init();
	set_gpio_function(ACT_LED, GPIO_OUT);

	xTaskCreate(task1, "LED_0", 128, NULL, 0, NULL);
	xTaskCreate(task2, "LED_1", 128, NULL, 0, NULL);

	vTaskStartScheduler();

	/*
	 *	We should never get here, but just in case something goes wrong,
	 *	we'll place the CPU into a safe loop.
	 */
	while(1);
}
