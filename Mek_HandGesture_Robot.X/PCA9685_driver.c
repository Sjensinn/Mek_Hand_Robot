
#include "PCA9685_driver.h"
#include "I2C_MSSP1_driver.h"
#include <xc.h>

void PCA_Init(uint8_t prescalar, uint8_t pca_addr){
    pca_address = pca_addr;     //Set the global variable with the address
    
    TRISBbits.TRISB3=0;                 
    PCA_OE_ENABLE();                    //Enabling PCA9685 with OE=0

    I2C_Start();            //Send start bit
    I2C_Write(pca_address);        //0x40 == address of PCA9685
    I2C_Write(0xFE);        //Select Prescalar register
    I2C_Write(prescalar);   //Prescalar value = 0d121 og 0x79 for 50Hz
    I2C_Stop();             //End this transmission
    //__delay_ms(10);

    I2C_Start();
    I2C_Write(pca_address);        //Address
    I2C_Write(0x00);        //MODE1 Register
    I2C_Write(0x21);        //Enable Auto Increment
    I2C_Stop();             //End this transmission
    //__delay_ms(10);

}

void PCA_write(uint8_t ChannelN, uint16_t on, uint16_t off){
    if(ChannelN > 15){
        return; //Error only 15 channels
    }
    
    I2C_Start();                        //Send start bit
    I2C_Write(pca_address);             //Address and R/W cleared
    //I2C_Write((ChannelN * 4) + 6);   //0x06 is the first register of output channels they come in 4
    I2C_Write(0x06);
    I2C_Write(on & 0xff);               //lower byte of 12 bit for ON
    I2C_Write((on & 0xf00) >> 8);       //Higher bits of 12 bit for ON
    I2C_Write(off & 0xff);              //Lower byte of 12 bit for OFF
    I2C_Write((off & 0xf00) >> 8);      //Higher bits of 12 bit for OFF
    I2C_Stop();                         //Send stop bit
}