//
// pcm.h
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
