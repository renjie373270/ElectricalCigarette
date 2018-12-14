#include "main.h"


//red
#define LED_CHARGING_ON()  GPIO_WriteLow(GPIOB, GPIO_PIN_4)
#define LED_CHARGING_OFF() GPIO_WriteHigh(GPIOB, GPIO_PIN_4)

//green
#define LED_BATTERY_FULL_ON()  GPIO_WriteLow(GPIOC, GPIO_PIN_3)
#define LED_BATTERY_FULL_OFF() GPIO_WriteHigh(GPIOC, GPIO_PIN_3)

//blue
#define LED_SMOKING_ON()  GPIO_WriteLow(GPIOB, GPIO_PIN_5)
#define LED_SMOKING_OFF() GPIO_WriteHigh(GPIOB, GPIO_PIN_5)


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