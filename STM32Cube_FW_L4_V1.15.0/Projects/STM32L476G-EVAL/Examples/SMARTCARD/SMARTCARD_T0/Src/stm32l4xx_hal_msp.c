/**
  ******************************************************************************
  * @file    SMARTCARD_T0/Src/stm32l4xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32L4xx_HAL_Examples
  * @{
  */

/** @addtogroup SMARTCARD_T0
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
  * @brief SMARTCARD MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  *           - NVIC configuration
  * @param hsmartcard: SmartCard handle pointer
  * @retval None
  */
void HAL_SMARTCARD_MspInit(SMARTCARD_HandleTypeDef *hsc)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  RCC_PeriphCLKInitTypeDef  RCC_PeriphCLKInitStruct;
  
  /* Enable Smartcard GPIO clocks */
  SC_USART_TX_CLK_ENABLE();
  SC_USART_CK_CLK_ENABLE();
                         
  /* Configure USART Tx pin as alternate function open-drain */
  GPIO_InitStruct.Pin = SC_USART_TX_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(SC_USART_TX_GPIO_PORT, &GPIO_InitStruct);

  /* Configure USART Clock pin as alternate function push-pull */
  GPIO_InitStruct.Pin = SC_USART_CK_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  HAL_GPIO_Init(SC_USART_CK_GPIO_PORT, &GPIO_InitStruct);

  /* Enable SC_USART IRQ */
  HAL_NVIC_SetPriority(SC_USART_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(SC_USART_IRQn);

  /* Enable SmartCard clock */
  SC_USART_CLK_ENABLE();

  /* Configure the USART clock source. The clock is derived from the PCLK1 #*/
  RCC_PeriphCLKInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3;
  RCC_PeriphCLKInitStruct.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphCLKInitStruct);  
}

/**
  * @brief SMARTCARD MSP De-Initialization 
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO, DMA and NVIC configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_SMARTCARD_MspDeInit(SMARTCARD_HandleTypeDef *hsmartcard)
{
  /*##-1- Reset peripherals ##################################################*/
  SC_USART_FORCE_RESET(); 
  SC_USART_RELEASE_RESET();

  /* Disable SmartCard clock */
  SC_USART_CLK_DISABLE();
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
