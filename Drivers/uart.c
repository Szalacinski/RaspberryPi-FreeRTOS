/**
 *	UART
 *
 *	
 **/
#include "uart.h"
#include "gpio.h"

extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void dummy ( unsigned int );
//-------------------------------------------------------------------
void uart_send ( unsigned int c )
{
    while(1)
    {
        if(GET32(AUX_MU_LSR_REG)&0x20) break;
    }
    PUT32(AUX_MU_IO_REG,c);
}
//-------------------------------------------------------------------
void uart_flush ( void )
{
    while(1)
    {
        if((GET32(AUX_MU_LSR_REG)&0x100)==0) break;
    }
}
//-------------------------------------------------------------------
void hexstrings ( unsigned int d )
{
    //unsigned int ra;
    unsigned int rb;
    unsigned int rc;

    rb=32;
    while(1)
    {
        rb-=4;
        rc=(d>>rb)&0xF;
        if(rc>9) rc+=0x37; else rc+=0x30;
        uart_send(rc);
        if(rb==0) break;
    }
    uart_send(0x20);
}
//-------------------------------------------------------------------
void hexstring ( unsigned int d )
{
    hexstrings(d);
    uart_send(0x0D);
    uart_send(0x0A);
}

void print( char* ch)
{
	while (*ch!=0)
	{
		uart_send((unsigned int)*ch);
		ch++;
	}
	uart_send(0x0D);
	uart_send(0x0A);
}
//-------------------------------------------------------------------
void uart_init(void)
{
	unsigned long a;
		
	//PUT32(IRQ_DISABLE_1,1 << 29);

	PUT32(AUX_ENABLES,1); //change this to OR later
	PUT32(AUX_MU_IER_REG,0);
	PUT32(AUX_MU_CNTL_REG,0);
	PUT32(AUX_MU_LCR_REG,3); //8-bit mode
	PUT32(AUX_MU_MCR_REG,0); //RTS line low
	PUT32(AUX_MU_IER_REG,0x5);

	PUT32(AUX_MU_IIR_REG,0xC6);
	PUT32(AUX_MU_BAUD_REG,270); //115200 baud

	a = pRegs->GPFSEL[1];
	a &= ~(7<<12);	//gpio14
	a |= 2<<12;	//alt5
	a &= ~(7<<15);	//gpio15
	a |= 2<<15;	//alt5
	pRegs->GPFSEL[1] = a;
	pRegs->GPPUD[0] = 0;
	for(a=0; a < 150; ++a)
		dummy(a);
	pRegs->GPPUDCLK[0] = ((1<<14)|(1<<15));
	for(a=0; a < 150; ++a)
		dummy(a);
	pRegs->GPPUDCLK[0] = 0;	
	PUT32(AUX_MU_CNTL_REG,3); //RX/TX enable
	
	//PUT32(IRQ_ENABLE_1,1<<29);
}
