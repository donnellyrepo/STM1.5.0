/**
  ******************************************************************************
  * @file    HASH/HASH_HMAC_SHA224MD5_IT_DMA_Suspension/Src/stm32l4xx_it.c
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32l4xx_it.h"

/** @addtogroup STM32L4xx_HAL_Examples
  * @{
  */

/** @addtogroup HASH_HMAC_SHA224MD5_IT_DMA_Suspension
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern HASH_HandleTypeDef HashHandle;
extern UART_HandleTypeDef huart;
extern uint32_t IT_call_nb;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}

/******************************************************************************/
/*                 STM32L4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32l4xx.s).                                               */
/******************************************************************************/

/**
* @brief  This function handles DMA interrupt request.
* @param  None
* @retval None
*/
void HASH_DMA_IRQHandler(void)
{
  HAL_DMA_IRQHandler(HashHandle.hdmain);
}


/**
  * @brief  This function handles HASH interrupt request.
  * @param  None
  * @retval None
  */
void HASH_IRQHandler(void)
{

  /* In case of HMAC MD5 processing, input data are fed
     in interruption mode. 
     Global variable IT_call_nb is used to artificially trigger 
     the low block processing suspension
     after three interrupts */
  IT_call_nb++;
  if  (IT_call_nb == 3)
  {
    HAL_HASH_SwFeed_ProcessSuspend(&HashHandle);
  }   
  
  HAL_HASH_IRQHandler(&HashHandle);
}


/**
  * @brief  This function handles USART1 interrupt request.
  * @param  None
  * @retval None
  */
void USART1_IRQHandler(void)
{

  /* As soon as triggered, TX data register empty interrupt is disabled
     to ensure there is one interrupt only (triggered for
     suspension illustration only) */
  __HAL_UART_DISABLE_IT(&huart, UART_IT_TXE);
  /* Request DMA-based low priority block processing suspension */
  if (HAL_HASH_DMAFeed_ProcessSuspend(&HashHandle) != HAL_OK)
  {
    while (1);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
