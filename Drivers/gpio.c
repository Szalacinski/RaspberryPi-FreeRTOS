#include "gpio.h"

volatile BCM2835_GPIO_REGS * const gpio_regs = (BCM2835_GPIO_REGS *) (0x20200000);

/*
	Despite the waste_cycle assembly not needing an argument, this tricks
	the compiler into thinking that work is being done.  In the future, a
	solution utilizing timers would be more proper.
*/
extern void waste_cycle(unsigned int i);

static void gpio_delay(void)
{
	for(int i = 0; i < 150; ++i)
		waste_cycle(i);
}


void set_gpio_function(unsigned int pin_num, enum GPIO_FUN func_num)
{

	int offset = pin_num / 10;

	unsigned long val = gpio_regs->GPFSEL[offset];	// Read in the original register value.

	int item = pin_num % 10;
	val &= ~(0x7 << (item * 3));
	val |= ((func_num & 0x7) << (item * 3));
	gpio_regs->GPFSEL[offset] = val;
}
/*
void SetGpioDirection(unsigned int pinNum, enum GPIO_DIR dir) {
	SetGpioFunction(pinNum,dir);
}
*/
void set_gpio(unsigned int pin_num, unsigned int pin_val)
{
	//TODO: Rewrite for handling more pins at once
	unsigned long offset = pin_num / 32;
	unsigned long mask = (1 << (pin_num % 32));

	if (pin_val) {
		gpio_regs->GPSET[offset] |= mask;
	} else {
		gpio_regs->GPCLR[offset] |= mask;
	}
}

int read_gpio(unsigned int pin_num)
{
	return ((gpio_regs->GPLEV[pin_num / 32]) >> (pin_num % 32)) & 1;
}

void enable_gpio_detect(unsigned int pin_num, enum DETECT_TYPE type)
{
	//TODO: Rewrite for handling more pins at once
	unsigned long mask = (1 << pin_num);
	unsigned long offset = pin_num / 32;
	
	switch(type) {
	case DETECT_RISING:
		gpio_regs->GPREN[offset] |= mask;
		break;
	case DETECT_FALLING:
		gpio_regs->GPFEN[offset] |= mask;
		break;
	case DETECT_HIGH:
		gpio_regs->GPHEN[offset] |= mask;
		break;
	case DETECT_LOW:
		gpio_regs->GPLEN[offset] |= mask;
		break;
	case DETECT_RISING_ASYNC:
		gpio_regs->GPAREN[offset] |= mask;
		break;
	case DETECT_FALLING_ASYNC:
		gpio_regs->GPAFEN[offset] |= mask;
		break;
	case DETECT_NONE:
		break;
	}
}

void disable_gpio_detect(unsigned int pin_num, enum DETECT_TYPE type)
{
	//TODO: Rewrite for handling more pins at once
	unsigned long mask = ~(1 << (pin_num % 32));
	unsigned long offset = pin_num / 32;
	
	switch(type) {
	case DETECT_RISING:
		gpio_regs->GPREN[offset] &= mask;
		break;
	case DETECT_FALLING:
		gpio_regs->GPFEN[offset] &= mask;
		break;
	case DETECT_HIGH:
		gpio_regs->GPHEN[offset] &= mask;
		break;
	case DETECT_LOW:
		gpio_regs->GPLEN[offset] &= mask;
		break;
	case DETECT_RISING_ASYNC:
		gpio_regs->GPAREN[offset] &= mask;
		break;
	case DETECT_FALLING_ASYNC:
		gpio_regs->GPAFEN[offset] &= mask;
		break;
	case DETECT_NONE:
		break;
	}
}

void clear_gpio_interrupt(unsigned int pin_num)
{
	//TODO: Rewrite for handling more pins at once
	unsigned long mask = (1 << (pin_num % 32));
	unsigned long offset = pin_num / 32;

	gpio_regs->GPEDS[offset] = mask;
}

void gpio_pud(unsigned long long pin_num, enum PULL_STATE state)
{
	gpio_regs->GPPUD = state;
	gpio_delay();
	gpio_regs->GPPUDCLK[0] = (unsigned long)(pin_num & 0xFFFFFFFF);
	gpio_regs->GPPUDCLK[1] = (unsigned long)(pin_num >> 32);
	gpio_delay();
	gpio_regs->GPPUD = 0;
	gpio_regs->GPPUDCLK[0] = 0;
	gpio_regs->GPPUDCLK[1] = 0;
}
