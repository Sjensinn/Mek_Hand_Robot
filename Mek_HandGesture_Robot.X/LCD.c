/* 
 * File:   LCD.c
 * Author: Sjensi
 *
 * Created on February 4, 2022, 8:59 AM
 */

#include "LCD.h"

void LCD_init(uint8_t lcd_addr){
    lcd_address = lcd_addr;
    IO_Expander(0x00);
    __delay_ms(30);
    LCD_CMD(0x03);
    __delay_ms(5);
    LCD_CMD(0x03);
    __delay_ms(5);
    LCD_CMD(0x03);
    __delay_ms(5);
    LCD_CMD(LCD_RETURN_HOME);
    __delay_ms(5);
    LCD_CMD(0x20 | (LCD_TYPE << 2));
    __delay_ms(50);
    LCD_CMD(LCD_TURN_ON);
    __delay_ms(50);
    LCD_CMD(LCD_CLEAR);
    __delay_ms(50);
    LCD_CMD(LCD_ENTRY_MODE_SET | LCD_RETURN_HOME);
    __delay_ms(50);
}

void IO_Expander(unsigned char data){
    I2C_Start();//I2C_Master_Start();
    I2C_Write(lcd_address);
    I2C_Write(data | BackLight_State);
    I2C_Stop();
}

void LCD_Write_4Bit(unsigned char Nibble){
  // Get The RS Value To LSB OF Data  
  Nibble |= RS;
  IO_Expander(Nibble | 0x04);
  IO_Expander(Nibble & 0xFB);
  __delay_us(50);
}

void LCD_CMD(unsigned char CMD){
  RS = 0; // Command Register Select
  LCD_Write_4Bit(CMD & 0xF0);
  LCD_Write_4Bit((CMD << 4) & 0xF0);
}

void LCD_write_char(char data){
  RS = 1;  // Data Register Select
  LCD_Write_4Bit(data & 0xF0);
  LCD_Write_4Bit((data << 4) & 0xF0);
}

void LCD_write_string(char* str){
    for(int i=0; str[i]!='\0'; i++)
    LCD_write_char(str[i]); 
}

void LCD_Set_Cursor(unsigned char ROW, unsigned char COL){    
  switch(ROW) 
  {
    case 2:
      LCD_CMD(0xC0 + COL-1);
      break;
    case 3:
      LCD_CMD(0x94 + COL-1);
      break;
    case 4:
      LCD_CMD(0xD4 + COL-1);
      break;
    // Case 1  
    default:
      LCD_CMD(0x80 + COL-1);
  }
}

void Backlight(){
  BackLight_State = LCD_BACKLIGHT;
  IO_Expander(0);
}

void noBacklight(){
  BackLight_State = LCD_NOBACKLIGHT;
  IO_Expander(0);
}

void LCD_SL(){
  LCD_CMD(0x18);
  __delay_us(40);
}

void LCD_SR(){
  LCD_CMD(0x1C);
  __delay_us(40);
}

void LCD_Clear(){
  LCD_CMD(0x01); 
  __delay_us(40);
}