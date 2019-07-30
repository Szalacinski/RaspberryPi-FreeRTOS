//
// dma.c
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
#include "dma.h"

volatile BCM2835_DMA_REGS * const dma_regs0 = (BCM2835_DMA_REGS *) (0x20007000);

volatile BCM2835_DMA_REGS * const dma_regs1 = (BCM2835_DMA_REGS *) (0x20007100);

volatile BCM2835_DMA_REGS * const dma_regs2 = (BCM2835_DMA_REGS *) (0x20007200);

volatile BCM2835_DMA_REGS * const dma_regs3 = (BCM2835_DMA_REGS *) (0x20007300);

volatile BCM2835_DMA_REGS * const dma_regs4 = (BCM2835_DMA_REGS *) (0x20007400);

volatile BCM2835_DMA_REGS * const dma_regs5 = (BCM2835_DMA_REGS *) (0x20007500);

volatile BCM2835_DMA_REGS * const dma_regs6 = (BCM2835_DMA_REGS *) (0x20007600);

volatile BCM2835_DMA_REGS * const dma_regs7 = (BCM2835_DMA_REGS *) (0x20007700);

volatile BCM2835_DMA_REGS * const dma_regs8 = (BCM2835_DMA_REGS *) (0x20007800);

volatile BCM2835_DMA_REGS * const dma_regs9 = (BCM2835_DMA_REGS *) (0x20007900);

volatile BCM2835_DMA_REGS * const dma_regs10 = (BCM2835_DMA_REGS *) (0x20007a00);

volatile BCM2835_DMA_REGS * const dma_regs11 = (BCM2835_DMA_REGS *) (0x20007b00);

volatile BCM2835_DMA_REGS * const dma_regs12 = (BCM2835_DMA_REGS *) (0x20007c00);

volatile BCM2835_DMA_REGS * const dma_regs13 = (BCM2835_DMA_REGS *) (0x20007d00);

volatile BCM2835_DMA_REGS * const dma_regs14 = (BCM2835_DMA_REGS *) (0x20007e00);

volatile BCM2835_DMA_REGS * const dma_regs15 = (BCM2835_DMA_REGS *) (0x20e05000);
