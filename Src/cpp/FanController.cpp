#include "Configuration.h"
#include <map>
#include <stm32f1xx_hal.h>


class FanController {
    volatile uint32_t* pwmChannel;
    uint16_t rpm = 0;
    FanSpeedMap fanMap;
    TempMap tempMap;

    long timer = -1;

public:

    FanController(volatile uint32_t* channel, FanSpeedMap fanMap, TempMap tempMap) {
        pwmChannel = channel;
        this->fanMap = fanMap;
        this->tempMap = tempMap;
    }

    uint16_t updateChannel(uint16_t temp, uint16_t minLimit, uint16_t maxLimit, uint16_t updateDelay) {
        if (HAL_GetTick() - timer > updateDelay) {
            uint16_t targetRPM;

            if (temp < minLimit) {
                targetRPM = tempMap.find(minLimit)->second;
            } else {
                if (temp > maxLimit) {
                    targetRPM = tempMap.find(maxLimit)->second;
                } else {
                    targetRPM = tempMap.find(temp)->second;
                }
            }

            *pwmChannel = std::min((int)(fanMap.find(targetRPM)->second * 2.55), 255);
            rpm = targetRPM;
            timer = HAL_GetTick();
        }

        return rpm;
    }
};