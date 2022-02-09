/* 
 * File:   LCD.h
 * Author: Sjensi
 * 
 * LCD I2C Address: 0x4E used to init
 * 
 * Created on February 4, 2022, 8:59 AM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "I2C_MSSP1_driver.h"

#define LCD_BACKLIGHT          0x08
#define LCD_NOBACKLIGHT        0x00
#define LCD_FIRST_ROW          0x80
#define LCD_SECOND_ROW         0xC0
#define LCD_THIRD_ROW          0x94
#define LCD_FOURTH_ROW         0xD4
#define LCD_CLEAR              0x01
#define LCD_RETURN_HOME        0x02
#define LCD_ENTRY_MODE_SET     0x04
#define LCD_CURSOR_OFF         0x0C
#define LCD_UNDERLINE_ON       0x0E
#define LCD_BLINK_CURSOR_ON    0x0F
#define LCD_MOVE_CURSOR_LEFT   0x10
#define LCD_MOVE_CURSOR_RIGHT  0x14
#define LCD_TURN_ON            0x0C
#define LCD_TURN_OFF           0x08
#define LCD_SHIFT_LEFT         0x18
#define LCD_SHIFT_RIGHT        0x1E
#define LCD_TYPE               2       
    
uint8_t lcd_address, RS;
uint8_t BackLight_State = LCD_BACKLIGHT;
    
/**
 * @brief   This function initializes the LCD screen with 4 bit procedure
 *          Refer to datasheet for intial procedure 
 * @param   8 bit lcd i2c address          
 * @return  void
 *
 */
void LCD_init(uint8_t lcd_addr);

/**
 * @brief   This function writes to LCD 
 * @param   unsigned char data (uint8_t) data to be written            
 * @return  void
 *
 *  Used by other functions
 */
void IO_Expander(unsigned char data);

/**
 * @brief   This function writes 4 bits to LCD
 * @param   unsigned char Nibble: half of the data to be written            
 * @return  void
 *
 * Used by other functions
 */
void LCD_Write_4Bit(unsigned char Nibble);

/**
 * @brief   This function writes to LCD CMD
 * @param   unsigned char CMD : data to be written            
 * @return  void
 * 
 * Sets register select to 0
 *
 */
void LCD_CMD(unsigned char CMD);

/**
 * @brief   This function writes a character to the LCD
 * @param   char data: Character to be written          
 * @return  void
 */
void LCD_write_char(char data);

/**
 * @brief   This function writes a string to the LCD
 * @param   char* str : String to print             
 * @return  void
 */
void LCD_write_string(char* str);

/**
 * @brief   This function sets the cursor at a specific location on LCD
 * @param   unsigned char ROW: Which Row will the cursor be placed at
 *          unsigned char COL: What COL will the cursor be placed at          
 * @return  void
 */
void LCD_Set_Cursor(unsigned char ROW, unsigned char COL);

/**
 * @brief   This functions turns on the backlight on the LCD
 * @param   void             
 * @return  void
 */
void Backlight();

/**
 * @brief   This functions turns off the backlight on the LCD
 * @param   void             
 * @return  void
 */
void noBacklight();

/**
 * @brief   This functions slides screen text right 
 * @param   void             
 * @return  void
 */
void LCD_SL();

/**
 * @brief   This functions slides screen text left 
 * @param   void             
 * @return  void
 */
void LCD_SR();

/**
 * @brief   This functions cleares the screen 
 * @param   void             
 * @return  void
 */
void LCD_Clear();


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

