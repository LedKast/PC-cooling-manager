#include "ConfigurationMaps.h"
#include <map>
#include <stm32f1xx_hal.h>


class FanController {
    volatile uint32_t* pwmChannel;
    FanSpeedMap fanMap;
    TempMap tempMap;

    long timer = -1;

public:

    FanController(volatile uint32_t* channel, FanSpeedMap fanMap, TempMap tempMap) {
        pwmChannel = channel;
        this->fanMap = fanMap;
        this->tempMap = tempMap;
    }

    void updateChannel(uint16_t temp, uint16_t minLimit, uint16_t maxLimit, uint16_t updateDelay) {
        if (HAL_GetTick() - timer > updateDelay) {
            if (temp < minLimit) {
                *pwmChannel = std::min((int)(fanMap.find(tempMap.find(minLimit)->second)->second * 2.55), 255);
            } else
                if (temp > maxLimit) {
                    *pwmChannel = std::min((int)(fanMap.find(tempMap.find(maxLimit)->second)->second * 2.55), 255);
                } else {
                    *pwmChannel = std::min((int)(fanMap.find(tempMap.find(temp)->second)->second * 2.55), 255);
                }

            timer = HAL_GetTick();
        }
    }
};