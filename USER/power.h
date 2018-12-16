//
// Created by RenJie on 2018/12/15 0015 15:35.
//

#ifndef ELECTRICALCIGARETTE_POWER_H
#define ELECTRICALCIGARETTE_POWER_H

#include "main.h"

#define POWER_CHECK_PORT   GPIOC
#define POWER_CHECK_PIN    GPIO_PIN_4
#define POWER_ADC_CHANNEL  ADC1_CHANNEL_2
#define POWER_TRIGGER_CHANNEL  ADC1_SCHMITTTRIG_CHANNEL2

#define POWER_CHARGE_PORT   GPIOD
#define POWER_CHARGE_PIN    GPIO_PIN_4

void Power_Charge_Init();
void Power_Charge_Check();
uint16_t Read_Voltage_Of_Battery_MV();

#endif //ELECTRICALCIGARETTE_POWER_H
