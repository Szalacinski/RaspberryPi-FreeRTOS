#ifndef _PCM_H_
#define _PCM_H_

typedef struct {
	unsigned long CS_A;	//PCM Control and Status
	unsigned long FIFO_A;	//PCM FIFO Data
	unsigned long MODE_A;	//PCM Mode
	unsigned long RXC_A;	//PCM Receive Configuration
	unsigned long TXC_A;	//PCM Transmit Configuration 
	unsigned long DREQ_A;	//PCM DMA Request Level
	unsigned long INTEN_A;	//PCM Interrupt Enables
	unsigned long INTSTC_A;	//PCM Interrupt Status & Clear
	unsigned long GRAY;	//PCM Gray Mode Control
} BCM2835_PCM_REGS;

extern volatile BCM2835_PCM_REGS * const pcm_regs;

#endif
