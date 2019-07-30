//
// pwm.h
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
#ifndef _PWM_H_
#define _PWM_H_

typedef struct {
	unsigned long CTL;	//PWM Control
	unsigned long STA;	//PWM Status
	unsigned long DMAC;	//PWM DMA Configuration
	unsigned long RNG1;	//PWM Channel 1 Range
	unsigned long DAT1;	//PWM Channel 1 Data
	unsigned long FIF1;	//PWM FIFO Input
	unsigned long RNG2;	//PWM Channel 2 Range
	unsigned long DAT2;	//PWM Channel 2 Data
} BCM2835_PWM_REGS;

extern volatile BCM2835_PWM_REGS * const pwm_regs;

#endif
