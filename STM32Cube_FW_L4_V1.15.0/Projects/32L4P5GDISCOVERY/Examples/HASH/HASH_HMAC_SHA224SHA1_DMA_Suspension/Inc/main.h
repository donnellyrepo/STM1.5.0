/**
  ******************************************************************************
  * @file    HASH/HASH_HMAC_SHA224SHA1_DMA_Suspension/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics. 
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the 
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "stm32l4p5g_discovery.h"
#include "string.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define DMA_REQUEST                           DMA_REQUEST_HASH_IN
#define DMA_CHANNEL                           DMA2_Channel7
#define DMA_CLK_ENABLE()                      __HAL_RCC_DMA2_CLK_ENABLE()
#define DMAMUX_CLK_ENABLE()                   __HAL_RCC_DMAMUX1_CLK_ENABLE()
#define HASH_DMA_IRQn                         DMA2_Channel7_IRQn
/* Exported functions ------------------------------------------------------- */
#define HASH_DMA_IRQHandler                   DMA2_Channel7_IRQHandler

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
