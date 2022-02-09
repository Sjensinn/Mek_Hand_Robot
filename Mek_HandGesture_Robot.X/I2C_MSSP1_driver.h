/* 
 * File:   I2C_MSSP1_driver.h
 * Author: Sjensi
 *
 * Pre-Requirements: 
 * --PIC16F18877 Microcontroller
 * --16MHz Fosc : if not we must change SSP1ADD
 * --Using MSSP1 with pins RC3 and RC4 for SCL & SDA
 * 
 * Created on February 2, 2022, 8:33 PM
 */

#ifndef I2C_DRIVER_H
#define	I2C_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

//Pin macros
#ifndef LED_TOGGLE()            
#define LED_TOGGLE() do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#endif

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 16000000
#endif
    
/**
 * @brief   This function Initates the I2C unit in MSSP1 as a master
 * @param   void          
 * @return  void
 * 
 * SCL is set to: 100kHz / 400 kHz
 * This function must be called before any other I2C function.
 * Only called once.
 */
void I2C_init(void);

/**
 * @brief   This function sends a start bit to the I2C bus to initiate communications
*  @param   void          
 * @return  void
 *
 * @code
 * void main(void){
 *     I2C_init();
 * 
 *     while(1){   
 *      I2C_Start();
 *      I2C_Write(address<<1);
 *      I2C_Write(register);
 *      I2C_Write(data);
 *      I2C_Stop();
 *     }
 * }
 * @endcode
 */
void I2C_Start(void);

/**
 * @brief   This function waits for the interrupt flag, then clears the interrupt flag bit and returns
 *          Used by other I2C functions
 * @param   void          
 * @return  void
 *
 */
void I2C_Wait(void);

/**
 * @brief   This function Writes data to SSP1BUF register, then waits for the data to be acknowledged 
 * @param   8 bit data to be written          
 * @return  void
 *
  * @code
 *  void main(void){
 *     I2C_init();
 * 
 *     while(1){   
 *      I2C_Start();
 *      I2C_Write(address<<1);
 *      I2C_Write(register);
 *      I2C_Write(data);
 *      I2C_Stop();
 *     }
 *  }
 * @endcode
 */
void I2C_Write(uint8_t data);

/**
 * @brief   This function writes repeated start to I2C bus
 * @param   void            
 * @return  void
 */
void I2C_RepeatedStart();

/**
 * @brief   This function writes stop signal to I2C bus
 * @param   void          
 * @return  void
 */
void I2C_Stop(void);

/**
 * @brief   This function reads data from I2C slave
 * @param   Ackbit (0/1) to determine if we want to continue transmission          
 * @return  returns data from SSP1BUF
 *
  * @code
 *  void main(void){
 *     I2C_init();
 *       
 *      int8_t buffer[10];
 * 
 *     while(1){   
 *      I2C_Start();
 *      I2C_Write(address<<1);
 *      I2C_Write(register);
 *      I2C_Stop();
 *      
 *      I2C_Start();
 *      I2C_Write(address<<1 + 0x01);
 *      for(int i = 9; i >= 0; i--){
 *          if(i > 1 || i != 0){
 *            buffer[i] = I2C_Read(0); 
 *          }
 *          else{
 *              buffer[i] = I2C_Read(1);
 *          }
 *       } 
 *      I2C_Stop();     
 *     }
 *  }
 * @endcode
 */
int8_t I2C_Read(int8_t ackbit);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_DRIVER_H */

