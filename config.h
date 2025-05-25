#ifndef CONFIG_H
#define CONFIG_H

// Configuración del dispositivo
#pragma config FOSC = INTIO67
#pragma config PLLCFG = OFF
#pragma config WDTEN = OFF
#pragma config PWRTEN = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF

#include <xc.h>
#define _XTAL_FREQ 16000000

// Definición de pines y constantes

// *********************** LCD ***********************
#define RS LATD0
#define EN LATD1
#define D4 LATD2
#define D5 LATD3
#define D6 LATD4
#define D7 LATD5

// *********************** LEDs ***********************
#define LED_CORRECTO LATD6
#define LED_INCORRECTO LATD7

// *********************** BUZZER ***********************
#define BUZZER LATC0

// *********************** SERVO ***********************
#define SERVO_PIN TRISCbits.TRISC2  // Pin del servo (RC2/CCP1)

// *********************** TECLADO ***********************
#define ROW1 PORTBbits.RB4  // Filas (Entradas)
#define ROW2 PORTBbits.RB5
#define ROW3 PORTBbits.RB6
#define ROW4 PORTBbits.RB7

// Valores de PWM para el servomotor
#define DUTY_CLOSE 30    // Valor para posición cerrada (0°)
#define DUTY_OPEN 240    // Valor para posición abierta (180°)
#define STEP_DELAY 10    // Tiempo entre pasos para movimiento suave

#endif
