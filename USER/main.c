#include "main.h"


void Clock_Init() {
    CLK_HSIPrescalerConfig(CLK_PRESCALER_CPUDIV16);
}

void ITC_Config() {
    disableInterrupts();
    ITC_SetSoftwarePriority(ITC_IRQ_TIM2_OVF, ITC_PRIORITYLEVEL_0);
    ITC_SetSoftwarePriority(ITC_IRQ_PORTC, ITC_PRIORITYLEVEL_1);
    ITC_SetSoftwarePriority(ITC_IRQ_PORTD, ITC_PRIORITYLEVEL_1);
    ITC_SetSoftwarePriority(ITC_IRQ_TIM1_OVF, ITC_PRIORITYLEVEL_2);
    enableInterrupts();
}

int main(void) {
    LED_Init();
    MIC_Init();
    Motor_Init();
    Atomizer_Init();
    Delay_Init();
    ITC_Config();
    while (1) {
        LED_Charging();
        Normal_Delay_In_MilliSeconds(200);
        LED_Battery_Full();
        Normal_Delay_In_MilliSeconds(200);
    }
}