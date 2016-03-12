#ifndef _LCD12864DRIVER_IO_H_
#define _LCD12864DRIVER_IO_H_

#include <avr/io.h>
/*-----------------------LCD����Ӳ��˵��-----------------
//MCU:ATmega128A
//��Ƭ��ʱ�ӣ��ⲿ8MHz����
//LCD�ͺţ�12864ZW
//LCD��������ST7920
//LCD�����ѹ��5V
//���ƽӿڣ����нӿ�
----------------------------END-------------------------*/
/*-----------------------LCD�̶�����----------------------
//MCU---LCD12864ZW_ST7920���п���   	
//Ӳ�����߷�����
//��������������������������������������������������������������
//1. GND(VSS)	--------	GND
//2. VCC(VDD)	--------	VCC
//3. V0			--------	VCC
//4. RS(CS)		--------	PC2
//5. R/W(SID)	--------	PC0
//6. E(SCLK)	--------	PC1
//15.PSB		--------	GND
//17.RST		--------	PC3
//19.LED+(A)	--------	VCC
//20.LED-(K)	--------	GND
��������������������������������������������������������������
----------------------------END-------------------------*/
//D3---LED��
//#define runled_1 	PORTA|=(1<<0)
//#define runled_0 	PORTA&=~(1<<0)
//******************Һ������ض���*********************
//�����Ҫ�޸Ķ˿ڶ��壬ֻ���ڴ˴�����
//*************CS��RS�� �˿� ����**************����Ƭѡ�źţ��ߵ�ƽ��Ч
#define lcd_DDR_CS_Out 		(DDRG|=(1<<2))
#define lcd_PORT_CS_H 		(PORTG|=(1<<2))
#define lcd_PORT_CS_L 		(PORTG&=~(1<<2))
//*************RST �˿� ����*******************��λ�ţ��͵�ƽ��Ч
//#define lcd_DDR_RST_Out 	(DDRC|=(1<<3))
//#define lcd_PORT_RST_H 		(PORTC|=(1<<3))
//#define lcd_PORT_RST_L 		(PORTC&=~(1<<3))
//*************SCLK��E�� �˿� ����*************����ʱ���ź�
#define lcd_DDR_SCLK_Out 	(DDRG|=(1<<4))
#define lcd_PORT_SCLK_H 	(PORTG|=(1<<4))
#define lcd_PORT_SCLK_L 	(PORTG&=~(1<<4))
//*************SID��R/W�� �˿� ����************�������������
#define lcd_DDR_SID_Out 	(DDRG|=(1<<3))
#define lcd_PORT_SID_H 		(PORTG|=(1<<3))
#define lcd_PORT_SID_L 		(PORTG&=~(1<<3))

//���С�����ѡ���
#define lcd_DDR_PSB_OUT 	(DDRG|=(1<<1))
#define lcd_DDR_PSB_H		(PORTG|=(1<<1))
#define lcd_DDR_PSB_L		(PORTG&=~(1<<1))
//-----------------------ms��ʱ---------------------------//
void lcd_ms_delay(unsigned int ms_16);
//-----------------------10us��ʱ-------------------------//
void lcd_10us_delay(unsigned int ten_us_16);
//-----------------------LCD��λ--------------------------//
void lcd_reset(void);
//-----------------------д�ֽ�---------------------------//
void lcd_byte_write(unsigned char byte_8);
//-----------------------д����---------------------------//
void lcd_command_write(unsigned char command_8);
//-----------------------д����---------------------------//
void lcd_data_write(unsigned char data_8);
//-----------------------LCD����--------------------------//
void lcd_screen_clear(void);
//-----------------------��ʾ����-------------------------//
void lcd_display_on_off(unsigned char on_off_8);
//-----------------------LCD��ʼ��------------------------//
void lcd_display_initialize(void);

#endif
