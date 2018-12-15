//
// Created by RenJie on 2018/12/15 0015 10:29.
//

#include "main.h"

//atomizer drive
#define ATOMIZER_DRIVE_PORT GPIOC
#define ATOMIZER_DRIVE_PIN  GPIO_PIN_5

//check the voltage on resistance
#define ATOMIZER_ADC1_PORT GPIOD
#define ATOMIZER_ADC1_PIN  GPIO_PIN_3
#define ATOMIZER_ADC1_EXTI_PORT EXTI_PORT_GPIOD

//check the voltage on atomizer
#define ATOMIZER_ADC2_PORT GPIOD
#define ATOMIZER_ADC2_PIN  GPIO_PIN_2
#define ATOMIZER_ADC2_EXTI_PORT EXTI_PORT_GPIOD


void Atomizer_Init() {
    disableInterrupts();
    GPIO_Init(ATOMIZER_ADC2_PORT, ATOMIZER_ADC2_PIN, GPIO_MODE_IN_PU_IT);
    EXTI_SetExtIntSensitivity(ATOMIZER_ADC2_EXTI_PORT, EXTI_SENSITIVITY_RISE_FALL);
    enableInterrupts();
}

bool Is_Atomizer_In() {
    return !GPIO_ReadInputPin(ATOMIZER_ADC2_PORT, ATOMIZER_ADC2_PIN);
}

void Atomizer_In() {
    //TODO Steven change io mode to adc
}

void Atomizer_Out() {
    //TODO Steven change io mode to extern interrupt
}


void Atomizer_In_Out() {
    if(Is_Atomizer_In()) {
        Atomizer_In();
    } else {
        Atomizer_Out();
    }
    Motor_Shake();
}

//TODO Steven, control mos drive for atomizer
void Atomizer_Smoking() {
    while (Is_Still_Smoking()) {
        Normal_Delay_In_MilliSeconds(100);
        LED_Smoking();
    }
    LED_Stop_Smoking();
}