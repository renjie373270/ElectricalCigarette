//
// Created by RenJie on 2018/12/14 0014 17:58.
//

#include "main.h"

void MIC_Init() {
    GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_IN_PU_IT);
    enableInterrupts();
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_FALL_LOW);
}


//TODO  high means smoking, low means not!!!!!!!!!!!!!!!
bool Is_Still_Smoking() {
    return !GPIO_ReadInputPin(GPIOC, GPIO_PIN_6);
}

