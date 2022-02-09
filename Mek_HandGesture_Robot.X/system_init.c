/* 
 * File:   system_init.h
 * Author: Sjensi
 *
 * Created on February 4, 2022, 8:48 AM
 */

#include "system_init.h"
#include "uart.h"
#include "I2C_MSSP1_driver.h"

void system_init(){
    clock_init();
    pin_init();
    uart_init();
    I2C_init();
    int_init();
}


void clock_init(){
    // Set the CLOCK CONTROL module to the options selected in the user interface.
    // NDIV 2; NOSC HFINTOSC; 
    OSCCON1 = 0x61;
    OSCCON2 = 0x70;
    // SOSCPWR Low power; CSWHOLD may proceed; 
    OSCCON3 = 0x0;
    // EXTOEN disabled; HFOEN enabled; MFOEN disabled; LFOEN disabled; SOSCEN disabled; ADOEN disabled; 
    OSCEN = 0x40;
    // HFFRQ 32_MHz; 
    OSCFRQ = 0x6;
    // 
    OSCSTAT = 0x0;
    // TUN undefined; 
    OSCTUNE = 0x0;
}

void pin_init(){
       /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x18;
    LATD = 0x0;
    LATE = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0x30;
    TRISB = 0xF1;
    TRISC = 0xBF;
    TRISD = 0x0;
    TRISE = 0x7;

    /**
    ANSELx registers
    */
    ANSELA = 0x30;
    ANSELB = 0xF0;
    ANSELC = 0x67;
    ANSELD = 0x0;
    ANSELE = 0x7;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUB = 0x0;
    WPUC = 0x0;
    WPUD = 0x0;
    WPUE = 0x0;
  

    /**
    APFCONx registers
    */

    /**
    ODx registers
    */
   
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;
    ODCOND = 0x0;
    ODCONE = 0x0;
    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x7;
    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0xF;

    /**
    PPS registers
    */
    RXPPS = 0x17; //RC7->EUSART:RX;
    T1CKIPPS = 0x10; //RC0->TMR1:T1CKI;
    T1GPPS = 0xD; //RB5->TMR1:T1G;
    RC6PPS = 0x10;  //RC6->EUSART:TX;
    SSP1CLKPPS = 0x13;  //RC3->MSSP1:SCL1;
    RC3PPS = 0x14;  //RC3->MSSP1:SCL1;
    SSP1DATPPS = 0x14;  //RC4->MSSP1:SDA1;
    RC4PPS = 0x15;  //RC4->MSSP1:SDA1;

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;
}

void int_init(void){
    INTCONbits.GIE = 1;         //Enable Global interrupts
    INTCONbits.PEIE = 1;        //Enable Pheripheral Interrupts
}