/**
  ******************************************************************************
  * @file    FMC/FMC_SRAM/Src/stm32l4xx_hal_msp.c
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

/** @defgroup FMC_SRAM
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
  * @brief SRAM MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param hsram: SRAM handle pointer
  * @retval None
  */
void HAL_SRAM_MspInit(SRAM_HandleTypeDef *hsram)
{
  GPIO_InitTypeDef GPIO_Init_Structure;

  /* Enable FMC clock */
  __HAL_RCC_FMC_CLK_ENABLE();

  /* Enable GPIOs clock */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();
  HAL_PWREx_EnableVddIO2();

  /* Common GPIO configuration */
  GPIO_Init_Structure.Mode      = GPIO_MODE_AF_PP;
  GPIO_Init_Structure.Pull      = GPIO_PULLUP;
  GPIO_Init_Structure.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_Init_Structure.Alternate = GPIO_AF12_FMC;

  /*## Address Bus #######*/
  /* GPIOF configuration */  
  GPIO_Init_Structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | \
                              GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_12 | GPIO_PIN_13 | \
                              GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOF, &GPIO_Init_Structure);
  
  /* GPIOG configuration */  
  GPIO_Init_Structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | \
                              GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5;
  HAL_GPIO_Init(GPIOG, &GPIO_Init_Structure);
  
  /* GPIOD configuration */
  GPIO_Init_Structure.Pin   = GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13;
  HAL_GPIO_Init(GPIOD, &GPIO_Init_Structure);

  /* GPIOE configuration */  
  GPIO_Init_Structure.Pin   = GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5;
  HAL_GPIO_Init(GPIOE, &GPIO_Init_Structure);

  /*## Data Bus #######*/
  /* GPIOD configuration */
  GPIO_Init_Structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_8 | GPIO_PIN_9 | \
                              GPIO_PIN_10 | GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOD, &GPIO_Init_Structure);

  /* GPIOE configuration */  
  GPIO_Init_Structure.Pin   = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | \
                              GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | \
                              GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOE, &GPIO_Init_Structure);
  
  /*## NOE and NWE configuration #######*/ 
  GPIO_Init_Structure.Pin = GPIO_PIN_4 |GPIO_PIN_5;
  HAL_GPIO_Init(GPIOD, &GPIO_Init_Structure);

  /*## Enable Bank pin configuration #######*/
  GPIO_Init_Structure.Pin = GPIO_PIN_7;
  HAL_GPIO_Init(GPIOD, &GPIO_Init_Structure);

  /*## NBL0, NBL1 configuration #######*/
  GPIO_Init_Structure.Pin = GPIO_PIN_0 | GPIO_PIN_1;
  HAL_GPIO_Init(GPIOE, &GPIO_Init_Structure); 
}

/**
  * @brief SRAM MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO configuration to their default state
  * @param hsram: SRAM handle pointer
  * @retval None
  */
void HAL_SRAM_MspDeInit(SRAM_HandleTypeDef *hsram)
{
  /*## Disable peripherals and GPIO Clocks ###################################*/
  /* Configure FMC as alternate function  */
  HAL_GPIO_DeInit(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5     | \
                  GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | \
                  GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);

  HAL_GPIO_DeInit(GPIOE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_7     | \
                  GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | \
                  GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);

  HAL_GPIO_DeInit(GPIOF, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | \
                  GPIO_PIN_5 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);

  HAL_GPIO_DeInit(GPIOG, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | \
                  GPIO_PIN_5 | GPIO_PIN_9);
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
