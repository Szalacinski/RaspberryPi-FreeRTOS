#include "uart.h"
#include "gpio.h"

volatile BCM2835_UART1_REGS * const uart1_regs = (BCM2835_UART1_REGS *) (0x20215000);

extern void dummy(unsigned int);

void uart_send(unsigned int data)
{
	while (!(uart1_regs->AUX_MU_LSR_REG & 0x20));
	uart1_regs->AUX_MU_IO_REG = data;
}

void uart_flush(void)
{
	while (uart1_regs->AUX_MU_LSR_REG & 0x100);
}

void hexstrings(unsigned int d)
{
	//unsigned int ra;
	unsigned int rb;
	unsigned int rc;

	rb = 32;
	do {
		rb -= 4;
		rc = (d >> rb) & 0xF;
		if (rc > 9)
			rc += 0x37;
		else
			rc += 0x30;
		uart_send(rc);
	} while (rb);
	uart_send(0x20);
}

void hexstring(unsigned int d)
{
	hexstrings(d);
	uart_send(0x0D);
	uart_send(0x0A);
}

void print(char *ch)
{
	//TODO: Function unsafe.  Write safer
	while (*ch) {
		uart_send((unsigned int)*ch);
		++ch;
	}
	uart_send(0x0D);
	uart_send(0x0A);
}

void uart_init(void)
{
	unsigned long a;

	uart1_regs->AUX_ENABLES = 1; //change this to OR later
	uart1_regs->AUX_MU_IER_REG = 0;
	uart1_regs->AUX_MU_CNTL_REG = 0;
	uart1_regs->AUX_MU_LCR_REG = 3; //8-bit mode
	uart1_regs->AUX_MU_MCR_REG = 0; //RTS line low
	uart1_regs->AUX_MU_IER_REG = 5;

	uart1_regs->AUX_MU_IIR_REG = 0xC6;
	uart1_regs->AUX_MU_BAUD_REG = 270; //115200 baud

	SetGpioFunction(14, FUN_5);
	SetGpioFunction(15, FUN_5);
	pRegs->GPPUD[0] = 0;
	for(a=0; a < 150; ++a)
		dummy(a);
	pRegs->GPPUDCLK[0] = ((1 << 14) | (1 << 15));
	for(a=0; a < 150; ++a)
		dummy(a);
	pRegs->GPPUDCLK[0] = 0;	
	uart1_regs->AUX_MU_CNTL_REG = 3; //RX/TX enable
}
