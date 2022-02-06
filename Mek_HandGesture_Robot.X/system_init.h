/* 
 * File:   system_init.h
 * Author: Sjensi
 *
 * Created on February 4, 2022, 8:48 AM
 */

#ifndef SYSTEM_INIT_H
#define	SYSTEM_INIT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "config_bits.h"
#include "tcs3200.h"
#include "I2C_MSSP1_driver.h"
#include "PCA9685_driver.h"
#include "timer1.h"

    
//Pin macros
#ifndef LED_TOGGLE()            
#define LED_TOGGLE() do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#endif

    void system_init(void);
    void clock_init(void);
    void pin_init(void);
    void uart_init(void);
    void int_init(void);
    
    


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_INIT_H */

