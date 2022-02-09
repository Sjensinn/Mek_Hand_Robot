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
#include "uart.h"
    
//Pin macros
#ifndef LED_TOGGLE()            
#define LED_TOGGLE() do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#endif

/**
 * @brief   This function initializes clock, pins, i2c, and interrupts
 * @param   void          
 * @return  void
 *
 *  Must be called for systems functionality
 *  Called at the beginning of the program
 *  Called only once.
 */
void system_init(void);

/**
 * @brief   This function initializes the systems clock
 * @param   void          
 * @return  void
 *
 *  Called by system_init()
 *  16MHz clock frequency using HFINTOSC
 * 
 */
void clock_init(void);

/**
 * @brief   This function initializes the systems pins
 * @param   void          
 * @return void
 *  
 *  Sets appropriate analog/digital
 *  Sets appropriate input/output
 *  Sets appropriate inital values
 */
void pin_init(void);

/**
 * @brief   This function enables the systems interrupts
 * @param   void          
 * @return  void
 *
 *  Does not manage interrupt routines.
 */
void int_init(void);
    
    


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_INIT_H */

