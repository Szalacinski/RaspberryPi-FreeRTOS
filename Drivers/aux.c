//Registers shared by UART1, SPI1, SPI2

#include "aux.h"

volatile BCM2835_AUX_REGS * const aux_regs = (BCM2835_AUX_REGS *) (0x20215000);
