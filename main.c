#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include"def.h"
#include"eint.h"
#include"ISD1700.h"
#include"ADC.h"
#include"LCD12864User.h"
#include"LCD12864Driver_IO.h"
#include"LCD_12864.h"
#include"key.h"

#define PUMP_ONE_START PORTA&=~(1<<0)
#define PUMP_ONE_STOP  PORTA|=(1<<0)
#define PUMP_TWO_START PORTA&=~((1<<0)|(1<<1))
#define PUMP_TWO_STOP  PORTA|=(1<<0)|(1<<1)
#define DRAW_OFF_START PORTA&=~(1<<2)
#define DRAW_OFF_STOP  PORTA|=(1<<2)

typedef union{
signed long data_use;
uchar data_trans[4];
}U_t;

U_t water_yield_curr;
signed long water_yield_need=0;

uchar display_flag=0;
uchar display_change_flag=0;
uchar key_val;
uint timer_counter=0;
uint counter=0;
uint timer=0;
uchar receive_counter=0;
uchar read_sensor_flag=0;
uchar speaker_counter=0;

int main()
{ 
 water_yield_curr.data_use=0;
 port_init();
 usart0_init(51);
 ISD_Init();
 sensor_init();
 lcd_display_initialize(); 
 
 SREG=0x80;
 while(1)
 {
  show_start_image();
  set_water_yield();
  timer1_init();
  display_curr_state();  
  pump();
  maintain();
  system_reset();
 }
}

void port_init()
{
 DDRA|=(1<<0)|(1<<1)|(1<<2);			//控制电机
 PORTA|=(1<<0)|(1<<1)|(1<<2);

}

void show_start_image()
{
 _lcd_picture_draw(gImage_yanshan);
 SetPlay(0);
 do{
  while(key_press()==0);
 }while((key_val=key_scan())!=12);

 
 lcd_screen_clear();
 _lcd_picture_clear();
 lcd_string_write(0x80,"液体转移监控装置");
 lcd_string_write(0x88,"请输入水的体积：");
 lcd_string_write(0x9a,"0000ml");
 //timer1_stop();
 SetPlay(1);
 //timer1_start();
}

void display_water_yield()
{
 lcd_command_write(0x30);	//基本指令集
 lcd_command_write(0x9a);
 lcd_data_write(water_yield_need/1000+48);
 lcd_data_write(water_yield_need%1000/100+48);
 lcd_data_write(water_yield_need%100/10+48);
 lcd_data_write(water_yield_need%10+48);
}

void display_curr_state()
{
 timer1_stop();
 _lcd_picture_clear();
 lcd_screen_clear();
 lcd_string_write(0x80,"液体转移监控装置");
 lcd_string_write(0x90,"设定水量：");
 
 lcd_command_write(0x95);
 lcd_data_write(water_yield_need/1000+48);
 lcd_data_write(water_yield_need%1000/100+48);
 lcd_data_write(water_yield_need%100/10+48);
 lcd_data_write(water_yield_need%10+48);
 lcd_string_write(0x97,"ml");

 read_sensor();
 lcd_string_write(0x88,"当前水量：");
 lcd_command_write(0x8d);
 lcd_data_write(water_yield_curr.data_use/1000+48);
 lcd_data_write(water_yield_curr.data_use%1000/100+48);
 lcd_data_write(water_yield_curr.data_use%100/10+48);
 lcd_data_write(water_yield_curr.data_use%10+48);
 lcd_string_write(0x8f,"ml");

 lcd_string_write(0x98,"所用时间：");
 lcd_command_write(0x9d);
 lcd_data_write(timer_counter/1000+48);
 lcd_data_write(timer_counter%1000/100+48);
 lcd_data_write(timer_counter%100/10+48);
 lcd_data_write(timer_counter%10+48);
 lcd_string_write(0x9f,"s");
 timer1_start();
}

void display_image()
{
 timer1_stop();
 _lcd_picture_clear();
 lcd_screen_clear();
 __lcd_picture_draw(lcd_buffer);
 lcd_picture_draw(gImage_test1);
 timer1_start();
}

void refresh_1()
{
 lcd_command_write(0x8d);
 lcd_data_write(water_yield_curr.data_use/1000+48);
 lcd_data_write(water_yield_curr.data_use%1000/100+48);
 lcd_data_write(water_yield_curr.data_use%100/10+48);
 lcd_data_write(water_yield_curr.data_use%10+48);

 lcd_command_write(0x9d);
 lcd_data_write(timer_counter/1000+48);
 lcd_data_write(timer_counter%1000/100+48);
 lcd_data_write(timer_counter%100/10+48);
 lcd_data_write(timer_counter%10+48);
}

void refresh_2()
{
 lcd_point_draw(counter,(unsigned char)(63-(water_yield_curr.data_use)/50),1);
}

void timer1_init()
{
 TCNT1=59285;
 TIMSK|=(1<<TOIE1);
 TCCR1B|=(1<<2);
}

void timer1_stop()
{
 TCCR1B=0x00;
}

void timer1_start()
{
 TCCR1B|=(1<<2);
}

void set_water_yield()
{
 char weishu=3;
 water_yield_need=0;
 while(key_press()==0);
 key_val=key_scan();
 while(key_val!=12)				
 {
  if((key_val!=3)&&(key_val!=7)&&(key_val!=11)&&(key_val!=14)&&(key_val!=15))
  {
   if((key_val>=0)&&(key_val<=2)){key_val++;}
   else if((key_val>=8)&&(key_val<=10)){key_val--;}
   else if(key_val==13){key_val=0;}
   if(weishu==3)
   {
    water_yield_need+=key_val*1000;
	weishu--;
	display_water_yield();
   }
   else if(weishu==2)
   {
    water_yield_need+=key_val*100;
	weishu--;
	display_water_yield();
   }
   else if(weishu==1)
   {
    water_yield_need+=key_val*10;
	weishu--;
	display_water_yield();
   }
   else if(weishu==0)
   {
    water_yield_need+=key_val;
	display_water_yield();
	weishu--;
   }
  }
  
  while(key_press()==0);
  key_val=key_scan();
  
 }
}

void sensor_init()
{
 usart0_transmit(0x4a);
 usart0_transmit(0x00);
}

void read_sensor()
{
 water_yield_curr.data_use=0;
 receive_counter=0;
 timer1_stop();
 usart0_transmit('L');		//返回重量值
 while(receive_counter<4);
 water_yield_curr.data_use-=800;
 water_yield_curr.data_use/=10;
 if(water_yield_curr.data_use<0)
 {
  water_yield_curr.data_use=0;
 }
 timer1_start();
}

void pump()
{
 read_sensor();
 while(water_yield_curr.data_use<water_yield_need)
 {
  if(key_press()==1)
  {
   key_val=key_scan();
   if(key_val==14)
   {
    display_flag=(display_flag+1)%2;
	if(display_flag==0)
    {
     display_curr_state();
    }
    else 
    {
     display_image();
    }
   }
  }
  PUMP_TWO_START;
  if(read_sensor_flag==1)
  {
   read_sensor();
   read_sensor_flag=0;
  }
  if(speaker_counter>=3)
  {
   speaker_counter=0;
   timer1_stop();
   SetPlay(2);
   timer1_start();
  }
 }
 PUMP_TWO_STOP;
 while(water_yield_curr.data_use>water_yield_need)
 {
  if(key_press()==1)
  {
   key_val=key_scan();
   if(key_val==14)
   {
    display_flag=(display_flag+1)%2;
    if(display_flag==0)
    {
     display_curr_state();
    }
    else 
    {
     display_image();
    }
   }
  }
  DRAW_OFF_START;
  if(read_sensor_flag==1)
  {
   read_sensor();
   read_sensor_flag=0;
  }
  if(speaker_counter>=3)
  {
   speaker_counter=0;
   timer1_stop();
   SetPlay(3);
   timer1_start();
  }
 }
 DRAW_OFF_STOP;
}

void maintain()
{
 while(1)
 {
  if(key_press()==1)
  {
   key_val=key_scan();
   if(key_val==12)break;  
   else if(key_val==14)
   {
    display_flag=(display_flag+1)%2;
	if(display_flag==0)
    {
     display_curr_state();
    }
    else 
    {
     display_image();
    }
   }
  }
  while(water_yield_curr.data_use<water_yield_need)
  {
   PUMP_ONE_START;
   if(read_sensor_flag==1)
   {
    read_sensor();
	read_sensor_flag=0;
   }
  }
  PUMP_ONE_STOP;
  while(water_yield_curr.data_use>water_yield_need)
  {
   DRAW_OFF_START;
   if(read_sensor_flag==1)
   {
    read_sensor();
	read_sensor_flag=0;
   }
  }
  DRAW_OFF_STOP;
  if(read_sensor_flag==1)
  {
   read_sensor();
   read_sensor_flag=0;
  }
  if(speaker_counter>=3)
  {
   speaker_counter=0;
   timer1_stop();
   SetPlay(4);
   timer1_start();
  }
 }
 
}

void system_reset()
{
 timer1_stop();
 timer_counter=0;
 counter=0;
 water_yield_need=0;
}

SIGNAL(TIMER1_OVF_vect)
{
 uchar i,j;
 TCNT1=59285;
 timer++;
 if(timer%5==0)
 {
  timer_counter++;
  counter++;
  speaker_counter++;
 }
 read_sensor_flag=1;
 if(counter>=128)
 {
  counter=0;
  for(i=0;i<64;i++)
  {
   for(j=0;j<16;j++)
   {
    lcd_buffer[i][j]=0;
   }
  }
  if(display_flag==1)
  display_image();
 }
 
 if(display_flag==0)
 {
  lcd_point_draw_buffer(counter,(unsigned char)(63-(water_yield_curr.data_use)/50),1);			//写图片缓冲区
  refresh_1();
 }
 else 
 {
  refresh_2();
 }
}


SIGNAL(USART0_RX_vect)
{
 receive_counter++;
 water_yield_curr.data_trans[4-receive_counter]=UDR0;
}
