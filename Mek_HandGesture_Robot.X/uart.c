
#include <xc.h>
#include "uart.h"

void uart_init(void){
        // Set the EUSART module to the options selected in the user interface.

    // ABDEN disabled; WUE disabled; BRG16 16bit_generator; SCKP Non-Inverted; ABDOVF no_overflow; 
    BAUD1CON = 0x48;

    // ADDEN disabled; CREN enabled; SREN disabled; RX9 8-bit; SPEN enabled; 
    RC1STA = 0x90;

    // TX9D 0x0; BRGH hi_speed; SENDB sync_break_complete; SYNC asynchronous; TXEN enabled; TX9 8-bit; CSRC client; 
    TX1STA = 0x26;

    // SPBRGL 159; 
    SP1BRGL = 0x9F;

    // SPBRGH 1; 
    SP1BRGH = 0x1;
}

void uart_Write(unsigned char data){
    while(0 == PIR3bits.TXIF){
        continue;
    }
    TX1REG = data;    // Write the data byte to the USART.
}
void uart_Write_String(char* buf){
    int i=0;
    while(buf[i] != '\0'){
        uart_Write(buf[i++]);
    }
}