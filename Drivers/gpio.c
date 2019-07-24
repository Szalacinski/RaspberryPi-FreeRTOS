/**
 *	Quick and very Dirty GPIO API.
 *
 **/

#include "gpio.h"


volatile BCM2835_GPIO_REGS * const pRegs = (BCM2835_GPIO_REGS *) (0x20200000);


void SetGpioFunction(unsigned int pinNum, enum GPIO_FUN funcNum) {

	int offset = pinNum / 10;

	unsigned long val = pRegs->GPFSEL[offset];	// Read in the original register value.

	int item = pinNum % 10;
	val &= ~(0x7 << (item * 3));
	val |= ((funcNum & 0x7) << (item * 3));
	pRegs->GPFSEL[offset] = val;
}
/*
void SetGpioDirection(unsigned int pinNum, enum GPIO_DIR dir) {
	SetGpioFunction(pinNum,dir);
}
*/
void SetGpio(unsigned int pinNum, unsigned int pinVal) {
	unsigned long offset=pinNum/32;
	unsigned long mask=(1<<(pinNum%32));

	if(pinVal) {
		pRegs->GPSET[offset]|=mask;
	} else {
		pRegs->GPCLR[offset]|=mask;
	}
}

int ReadGpio(unsigned int pinNum) {
	return ((pRegs->GPLEV[pinNum/32])>>(pinNum%32))&1;
}

void EnableGpioDetect(unsigned int pinNum, enum DETECT_TYPE type)
{
	unsigned long mask=(1<<pinNum);
	unsigned long offset=pinNum/32;
	
	switch(type) {
	case DETECT_RISING:
		pRegs->GPREN[offset]|=mask;
		break;
	case DETECT_FALLING:
		pRegs->GPFEN[offset]|=mask;
		break;
	case DETECT_HIGH:
		pRegs->GPHEN[offset]|=mask;
		break;
	case DETECT_LOW:
		pRegs->GPLEN[offset]|=mask;
		break;
	case DETECT_RISING_ASYNC:
		pRegs->GPAREN[offset]|=mask;
		break;
	case DETECT_FALLING_ASYNC:
		pRegs->GPAFEN[offset]|=mask;
		break;
	case DETECT_NONE:
		break;
	}
}

void DisableGpioDetect(unsigned int pinNum, enum DETECT_TYPE type)
{
	unsigned long mask=~(1<<(pinNum%32));
	unsigned long offset=pinNum/32;
	
	switch(type) {
	case DETECT_RISING:
		pRegs->GPREN[offset]&=mask;
		break;
	case DETECT_FALLING:
		pRegs->GPFEN[offset]&=mask;
		break;
	case DETECT_HIGH:
		pRegs->GPHEN[offset]&=mask;
		break;
	case DETECT_LOW:
		pRegs->GPLEN[offset]&=mask;
		break;
	case DETECT_RISING_ASYNC:
		pRegs->GPAREN[offset]&=mask;
		break;
	case DETECT_FALLING_ASYNC:
		pRegs->GPAFEN[offset]&=mask;
		break;
	case DETECT_NONE:
		break;
	}
}

void ClearGpioInterrupt(unsigned int pinNum)
{
	unsigned long mask=(1<<(pinNum%32));
	unsigned long offset=pinNum/32;

	pRegs->GPEDS[offset]=mask;
}
