#include<avr/io.h>
#include"def.h"

void delay1ms(void)
{
 uint i;
 for(i=0;i<1140;i++);
}

void delayms(uint x)
{
 uint i;
 for(i=0;i<x;i++)
 delay1ms();
}

void delay_25us(void)
{
 uchar i;
 for(i=0;i<30;i++);
}

void delay(uint x)
{
 uint i,j;	
 for(i=0;i<x;i++)
 for(j=0;j<30;j++);
}

void delay_10us(void)
{
 char i;
 for(i=0;i<30;i++);
}

void delay_us(uchar us)
{
 uint i;
 for(i=us;i>0;i--)
   asm("nop");
}

void delay_ms(uint ms)
{
 uint i,j;
 for(i=ms;i>0;i--)
     for(j=1141;j>0;j--);
} 
