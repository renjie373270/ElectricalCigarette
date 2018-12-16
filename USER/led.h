#ifndef __LED_H
#define __LED_H

#include "main.h"

//charging
#define LED_RED_PORT GPIOB
#define LED_RED_PIN  GPIO_PIN_4

//battery full
#define LED_GREEN_PORT GPIOC
#define LED_GREEN_PIN  GPIO_PIN_3

//smoking
#define LED_BLUE_PORT GPIOB
#define LED_BLUE_PIN  GPIO_PIN_5

void LED_Init();
void LED_Out_Of_Battery();
void LED_Charging();
void LED_Stop_Charging();
void LED_Battery_Full();
void LED_Smoking();
void LED_Stop_Smoking();
void LED_All_Off();

#endif
