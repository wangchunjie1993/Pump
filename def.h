#ifndef __DEF_H__
#define __DEF_H__

#define uchar unsigned char
#define uint unsigned int

/***********ľ�����(cm)**************/
#define a 110	//��
#define b 115	//��
#define L1 116
#define L2 149
#define R 25
#define START_POINT 6
#define OFFSET 9
#define PER_STEP_1 207.5
#define PER_STEP_2 203.5

/***************��������*****************/
/*#define MOD (PIND&0x01)
#define SHU (PIND&0x02)
#define OK  (PIND&0x04)*/


/************1602LCD��������************/
/*#define RS_1 PORTA|=BIT(5)
#define RS_0 PORTA&=~BIT(5)

#define RW_1 PORTA|=BIT(6)
#define RW_0 PORTA&=~BIT(6)

#define E_1 PORTA|=BIT(7)
#define E_0 PORTA&=~BIT(7)*/

//#define EN_0 PORTF&=~BIT(3);
//#define EN_1 PORTF|=BIT(3);
//#define RS_C PORTF&=~BIT(2);
//#define RS_D PORTF|=BIT(2);


/******************12864LCD��������********************/
#define CS PORTG |= (1<<2)			//Ƭѡ�ź�
#define SID_UP PORTG|= (1<<3)		//�ߵ�ƽ�����ź�
#define SID_DOWN PORTG&= ~(1<<3)	//�͵�ƽ�����ź�
#define SCLK_UP PORTG|=(1<<4)		//ͬ��ʱ�Ӹߵ�ƽ�ź�
#define SCLK_DOWN PORTG &= ~(1<<4)	//ͬ��ʱ�ӵ͵�ƽ�ź�
#define RST_UP PORTA|=(1<<5)		//��λ�ź���Ч
#define RST_DOWN PORTA &= ~(1<<5)	//��λ�ź���Ч
#define PSB PORTG&=~(1<<1)			//���С�����ѡ���


/**************��翪��****************/
#define FRONT	(PINA&(1<<0))
#define LEFT	(PINA&(1<<1))
#define RIGHT	(PINA&(1<<2))

/************��������������*************/
/*#define Trig_1 PORTB|=BIT(2)
#define Trig_0 PORTB&=~BIT(2)
#define Echo (PINB&BIT(3))*/


/************���ɰڲ���**************/
#define g 			9.8				//�������ٶ�
#define THRESHOLD	0.07			//���ڼ�����ɰڷ���ʱ���ٶȱ仯������ֵ
#define ERROR		-2				//��ʼλ�����ɰ������ֱλ�����	

typedef union
{
	uchar data_trans[4];		//���������ֽڴ���
	float data_use;				//ֱ��ʹ�õ�����
}float_data;


/******************�������ת����λ��*******************/
#define STEERING_STEP	40
#define MOTOR_STEP		116

/******************SPI--SS*****************/
#define SS_0 PORTB&=~(1<<0)
#define SS_1 PORTB|=(1<<0)


#endif
