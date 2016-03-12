#include "LCD12864Driver_IO.h"
/**************************************************************************
//����void lcd_ms_delay(unsigned int ms_16)
//���ܣ�ms��ʱ
//��������ʱʱ��
***************************************************************************/
void lcd_ms_delay(unsigned int ms_16)
{
	unsigned int i,j;
	for(i=0;i<ms_16;i++)
	{
	   for(j=0;j<795;j++);
    }
}
/**************************************************************************
//����void lcd_10us_delay(unsigned int ten_us_16)
//���ܣ�10us��ʱ
//��������ʱʱ��
***************************************************************************/
void lcd_10us_delay(unsigned int ten_us_16)
{
    unsigned int p,q;
    for(p=ten_us_16;p>0;p--)
        for(q=9;q>0;q--);
}
/**************************************************************************
//����void lcd_reset(void)
//���ܣ�LCD��λ
//��������
***************************************************************************/
void lcd_reset(void)
{
	/*lcd_PORT_RST_L;			//��λ�����õ�
	lcd_ms_delay(5);		//��ʱ1ms
	lcd_PORT_RST_H;			//��λ�����ø�*/
}
/**************************************************************************
//����void lcd_byte_write(unsigned char byte_8)
//���ܣ�д�ֽ�
//������һ���ֽ����ݣ�8λ��
***************************************************************************/
void lcd_byte_write(unsigned char byte_8)
{	
	unsigned char i;
	lcd_PORT_SCLK_L;
	for(i=8;i>0;i--)
	{
		if(byte_8 & 0x80) lcd_PORT_SID_H;	//��1
		else lcd_PORT_SID_L;				//��0
		//NOP();			//����ʱ��
		lcd_PORT_SCLK_H;
		lcd_PORT_SCLK_L;
		byte_8=byte_8<<1;
		//------------------//
		//lcd_10us_delay(1);	//ģ��SPI����ͨ�ţ���ʱ
		//------------------//������SPI�ٶȣ���ʱԽ����SPI�����ٶ�Խ����
	}
}
/**************************************************************************
//����void lcd_command_write(unsigned char command_8)
//���ܣ�д����
//��������ַ�����8λ��
***************************************************************************/
void lcd_command_write(unsigned char command_8)
{
	lcd_byte_write(0xf8);	//��ʼ�ֽڣ�11111��WR=0��д����RS=0��ָ���0
	lcd_byte_write(command_8 & 0xf0);		//д����λ
	lcd_byte_write(command_8<<4&0xf0);	//д����λ
}
/**************************************************************************
//����void lcd_data_write(unsigned char data_8)
//���ܣ�д����
//���������ݣ�8λ��
***************************************************************************/
void lcd_data_write(unsigned char data_8)
{
	lcd_byte_write(0xfa);	//��ʼ�ֽڣ�11111��WR=0��д����RS=1�����ݣ���0
	lcd_byte_write(data_8 & 0xf0);		//д����λ
	lcd_byte_write(data_8<<4&0xf0);	//д����λ	
}
/**************************************************************************
//����void lcd_screen_clear(void)
//���ܣ�LCD����
//��������
***************************************************************************/
void lcd_screen_clear(void)
{
	lcd_command_write(0x30);	//����ָ�
	lcd_command_write(0x01);	//�����ʾDDRAM
	lcd_ms_delay(2);
}
/**************************************************************************
//����void lcd_display_on_off(unsigned char on_off_8)
//���ܣ���ʾ����
//���������ر�����Ϊ1����ʾ����������ʾ�ء�
***************************************************************************/
void lcd_display_on_off(unsigned char on_off_8)
{
	lcd_command_write(0x30);	//����ָ�
	if(on_off_8==1) lcd_command_write(0x0C);	//��ʾ״̬���أ�������ʾ���������ʾ�أ������ʾ���׹�
	else lcd_command_write(0x08);				//��ʾ״̬���أ�������ʾ�أ������ʾ�أ������ʾ���׹�
}
/**************************************************************************
//����void lcd_display_initialize(void)
//���ܣ�LCD��ʼ��
//��������
***************************************************************************/
void lcd_display_initialize(void)
{
	//unsigned char init_cycles=2;
	//lcd_DDR_RST_Out;		//��λ��������Ϊ���
	lcd_DDR_SID_Out;		//������������Ϊ���
	lcd_DDR_SCLK_Out;		//ʱ����������Ϊ���
	lcd_DDR_CS_Out;			//Ƭѡ��������Ϊ���
	lcd_DDR_PSB_OUT;
	lcd_DDR_PSB_L;
	lcd_ms_delay(40);
	lcd_reset();			//LCD��λ
	lcd_PORT_CS_H;			//Ƭѡʹ��
	lcd_command_write(0x30);	//����ָ�
	lcd_10us_delay(15);
	lcd_command_write(0x30);	//����ָ�
	lcd_10us_delay(5);
	lcd_command_write(0x0C);	//��ʾ״̬���أ�������ʾ���������ʾ�أ������ʾ���׹�
	lcd_10us_delay(15);
	lcd_command_write(0x01);	//�����ʾDDRAM
	lcd_ms_delay(15);
	lcd_command_write(0x06);	//��ʼ���趨���������
	lcd_command_write(0x02);	//��ַ����
	lcd_screen_clear();		//LCD����
	lcd_display_on_off(1);	//����ʾ
	//�����ǳ�ʼ�����LED�ź�ָʾ����˸����
	/*while(init_cycles!=0)	//LED�ƣ�D3����˸����
	{
		runled_1;			//D3---LED����
		lcd_ms_delay(300);
		runled_0;			//D3---LED����
		lcd_ms_delay(300);
		init_cycles--;
	}
	runled_0;				//D3---LED����*/
}
