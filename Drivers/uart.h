#ifndef _UART_H_
#define _UART_H_

typedef struct {
	unsigned long AUX_IRQ;		//Auxiliary Interrupt Status
	unsigned long AUX_ENABLES;	//Auxiliary Enables 
	unsigned long Reserved_1[14];
	unsigned long AUX_MU_IO_REG;	//Mini Uart I/O Data
	unsigned long AUX_MU_IER_REG;	//Mini Uart Interrupt Enable
	unsigned long AUX_MU_IIR_REG;	//Mini Uart Interrupt Identify
	unsigned long AUX_MU_LCR_REG;	//Mini Uart Line Control
	unsigned long AUX_MU_MCR_REG;	//Mini Uart Modem Control
	unsigned long AUX_MU_LSR_REG;	//Mini Uart Line Status
	unsigned long AUX_MU_MSR_REG;	//Mini Uart Modem Status
	unsigned long AUX_MU_SCRATCH;	//Mini Uart Scratch
	unsigned long AUX_MU_CNTL_REG;	//Mini Uart Extra Control
	unsigned long AUX_MU_STAT_REG;	//Mini Uart Extra Status
	unsigned long AUX_MU_BAUD_REG;	//Mini Uart Baudrate
} BCM2835_UART1_REGS;

extern volatile BCM2835_UART1_REGS * const uart1_regs;

void print(char *ch);

#endif
