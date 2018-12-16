//
// Created by RenJie on 2018/12/15 0015 10:29.
//

#include "atomizer.h"

#define ATOMIZER_ON()  GPIO_WriteLow(ATOMIZER_DRIVE_PORT, ATOMIZER_DRIVE_PIN)
#define ATOMIZER_OFF() GPIO_WriteHigh(ATOMIZER_DRIVE_PORT, ATOMIZER_DRIVE_PIN)


void Atomizer_ADC_Node1_Init() {
    ADC1_DeInit();
    GPIO_Init(ATOMIZER_ADC_NODE_1_PORT, ATOMIZER_ADC_NODE_1_PIN, GPIO_MODE_IN_FL_NO_IT);
    ADC1_Init(ADC1_CONVERSIONMODE_SINGLE, ATOMIZER_ADC_NODE_1_CHANNEL, ADC1_PRESSEL_FCPU_D2,
              ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ATOMIZER_ADC_NODE_1_TRIGGER_CHANNEL, DISABLE);
    ADC1_Cmd(ENABLE);
}

void Atomizer_ADC_Node2_Init() {
    ADC1_DeInit();
    GPIO_Init(ATOMIZER_ADC_NODE_2_PORT, ATOMIZER_ADC_NODE_2_PIN, GPIO_MODE_IN_FL_NO_IT);
    ADC1_Init(ADC1_CONVERSIONMODE_SINGLE, ATOMIZER_ADC_NODE_2_CHANNEL, ADC1_PRESSEL_FCPU_D2,
              ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ATOMIZER_ADC_NODE_2_TRIGGER_CHANNEL, DISABLE);
    ADC1_Cmd(ENABLE);
}

uint16_t Get_Node_1_Voltage_MV() {
    int i;
    uint16_t adcValue = 0;
    uint32_t voltageInMV = 0;

    Atomizer_ADC_Node1_Init();
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

uint16_t Get_Node_2_Voltage_MV() {
    int i;
    uint16_t adcValue = 0;
    uint32_t voltageInMV = 0;

    Atomizer_ADC_Node2_Init();
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

uint16_t Get_Atomizer_Power() {
    static uint16_t voltageOfAtomizerMV = 0;
    static uint16_t voltageOfResistanceMV = 0;
    static double currentInMA = 0;
    static double powerInMW = 0;

    voltageOfAtomizerMV = Get_Node_2_Voltage_MV();
    voltageOfResistanceMV = Get_Node_1_Voltage_MV();

    currentInMA = voltageOfResistanceMV -  voltageOfAtomizerMV;
    currentInMA = currentInMA * 1000 / 400.0;//unit, mA
    powerInMW = voltageOfAtomizerMV * currentInMA / 1000.0;
    return (uint16_t)powerInMW;
}


void Atomizer_Drive_Init() {
    GPIO_Init(ATOMIZER_DRIVE_PORT, ATOMIZER_DRIVE_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
    ATOMIZER_OFF();
}

void Atomizer_Init() {
    disableInterrupts();
    GPIO_Init(ATOMIZER_ADC_NODE_2_PORT, ATOMIZER_ADC_NODE_2_PIN, GPIO_MODE_IN_PU_IT);
    EXTI_SetExtIntSensitivity(ATOMIZER_ADC_NODE_2_EXTI_PORT, EXTI_SENSITIVITY_RISE_FALL);
    enableInterrupts();
}

bool Is_Atomizer_In() {
    return !GPIO_ReadInputPin(ATOMIZER_ADC_NODE_2_PORT, ATOMIZER_ADC_NODE_2_PIN);
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
    uint16_t voltageOfBattery = Read_Voltage_Of_Battery_MV();
    if(voltageOfBattery < 3650) {
        LED_Out_Of_Battery();
        return;
    }
    while (Is_Still_Smoking()) {
        Software_Delay_MS(20);
        LED_Smoking();
        ATOMIZER_ON();
        static uint16_t power = 0;
        power = Get_Atomizer_Power();
        Atomizer_Init();
    }
    LED_Stop_Smoking();
    ATOMIZER_OFF();
}