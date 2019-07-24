#include "pwm.h"

volatile BCM2835_PWM_REGS * const pwm_regs = (BCM2835_PWM_REGS *) (0x2020C000);
