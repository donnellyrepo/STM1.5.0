/**
  ******************************************************************************
  * @file    HASH/HASH_HMAC_SHA224SHA1_DMA_Suspension/Src/stm32l4xx_hal_msp.c
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

/** @defgroup HAL_MSP
  * @brief HAL MSP module.
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
  * @brief  Initializes the HASH MSP.
  *        This function configures the hardware resources used in this example:
  *           - HASH clock enable
  *           - DMA clock enable
  * @param  hhash: HASH handle pointer
  * @retval None
  */
void HAL_HASH_MspInit(HASH_HandleTypeDef *hhash)
{
  static DMA_HandleTypeDef  hdma_hash;

  /* Enable HASH clock */
  __HAL_RCC_HASH_CLK_ENABLE();
  
  /* Enable DMA clock */
  DMA_CLK_ENABLE();
  DMAMUX_CLK_ENABLE();
  
  /***************** Configure common DMA In parameters ***********************/
  hdma_hash.Init.Request             = DMA_REQUEST;
  hdma_hash.Init.Direction           = DMA_MEMORY_TO_PERIPH;
  hdma_hash.Init.PeriphInc           = DMA_PINC_DISABLE;
  hdma_hash.Init.MemInc              = DMA_MINC_ENABLE;
  hdma_hash.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
  hdma_hash.Init.MemDataAlignment    = DMA_MDATAALIGN_WORD;
  hdma_hash.Init.Mode                = DMA_NORMAL;
  hdma_hash.Init.Priority            = DMA_PRIORITY_HIGH;
  hdma_hash.Instance = DMA_CHANNEL;
  
  /* Associate the DMA handle */
  __HAL_LINKDMA(hhash, hdmain, hdma_hash);
  
  /* Deinitialize the Stream for new transfer */
  HAL_DMA_DeInit(hhash->hdmain);
  
  /* Configure the DMA Stream */
  HAL_DMA_Init(hhash->hdmain);    
  
  HAL_NVIC_SetPriority(HASH_DMA_IRQn, 0x0F, 0x0);
  HAL_NVIC_EnableIRQ(HASH_DMA_IRQn);    
  
}

/**
  * @brief  De-Initializes the HASH MSP.
  * @param  hhash: HASH handle pointer
  * @retval None
  */
void HAL_HASH_MspDeInit(HASH_HandleTypeDef *hhash)
{
  /* Force the HASH Periheral Clock Reset */  
  __HAL_RCC_HASH_FORCE_RESET(); 
  
  /* Release the HASH Periheral Clock Reset */  
  __HAL_RCC_HASH_RELEASE_RESET();
  
  /* Disable HASH clock */
  __HAL_RCC_HASH_CLK_DISABLE();
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
