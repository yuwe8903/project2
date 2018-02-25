
/************************************************************
*  @file uart.c
*  @description This is the function defination for the
*       function declaraion in uart.h file
*  @author Yue Wei
*  @date Feb 19 2018
*************************************************************/
#include "uart.h"
#include <stdint.h>
#include "MKL25Z4.h"
void UART_configure()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK; /*enable gate clock for portA*/
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK; /*enable gate clock for uart0*/

	/*select Alt2 for UART0_RX and TX*/
	PORTA_PCR1 |= PORTA_MUX1; //UART0_RX
	PORTA_PCR1 &= PORTA_MUX2; //UART0_RX
	PORTA_PCR2 |= PORTA_MUX1; //UART0_TX
	PORTA_PCR2 &= PORTA_MUX2; //UART0_TX

	/*Select clock source PLL/FLL clock */
	SIM_SOPT2 &= ~(SIM_SOPT2_UART0SRC_MASK);
	SIM_SOPT2 |= UART0SRC_MASK;
	SIM_SOPT2 &= ~(SIM_SOPT2_PLLFLLSEL_MASK); /*PLL, FLL select, 0 is FLL*/
	//SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK;  /*PLL, FLL select, 1 is PLL/2 */


	/*Set up baud rate = 38400,
	 * if OSR+1 =  5x(00100) then SBR = 250 = 0b1111_1010 = 0xFA
	 * if OSR+1 = 10x(01001) then SBR = 125 = 0b0111_1101 = 0x7D
	 * if OSR+1 = 25x(11000) then SBR =  50 = 0b0011_0010 = 0x32
	 */
	//uint16_t sbr = (DEFAULT_SYSTEM_CLOCK/(OVER_SAMPLE+1)) / BAUD_RATE;
	UART0_BDH &= ~UARTLP_BDH_SBR_MASK; /*clear SRB bits, MASK = 0x1F*/
	UART0_BDH &= UART_STOP_BIT_MASK;   /*clear STOP bit, MASK = 0b1101_1111*/
	//UART0_BDH |= (sbr>>8);
	UART0_BDL &= ~UARTLP_BDL_SBR_MASK; /*clear SRB bits, MASK = 0xFF*/
	UART0_BDL |= 0x7D;
	//UART0_BDL |= sbr;
	UART0_C4 &= ~UARTLP_C4_OSR_MASK;   /*clear OSR bits, MASK = 0x1F*/
	UART0_C4 |= OVER_SAMPLE_MASK;           /*set OSR bits, MASK = 0b01001*/

	//UART0_C1 &= UART_NO_PARITY_MASK; /*disable parity bit, MAKS = 0b1111_1101*/
	//UART0_C1 &= UART_8BIT_MASK;      /*RX and TX using 8bit data, MAKS = 0b1110_1111 */
	UART0_C1 &= 0x00;
	UART0_C2 |= UARTLP_C2_RE_MASK | UARTLP_C2_TE_MASK;
	UART0_S2 &= UART_LSB_MASK;

	//SIM_SOPT5_UART0TXSRC_MASK;
	//SIM_SOPT5_UART0RXSRC_MASK;
	//SIM_SOPT5_UART0TXSRC(0);
	return;
}

void UART_send(uint16_t * ptr)
{
	while((UART0_S1 & UART_S1_TDRE_MASK) != 0)
	{
		UART0_D = *ptr;
	}
	return;
}

void UART_send_n(uint16_t * ptr, size_t length)
{
	for(uint8_t i = 0; i<length; i++)
	{
		while((UART0_S1 & UART_S1_TDRE_MASK) != 0)
		{
			UART0_D = *ptr;
		}
		ptr++;
	}
	return;
}


int8_t UART_receive(uint16_t * ptr)
{
	int8_t data;
	*ptr = UART0_D;
	while((UART0_S1 & UARTLP_S1_RDRF_MASK) ==0)
	{
		data = *ptr;
	}
	return data;
}


int32_t UART_receive_n(uint16_t * ptr, size_t length)
{
	return 0;
}


void UART0_IRQHandler()
{
	return;
}
