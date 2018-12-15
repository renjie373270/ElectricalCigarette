//
// Created by RenJie on 2018/12/15 0015 15:10.
//

#include "adc.h"


void ADC_Init(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, ADC1_Channel_TypeDef ADC1_Channel, ADC1_SchmittTrigg_TypeDef ADC1_SchmittTriggerChannel) {
    ADC1_DeInit();
    GPIO_Init(GPIOx, GPIO_Pin, GPIO_MODE_IN_FL_NO_IT);
    ADC1_Init(ADC1_CONVERSIONMODE_SINGLE, ADC1_Channel, ADC1_PRESSEL_FCPU_D2,
              ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ADC1_SchmittTriggerChannel, DISABLE);
    ADC1_Cmd(ENABLE);
}


uint16_t Read_Voltage_In_MV(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, ADC1_Channel_TypeDef ADC1_Channel, ADC1_SchmittTrigg_TypeDef ADC1_SchmittTriggerChannel) {
    int i;
    uint16_t adcValue = 0;
    uint32_t voltageInMV = 0;

    ADC_Init(GPIOx, GPIO_Pin, ADC1_Channel, ADC1_SchmittTriggerChannel);

    for(i = 0; i < 4; i++) {
        ADC1_StartConversion();
        while(RESET==ADC1_GetFlagStatus(ADC1_FLAG_EOC));
        ADC1_ClearFlag(ADC1_FLAG_EOC);
        adcValue += ADC1_GetConversionValue();
    }

    voltageInMV = adcValue >> 2;
    voltageInMV = (voltageInMV * 3300) >> 10;
    return voltageInMV;
}