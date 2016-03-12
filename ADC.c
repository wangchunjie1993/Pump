#include<avr/io.h>
#include"def.h"

/***************************
* ADC的第num通道初始化,num--(0,7)
***************************/
void ADC_init(uchar num)
{
	DDRF&=~(1<<num);
	PORTF&=~(1<<num);
	ADMUX&=~(0x3f);
	ADMUX|=(1<<5)|num;
}

/***************************
* 读取ADC的值
***************************/
int read_ADC()
{
	int ad_val=0;
	ADCSRA|=(1<<7)|(1<<6);
	while((ADCSRA&(1<<4))==0);
	ad_val|=(ADCL>>6);
	ad_val|=(ADCH<<2);
	return ad_val;
}
