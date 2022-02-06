/* 
 * File:   i2c_driver.h
 * Author: user
 *
 * Pre-Requirements: 
 * --PIC16F18877 Microcontroller
 * --16MHz Fosc : if not we must change SSP1ADD
 * --Using MSSP1 with pins RC3 and RC4 for SCL & SDA
 * 
 * How to:
 * 
 * 
 * Created on February 2, 2022, 8:33 PM
 */

#ifndef I2C_DRIVER_H
#define	I2C_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
//Pin macros
#ifndef LED_TOGGLE()            
#define LED_TOGGLE() do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#endif

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 16000000
#endif
    
#include <xc.h>
    
void I2C_init(void);
void I2C_Start(void);
void I2C_Wait(void);
void I2C_Write(uint8_t data);
void I2C_RepeatedStart();
void I2C_Stop(void);

void I2C_Read(uint8_t* readbuffer, uint8_t place, uint8_t a);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_DRIVER_H */

