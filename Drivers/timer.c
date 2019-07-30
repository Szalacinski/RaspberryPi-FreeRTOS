#include "timer.h"

volatile BCM2835_TIMER_REGS * const timer_regs = (BCM2835_TIMER_REGS *) (0x20003000);
