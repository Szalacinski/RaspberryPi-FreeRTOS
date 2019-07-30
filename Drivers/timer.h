#ifndef _TIMER_H_
#define _TIMER_H_

typedef struct {
	unsigned long CS;	//Control/Status
	unsigned long CLO;	//Lower 32 bits
	unsigned long CHI;	//Higher 32 bits
	unsigned long C0;	//Compare 0
	unsigned long C1;	//Compare 1
	unsigned long C2;	//Compare 2
	unsigned long C3;	//Compare 3
} BCM2835_TIMER_REGS;

extern volatile BCM2835_TIMER_REGS * const timer_regs;

#endif
