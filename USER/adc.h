//
// Created by RenJie on 2018/12/15 0015 15:09.
//

#ifndef ELECTRICALCIGARETTE_POWER_H
#define ELECTRICALCIGARETTE_POWER_H

#include "main.h"

uint16_t Read_Voltage_In_MV(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, ADC1_Channel_TypeDef ADC1_Channel, ADC1_SchmittTrigg_TypeDef ADC1_SchmittTriggerChannel);

#endif //ELECTRICALCIGARETTE_POWER_H
