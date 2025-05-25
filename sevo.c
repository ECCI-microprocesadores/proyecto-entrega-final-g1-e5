#include "config.h"
#include "servo.h"

void Servo_Init(void) {
    // Configuración del PWM para el servo
    TRISCbits.TRISC2 = 0;       // RC2 como salida (CCP1)
    T2CONbits.T2CKPS = 0b10;    // Prescaler 16
    PR2 = 249;                  // Periodo para ~50Hz con 16MHz
    CCP1CONbits.CCP1M = 0b1100; // Modo PWM
    CCPR1L = DUTY_CLOSE;        // Posición inicial (cerrado)
    CCP1CONbits.DC1B = 0;
    T2CONbits.TMR2ON = 1;       // Encender Timer2
}

void Servo_SetPosition(unsigned int duty) {
    // Limitar el rango del duty cycle
    if(duty < DUTY_CLOSE) duty = DUTY_CLOSE;
    if(duty > DUTY_OPEN) duty = DUTY_OPEN;
    
    CCPR1L = duty;
    CCP1CONbits.DC1B = 0;
}

void Servo_MoveSmoothly(unsigned int target_duty) {
    // Movimiento suave desde la posición actual al objetivo
    unsigned int current_duty = CCPR1L;
    
    if(target_duty > current_duty) {
        // Movimiento de apertura (incremento)
        while(current_duty < target_duty) {
            current_duty++;
            Servo_SetPosition(current_duty);
            __delay_ms(STEP_DELAY);
        }
    } else {
        // Movimiento de cierre (decremento)
        while(current_duty > target_duty) {
            current_duty--;
            Servo_SetPosition(current_duty);
            __delay_ms(STEP_DELAY);
        }
    }
}