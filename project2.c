/************************************************************
*  @file project2.c
*  @Author Yue Wei
*  @date Mar 3 2018
*************************************************************/

#include<stdint.h>
#include "project1.h"

void project2(void)
{
  GPIO_Configure;
  CB_t buf;
  CB_init(cbuf,16);

  uint8_t data1 = 3;
  uint8_t * ptr1 = &data1;
  UART_send((uint16_t*)ptr1);

  uint8_t data2[] = "hello";
  uint8_t * ptr2 = data2;
  UART_send_n((uint16_t*)ptr2);

  uint8_t data3;
  uint8_t * ptr1 = &data3;
  UART_receive((uint16_t*)ptr1);
  return;
}


