//
// Created by RenJie on 2018/12/15 0015 13:46.
//

#ifndef ELECTRICALCIGARETTE_DELAY_H
#define ELECTRICALCIGARETTE_DELAY_H

#include "main.h"


void Delay_Init();
void Delay_Timer1_Decrement();
void Delay_Timer2_Decrement();
void Normal_Delay_In_MilliSeconds(uint32_t time);
void Special_Delay_In_MilliSeconds(uint32_t time);

#endif //ELECTRICALCIGARETTE_DELAY_H
