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
 *  Servo min and servo max needs to be tested manually
 *  approximately 100 min and 500 max
 * 
 * 
 *  Example - inside main
 *      PCA_Init(130, 0x80); //first initiate
 * 
 *      //To find min max values
 *      LATBbits.LATB2 = 0;             //Min range
        PCA_write(0, 4000, 95);         //4095 is max resolution, On for 4000/4095, off for 95/4095
        __delay_ms(5000);

        LATBbits.LATB2 = 1;             //Max range
        PCA_write(0, 3595, 500);        //4095 is max resolution, On for 500/4095, Off for 3595/4095
        __delay_ms(5000);
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
    

    uint8_t pca_address;

/**
 * @brief This function initializes the PCA9685 unit
 *        This routine must be called before any other PCA9685 routines.
 * @param   8 bit value for PCA9685 prescalar 
 *          8 bit value for PCA9685 I2C address
 * @return void.
 *
 * @code
 * void main(void){
 *     PCA_Init();
 *     
 *     while(1){   
 *         PCA_Tasks();
 *     }
 * }
 * @endcode
 */
void PCA_Init(uint8_t prescalar, uint8_t pca_addr);

/**
 * @brief This function writes values on/off to led channel ChannelN of PCA9685
 * @param ChannelN : The number of the channel of PCA9685 to be written to
 *              on : The on value for given channel - Set to 0 for servo
 *             off : The off value for given channel - 5% to 10% duty cycle for Servo             
 * @return void.
 *
 * @code
 * void main(void){
 *     PCA_Init();
 *     
 *     while(1){   
 *         PCA_Write(0, 0, SERVOMIN);
 *          __delay_ms(500);
 *          PCA_Write(0, 0, SERVOMAX);
 *     }
 * }
 * @endcode
 */
void PCA_write(uint8_t ChannelN, uint16_t on, uint16_t off);
    

#ifdef	__cplusplus
}
#endif

#endif	/* PCA9685_DRIVER_H */

