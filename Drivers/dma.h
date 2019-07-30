#ifndef _DMA_H_
#define _DMA_H_

typedef struct {
	unsigned long CS;	//Control and Status
	unsigned long CONBLK_AD;//Control Block Address
	unsigned long TI;	//Word 0 (Transfer Information)
	unsigned long SOURCE_AD;//Word 1 (Source Address)
	unsigned long DEST_AD;	//Word 2 (Destination Address)
	unsigned long TXFR_LEN;	//Word 3 (Transfer Length)
	unsigned long STRIDE;	//Word 4 (2D Stride)
	unsigned long NEXTCONBK;//Word 5 (Next CB Address)
	unsigned long DEBUG;	//Debug
} BCM2835_DMA_REGS;

//The STRIDE register doesn't exist for DMA channel 7 and above.
//These are referred to as LITE channels in the datasheet.

extern volatile BCM2835_DMA_REGS * const dma_regs0;

extern volatile BCM2835_DMA_REGS * const dma_regs1;

extern volatile BCM2835_DMA_REGS * const dma_regs2;

extern volatile BCM2835_DMA_REGS * const dma_regs3;

extern volatile BCM2835_DMA_REGS * const dma_regs4;

extern volatile BCM2835_DMA_REGS * const dma_regs5;

extern volatile BCM2835_DMA_REGS * const dma_regs6;

extern volatile BCM2835_DMA_REGS * const dma_regs7;

extern volatile BCM2835_DMA_REGS * const dma_regs8;

extern volatile BCM2835_DMA_REGS * const dma_regs9;

extern volatile BCM2835_DMA_REGS * const dma_regs10;

extern volatile BCM2835_DMA_REGS * const dma_regs11;

extern volatile BCM2835_DMA_REGS * const dma_regs12;

extern volatile BCM2835_DMA_REGS * const dma_regs13;

extern volatile BCM2835_DMA_REGS * const dma_regs14;

extern volatile BCM2835_DMA_REGS * const dma_regs15;

#endif
