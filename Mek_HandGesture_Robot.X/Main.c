/*
 * File:   Main.c
 * Author: Sjensi
 *
 * Downloaded via GitBash, Edited via MpLab
 * 
 *  * Created on February 6, 2022, 9:50 PM
 */

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 16000000
#endif

#include "config_bits.h"
#include "system_init.h"
#include <xc.h>
#include <stdio.h>
#include "LCD.h"
#include "PCA9685_driver.h"
#include "I2C_MSSP1_driver.h"
#include "gy_521.h"


/*void putch(uint8_t txData);*/

void main(void) {
    system_init();                  //Initiate clock, pins, uart, i2c, timer1 and interrupts
    
    //Variables for Gyro
    int16_t accelo_x, accelo_y, accelo_z;
    int16_t gyro_x, gyro_y, gyro_z;
    int16_t temperature;
    
    gy_init(0x68);

    while(1){
        LED_TOGGLE();
        PORTBbits.RB4 = 0;
        gy_Read(&accelo_x, &accelo_y, &accelo_z, &gyro_x, &gyro_y, &gyro_z, &temperature);
        __delay_ms(50);
    }
    return;
}



/*void putch(uint8_t data){
    while(0 == PIR3bits.TXIF){
        continue;
    }
    TX1REG = data;    // Write the data byte to the USART.
}*/
