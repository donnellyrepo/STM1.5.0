/**
  ******************************************************************************
  * @file    RTC/RTC_LSI/Src/stm32l4xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
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

/** @addtogroup stm32l4xx_HAL_Examples
  * @{
  */

/** @defgroup RTC_LSI
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
  * @brief RTC MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  * @param hrtc: RTC handle pointer
  * @note  Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select 
  *        the RTC clock source; in this case the Backup domain will be reset in  
  *        order to modify the RTC Clock source, as consequence RTC registers (including 
  *        the backup registers) and RCC_CSR register are set to their reset values.  
  * @retval None
  */
void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc)
{
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_PeriphCLKInitTypeDef  PeriphClkInitStruct;
  
  /* Enable access to the backup domain */
  __HAL_RCC_PWR_CLK_ENABLE();
  HAL_PWR_EnableBkUpAccess();
  
  /*## Get RTC clock configuration #########################################*/
  HAL_RCCEx_GetPeriphCLKConfig(&PeriphClkInitStruct);
  
  /* Check whether RTC clock is already configured from previous program run */
  if(PeriphClkInitStruct.RTCClockSelection == RCC_RTCCLKSOURCE_LSI)
  {
    /* Do nothing */
  }
  else
  {
    /* If selected RTC clock source is different from current RTC clock source,
    first disable RTC clock source */
    if(PeriphClkInitStruct.RTCClockSelection != RCC_RTCCLKSOURCE_NONE)
    {
      PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
      PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_NONE;
      if(HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
      {
        Error_Handler();
      }
    }
    
    /*## Configure LSI as RTC clock source ###################################*/ 
    HAL_RCC_GetOscConfig(&RCC_OscInitStruct);
    
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_LSE;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    RCC_OscInitStruct.LSIState = RCC_LSI_ON;
    RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
    if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
    if(HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    { 
      Error_Handler();
    }
  }
  
  /*## Enable RTC peripheral Clocks #######################################*/ 
  /* Enable RTC Clock */ 
  __HAL_RCC_RTC_ENABLE(); 

  /* Enable RTC APB clock  */
  __HAL_RCC_RTCAPB_CLK_ENABLE();
  
  /*##-3- Configure the NVIC for RTC Alarm ###################################*/
  HAL_NVIC_SetPriority(RTC_WKUP_IRQn, 0x0, 0);
  
  /* Enable the RTC global Interrupt */
  HAL_NVIC_EnableIRQ(RTC_WKUP_IRQn);
}

/**
  * @brief RTC MSP De-Initialization 
  *        This function freeze the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  * @param hrtc: RTC handle pointer
  * @retval None
  */
void HAL_RTC_MspDeInit(RTC_HandleTypeDef *hrtc)
{
  /*##-1- Reset peripherals ##################################################*/
  __HAL_RCC_RTC_DISABLE();    
}

/**
  * @brief TIM MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  * @param htim: TIM handle pointer
  * @retval None
  */
void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim)
{
  /* TIM16 Peripheral clock enable */
  __HAL_RCC_TIM16_CLK_ENABLE();
  
  /* Configure the NVIC for TIM16 */
  HAL_NVIC_SetPriority(TIM1_UP_TIM16_IRQn,0,0);
  
  /* Enable the TIM16 global Interrupt */
  HAL_NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);
}

/**
  * @brief RTC MSP De-Initialization 
  *        This function freeze the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  * @param htim: TIM handle pointer
  * @retval None
  */
void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef *htim)
{
   /* Enable the TIM16 global Interrupt */
  HAL_NVIC_DisableIRQ(TIM1_UP_TIM16_IRQn);
  
  /* TIM16 Peripheral clock disable */
  __HAL_RCC_TIM16_CLK_DISABLE();
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
