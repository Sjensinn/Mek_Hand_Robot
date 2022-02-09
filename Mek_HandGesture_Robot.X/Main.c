/*
 * File:   Main.c
 * Author: Sjensi
 *
 * Mekatronisk Kerfi 1 : Gesture controlled Robot
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

void main(void) {
    system_init();                  //Initiate clock, pins, uart, i2c, timer1 and interrupts
    LCD_init(0x4E);                 //For some Tony Stark action?
    gy_init(0x68);                  //Initiate MPU6050 with I2C address: 0x68
    PCA_Init(130, 0x08);            //Initiate PCA9685 unit with I2C address: 0x80 and prescalar of 130
    
    
    //Variables for Gyro
    int16_t accelo_x, accelo_y, accelo_z;
    int16_t gyro_x, gyro_y, gyro_z;
    int16_t temperature;
    
    //Variables for contact bit
    uint8_t finger1, finger2, finger3;

    while(1){
        LED_TOGGLE();
        gy_Read(&accelo_x, &accelo_y, &accelo_z, &gyro_x, &gyro_y, &gyro_z, &temperature);
        //send accel and gyro data along with noFinger/finger1/finger2/finger3 variablesto Data transformation function
        //send transformed data over Xbee unit
        //__delay_ms(100); //Refresh rate needs to be decied
    }
    return;
}



