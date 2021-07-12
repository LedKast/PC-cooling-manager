#include "GUI.cpp"
#include "BluetoothUART.cpp"
#include "FanController.cpp"
#include "TempReader.cpp"

#include "Configuration.h"
#include "Maps.h"


class Orchestrator {
    FanController frontController = FanController(&PWM_FRONT, BEQUIET_BL040_140MM, TEMP_MAP_WATER_FRONT);
    FanController topController = FanController(&PWM_TOP, BEQUIET_BL039_120MM, TEMP_MAP_WATER_RADIATOR_120MM);
    FanController backController = FanController(&PWM_BACK, BEQUIET_BL040_140MM, TEMP_MAP_WATER_BACK);
    FanController bottomController = FanController(&PWM_BOTTOM, BEQUIET_BL040_140MM, TEMP_MAP_WATER_BOTTOM);
    GUI gui;
    FanModel fansRPM = FanModel();
    TempReader tempReader = TempReader();
    TempModel* temps;

    GPIO_PinState indicatorLed = GPIO_PIN_SET;
    long loopStateTimer = -1;

public:
    Orchestrator(UART_HandleTypeDef* huart) {
        setup();
    }

    [[noreturn]] void loop() {
        while (true) {
            temps = tempReader.read();
            updateFans();

            gui.draw(temps, fansRPM, 500);
            // TODO add by VRM changing

            // TODO add buttons, add service mode (send test data via BT)

//            btUART.receiver(&huart2);
            blinkOnboardLed();
        }
    }

private:
    void setup() {
        // TODO provide huart
        gui = GUI();
//        btUART = BluetoothUART();
    }

    void updateFans() {
        fansRPM.frontRPM = frontController.updateChannel(temps->waterTemp, MIN_BORDER_WATER_TEMP, MAX_BORDER_WATER_TEMP, FAN_UPDATE_DELAY);
        fansRPM.topRPM = topController.updateChannel(temps->waterTemp, MIN_BORDER_WATER_TEMP, MAX_BORDER_WATER_TEMP, FAN_UPDATE_DELAY);
        fansRPM.backRPM = backController.updateChannel(temps->waterTemp, MIN_BORDER_WATER_TEMP, MAX_BORDER_WATER_TEMP, FAN_UPDATE_DELAY);
        fansRPM.bottomRPM = bottomController.updateChannel(temps->waterTemp, MIN_BORDER_WATER_TEMP, MAX_BORDER_WATER_TEMP, FAN_UPDATE_DELAY);
    }

    void blinkOnboardLed() {
        if (HAL_GetTick() - loopStateTimer > 500) {
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, indicatorLed);
            indicatorLed = (indicatorLed == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;
            loopStateTimer = HAL_GetTick();
        }
    }
};