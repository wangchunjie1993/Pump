#include<avr/io.h>
#include"def.h"

/***********************************
* SPI主机初始化，16分频
***********************************/
void SPI_master_init()
{
	DDRB|=(1<<0)|(1<<1)|(1<<2);
	DDRB&=(~(1<<3));
	
	//SPCR = (1<<0)|(1<<4)|(1<<6);
	SPCR=0x78;
	//SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0)|(1<<DORD)|(1<<CPOL);
}

/***********************************
* SPI主机发送数据
***********************************/
uchar SPI_master_transmit(uchar data)
{
    SS_0;
	SPDR = data;
	//while(!(SPSR&(1<<7)));
	while (!(SPSR & (1<<SPIF)));
	return SPDR;
}



/***********************************
* SPI从机机初始化
***********************************/
void SPI_slave_init()
{
	DDRB|=(1<<3);
	DDRB&=(~(1<<0))&(~(1<<1))&(~(1<<2));
	
	SPCR = (1<<6);
}

/***********************************
* SPI从机接收
***********************************/
uchar SPI_slave_receive()
{
	while(!(SPSR&(1<<7)));
	return SPDR;
}
