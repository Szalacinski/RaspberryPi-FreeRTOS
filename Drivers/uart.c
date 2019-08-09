#include "aux.h"
#include "uart.h"
#include "gpio.h"

volatile BCM2835_UART1_REGS * const uart1_regs = (BCM2835_UART1_REGS *) (0x20215040);
/*
	Despite the waste_cycle assembly not needing an argument, this tricks
	the compiler into thinking that work is being done.  In the future, a
	solution utilizing timers would be more proper.
*/
extern void waste_cycle(unsigned int i);

void uart_send(unsigned int data)
{
	while (!(uart1_regs->AUX_MU_LSR_REG & 0x20));
	uart1_regs->AUX_MU_IO_REG = data;
}

void uart_flush(void)
{
	while (uart1_regs->AUX_MU_LSR_REG & 0x100);
}

void uart_print(char *c)
{
	//TODO: Function unsafe.  Write safer
	while (*c) {
		uart_send((unsigned int) *c);
		++c;
	}
}

static void uart_delay(void)
{
	for(int i = 0; i < 150; ++i)
		waste_cycle(i);
}

void uart_init(void)
{
	aux_regs->AUX_ENABLES |= 1;		//Enable Mini UART
	uart1_regs->AUX_MU_IER_REG = 0;		//Reset register
	uart1_regs->AUX_MU_CNTL_REG = 0;	//Disable RX/TX
	uart1_regs->AUX_MU_LCR_REG = 3;		//8-bit mode
	uart1_regs->AUX_MU_MCR_REG = 0;		//RTS line low
	uart1_regs->AUX_MU_IER_REG = 5;		//Enable receive interrupt
	uart1_regs->AUX_MU_IIR_REG = 0xC6;
	uart1_regs->AUX_MU_BAUD_REG = 270;	//115200 baud

	set_gpio_function(14, FUN_5);
	set_gpio_function(15, FUN_5);
	gpio_regs->GPPUD[0] = 0;
	uart_delay();
	gpio_regs->GPPUDCLK[0] = ((1 << 14) | (1 << 15));
	uart_delay();
	gpio_regs->GPPUDCLK[0] = 0;	
	uart1_regs->AUX_MU_CNTL_REG = 3;	//EnableRX/TX
}
