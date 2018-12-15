//
// Created by RenJie on 2018/12/15 0015 11:02.
//

#include "motor.h"


#define MOTOR_RUNNING()  GPIO_WriteLow(MOTOR_DRIVE_PORT, MOTOR_DRIVE_PIN)
#define MOTOR_STOP()     GPIO_WriteHigh(MOTOR_DRIVE_PORT, MOTOR_DRIVE_PIN)


void Motor_Init() {
    GPIO_Init(MOTOR_DRIVE_PORT, MOTOR_DRIVE_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
    MOTOR_STOP();
}

void Motor_Shake() {
    Motor_Init();
    MOTOR_RUNNING();
    Software_Delay_MS(200);
    MOTOR_STOP();
}