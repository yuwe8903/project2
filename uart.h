
/***************************************************************
*  @file uart.h
*  @description declare macros and functions for uart.c
*  @author Yue Wei
*  @date Feb 19 2018
****************************************************************/

#ifndef _UART_H_
#define _UART_H_

#include "MKL25Z4.h"
#include <stdint.h>
#include <stdlib.h>

/*BAUD RATE macro*/
#define BAUD_RATE (38400)
//#define CLOCK_SETUP (1)
#define OVER_SAMPLE_MASK (0b01001)
#define SRB_MASK (0x7D)

/* Clock macro*/
#define UART0_CLK_MASK (0x00000400)
#define PORTB_CLK_MASK (0x00000400)
#define PORTD_CLK_MASK (0x00001000)

/*macro declaration for the the MUXbit(10-8) to select Alt2 0b010 for UART0*/
#define PORTA_MUX1 (0x200)      /*OR  bit9 to 1 */
#define PORTA_MUX2 (0xFFFFFAFF) /*AND bit8, bit10 to 0 */

/*Choose bit 26&27 of UART0SRC to be 01 MCGFLLCLK or MCGPLLCLK/2*/
#define UART0SRC_MASK (0x04000000)

/*UART0 control registers mask macro*/
#define UART_LSB_MASK (0xDF)  //clear bit 5 to 0 using &, in UART0_S2
/*
#define UART_NO_PARITY_MASK (0xFD) //clear bit 2 to 0 using &, in UART0_C1
#define UART_ILT_BIT_MASK (0xFB)   //clear bit 3 to 0 using &, in UART0_C1
#define UART_WAKE_BIT_MASK (0xF7)  //clear bit 4 to 0 using &, in UART0_C1
#define UART_8BIT_MASK (0xEF)      //clear bit 5 to 0 using &, in UART0_C1
#define UART_RSRC_BIT_MASK (0xDF)  //clear bit 6 to 0 using &, in UART0_C1
#define UART_DOZEEN_BIT_MASK (0xBF)//clear bit 7 to 0 using &, in UART0_C1
#define UART_LOOPS_BIT_MASK (0x7F) //clear bit 8 to 0 using &, in UART0_C1
*/
#define UART_STOP_BIT_MASK (0xDF)  //clear bit 5 to 0 using &, in UART0_BDH

/*********************************************************
* void UART_configure() - This function will configure
* 	UART to 9600 8N1
* Inputs:
* 	No inputs
* Return:
*   Nothing
**********************************************************/
void UART_configure();

/*********************************************************
* void UART_send() - This function will sent a single
* 	byte down to a specific UART device.
* Inputs:
* 	ptr: pointer points to the data item to send
* Return:
*   Nothing
**********************************************************/
void UART_send(uint16_t * ptr);

/*********************************************************
* void UART_send_n() - This function will sent multiple
* 	block of data down to a specific UART device.
* Inputs:
* 	ptr: pointer points to contiguous block of data
* 	length: number of items
* Return:
*   Nothing
**********************************************************/
void UART_send_n(uint16_t * ptr, size_t length);

/*********************************************************
* int8_t UART_receive() - This function will return a
* 	received byte on the UART using an input pointer.
* Inputs:
* 	ptr: pointer points to the memory location to place
* 	data that's being received.
* Return:
*   return the received data
**********************************************************/
int8_t UART_receive(uint16_t * ptr);

/*********************************************************
* int32_t UART_receive_n() - This function will receive
* 	a number of bytes on the UART using an input pointer.
* Inputs:
* 	ptr: pointer points to the memory location to place
* 	data that's being received.
* 	length: number of items to receive
* Return:
*   return the received data
**********************************************************/
int32_t UART_receive_n(uint16_t * ptr, size_t length);

/*********************************************************
* void UART0_IRQHandler() - This function is the IRQ
* 	handler for the UART. It should clear the associated
* 	flag when completed.
* Handle two types of interrupt:
* 	a. Receive Interrupt
* 	b. Transmit Interrupt
* Inputs:
* 	No inputs
* Return:
*   No return
**********************************************************/
void UART0_IRQHandler();

#endif /* _UART_H_ */
