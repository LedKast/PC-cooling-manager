#ifndef CLIONSTM32TEST_MAPS_H
#define CLIONSTM32TEST_MAPS_H

// TEMPERATURE MAPS <TEMP, RPM>

const TempMap TEMP_MAP_WATER_RADIATOR_120MM = {
        {MIN_BORDER_WATER_TEMP, 450},
        {39,                    450},
        {40,                    450},
        {41,                    650},
        {42,                    750},
        {43,                    1000},
        {44,                    1250},
        {MAX_BORDER_WATER_TEMP, 1500},
};

// TODO set map
const TempMap TEMP_MAP_WATER_FRONT = {
        {MIN_BORDER_WATER_TEMP, 450},
        {39,                    450},
        {40,                    450},
        {41,                    450},
        {42,                    450},
        {43,                    750},
        {44,                    750},
        {MAX_BORDER_WATER_TEMP, 850},
};


// TODO set map
const TempMap TEMP_MAP_WATER_BACK = {
        {MIN_BORDER_WATER_TEMP, 450},
        {39,                    450},
        {40,                    450},
        {41,                    450},
        {42,                    450},
        {43,                    750},
        {44,                    750},
        {MAX_BORDER_WATER_TEMP, 850},
};

// TODO set map
const TempMap TEMP_MAP_WATER_BOTTOM = {
        {MIN_BORDER_WATER_TEMP, 450},
        {39,                    450},
        {40,                    450},
        {41,                    450},
        {42,                    450},
        {43,                    750},
        {44,                    750},
        {MAX_BORDER_WATER_TEMP, 850},
};

// FAN MAPS <RPM, PWM%>

// TODO update map by real values
const FanSpeedMap BEQUIET_BL040_140MM = {
        {450, 20},
        {500, 32},
        {550, 39},
        {600, 46},
        {650, 53},
        {700, 60},
        {750, 66},
        {800, 73},
        {850, 80},
        {900, 87},
        {950, 93},
        {1000, 100}
};

// TODO update map by real values
const FanSpeedMap BEQUIET_BL039_120MM = {
        {450, 20},
        {500, 30},
        {550, 33},
        {600, 37},
        {650, 40},
        {700, 44},
        {750, 47},
        {800, 51},
        {850, 55},
        {900, 58},
        {950, 62},
        {1000, 66},
        {1050, 69},
        {1100, 73},
        {1150, 76},
        {1200, 80},
        {1250, 83},
        {1300, 87},
        {1350, 91},
        {1400, 94},
        {1450, 97},
        {1500, 100},
};

#endif //CLIONSTM32TEST_MAPS_H
