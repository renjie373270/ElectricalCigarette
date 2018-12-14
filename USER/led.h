#ifndef __LED_H
#define __LED_H
#include "stm8s_gpio.h"

//red
#define LED_CHARGING_ON()  GPIO_WriteLow(GPIOB, GPIO_PIN_4)
#define LED_CHARGING_OFF() GPIO_WriteHigh(GPIOB, GPIO_PIN_4)

//green
#define LED_BATTERY_FULL_ON()  GPIO_WriteLow(GPIOC, GPIO_PIN_3)
#define LED_BATTERY_FULL_OFF() GPIO_WriteHigh(GPIOC, GPIO_PIN_3)

//blue
#define LED_SMOKING_ON()  GPIO_WriteLow(GPIOB, GPIO_PIN_5)
#define LED_SMOKING_OFF() GPIO_WriteHigh(GPIOB, GPIO_PIN_5)

void LED_Init(void);
void LED_Charging();
void LED_Stop_Charging();
void LED_Battery_Full();
void LED_Smoking();
void LED_Stop_Smoking();

#endif
