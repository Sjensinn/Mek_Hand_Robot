    
#include <xc.h>
#include "gy_521.h"
#include "I2C_MSSP1_driver.h"
#include "uart.h"
#include <stdio.h>

void gy_init(uint8_t gyAdd){
    gy_address = gyAdd << 1;
    __delay_ms(200);
    
    //Set sampling rate to 1KHz
    I2C_Start();                    //Send start signal
    I2C_Write(gy_address);          //Write address and R/W bit cleared
    I2C_Write(SMPLRT_DIV);          //Sample Rate divider reg
    I2C_Write(0x07);                //Sample rate = gyro_output_rate/(1+ SMPLRT_DIV) for 1KHz
    I2C_Stop();
    
    //Set the clock src and disable sleep
    I2C_Start();                    //Send start signal
    I2C_Write(gy_address);          //Write address and R/W bit cleared
    I2C_Write(PWR_MGMT_1);          //Power management1 reg
    I2C_Write(0x01);                //Using X axis gyro for clock as recommended
    I2C_Stop();
    
    //Configure Digital low pass filter reg
    I2C_Start();                    //Send start signal
    I2C_Write(gy_address);          //Write address and R/W bit cleared
    I2C_Write(CONFIG);              //Config register
    I2C_Write(0x00);                //don't use external inputs
    I2C_Stop();
    
    //Configure gyro to 2000�/s and accel to -+2g
    I2C_Start();                    //Send start signal
    I2C_Write(gy_address);          //Write address and R/W bit cleared
    I2C_Write(GYRO_CONFIG);         //Gyro config register
    I2C_Write(0x00);                //250 deg per sec (0x00), no self test (0x18 for 2000�/sec))
    I2C_Write(0x00);                //Accel config to 0x00 for +-2g
    I2C_Stop();
    
    //Set interrupts
    I2C_Start();                    //Send start signal
    I2C_Write(gy_address);          //Write address and R/W bit cleared
    I2C_Write(INT_ENABLE);          //Interrupts enable Register
    I2C_Write(0x00);                 //When data is ready disable
    I2C_Stop();
}

void gy_Read(int16_t* Ax, int16_t* Ay, int16_t* Az, int16_t* Gx, int16_t* Gy, int16_t* Gz, int16_t* Temp){
    
    I2C_Start();
    I2C_Write(gy_address);          //Address in write
    I2C_Write(ACCEL_XOUT_H);        //First register to read
    I2C_Stop();
    
    uint16_t axt, ayt, azt, gxt, gyt, gzt, tt;
    float axtf, aytf, aztf, gxtf, gytf, gztf, ttf;
    char buffer[40];
    
    //Reading values from the sensor and asigning to pointer
    I2C_Start();
    I2C_Write(gy_address | 0x01);   //Address in read
    I2C_Read(0); //Error??
    axt = ((int16_t)I2C_Read(0)<<8) | I2C_Read(0);
    ayt = ((int16_t)I2C_Read(0)<<8) | I2C_Read(0);
    azt = ((int16_t)I2C_Read(0)<<8) | I2C_Read(0);
    tt  = ((int16_t)I2C_Read(0)<<8) | I2C_Read(0);
    gxt = ((int16_t)I2C_Read(0)<<8) | I2C_Read(0);
    gyt = ((int16_t)I2C_Read(0)<<8) | I2C_Read(0);
    gzt = ((int16_t)I2C_Read(0)<<8) | I2C_Read(1);
    I2C_Stop();
        
    axtf = (float)axt/16384.0;	
    aytf = (float)ayt/16384.0;
    aztf = (float)azt/16384.0;
    gxtf = (float)gxt/131.0;
    gytf = (float)gyt/131.0;
    gztf = (float)gzt/131.0;
    ttf = ((float)tt/340.00)+36.53; /* Convert temperature in �/c */
    
      // Print The Results
    sprintf(buffer,"Ax = %.2f \t",axtf);	
    uart_Write_String(buffer);

    sprintf(buffer," Ay = %.2f \t",aytf);
    uart_Write_String(buffer);

    sprintf(buffer," Az = %.2f \t",aztf);
    uart_Write_String(buffer);

    sprintf(buffer," T = %.2f  ",ttf);
    uart_Write_String(buffer);

    sprintf(buffer," Gx = %.2f \t",gxtf);
    uart_Write_String(buffer);

    sprintf(buffer," Gy = %.2f \t",gytf);
    uart_Write_String(buffer);

    sprintf(buffer," Gz = %.2f\r\n",gztf);
    uart_Write_String(buffer);
    

    
    return;
}

