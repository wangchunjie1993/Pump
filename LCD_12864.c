//ICC-AVR application builder : 2013/7/4 18:16:05
// Target : M128
// Crystal: 8.0000Mhz

#include<avr/io.h>
#include<util/delay.h>
#include"LCD12864Driver_IO.h"
#include"def.h"


 //功能 : 按照液晶的串口通信协议，发送数据
void write_bit(uchar bits)
{
 uchar i;
 for(i=0;i<8;i++)
 {
  if((bits<<i) & 0x80)
  {
   SID_UP;
  }
  else
  {
   SID_DOWN;
  }
  SCLK_DOWN;
  SCLK_UP;
 }
}


//功能 : 写串口指令
void write_command(uchar command)
{
 CS;
 write_bit(0xf8);//串口格式，写控制指令
 write_bit(command & 0xf0);//写高4位
 write_bit((command<<4) & 0xf0);//写低4位
 _delay_ms(2);
}

//功能 : 写串口数据
void write_data(uchar data)
{
 CS;
 write_bit(0xfa);//写数据
 write_bit(data & 0xf0);//写高4位
 write_bit((data<<4) & 0xf0);//写低4位
 _delay_ms(2);
}

 //设定显示位置
void write_address(uchar x,uchar y)
{
 uchar add;
 switch(x)
 {
  case 0:add=0x80+y;break;
  case 1:add=0x90+y;break;
  case 2:add=0x88+y;break;
  case 3:add=0x98+y;break;
 }
 write_command(add);
 _delay_us(90);
}

void write_word(uchar *pos)
{
  while(*pos)
  {
   write_data(*pos);
   pos++;
   _delay_us(90);
  }
}
void init_12864(void)
{
 //RST_DOWN;
 //delay(10);
 //RST_UP;
 //delay(50);
 lcd_DDR_RST_Out;		//复位引脚设置为输出
 lcd_DDR_SID_Out;		//数据引脚设置为输出
 lcd_DDR_SCLK_Out;		//时钟引脚设置为输出
 lcd_DDR_CS_Out;
 lcd_DDR_PSB_OUT;
 write_command(0x30);//功能设置:设置为基本指令集
 _delay_us(90);
 write_command(0x0c);//整体显示，不显示光标和位置
 _delay_us(90);
 write_command(0x01);//清屏
 _delay_ms(8);
 PSB;
}




