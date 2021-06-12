#include <configuration_default.h>

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
                *pwmChannel = fanMap[tempMap[minLimit]] * 2.55;
            } else
                if (temp > maxLimit) {
                    *pwmChannel = fanMap[tempMap[maxLimit]] * 2.55;
                } else {
                    *pwmChannel = fanMap[tempMap[temp]] * 2.55;
                }

            timer = HAL_GetTick();
        }
    }
};