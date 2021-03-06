#include "led.h"

#define LED_CHARGING_ON()  GPIO_WriteLow(LED_RED_PORT, LED_RED_PIN)
#define LED_CHARGING_OFF() GPIO_WriteHigh(LED_RED_PORT, LED_RED_PIN)
#define LED_BATTERY_FULL_ON()  GPIO_WriteLow(LED_GREEN_PORT, LED_GREEN_PIN)
#define LED_BATTERY_FULL_OFF() GPIO_WriteHigh(LED_GREEN_PORT, LED_GREEN_PIN)
#define LED_SMOKING_ON()  GPIO_WriteLow(LED_BLUE_PORT, LED_BLUE_PIN)
#define LED_SMOKING_OFF() GPIO_WriteHigh(LED_BLUE_PORT, LED_BLUE_PIN)


void LED_Init() {
    GPIO_Init(LED_RED_PORT, LED_RED_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
    GPIO_Init(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
    GPIO_Init(LED_BLUE_PORT, LED_BLUE_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
    LED_CHARGING_OFF();
    LED_BATTERY_FULL_OFF();
    LED_SMOKING_OFF();
}

void LED_Out_Of_Battery() {
    uint16_t i;
    for(i = 0; i < 4; i++) {
        LED_CHARGING_ON();
        Software_Delay_MS(200);
        LED_CHARGING_OFF();
        Software_Delay_MS(200);
    }
}

void LED_Charging() {
    LED_CHARGING_ON();
    LED_BATTERY_FULL_OFF();
}

void LED_Stop_Charging() {
    LED_CHARGING_OFF();
    LED_BATTERY_FULL_OFF();
}

void LED_Battery_Full() {
    LED_CHARGING_OFF();
    LED_BATTERY_FULL_ON();
}

void LED_Smoking() {
    LED_SMOKING_ON();
}

void LED_Stop_Smoking() {
    LED_SMOKING_OFF();
}

void LED_All_Off() {
    LED_CHARGING_OFF();
    LED_BATTERY_FULL_OFF();
    LED_SMOKING_OFF();
}