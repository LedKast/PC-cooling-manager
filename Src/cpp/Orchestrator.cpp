#include "GUI.cpp"
#include "BluetoothUART.cpp"
#include "FanController.cpp"
#include "TempReader.cpp"

#include "configuration_default.h"


BluetoothUART btUART;

class Orchestrator {
    GUI gui;
    TempReader tempReader = TempReader();
    TempModel* temps;
    std::map<uint16_t, FanController> controllers;
    FanController frontController = FanController(&PWM_FRONT, BEQUIET_BL040_140MM, TEMP_MAP_WATER_FRONT);
    FanController topController = FanController(&PWM_FRONT, BEQUIET_BL040_140MM, TEMP_MAP_WATER_FRONT);
    FanController backController = FanController(&PWM_FRONT, BEQUIET_BL040_140MM, TEMP_MAP_WATER_FRONT);
    FanController bottomController = FanController(&PWM_FRONT, BEQUIET_BL040_140MM, TEMP_MAP_WATER_FRONT);

    GPIO_PinState indicatorLed = GPIO_PIN_SET;
    long loopStateTimer = -1;

public:
    Orchestrator(UART_HandleTypeDef* huart) {
        setup();
    }

    [[noreturn]] void loop() {

        while (true) {
            tempReader.read();
            temps = tempReader.getTemps();
            gui.draw(temps, 500);

            frontController.updateChannel(temps->waterTemp, MIN_BORDER_WATER_TEMP, MAX_BORDER_WATER_TEMP, 2500);
            topController.updateChannel(temps->waterTemp, MIN_BORDER_WATER_TEMP, MAX_BORDER_WATER_TEMP, 2500);
            backController.updateChannel(temps->waterTemp, MIN_BORDER_WATER_TEMP, MAX_BORDER_WATER_TEMP, 2500);
            bottomController.updateChannel(temps->waterTemp, MIN_BORDER_WATER_TEMP, MAX_BORDER_WATER_TEMP, 2500);

            // TODO add by VRM changing

//            btUART.receiver(&huart2);
            blinkOnboardLed();
        }
    }

private:
    void setup() {
        // TODO provide huart
        gui = GUI();
        btUART = BluetoothUART();
    }

    void blinkOnboardLed() {
        if (HAL_GetTick() - loopStateTimer > 500) {
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, indicatorLed);
            indicatorLed = (indicatorLed == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;
            loopStateTimer = HAL_GetTick();
        }
    }
};