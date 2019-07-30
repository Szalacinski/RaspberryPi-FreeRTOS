//
// i2c.h
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
#ifndef _I2C_H_
#define _I2C_H_

typedef struct {
	unsigned long C;	//Control
	unsigned long S;	//Status
	unsigned long DLEN;	//Data Length
	unsigned long A;	//Slave Address
	unsigned long FIFO;	//Data FIFO
	unsigned long DIV;	//Clock Divider
	unsigned long DEL;	//Data Delay
	unsigned long CLKT;	//Clock Stretch Timeout
} BCM2835_I2C_REGS;

//SDA ALT0 GPIO0 & SCL ALT0 GPIO1
extern volatile BCM2835_I2C_REGS * const i2c0_regs;

//SDA ALT0 GPIO2 & SCL ALT0 GPIO3
extern volatile BCM2835_I2C_REGS * const i2c1_regs;

//This is used by the HDMI interface, and should not be accessed.
//extern volatile BCM2835_I2C_REGS * const i2c2_regs;

#endif
