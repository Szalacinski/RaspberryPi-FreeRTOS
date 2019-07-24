#ifndef _GPIO_H_
#define _GPIO_H_

#define ACT_LED 47

/* GPIO event detect types */
enum DETECT_TYPE {
	DETECT_NONE,
	DETECT_RISING,
	DETECT_FALLING,
	DETECT_HIGH,
	DETECT_LOW,
	DETECT_RISING_ASYNC,
	DETECT_FALLING_ASYNC
};

/* GPIO pull up or down states */
enum PULL_STATE {
	PULL_DISABLE,
	PULL_UP,
	PULL_DOWN,
	PULL_RESERVED
};

/* Pin data direction */
/*
enum GPIO_DIR {
	GPIO_IN,
	GPIO_OUT
};
*/
/* Pin data direction */
enum GPIO_FUN {
	GPIO_IN,
	GPIO_OUT,
	FUN_5,
	FUN_4,
	FUN_0,
	FUN_1,
	FUN_2,
	FUN_3
};

typedef struct {
	unsigned long	GPFSEL[6];	///< Function selection registers.
	unsigned long	Reserved_1;
	unsigned long	GPSET[2];
	unsigned long	Reserved_2;
	unsigned long	GPCLR[2];
	unsigned long	Reserved_3;
	unsigned long	GPLEV[2];
	unsigned long	Reserved_4;
	unsigned long	GPEDS[2];
	unsigned long	Reserved_5;
	unsigned long	GPREN[2];
	unsigned long	Reserved_6;
	unsigned long	GPFEN[2];
	unsigned long	Reserved_7;
	unsigned long	GPHEN[2];
	unsigned long	Reserved_8;
	unsigned long	GPLEN[2];
	unsigned long	Reserved_9;
	unsigned long	GPAREN[2];
	unsigned long	Reserved_A;
	unsigned long	GPAFEN[2];
	unsigned long	Reserved_B;
	unsigned long	GPPUD[1];
	unsigned long	GPPUDCLK[2];
	//Ignoring the reserved and test bytes
} BCM2835_GPIO_REGS;


/* GPIO pin setup */
void SetGpioFunction	(unsigned int pinNum, enum GPIO_FUN funcNum);

/* A simple wrapper around SetGpioFunction */
//void SetGpioDirection	(unsigned int pinNum, enum GPIO_DIR dir);

/* Set GPIO output level */
void SetGpio			(unsigned int pinNum, unsigned int pinVal);

/* Read GPIO pin level */
int ReadGpio			(unsigned int pinNum);

/* GPIO pull up/down resistor control function (NOT YET IMPLEMENTED) */
int PudGpio				(unsigned int pinNum, enum PULL_STATE state);

/* Interrupt related functions */
void EnableGpioDetect	(unsigned int pinNum, enum DETECT_TYPE type);
void DisableGpioDetect	(unsigned int pinNum, enum DETECT_TYPE type);
void ClearGpioInterrupt	(unsigned int pinNum);

extern volatile BCM2835_GPIO_REGS * const pRegs;

#endif
