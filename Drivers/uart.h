//
// uart.h
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
#ifndef _UART_H_
#define _UART_H_

typedef struct {
	unsigned long AUX_MU_IO_REG;	//Mini Uart I/O Data
	unsigned long AUX_MU_IER_REG;	//Mini Uart Interrupt Enable
	unsigned long AUX_MU_IIR_REG;	//Mini Uart Interrupt Identify
	unsigned long AUX_MU_LCR_REG;	//Mini Uart Line Control
	unsigned long AUX_MU_MCR_REG;	//Mini Uart Modem Control
	unsigned long AUX_MU_LSR_REG;	//Mini Uart Line Status
	unsigned long AUX_MU_MSR_REG;	//Mini Uart Modem Status
	unsigned long AUX_MU_SCRATCH;	//Mini Uart Scratch
	unsigned long AUX_MU_CNTL_REG;	//Mini Uart Extra Control
	unsigned long AUX_MU_STAT_REG;	//Mini Uart Extra Status
	unsigned long AUX_MU_BAUD_REG;	//Mini Uart Baudrate
} BCM2835_UART1_REGS;

extern volatile BCM2835_UART1_REGS * const uart1_regs;

void print(char *ch);

#endif
