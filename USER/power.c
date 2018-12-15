//
// Created by RenJie on 2018/12/15 0015 15:35.
//

#include "power.h"

uint16_t Read_Voltage_Of_Battery_MV() {
    uint16_t voltageOfBatteryNodeInMV = Read_Voltage_In_MV(POWER_CHECK_PORT, POWER_CHECK_PIN, POWER_ADC_CHANNEL, POWER_TRIGGER_CHANNEL);
    uint16_t voltageOfBatteryInMV = voltageOfBatteryNodeInMV << 1;
    return voltageOfBatteryInMV;
}

