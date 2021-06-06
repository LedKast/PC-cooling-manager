#include "GUI.cpp"
#include "BluetoothUART.cpp"
#include "FanController.cpp"

#include "configuration_default.h"


BluetoothUART btUART;

class Orchestrator {
    GUI gui;
    FanController controllers[];

public:
    Orchestrator(UART_HandleTypeDef* huart) {
        // TODO provide huart
        gui = GUI();
        btUART = BluetoothUART();
    }

    void loop() {
        setup();

        while (true) {

            gui.demoTFT();

//            btUART.receiver(&huart2);
        }
    }

private:
    void setup() {
        // TODO create controller objects
        FanController channel1 = FanController(&PWM_FRONT);
    }
};