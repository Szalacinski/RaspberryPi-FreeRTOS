//
// emmc.h
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
#ifndef _EMMC_H_
#define _EMMC_H_

typedef struct {
	unsigned long ARG2;		//ACMD23 Argument
	unsigned long BLKSIZECNT;	//Block Size and Count
	unsigned long ARG1;		//Argument
	unsigned long CMDTM;		//Command and Transfer Mode
	unsigned long RESP0;		//Response bits 31 : 0
	unsigned long RESP1;		//Response bits 63 :32
	unsigned long RESP2;		//Response bits 95 : 64
	unsigned long RESP3;		//Response bits 127 : 96
	unsigned long DATA;		//Data
	unsigned long STATUS;		//Status
	unsigned long CONTROL0;		//Host Configuration bits
	unsigned long CONTROL1;		//Host Configuration bits
	unsigned long INTERRUPT;	//Interrupt Flags
	unsigned long IRPT_MASK;	//Interrupt Flag Enable
	unsigned long IRPT_EN;		//Interrupt Generation Enable
	unsigned long CONTROL2;		//Host Configuration bits
	unsigned long FORCE_IRPT;	//Force Interrupt Event: 0x50
	unsigned long Reserved_1[7];
	unsigned long BOOT_TIMEOUT;	//Timout in boot mode: 0x70
	unsigned long DBG_SEL;		//Debug Bus Configuration: 0x74
	unsigned long Reserved_2[3];
	unsigned long EXRDFIFO_CFG;	//Extension FIFO Configuration: 0x80
	unsigned long EXRDFIFO_EN;	//Extension FIFO Enable
	unsigned long TUNE_STEP;	//Delay per card clock tuning step
	unsigned long TUNE_STEPS_STD;	//Card clock tuning steps for DDR
	unsigned long TUNE_STEPS_DDR;	//Card clock tuning steps for DDR: 0x90
	unsigned long Reserved_3[23];
	unsigned long SPI_INT_SPT;	//SPI Interrupt Support: 0xf0
	unsigned long Reserved_4[2];
	unsigned long SLOTISR_VER;	//Slot Interrupt Status and Version: 0xfc

} BCM2835_EMMC_REGS;

extern volatile BCM2835_EMMC_REGS * const emmc_regs;
#endif
