#include "config.h"
#include "lcd.h"

void LCD_Clear(void) {
    LCD_Cmd(0x01);
    __delay_ms(2);
}

void LCD_Init(void) {
    __delay_ms(50);
    LCD_Cmd(0x33); __delay_ms(5);
    LCD_Cmd(0x32); __delay_ms(5);
    LCD_Cmd(0x28);
    LCD_Cmd(0x0C);
    LCD_Cmd(0x06);
    LCD_Clear();
}

void LCD_Cmd(unsigned char cmd) {
    RS = 0;
    D7 = (cmd >> 7) & 1; D6 = (cmd >> 6) & 1;
    D5 = (cmd >> 5) & 1; D4 = (cmd >> 4) & 1;
    EN = 1; __delay_us(10); EN = 0; __delay_us(100);
    
    D7 = (cmd >> 3) & 1; D6 = (cmd >> 2) & 1;
    D5 = (cmd >> 1) & 1; D4 = (cmd >> 0) & 1;
    EN = 1; __delay_us(10); EN = 0; __delay_ms(2);
}

void LCD_WriteChar(char c) {
    RS = 1;
    D7 = (c >> 7) & 1; D6 = (c >> 6) & 1;
    D5 = (c >> 5) & 1; D4 = (c >> 4) & 1;
    EN = 1; __delay_us(10); EN = 0; __delay_us(100);
    
    D7 = (c >> 3) & 1; D6 = (c >> 2) & 1;
    D5 = (c >> 1) & 1; D4 = (c >> 0) & 1;
    EN = 1; __delay_us(10); EN = 0; __delay_us(100);
}

void LCD_WriteString(const char *str) {
    while(*str) LCD_WriteChar(*str++);
}

void LCD_SetCursor(unsigned char row, unsigned char col) {
    unsigned char address = (row == 1) ? 0x80 : 0xC0;
    address += col - 1;
    LCD_Cmd(address);
}