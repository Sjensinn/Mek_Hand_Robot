/*
 * File:   Main.c
 * Author: Sjensi
 *
 * Created on February 6, 2022, 9:50 PM
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


void putch(uint8_t txData);

void main(void) {
    system_init();                  //Initiate clock, pins, uart, i2c, timer1 and interrupts
    //PCA_Init(130, 0x80);          //Initiate PCA9685 module with 130 prescalar and address = 0x80
    //LCD_init(0x4E);               // Initialize LCD module with I2C address = 0x4E
    //sensor_init();                //Initialize the TCS3200 sensor
    
    while(1){                       //Embedded systems never stop having fun!
        LED_TOGGLE();               //And we have rave lights
        __delay_ms(1000); 
    }
    return;
}



void putch(uint8_t data){
    while(0 == PIR3bits.TXIF){
        continue;
    }
    TX1REG = data;    // Write the data byte to the USART.
}