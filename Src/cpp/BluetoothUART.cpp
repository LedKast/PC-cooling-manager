#include "main.h"
#include <cstring>
#include <string>

class BluetoothUART {
    char str1[60] = {0};

    typedef struct USART_prop{
        uint8_t usart_buf[60];
        uint8_t usart_cnt;
    } USART_prop_ptr;
    USART_prop_ptr usartprop;

//    void string_parse(char* buf_str, UART_HandleTypeDef& huart)
//    {
//        HAL_UART_Transmit_IT(&huart, (uint8_t*)buf_str, strlen(buf_str));
//    }

public:
    BluetoothUART(){
    }

    void Receiver(UART_HandleTypeDef* huart) {
//        if (huart->RxXferCount != 0) {
            HAL_UART_Receive_IT(huart, (uint8_t *) str1, 10);
//        }
    }

    void Transmitter(UART_HandleTypeDef* huart)
    {
        if (str1[0] != 0)
            HAL_UART_Transmit_IT(huart, (uint8_t *) str1, 10);

//        if (usartprop.usart_cnt>59)
//        {
//            usartprop.usart_cnt=0;
//            HAL_UART_Receive_IT(&huart, (uint8_t*)str1, 1);
//            return;
//        }
//
//        usartprop.usart_buf[usartprop.usart_cnt] = b;
//        if(b==0x0A)
//        {
//            usartprop.usart_buf[usartprop.usart_cnt+1]=0;
//            string_parse((char*)usartprop.usart_buf, huart);
//            usartprop.usart_cnt=0;
//            HAL_UART_Receive_IT(&huart, (uint8_t*)str1, 1);
//            return;
//
//        }
//        usartprop.usart_cnt++;
    }
};