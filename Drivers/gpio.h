#ifndef _GPIO_H_
#define _GPIO_H_


#define CAM_GPIO1	40
#define WL_ON		41
#define WIFI_CLK	43
#define CAM_GPIO0	44
#define BT_ON		45
#define ACT_LED		47

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

/* Pin directions and functions */
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
void set_gpio_function(unsigned int pin_num, enum GPIO_FUN func_num);
void set_gpio(unsigned int pin_num, unsigned int pin_val);
int read_gpio(unsigned int pin_num);

/* Interrupt related functions */
void enable_gpio_detect(unsigned int pin_num, enum DETECT_TYPE type);
void disable_gpio_detect(unsigned int pin_num, enum DETECT_TYPE type);
void clear_gpio_interrupt(unsigned int pin_num);

/* GPIO pull up/down resistor control function (NOT YET IMPLEMENTED) */
//int pud_gpio(unsigned int pin_num, enum PULL_STATE state);

extern volatile BCM2835_GPIO_REGS * const gpio_regs;

#endif
