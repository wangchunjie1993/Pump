#include<iom128v.h>
#include"def.h"

/***************
* usart0
***************/
void usart0_init(uint baud);
void usart0_transmit(uchar data);
uchar usart0_receive();
//#pragma interrupt_handler usart0_receive_isr:19
//void usart0_receive_isr();

/***************
* usart1
***************/
void usart1_init(uint baud);
void usart1_transmit(uchar data);

//#pragma interrupt_handler usart1_receive_isr:31
//void usart1_receive_isr();
