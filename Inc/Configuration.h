#ifndef CLIONSTM32TEST_CONFIGURATION_H
#define CLIONSTM32TEST_CONFIGURATION_H

#include <map>
#include <cstdint>

typedef std::map<uint16_t, uint16_t> FanSpeedMap;   // <RPM, PWM%>
typedef std::map<uint16_t, uint16_t> TempMap;  // <Temp, RPM>

#define CONSOLE_GREETING "PC chill core v1.3\r\n"

#define SCREEN_ROTATION 3

#define FAN_UPDATE_DELAY 2500

#define PWM_FRONT TIM3->CCR1   // CH1
#define PWM_BOTTOM TIM3->CCR2  // CH2
#define PWM_BACK TIM3->CCR3    // CH3
#define PWM_TOP TIM3->CCR4     // CH3

// DS18B20 bindings

#define WATER_SENS GPIO_PIN_10
#define VRM_SENS GPIO_PIN_11


// TEMPERATURE BORDERS

#define MIN_BORDER_WATER_TEMP 35
#define MAX_BORDER_WATER_TEMP 43

// TEMPERATURE LEVELS

#define VRM_WARNING_LEVEL 70
#define VRM_CRITICAL_LEVEL 80

#define WATER_WARNING_LEVEL 38
#define WATER_CRITICAL_LEVEL 40

#endif //CLIONSTM32TEST_CONFIGURATION_H
