#include "i2c.h"

//extern void dummy(unsigned int);

volatile BCM2835_I2C_REGS * const i2c0_regs = (BCM2835_I2C_REGS *) (0x20205000);
volatile BCM2835_I2C_REGS * const i2c1_regs = (BCM2835_I2C_REGS *) (0x20804000);

//This is used by the HDMI interface, and should not be accessed.
//volatile BCM2835_I2C_REGS * const i2c2_regs = (BCM2835_I2C_REGS *) (0x20805000);

/*
void i2c_init()
{

}

void i2c_read()
{

}

void i2c_write(i2c_dev)
{
	while ((S & 1) || ~(S & 2)) {
		while(DLEN)
			dummy(DLEN);
	}
	
}
*/


