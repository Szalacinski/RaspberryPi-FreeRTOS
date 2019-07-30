//
// dma.h
// 
// MIT License
//
// Copyright (c) 2019 Caleb Szalacinski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
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
