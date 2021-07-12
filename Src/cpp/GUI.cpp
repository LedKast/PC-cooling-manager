#include "st7735.h"
#include "fonts.h"
#include <cstdio>
#include "Configuration.h"

#include "model/TempModel.cpp"
#include "model/FanModel.cpp"

class GUI {
//    uint16_t k = 0;
    char buff3[3];
    char buff5[5];
    long redrawTimer = -1;
    long animationTimer = -1;
    uint8_t lineSpace = 22;

    uint8_t animationSize = 6;
    bool animationDirection = true;
    uint8_t animationTargetSize = animationSize;

public:

    GUI(uint8_t rotation = 2) {
        ST7735_Init();
        ST7735_Backlight_On();
        ST7735_SetRotation(rotation);
        ST7735_FillScreen(ST7735_BLACK);
    }

    void draw(TempModel* tempModel, FanModel& fanModel, uint16_t refreshTime = 500) {
        if (HAL_GetTick() - redrawTimer > refreshTime) {
            // LINE 1 left (water temp)
            uint8_t lineMultiplier = 0;
            drawLabel(0, lineSpace * lineMultiplier, "WTR", "", ST7735_TEXT);
            draw2digit(
                    10 * 3,
                    lineSpace * lineMultiplier + 1,
                    tempModel->waterTemp,
                    getColorByTemp2Points(tempModel->waterTemp, WATER_WARNING_LEVEL, WATER_CRITICAL_LEVEL));

            // LINE 1 right
//            lineMultiplier = 1;
            drawLabel(64, lineSpace * lineMultiplier, "VRM", "", ST7735_TEXT);
            draw2digit(
                    64 + 10 * 3,
                    lineSpace * lineMultiplier + 1,
                    tempModel->vrmTemp,
                    getColorByTemp2Points(tempModel->vrmTemp, VRM_WARNING_LEVEL, VRM_CRITICAL_LEVEL));

            uint16_t image[] = {0xFF, 0xFF, 0xFF, 0xFF};
//            ST7735_DrawImage(0, 10, 2, 2, image);


            // LINE 3
            lineMultiplier = 2;
            drawLabel(0, lineSpace * lineMultiplier, "T ^", "", ST7735_TEXT);
            draw4digit(
                    10 * 3,
                    lineSpace * lineMultiplier + 1,
                    fanModel.topRPM,
                    getColorByTemp2Points(tempModel->waterTemp, 1000, 1250));

            // LINE 4
            lineMultiplier = 3;
            drawLabel(0, lineSpace * lineMultiplier, "F->", "", ST7735_TEXT);
            draw4digit(
                    10 * 3,
                    lineSpace * lineMultiplier + 1,
                    fanModel.frontRPM,
                    getColorByTemp2Points(tempModel->waterTemp, 750, 900));

            // LINE 5
            lineMultiplier = 4;
            drawLabel(0, lineSpace * lineMultiplier, "<-B", "", ST7735_TEXT);
            draw4digit(
                    10 * 3,
                    lineSpace * lineMultiplier + 1,
                    fanModel.backRPM,
                    getColorByTemp2Points(tempModel->waterTemp, 750, 900));

//            // LINE 6 TODO enable for bottom fans
//            lineMultiplier = 5;
//            drawLabel(0, lineSpace * lineMultiplier, "BTT", "FAN", ST7735_WHITE);
//            draw4digit(10 * 3, lineSpace * lineMultiplier + 1, fanModel.bottomRPM, ST7735_WHITE);



            redrawTimer = HAL_GetTick();
        }

        drawAnimation(120, 120, ST7735_WHITE);
    }

private:
    void drawLabel(int16_t x, int16_t y, const char* str1, const char* str2, int16_t color) {
        ST7735_DrawString(x, y, str1, Font_7x10, color, ST7735_BLACK);
        ST7735_DrawString(x, y + 10, str2, Font_7x10, color, ST7735_BLACK);
    }

    void draw2digit(int16_t x, int16_t y, int16_t value, int16_t color) {
        snprintf(buff3, sizeof(buff3), "%d", value);
        ST7735_DrawString(x, y, buff3, Font_11x18, color, ST7735_BLACK);
    }

    void draw4digit(int16_t x, int16_t y, int16_t value, int16_t color) {
        snprintf(buff5, sizeof(buff5), "%d", value);
        ST7735_DrawString(x, y, buff5, Font_11x18, color, ST7735_BLACK);
    }

    void drawBarChart(
            int16_t x,
            int16_t y,
            int16_t w,
            int16_t h,
            uint16_t value,
            uint16_t offset,
            uint16_t limit,
            uint16_t frameColor,
            uint16_t color) {

        // TODO add check for value and offset/limit

        ST7735_DrawRect(x, y, w, h, frameColor);
        ST7735_FillRectangle(x + 2, y + 2, w - 4, 6, ST7735_BLACK);
        ST7735_FillRectangle(x + 2, y + 2, (int)(((float)(value - offset)/(float)limit)*(float)(w - 4))%(w - 3), h - 4, color);
    }

    void drawAnimation(int16_t x, int16_t y, uint16_t color) {

        if (HAL_GetTick() - animationTimer > 400) {
            ST7735_FillCircle(x, y, animationSize, ST7735_BLACK);
            ST7735_FillCircle(x, y, animationTargetSize, color);
            animationTimer = HAL_GetTick();
            animationTargetSize = animationTargetSize + ((animationDirection) ? -1 : 1);
            if (animationTargetSize == animationSize || animationTargetSize == 3) {
                animationDirection = !animationDirection;
            }
        }
    }

    uint16_t getColorByTemp2Points(uint16_t value, uint16_t warnLevel, uint16_t criticalLevel) {
        if (value < warnLevel) {
            return ST7735_NORMAL;
        } else {
            if (value < criticalLevel) {
                return ST7735_WARNING;
            } else {
                return ST7735_CRITICAL;
            }
        }
    }
};



