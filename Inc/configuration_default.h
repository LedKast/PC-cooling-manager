#ifndef CLIONSTM32TEST_CONFIGURATION_DEFAULT_H
#define CLIONSTM32TEST_CONFIGURATION_DEFAULT_H

#include <map>

typedef std::map<uint16_t, uint16_t> FanSpeedMap;   // <RPM, PWM%>
typedef std::map<uint16_t, uint16_t> TempMap;  // <Temp, RPM>


#define CONSOLE_GREETING "PC chill core v1.3\r\n"

// PWM channels

enum PwmChannels {
    FRONT,
    BOTTOM,
    BACK,
    TOP
};

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

// TEMPERATURE MAPS <TEMP, RPM>

extern const TempMap TEMP_MAP_WATER_RADIATOR_120MM = {
        {MIN_BORDER_WATER_TEMP, 500},
        {39,                    500},
        {40,                    600},
        {41,                    700},
        {42,                    900},
        {43,                    1000},
        {44,                    1250},
        {MAX_BORDER_WATER_TEMP, 1500},
};

// TODO set map
extern const TempMap TEMP_MAP_WATER_FRONT = {
        {MIN_BORDER_WATER_TEMP, 500},
        {39,                    500},
        {40,                    600},
        {41,                    700},
        {42,                    900},
        {43,                    1000},
        {44,                    1250},
        {MAX_BORDER_WATER_TEMP, 1500},
};


// TODO set map
extern const TempMap TEMP_MAP_WATER_BACK = {
        {MIN_BORDER_WATER_TEMP, 500},
        {39,                    500},
        {40,                    600},
        {41,                    700},
        {42,                    900},
        {43,                    1000},
        {44,                    1250},
        {MAX_BORDER_WATER_TEMP, 1500},
};

// TODO set map
extern const TempMap TEMP_MAP_WATER_BOTTOM = {
        {MIN_BORDER_WATER_TEMP, 500},
        {39,                    500},
        {40,                    600},
        {41,                    700},
        {42,                    900},
        {43,                    1000},
        {44,                    1250},
        {MAX_BORDER_WATER_TEMP, 1500},
};

// FAN MAPS <RPM, PWM%>

// TODO set map
extern const FanSpeedMap BEQUIET_BL040_140MM = {
        {450, 0},
        {450, 5},
        {450, 10},
        {450, 15},
        {450, 20},
        {450, 25},
        {450, 30},
        {450, 35},
        {450, 40},
        {450, 45},
        {450, 50},
        {450, 55},
        {450, 60},
        {450, 65},
        {450, 70},
        {450, 75},
        {450, 80},
        {450, 85},
        {450, 90},
        {450, 95},
        {1000, 100}
};

// TODO set map
extern const FanSpeedMap BEQUIET_BL039_120MM = {
        {450, 0},
        {450, 5},
        {450, 10},
        {450, 15},
        {450, 20},
        {450, 25},
        {450, 30},
        {450, 35},
        {450, 40},
        {450, 45},
        {450, 50},
        {450, 55},
        {450, 60},
        {450, 65},
        {450, 70},
        {450, 75},
        {450, 80},
        {450, 85},
        {450, 90},
        {450, 95},
        {1000, 100}
};

#endif //CLIONSTM32TEST_CONFIGURATION_DEFAULT_H
