
#include <xc.h>
#include "I2C_MSSP1_driver.h"

void I2C_init(void){
        /* CKE disabled; SMP Standard Speed;  */
    SSP1STAT = 0x80;
    /* SSPM FOSC/4_SSPxADD_I2C; CKP disabled; SSPEN DIsabled for now;  */
    SSP1CON1 = 0x8;
    /* SEN disabled; RSEN disabled; PEN disabled; RCEN disabled; ACKEN disabled; ACKDT acknowledge; GCEN disabled;  */
    SSP1CON2 = 0x0;
    /* DHEN disabled; AHEN disabled; SBCDE disabled; SDAHT 100ns; BOEN disabled; SCIE disabled; PCIE disabled;  */
    SSP1CON3 = 0x0;
    /* SSPADD 39;  for 100kHz*/
    //SSP1ADD = 0x27;
    /* SSPADD 159 for 400kHz*/
    SSP1ADD = 159;
    
    TRISCbits.TRISC3 = 1;  //RC3 (SCL) as input
    TRISCbits.TRISC4 = 1;  //RC4 (SDA) as input
    
    SSP1CON1bits.SSPEN = 1;
}

// Waits for previous transmit to finish and then sends the start condition (SEN = 1).
void I2C_Start(void){    
  SSP1CON2bits.SEN = 1;             //Initiate start condition
  I2C_Wait();
}

void I2C_Wait(void){
    while(!PIR3bits.SSP1IF){    //Check if transmission finished, or Start Stop acknowledged
        if(SSP1CON1bits.WCOL == 1){ //If we have an issue with writing
            while(1){
                LED_TOGGLE();
                __delay_ms(50); //Toggle led fast
            }
        }
        continue;
    }
    PIR3bits.SSP1IF = 0; //Clear the flag
}

// Waits for previous transmit to finish and then sends the restart condition (RSEN = 1)
void I2C_RepeatedStart(void){
  SSP1CON2bits.RSEN = 1;           //Initiate repeated start condition
  I2C_Wait();
}

// Waits for previous transmit to finish and then sends the stop condition (PEN = 1).
void I2C_Stop(void){
  SSP1CON2bits.PEN = 1;           //Initiate stop condition
  I2C_Wait();
}

//Sets SSPBUF (transmit/receive buffer) to data.
void I2C_Write(uint8_t data){
  SSP1BUF = data;         //Write data to SSPBUF
  I2C_Wait();
}

//  Takes in an integer, 0 or 1, which is what the Acknowledge Data bit (ACKDT) is set to. Set to 0 to acknowledge (when reading first 2 bytes) and 1 when reading last byte. Also, sends restart condition, and sets Acknowledge Sequence Enable bit (ACKEN) to 1 to initiate acknowledge sequence on SDA and SCL and send ACKDT bit. The hardware automatically clears this bit.
 int8_t I2C_Read(int8_t ackbit){
    int8_t tempreadbuffer;      //Temporary variable for reading from buffer
    
    SSP1CON2bits.RCEN = 1;          //Set Recieve Enable
    I2C_Wait();                     //Wait for ack
    
    tempreadbuffer = SSP1BUF;       //Read data from SSPBUF
    SSP1STATbits.BF = 0;            //clearing the BF (Buffer full flag)
    
    SSP1CON2bits.ACKDT = (ackbit);
    SSP1CON2bits.ACKEN = 1;
    I2C_Wait();
    
    return tempreadbuffer;                         
}

