#include "st7735.h"
#include "fonts.h"
#include <stdio.h>

class GUI {
    uint16_t k = 0;
    char buff[4];

public:

    GUI(uint8_t rotation = 2) {
        ST7735_Init();
        ST7735_Backlight_On();
        ST7735_SetRotation(rotation);
        ST7735_FillScreen(ST7735_BLACK);
    }

    void demoTFT() {
        // LINE 1
        ST7735_DrawString(0, 0, "CPU", Font_7x10, 0x74F4, ST7735_BLACK);
        ST7735_DrawString(0, 10, "FAN", Font_7x10, 0x74F4, ST7735_BLACK);

        snprintf(buff, sizeof(buff), "%d", k);
        ST7735_DrawString(10*3, 1, buff, Font_11x18, ST7735_WHITE, ST7735_BLACK);

        ST7735_DrawRect(70, 0, 55, 10, 0x74F4);
        ST7735_FillRectangle(72, 2, 51, 6, ST7735_BLACK);
        ST7735_FillRectangle(72, 2, (int)(((float)k/100.0)*51.0)%52, 6, ST7735_WHITE);


//    ST7735_DrawString(0,64, usartprop.usart_buf, Font_7x10, ST7735_WHITE, ST7735_BLACK);

        // // LINE 2
        // ST7735_DrawString(0, 18, buff, Font_11x18, ST7735_WHITE, ST7735_BLACK);


        for (int i = 0; i < sizeof(buff); i++) {
            buff[i]=0;
        }

        k+=5;

        HAL_Delay(1000);
    }
};



