/* 
 * File:   LCD.h
 * Author: Sjensi
 * LCD I2C Address: 0x4E used to init
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
#define LCD_TYPE               2       // 0 -> 5x7 | 1 -> 5x10 | 2 -> 2 lines
    
uint8_t lcd_address, RS;
uint8_t BackLight_State = LCD_BACKLIGHT;
    
void LCD_init(uint8_t lcd_addr);

void IO_Expander(unsigned char data);

void LCD_Write_4Bit(unsigned char Nibble);

void LCD_CMD(unsigned char CMD);

void LCD_write_char(char data);

void LCD_write_string(char* str);

void LCD_Set_Cursor(unsigned char ROW, unsigned char COL);

void Backlight();

void noBacklight();

void LCD_SL();

void LCD_SR();

void LCD_Clear();


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

