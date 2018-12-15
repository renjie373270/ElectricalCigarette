//
// Created by RenJie on 2018/12/15 0015 11:01.
//

#ifndef ELECTRICALCIGARETTE_MOTOR_H
#define ELECTRICALCIGARETTE_MOTOR_H

#include "main.h"

//motor drive
#define MOTOR_DRIVE_PORT GPIOC
#define MOTOR_DRIVE_PIN  GPIO_PIN_7

void Motor_Init();
void Motor_Shake();

#endif //ELECTRICALCIGARETTE_MOTOR_H
