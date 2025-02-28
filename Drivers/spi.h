//
// spi.h
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
#ifndef _SPI_H_
#define _SPI_H_
/*
#define MINI_SPI_CE0	1
#define MINI_SPI_CE1	(
*/
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
