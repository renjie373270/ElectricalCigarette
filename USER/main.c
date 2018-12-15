#include "main.h"


void delay(unsigned int x) {
    unsigned int i, j;
    for(i=0;i<x;i++) {
        for(j=0;j<200;j++);
    }
}

void Clock_Init() {
    CLK_HSIPrescalerConfig(CLK_PRESCALER_CPUDIV16);
}

int main(void) {
    LED_Init();
    MIC_Init();
    Motor_Init();
    Atomizer_Init();
    while (1) {
        LED_Charging();
        delay(1000);
        LED_Battery_Full();
        delay(1000);
    }
}