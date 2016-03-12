#include<avr/io.h>
#include<util/delay.h>
#include"def.h"
#include"ISD1700.h"
#include"SPI.h"


uchar SR0_L,SR0_H,SR1,ID,APCL=0,APCH=0;
uint caToneAdd[10]={0x0010,0x001c,0x001d,0x002d,0x002e,0x0035,0x0036,0x0039,0x0040,0x004d};

void ISD_PU()			//�ϵ�
{
 SS_0;
 SPI_master_transmit(ISD1700_PU);
 SPI_master_transmit(0x00);
 SS_1; 
 _delay_ms(50);

}

void ISP_PD()			//�µ�
{
 SS_0;
 SPI_master_transmit(ISD1700_PD);
 SPI_master_transmit(0x00);
 SS_1; 
 _delay_ms(50);

}

void ISP_STOP()			//ֹͣ��ǰ����
{
 SS_0;
 SPI_master_transmit(ISD1700_STOP);
 SPI_master_transmit(0x00);
 SS_1; 
 _delay_ms(50);

}

void RdStatus()		//��ȡ״̬
{
 SS_0;
 SPI_master_transmit(ISD1700_RD_STAUS);
 SPI_master_transmit(0x00);
 SPI_master_transmit(0x00);
 SS_1;
 _delay_ms(50);
 SR0_L=SPI_master_transmit(ISD1700_RD_STAUS);
 SR0_H=SPI_master_transmit(0x00);
 SR1=SPI_master_transmit(0x00);
 SS_1;
 _delay_ms(50);

}

void ClrInt()		//����ж�
{
 SS_0;
 SPI_master_transmit(ISD1700_CLR_INT);
 SPI_master_transmit(0x00);
 SS_1; 
 _delay_ms(50);

}

void ISD_WR_NVCFG()			//����д��Ĵ���
{
 SS_0;
 SPI_master_transmit(ISD1700_WR_NVCFG);
 SPI_master_transmit(0x00);
 SS_1; 
 _delay_ms(50);

}
	
void ISD_WR_APC2()			//����APC2
{
 SS_0;
 SPI_master_transmit(ISD1700_WR_APC2);
 SPI_master_transmit(0xa8);
 SPI_master_transmit(0x0c);
 SS_1; 
 _delay_ms(50);
 ISD_WR_NVCFG();

}

void Rd_APC()	//��ȡAPC
{
 SS_0;
 SPI_master_transmit(ISD1700_RD_APC);
 SPI_master_transmit(0x00);
 SPI_master_transmit(0x00);
 SPI_master_transmit(0x00);
 SS_1; 
 _delay_ms(50);
 SR0_L=SPI_master_transmit(ISD1700_RD_APC);
 SR0_H=SPI_master_transmit(0x00);
 APCL=SPI_master_transmit(0x00);
 APCH=SPI_master_transmit(0x00);
 SS_1;
 _delay_ms(50);
 
}

void ISD_Init()			//��ʼ��
{
 SPI_master_init(); 
 ISD_Reset();
 ISD_Reset();
 ISD_Reset();
 /*do
 {
  ISD_PU();
  _delay_ms(10);
  RdStatus();
  _delay_ms(10);
 }while(((SR0_L&0x01)!=0)||((SR1&0x01)==0));*/
 ISD_PU();
 ISD_PU();
 ISD_PU();
 ClrInt();
 ISD_WR_APC2();
 Rd_APC();
}

void ISD_CHK_MEM()			//�ռ���
{
 SS_0;
 SPI_master_transmit(ISD1700_CHK_MEM);
 SPI_master_transmit(0x00);
  SS_1;
 _delay_ms(50);

}

void ISD_Reset()			//��λ
{
 SS_0;
 SPI_master_transmit(ISD1700_REST);
 SPI_master_transmit(0x00);
 SS_1;
 _delay_ms(50);
 
}

void RD_DevID()		//��ȡID
{
 SS_0;
 SPI_master_transmit(ISD1700_DEVID);
 SPI_master_transmit(0x00);
 SPI_master_transmit(0x00);
 SS_1; 
 _delay_ms(50);
 SR0_L=SPI_master_transmit(ISD1700_DEVID);
 SR0_H=SPI_master_transmit(0x00);
 ID=SPI_master_transmit(0x00);
  SS_1;
 _delay_ms(50);

 return ID;
}


//ȡ����ǰ��������ĩ��ַ
void GetToneAdd(uchar cNum,uint * ipStartAdd,uint * ipEndAdd)
{
 *ipStartAdd=caToneAdd[cNum*2];
 *ipEndAdd=caToneAdd[cNum*2+1];
}

void SetPlay(uchar cNum)		//���㲥��
{
 uint Add_ST,Add_ED;
 uchar Add_ST_H,Add_ST_L,Add_ED_H,Add_ED_L;
 /*do
 {
  RdStatus();
 }while(((SR0_L&0x01)!=0)||((SR1&0x01)==0));*/

 _delay_ms(50);
 ClrInt();
 GetToneAdd(cNum,&Add_ST,&Add_ED);

 Add_ST_L=(uchar)(Add_ST&0x00ff);
 Add_ST_H=(uchar)((Add_ST>>8)&0x00ff);
 Add_ED_L=(uchar)(Add_ED&0x00ff);
 Add_ED_H=(uchar)((Add_ED>>8)&0x00ff);
 
 SS_0;
 SPI_master_transmit(ISD1700_SET_PLAY);
 SPI_master_transmit(0x00);
 SPI_master_transmit(Add_ST_L);
 SPI_master_transmit(Add_ST_H);
 SPI_master_transmit(Add_ED_L);
 SPI_master_transmit(Add_ED_H);
 SPI_master_transmit(0x00);
 SS_1;
 _delay_ms(100);
 
 do
 {
  RdStatus();
 }while(((SR0_L&0x01)!=0)||((SR1&0x04)!=0));

}

void SetREC(uchar cNum)		//����¼��
{
 uint Add_ST,Add_ED;
 uchar Add_ST_H,Add_ST_L,Add_ED_H,Add_ED_L;
 /*do
 {
  RdStatus();
 }while(((SR0_L&0x01)!=0)||((SR1&0x01)==0));*/
 _delay_ms(50);
 ClrInt();
 GetToneAdd(cNum,&Add_ST,&Add_ED);

 Add_ST_L=(uchar)(Add_ST&0x00ff);
 Add_ST_H=(uchar)((Add_ST>>8)&0x00ff);
 Add_ED_L=(uchar)(Add_ED&0x00ff);
 Add_ED_H=(uchar)((Add_ED>>8)&0x00ff);

 SS_0;
 SPI_master_transmit(ISD1700_SET_REC);
 SPI_master_transmit(0x00);
 SPI_master_transmit(Add_ST_L);
 SPI_master_transmit(Add_ST_H);
 SPI_master_transmit(Add_ED_L);
 SPI_master_transmit(Add_ED_H);
 SPI_master_transmit(0x00);
 SS_1; 
 _delay_ms(50);

 do
 {
  RdStatus();
 }while(((SR0_L&0x01)!=0)||((SR1&0x08)==0));
}

void Erase_All()		//ȫ��ɾ��
{
 SS_0;
 SPI_master_transmit(ISD1700_G_ERASE);
 SPI_master_transmit(0x00);
 SS_1; 
 _delay_ms(50);

}
