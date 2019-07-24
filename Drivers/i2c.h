#ifndef _I2C_H_
#define _I2C_H_

typedef struct {
	unsigned long C;	//Control
	unsigned long S;	//Status
	unsigned long DLEN;	//Data Length
	unsigned long A;	//Slave Address
	unsigned long FIFO;	//Data FIFO
	unsigned long DIV;	//Clock Divider
	unsigned long DEL;	//Data Delay
	unsigned long CLKT;	//Clock Stretch Timeout
} BCM2835_I2C_REGS;

//SDA ALT0 GPIO0 & SCL ALT0 GPIO1
extern volatile BCM2835_I2C_REGS * const i2c0_regs;

//SDA ALT0 GPIO2 & SCL ALT0 GPIO3
extern volatile BCM2835_I2C_REGS * const i2c1_regs;

//This is used by the HDMI interface, and should not be accessed.
//extern volatile BCM2835_I2C_REGS * const i2c2_regs;

#endif
