#include "led.h"


void LED_Init() {
    GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST);
    GPIO_Init(GPIOB, GPIO_PIN_4 | GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);
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