#ifndef _LCD12864USER_H_
#define _LCD12864USER_H_

#include "LCD12864Driver_IO.h"
extern unsigned char lcd_buffer[64][16];//lcdͼ����ʾ������
extern unsigned char temperature_coordinate[];			//temperature_coordinateͼƬ����
extern unsigned char intel[][8];				//avrͼƬ����
extern unsigned char gImage_test1[1024];
unsigned char gImage_yanshan[1024];
//----------------------------д�ַ���-----------------------------------------------------------//
void lcd_string_write(unsigned char address_8,unsigned char *string_8);
//----------------------------д�����ַ���-------------------------------------------------------//
void lcd_multi_line_string_write(unsigned char address_8,unsigned char *string_8);
//----------------------------��ʾ����-----------------------------------------------------------//
void lcd_display_left_move(unsigned char number_8);
//----------------------------��ʾ����-----------------------------------------------------------//
void lcd_display_right_move(unsigned char number_8);
//----------------------------ȫ������-----------------------------------------------------------//
void lcd_display_inverse(void);
//----------------------------ͼƬ����-----------------------------------------------------------//
void lcd_picture_clear(void);
void _lcd_picture_clear(void);
//----------------------------��ȫ��ͼƬ---------------------------------------------------------//
void lcd_picture_draw(unsigned char *picture_8);
void _lcd_picture_draw(unsigned char picture_8[][8]);
void __lcd_picture_draw(unsigned char picture_8[][16]);
//----------------------------��СͼƬ-----------------------------------------------------------//
void lcd_small_picture_draw(unsigned char x_8,unsigned char y_8,
							unsigned char lenght_8,unsigned char height_8,
							const unsigned char *picture_8);
//----------------------------����---------------------------------------------------------------//
void lcd_point_draw(unsigned char x_8,unsigned char y_8,unsigned char color_8);
void _lcd_point_draw(unsigned char x_8,unsigned char y_8,unsigned char color_8,unsigned char lcd_buffer[64][16]);
//----------------------------��ֱ��-------------------------------------------------------------//�˺��������
void lcd_line_draw(unsigned char x0_8,unsigned char y0_8,
				   unsigned char x1_8,unsigned char y1_8,unsigned char color_8);
//----------------------------��Բ---------------------------------------------------------------//�˺��������
void lcd_circle_draw(unsigned char x_8,unsigned char y_8,unsigned char radius_8);

#endif
