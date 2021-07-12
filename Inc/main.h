/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ds18b20.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ONBOARD_LED_Pin GPIO_PIN_13
#define ONBOARD_LED_GPIO_Port GPIOC
#define OPT_BTN_Pin GPIO_PIN_4
#define OPT_BTN_GPIO_Port GPIOA
#define OPT_BTN_EXTI_IRQn EXTI4_IRQn
#define PWM3_BACK_Pin GPIO_PIN_0
#define PWM3_BACK_GPIO_Port GPIOB
#define PWM4_TOP_Pin GPIO_PIN_1
#define PWM4_TOP_GPIO_Port GPIOB
#define TEMP_WATER_Pin GPIO_PIN_10
#define TEMP_WATER_GPIO_Port GPIOB
#define TEMP_VRM_Pin GPIO_PIN_11
#define TEMP_VRM_GPIO_Port GPIOB
#define ST7735_RES_Pin GPIO_PIN_12
#define ST7735_RES_GPIO_Port GPIOB
#define ST7735_DC_Pin GPIO_PIN_13
#define ST7735_DC_GPIO_Port GPIOB
#define ST7735_CS_Pin GPIO_PIN_14
#define ST7735_CS_GPIO_Port GPIOB
#define ST7736_BL_Pin GPIO_PIN_15
#define ST7736_BL_GPIO_Port GPIOB
#define PWM1_FRONT_Pin GPIO_PIN_4
#define PWM1_FRONT_GPIO_Port GPIOB
#define PWM2_BOTTOM_Pin GPIO_PIN_5
#define PWM2_BOTTOM_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
