#include<avr/io.h>
#include"def.h"

void eint0_fall_init()  		//�ⲿ�ж�0���½���
{
 EICRA&=~(3<<0);
 EICRA|=(1<<1);
 EIMSK|=(1<<0);
}

void eint0_rise_init()
{
 EICRA&=~(3<<0);
 EICRA|=(1<<1)|(1<<0);
 EIMSK|=(1<<0);
}


void eint1_fall_init()		//�ⲿ�ж�1���½���
{
 EICRA&=~(3<<2);
 EICRA|=(1<<3);
 EIMSK|=(1<<1);
}

void eint1_rise_init()		//�ⲿ�ж�1��������
{
 EICRA|=(3<<2);
 EIMSK|=(1<<1);
}

void eint2_fall_init()		//�ⲿ�ж�2���½���
{
 EICRA&=~(3<<4);
 EICRA|=(1<<5);
 EIMSK|=(1<<2);
}

void eint2_rise_init()		//�ⲿ�ж�2��������
{
 EICRA|=(3<<4);
 EIMSK|=(1<<2);
}

void eint3_fall_init()		//�ⲿ�ж�3���½���
{
 EICRA&=~(3<<6);
 EICRA|=(1<<7);
 EIMSK|=(1<<3);
}


