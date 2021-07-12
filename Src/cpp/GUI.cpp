#include "st7735.h"
#include "fonts.h"
#include <stdio.h>

#include "model/TempModel.cpp"

class GUI {
//    uint16_t k = 0;
    char buff3[3];
    char buff4[4];
    long redrawTimer = -1;
    long animationTimer = -1;
    bool animation = true;
    uint8_t lineSpace = 22;

public:

    GUI(uint8_t rotation = 2) {
        ST7735_Init();
        ST7735_Backlight_On();
        ST7735_SetRotation(rotation);
        ST7735_FillScreen(ST7735_BLACK);
    }

    void draw(TempModel* tempModel, uint16_t refreshTime = 500) {
        if (HAL_GetTick() - redrawTimer > refreshTime) {
            // LINE 1 (water temp)
            drawLabel(0, 0, "WTR", "TMP", ST7735_WHITE);
            drawValue2(10 * 3, 1, tempModel->waterTemp, ST7735_WHITE);
            if (tempModel->waterTemp >= 20) {
                // TODO fix offset limit
                drawBarChart(55, 0, 51, 10, tempModel->waterTemp, 20, 50, 0x74F4, ST7735_WHITE);
            }

            // LINE 2 (front)
            uint8_t lineMultiplier = 1;
            drawLabel(0, lineSpace * lineMultiplier, "F->", "FAN", ST7735_WHITE);
            drawValue4(10 * 3, lineSpace * lineMultiplier + 1, 1000, ST7735_WHITE);
//            drawBarChart(55, lineSpace * 1, 51, 10, tempModel->waterTemp, 450, 1000, 0x74F4, ST7735_WHITE);

            drawAnimation(100, 100, 7, ST7735_WHITE);

            redrawTimer = HAL_GetTick();
        }
    }

private:
    void drawLabel(int16_t x, int16_t y, const char* str1, const char* str2, int16_t color) {
        ST7735_DrawString(x, y, str1, Font_7x10, color, ST7735_BLACK);
        ST7735_DrawString(x, y + 10, str2, Font_7x10, color, ST7735_BLACK);
    }

    void drawValue2(int16_t x, int16_t y, int16_t value, int16_t color) {
        snprintf(buff3, sizeof(buff3), "%d", value);
        ST7735_DrawString(x, y, buff3, Font_11x18, color, ST7735_BLACK);
    }

    void drawValue4(int16_t x, int16_t y, int16_t value, int16_t color) {
        snprintf(buff4, sizeof(buff4), "%d", value);
        ST7735_DrawString(x, y, buff4, Font_11x18, color, ST7735_BLACK);
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
        ST7735_DrawRect(x, y, w, h, frameColor);
        ST7735_FillRectangle(x + 2, y + 2, w - 4, 6, ST7735_BLACK);
        ST7735_FillRectangle(x + 2, y + 2, (int)(((float)(value - offset)/(float)limit)*(float)(w - 4))%(w - 3), h - 4, color);
    }

    void drawAnimation(int16_t x, int16_t y, uint8_t size, uint16_t color) {
        if (animation) {
            ST7735_FillCircle(x, y, size, color);
        } else {
            ST7735_FillCircle(x, y, size, ST7735_BLACK);
            ST7735_DrawCircle(x, y, size, color);
        }

        if (HAL_GetTick() - animationTimer > 1000) {
            animationTimer = HAL_GetTick();
            animation = !animation;
        }

    }

//    void demoTFT() {
//        // LINE 1
//        ST7735_DrawString(0, 0, "CPU", Font_7x10, 0x74F4, ST7735_BLACK);
//        ST7735_DrawString(0, 10, "FAN", Font_7x10, 0x74F4, ST7735_BLACK);
//
//        snprintf(buff, sizeof(buff), "%d", k);
//        ST7735_DrawString(10*3, 1, buff, Font_11x18, ST7735_WHITE, ST7735_BLACK);
//
//
//
////    ST7735_DrawString(0,64, usartprop.usart_buf, Font_7x10, ST7735_WHITE, ST7735_BLACK);
//
//        // // LINE 2
//        // ST7735_DrawString(0, 18, buff, Font_11x18, ST7735_WHITE, ST7735_BLACK);
//
//
//        for (int i = 0; i < sizeof(buff); i++) {
//            buff[i]=0;
//        }
//
//        k+=5;
//
//        HAL_Delay(1000);
//    }
};



