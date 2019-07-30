//
// slave.h
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
