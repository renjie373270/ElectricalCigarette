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

extern void Atomizer_Drive_Init();

int main(void) {
    LED_Init();
    MIC_Init();
    Atomizer_Init();
    ITC_Config();
    while (1) {
        uint16_t voltageOfBattery = Read_Voltage_Of_Battery_MV();
        //charging
        if(voltageOfBattery > 3700 || voltageOfBattery == 0) {
            if(voltageOfBattery > 4150)
                LED_Battery_Full();
             else
                LED_Charging();
        } else {
            LED_All_Off();
            //TODO Steven, sleep
        }
        Software_Delay_MS(100);
    }
}


#ifdef USE_FULL_ASSERT

void assert_failed(u8* file, u32 line)
{
  while (1)
  {
  }
}
#endif