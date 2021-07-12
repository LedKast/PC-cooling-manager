#ifndef CLIONSTM32TEST_CONFIGURATIONMAPS_H
#define CLIONSTM32TEST_CONFIGURATIONMAPS_H

#include <map>
#include <cstdint>

typedef std::map<uint16_t, uint16_t> FanSpeedMap;   // <RPM, PWM%>
typedef std::map<uint16_t, uint16_t> TempMap;  // <Temp, RPM>

#define CONSOLE_GREETING "PC chill core v1.3\r\n"


#define FAN_UPDATE_DELAY 2500

#define PWM_FRONT TIM3->CCR1   // CH1
#define PWM_BOTTOM TIM3->CCR2  // CH2
#define PWM_BACK TIM3->CCR3    // CH3
#define PWM_TOP TIM3->CCR4     // CH3

// DS18B20 bindings

#define WATER_SENS GPIO_PIN_10
#define VRM_SENS GPIO_PIN_11


// TEMPERATURE BORDERS

#define MIN_BORDER_WATER_TEMP 38
#define MAX_BORDER_WATER_TEMP 45

const TempMap TEMP_MAP_WATER_RADIATOR_120MM;
const TempMap TEMP_MAP_WATER_FRONT;
const TempMap TEMP_MAP_WATER_BACK;
const TempMap TEMP_MAP_WATER_BOTTOM;
const FanSpeedMap BEQUIET_BL040_140MM;
const FanSpeedMap BEQUIET_BL039_120MM;

#endif //CLIONSTM32TEST_CONFIGURATIONMAPS_H
