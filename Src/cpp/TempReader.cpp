#include "Configuration.h"
#include "model/TempModel.cpp"
#include "ds18b20.h"

class TempReader {
    struct SensorData
    {
        uint8_t dt[8];
        uint16_t raw_temp;
        long timer;
        bool skipromEnable;
    } ds18_1 = {NULL, 0, 0, true}, ds18_2 = {NULL, 0, 0, true};

    TempModel temps = TempModel();

public:
    TempReader() {
        // DS18B20 temp
        port_init();
        ds18b20_init(SKIP_ROM);
    }

    TempModel* read() {
        // TODO усреднять значение за некоторый промежуток времени (например через стек или кольцевую очередь)
        set_port(VRM_SENS); // VRM
        readDS18(&temps.vrmTemp, &ds18_1);

        set_port(WATER_SENS); // water
        readDS18(&temps.waterTemp, &ds18_2);
        return &temps;
    }

private:
    void readDS18(uint8_t *temp, SensorData *ds18)
    {
        long currentTick = HAL_GetTick();

        if (ds18->skipromEnable && currentTick - ds18->timer >= 150)
        {
            ds18->skipromEnable = false;
            ds18b20_MeasureTemperCmd(SKIP_ROM, 0);
        }

        if(!ds18->skipromEnable && currentTick - ds18->timer >= 950) // 800+150
        {
            ds18b20_ReadStratcpad(SKIP_ROM, ds18->dt, 0);
            ds18->raw_temp = ((uint16_t)ds18->dt[1] << 8) | ds18->dt[0];
            *temp = ds18b20_Convert(ds18->raw_temp);

            ds18->timer = HAL_GetTick();

            //TODO HAL_Delay(150);

            ds18->skipromEnable = true;
        }
    }
};