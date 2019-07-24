#include "aux.h"
#include "spi.h"

volatile BCM2835_SPI_REGS * const spi0_regs = (BCM2835_SPI_REGS *) (0x20204000);

volatile BCM2835_MINI_SPI_REGS * const spi1_regs = (BCM2835_MINI_SPI_REGS *) (0x20215080);

//No pinout for spi2
//volatile BCM2835_MINI_SPI_REGS * const spi2_regs = (BCM2835_MINI_SPI_REGS *) (0x202150C0);
