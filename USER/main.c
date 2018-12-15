#include "main.h"


void Clock_Init() {
    CLK_HSIPrescalerConfig(CLK_PRESCALER_CPUDIV16);
}

void ITC_Config() {
    disableInterrupts();
    ITC_SetSoftwarePriority(ITC_IRQ_PORTC, ITC_PRIORITYLEVEL_0);
    ITC_SetSoftwarePriority(ITC_IRQ_PORTD, ITC_PRIORITYLEVEL_1);
    enableInterrupts();
}

static uint16_t voltageOfBattery;

int main(void) {
    LED_Init();
    MIC_Init();
    Atomizer_Init();
    ITC_Config();
    while (1) {
        LED_Charging();
        Software_Delay_MS(200);
        LED_Battery_Full();
        Software_Delay_MS(200);
        voltageOfBattery = Read_Voltage_Of_Battery_MV();
    }
}