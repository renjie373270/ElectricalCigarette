//
// Created by RenJie on 2018/12/15 0015 10:29.
//

#include "atomizer.h"

#define ATOMIZER_ON()  GPIO_WriteLow(ATOMIZER_DRIVE_PORT, ATOMIZER_DRIVE_PIN)
#define ATOMIZER_OFF() GPIO_WriteHigh(ATOMIZER_DRIVE_PORT, ATOMIZER_DRIVE_PIN)

void Atomizer_Drive_Init() {
    GPIO_Init(ATOMIZER_DRIVE_PORT, ATOMIZER_DRIVE_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
    ATOMIZER_OFF();
}

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
    Atomizer_Drive_Init();
}

void Atomizer_Out() {
    Atomizer_Init();
}


void Atomizer_In_Out() {
    static bool isAtomizerIn = false;
    if(!isAtomizerIn && Is_Atomizer_In()) {
        isAtomizerIn = true;
        Atomizer_In();
        Motor_Shake();
    }

    if(isAtomizerIn && !Is_Atomizer_In()) {
        isAtomizerIn = false;
        Atomizer_Out();
        Motor_Shake();
    }
}


//TODO Steven, power control
//TODO Steven, check power
void Atomizer_Smoking() {
    while (Is_Still_Smoking()) {
        Software_Delay_MS(100);
        LED_Smoking();
        ATOMIZER_ON();
    }
    LED_Stop_Smoking();
    ATOMIZER_OFF();
}