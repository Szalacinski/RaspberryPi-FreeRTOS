#ifndef _AUX_H_
#define _AUX_H_

//Registers shared by UART1, SPI1, SPI2

typedef struct {
	unsigned long AUX_IRQ;		//Auxiliary Interrupt Status
	unsigned long AUX_ENABLES;	//Auxiliary Enables
} BCM2835_AUX_REGS;

extern volatile BCM2835_AUX_REGS * const aux_regs;

#endif
