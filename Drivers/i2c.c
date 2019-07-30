//
// i2c.c
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
#include "i2c.h"

//extern void dummy(unsigned int);

volatile BCM2835_I2C_REGS * const i2c0_regs = (BCM2835_I2C_REGS *) (0x20205000);
volatile BCM2835_I2C_REGS * const i2c1_regs = (BCM2835_I2C_REGS *) (0x20804000);

//This is used by the HDMI interface, and should not be accessed.
//volatile BCM2835_I2C_REGS * const i2c2_regs = (BCM2835_I2C_REGS *) (0x20805000);

/*
void i2c_init()
{

}

void i2c_read()
{

}

void i2c_write(i2c_dev)
{
	while ((S & 1) || ~(S & 2)) {
		while(DLEN)
			dummy(DLEN);
	}
	
}
*/


