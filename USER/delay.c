//
// Created by RenJie on 2018/12/15 0015 13:47.
//

#include "delay.h"

static uint32_t timer1DelayInMilliSeconds;
static uint32_t timer2DelayInMilliSeconds;


// interrupt priority, tim2 > tim1 > extern
void TIM1_Init() {
    disableInterrupts();
    TIM1_TimeBaseInit(0, TIM1_COUNTERMODE_UP, 1000, 0);
    TIM1_ARRPreloadConfig(ENABLE);
    TIM1_ITConfig(TIM1_IT_UPDATE , ENABLE);
    TIM1_Cmd(ENABLE);
    enableInterrupts();
}

void TIM2_Init() {
    disableInterrupts();
    TIM2_TimeBaseInit(TIM2_PRESCALER_1, 1000);
    TIM2_ARRPreloadConfig(ENABLE);
    TIM2_ITConfig(TIM2_IT_UPDATE , ENABLE);
    TIM2_Cmd(ENABLE);
    enableInterrupts();
}

void Delay_Init() {
    TIM1_Init();
    TIM2_Init();
}

void Delay_Timer1_Decrement() {
    if(timer1DelayInMilliSeconds > 0)
        timer1DelayInMilliSeconds --;
}

void Delay_Timer2_Decrement() {
    if(timer2DelayInMilliSeconds > 0)
        timer2DelayInMilliSeconds --;
}

void Normal_Delay_In_MilliSeconds(uint32_t time) {
    timer1DelayInMilliSeconds = time;
    while (timer1DelayInMilliSeconds != 0);
}

void Special_Delay_In_MilliSeconds(uint32_t time) {
    timer2DelayInMilliSeconds = time;
    while (timer2DelayInMilliSeconds != 0);
}

void Software_Delay_MS(uint32_t timeInMilliSeconds) {
    uint16_t i, j;
    for(i = 0; i < timeInMilliSeconds; i ++) {
        for(j = 0; j < 200; j++);
    }
}

