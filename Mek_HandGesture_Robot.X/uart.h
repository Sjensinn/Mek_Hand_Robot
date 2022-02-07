/* 
 * File:   uart.h
 * Author: user
 *
 * Created on February 7, 2022, 7:57 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

void uart_init(void);
void uart_Write(unsigned char data);
void uart_Write_String(char* buf);


#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

