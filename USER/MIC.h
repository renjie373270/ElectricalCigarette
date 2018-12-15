//
// Created by RenJie on 2018/12/14 0014 17:57.
//

#ifndef ELECTRICALCIGARETTE_MIC_H
#define ELECTRICALCIGARETTE_MIC_H

#include "main.h"

#define MIC_PORT GPIOC
#define MIC_PIN  GPIO_PIN_6
#define MIC_EXTI_PORT EXTI_PORT_GPIOC

void MIC_Init();
bool Is_Still_Smoking();

#endif //ELECTRICALCIGARETTE_MIC_H
