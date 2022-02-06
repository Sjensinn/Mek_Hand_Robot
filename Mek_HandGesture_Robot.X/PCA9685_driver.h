/* 
 * File:   PCA9685_driver.h
 * Author: Sjensi
 *
 * --Information: Read before use!
 *      *Measured Clock frequency is 26.763.265 Hz
 *      *Calculated prescalar for given frequency to get 50Hz output is 130
 *      *PCA9685 address: 0x80
 *      *I2c Frequency should be 100kHz
 *      
 * Created on February 3, 2022, 8:27 AM
 */

#ifndef PCA9685_DRIVER_H
#define	PCA9685_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
    
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 16000000
#endif
    
#define PCA_OE_ENABLE() LATBbits.LATB3 = 0;
#define PCA_OE_DISABLE() LATBbits.LATB3 = 1;
    
#define SERVOMIN  95 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  500 // This is the 'maximum' pulse length count (out of 4096)

    uint8_t pca_address;

//Initiate the PCA with given prescalar and address

void PCA_Init(uint8_t prescalar, uint8_t pca_addr);

//Write to LEDn channel with given On and off value
void PCA_write(uint8_t ChannelN, uint16_t on, uint16_t off);
    

#ifdef	__cplusplus
}
#endif

#endif	/* PCA9685_DRIVER_H */

