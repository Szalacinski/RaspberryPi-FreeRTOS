#ifndef _SPI_H_
#define _SPI_H_

typedef struct {
	unsigned long CS;	//SPI Master Control and Status
	unsigned long FIFO;	//SPI Master TX and RX FIFOs
	unsigned long CLK;	//SPI Master Clock Divider
	unsigned long DLEN;	//SPI Master Data Length
	unsigned long LTOH;	//SPI LOSSI mode TOH
	unsigned long DC;	//SPI DMA DREQ Controls
} BCM2835_SPI_REGS;

typedef struct {
	unsigned long AUX_SPI_CNTL0_REG;	//SPI Control Register 0
	unsigned long AUX_SPI_CNTL1_REG;	//SPI Control Register 1
	unsigned long AUX_SPI_STAT_REG;		//SPI Status
	unsigned long AUX_SPI_IO_REG;		//SPI Data
	unsigned long AUX_SPI_PEEK_REG;		//SPI Peek
} BCM2835_MINI_SPI_REGS;

extern volatile BCM2835_SPI_REGS * const spi0_regs;

extern volatile BCM2835_MINI_SPI_REGS * const spi1_regs;

//No pinout for spi2
//extern volatile BCM2835_MINI_SPI_REGS * const spi2_regs;
#endif
