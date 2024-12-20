/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

#define TX_BUFFER_SIZE 256
#define RX_BUFFER_SIZE 256

#define SHOOT_BTN_ID 0
#define ROTATE_LEFT_BTN_ID 1
#define ROTATE_RIGHT_BTN_ID 2

#define PRESSED_BNT_ID_PATTERN "BTN_ID=%d\n"
#define DESTROYED_SHIP_SIZE_PATTERN "DESTROYED_SHIP_SIZE=%d\n"
#define BTN_ID_DELIMETER '\n'

extern volatile int destroyed_ship_summary;


/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);
void transmit_int_pattern_uart(UART_HandleTypeDef *huart, const char* pattern, int value);

/* USER CODE BEGIN EFP */


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_START_Pin GPIO_PIN_1
#define BTN_START_GPIO_Port GPIOA
#define BTN_START_EXTI_IRQn EXTI1_IRQn
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define A2_Pin GPIO_PIN_4
#define A2_GPIO_Port GPIOA
#define A2_EXTI_IRQn EXTI4_IRQn
#define D1_Pin GPIO_PIN_5
#define D1_GPIO_Port GPIOA
#define D2_Pin GPIO_PIN_6
#define D2_GPIO_Port GPIOA
#define D3_Pin GPIO_PIN_7
#define D3_GPIO_Port GPIOA
#define A3_Pin GPIO_PIN_0
#define A3_GPIO_Port GPIOB
#define A3_EXTI_IRQn EXTI0_IRQn
#define SHIFT_CLK_Pin GPIO_PIN_8
#define SHIFT_CLK_GPIO_Port GPIOA
#define SDI_Pin GPIO_PIN_9
#define SDI_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LATCH_CLK_Pin GPIO_PIN_5
#define LATCH_CLK_GPIO_Port GPIOB
#define D4_Pin GPIO_PIN_6
#define D4_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
