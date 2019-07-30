//
// arm_timer.h
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
#ifndef _ARM_TIMER_H_
#define _ARM_TIMER_H_

typedef struct {
	unsigned long LOAD;		//Time to count down
	unsigned long VALUE;		//Current timer value
	unsigned long CONTROL;		//Control
	unsigned long IRQ_CLEAR_ACK;	//Clear interrupt-pending bit         WO
	unsigned long RAW_IRQ;		//Read interrupt-pending bit          RO
	unsigned long MASKED_IRQ;	//Status of interrupt                 RO
	unsigned long RELOAD;		//LOAD but only accessed when VALUE == 0
	unsigned long PREDIVIDER;	//apb_clock/(PREDIVIDER+1) = timer_clock
	unsigned long FREE_RUNNING;	//Counter that continues to roll over RO
} BCM2835_ARM_TIMER_REGS;

extern volatile BCM2835_ARM_TIMER_REGS * const arm_timer_regs;

#endif
