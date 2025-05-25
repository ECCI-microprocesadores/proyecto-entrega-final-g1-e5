#ifndef SERVO_H
#define SERVO_H

void Servo_Init(void);
void Servo_SetPosition(unsigned int duty);
void Servo_MoveSmoothly(unsigned int target_duty);

#endif