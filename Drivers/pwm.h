#ifndef _PWM_H_
#define _PWM_H_

typedef struct {
	unsigned long CTL;	//PWM Control
	unsigned long STA;	//PWM Status
	unsigned long DMAC;	//PWM DMA Configuration
	unsigned long RNG1;	//PWM Channel 1 Range
	unsigned long DAT1;	//PWM Channel 1 Data
	unsigned long FIF1;	//PWM FIFO Input
	unsigned long RNG2;	//PWM Channel 2 Range
	unsigned long DAT2;	//PWM Channel 2 Data
} BCM2835_PWM_REGS;

extern volatile BCM2835_PWM_REGS * const pwm_regs;

#endif
