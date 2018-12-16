//
// Created by RenJie on 2018/12/15 0015 15:35.
//

#include "power.h"

void Power_ADC_Init() {
    ADC1_DeInit();
    GPIO_Init(POWER_CHECK_PORT, POWER_CHECK_PIN, GPIO_MODE_IN_FL_NO_IT);
    ADC1_Init(ADC1_CONVERSIONMODE_SINGLE, POWER_ADC_CHANNEL, ADC1_PRESSEL_FCPU_D2,
            ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, POWER_TRIGGER_CHANNEL, DISABLE);
    ADC1_Cmd(ENABLE);
}

uint16_t Read_Voltage_Of_Battery_MV() {
    int i;
    uint16_t adcValue = 0;
    uint32_t voltageInMV = 0;

    Power_ADC_Init();

    for(i = 0; i < 4; i++) {
        ADC1_StartConversion();
        while(RESET==ADC1_GetFlagStatus(ADC1_FLAG_EOC));
        ADC1_ClearFlag(ADC1_FLAG_EOC);
        adcValue += ADC1_GetConversionValue();
    }

    voltageInMV = adcValue >> 2;
    voltageInMV = (voltageInMV * 3300) >> 10;
    return voltageInMV << 1;
}

