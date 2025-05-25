#include "config.h"
#include "keyboard.h"

void Keyboard_Init(void) {
    LATB = 0x0F;  // Poner las columnas en alto
    __delay_ms(50);
}

char Keyboard_Scan(void) {
    // Columna 1 (RB0 baja)
    LATB = 0x0E;  // Activar columna 1 (RB0)
    __delay_us(200);
    if (!ROW1) return '1';
    if (!ROW2) return '4';
    if (!ROW3) return '7';
    if (!ROW4) return '*';
    
    // Columna 2 (RB1 baja)
    LATB = 0x0D;  // Activar columna 2 (RB1)
    __delay_us(200);
    if (!ROW1) return '2';
    if (!ROW2) return '5';
    if (!ROW3) return '8';
    if (!ROW4) return '0';
    
    // Columna 3 (RB2 baja)
    LATB = 0x0B;  // Activar columna 3 (RB2)
    __delay_us(200);
    if (!ROW1) return '3';
    if (!ROW2) return '6';
    if (!ROW3) return '9';
    if (!ROW4) return '#';
    
    // Columna 4 (RB3 baja)
    LATB = 0x07;  // Activar columna 4 (RB3)
    __delay_us(200);
    if (!ROW1) return 'A';
    if (!ROW2) return 'B';
    if (!ROW3) return 'C';
    if (!ROW4) return 'D';
    
    LATB = 0x0F;  // Apagar todas las columnas
    return 0;
}

char Keyboard_GetKey(void) {
    static char last_key = 0;
    static unsigned char debounce_count = 0;
    
    char current_key = Keyboard_Scan();
    
    if(current_key != 0) {
        if(current_key != last_key) {
            debounce_count = 0;
            last_key = current_key;
            return 0;
        } else {
            debounce_count++;
            if(debounce_count >= 2) {
                debounce_count = 0;
                return current_key;
            }
        }
    } else {
        if(last_key != 0) {
            debounce_count++;
            if(debounce_count >= 8) {
                last_key = 0;
                debounce_count = 0;
            }
        }
    }
    
    return 0;
}Ss