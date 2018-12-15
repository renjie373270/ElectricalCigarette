//
// Created by RenJie on 2018/12/14 0014 17:58.
//

#include "main.h"

void MIC_Init() {
    disableInterrupts();
    GPIO_Init(MIC_PORT, MIC_PIN, GPIO_MODE_IN_PU_IT);
    EXTI_SetExtIntSensitivity(MIC_EXTI_PORT, EXTI_SENSITIVITY_FALL_LOW);
    enableInterrupts();
}

//TODO  Steven high means smoking, low means not!!!!!!!!!!!!!!!
bool Is_Still_Smoking() {
    return !GPIO_ReadInputPin(MIC_PORT, MIC_PIN);
}

