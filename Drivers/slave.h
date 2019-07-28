#ifndef _SLAVE_H_
#define _SLAVE_H_

typedef struct {
	unsigned long DR;	//Data register
	unsigned long RSR;	//Operation Status and Error Clear
	unsigned long SLV;	//I2C Slave Address
	unsigned long CR;	//Control register
	unsigned long FR;	//Flag register
	unsigned long IFLS;	//Interrupt FIFO Level Select
	unsigned long IMSC;	//Interrupt Mask Clear
	unsigned long RIS;	//Raw Interrupt Status
	unsigned long MIS;	//Masked Interrupt Status
	unsigned long ICR;	//Interrupt Clear register
	unsigned long DMACR;	//DMA Control register
	unsigned long TDR;	//FIFO Test Data
	unsigned long GPUSTAT;	//GPU Status register
	unsigned long HCTRL;	//Host Control register
	unsigned long DEBUG1;	//I2C Debug register
	unsigned long DEBUG2;	//SPI Debug register
} BCM2835_SLV_REGS;

extern volatile BCM2835_SLV_REGS * const slv_regs;

#endif
