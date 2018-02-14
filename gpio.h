/************************************************************
*  @file gpio.h 
*  @authour Yue Wei
*  @date Feb 13 2018
*************************************************************/
#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>
#include <stdlib.h>
/************************************************************
*  my_memmove() - Takes two byte pointer (one source and
*       one destination) and a length of bytes to copy from 
*       the source location to the destination. The behavior
*       should handle overlap of src and dst.
*  Inputs:
*       unit8_t * src: Pointer starting byte
*       unit8_t * dst: Pointer ending byte
*       size_t length : Number of bytes to move
*  Return: Return a pointer to the destination(dst)  
*************************************************************/

#define RGB_RED_PIN ()
#define RGB_GREEN_PIN ()
#define RGB_BLUE_PIN ()
#define RGB_GREEN_ON ()
#define RGB_GREEN_OFF ()
#define RGB_GREEN_TOGGLE ()
/************************************************************
*  GPIO_Configure() - Takes two byte pointer (one source and
*       one destination) and a length of bytes to copy from 
*       the source location to the destination. The behavior
*       should handle overlap of src and dst.
*  Inputs:
*       unit8_t * src: Pointer starting byte
*       unit8_t * dst: Pointer ending byte
*       size_t length : Number of bytes to move
*  Return: Return a pointer to the destination(dst)  
*************************************************************/
void GPIO_Configure();

void Toggle_Red_LED();

void PORTB_Set(uint8_t bit_num);

void PORTD_Set(uint8_t bit_num);

void PORTB_Clear(uint8_t bit_num);
void PORTD_Clear(uint8_t bit_num);


void PORTB_Toggle(uint8_t bit_num);
void PORTD_Toggle(uint8_t bit_num);

#endif /*_GPIO_H_*/
