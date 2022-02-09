/* 
 * File:   uart.h
 * Author: Sjensi
 * 
 * UART driver for PIC16F18877 
 * Prerequirements:
 * -16MHz int osc
 * -using pins RC6->EUSART:TX and RC7->EUSART:RX
 * 
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * @brief   This function intitiates the USART module in asynchronous mode
 * @param   void             
 * @return  void
 * 
 *      Baudrate: 9600
 */
void uart_init(void);

/**
 * @brief   This function writes one character to USART bus
 * @param   char data: byte to be written to RX pin          
 * @return  void
 */
void uart_Write(unsigned char data);

/**
 * @brief   This function writes a string to USART bus
 * @param   char* buf: pointer to char array (string)             
 * @return  void 
 */
void uart_Write_String(char* buf);


#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

