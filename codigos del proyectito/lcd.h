#ifndef LCD_H
#define LCD_H

void LCD_Init(void);
void LCD_Cmd(unsigned char cmd);
void LCD_WriteChar(char c);
void LCD_WriteString(const char *str);
void LCD_SetCursor(unsigned char row, unsigned char col);
void LCD_Clear(void);

#endif
