/**
  ******************************************************************************
  * @file    OPAMP/OPAMP_PGA/Src/stm32l4xx_it.c
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
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
#include "stm32l4xx_it.h"

/** @addtogroup STM32L4xx_HAL_Examples
  * @{
  */

/** @addtogroup OPAMP_PGA
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern DAC_HandleTypeDef    DacHandle;

extern OPAMP_HandleTypeDef  OpampHandle;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
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

void DMA1_Channel3_IRQHandler(void)
{
  HAL_DMA_IRQHandler(DacHandle.DMA_Handle1);
}


/**
  * @brief  This function handles external lines 15 to 10 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI15_10_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(TAMPER_BUTTON_PIN);

#ifndef CHANGE_GAIN_IN_SLEEP_IN_MAIN
  /* In case the gain change within the IT */

  if (OpampHandle.Init.PgaGain == OPAMP_PGA_GAIN_2)
  {
/*----------------------------------------------------------------------------*/
/* Step 3: (another push on Key button)                                       */
/*    DAC:     Low power mode                                                 */
/*  	OPAMP:   Low power mode - gain = 4                                      */
/*    DMA:     circular mode - DMA half transfer - no IT handled by Cortex    */
/*    Cortex:  sleep mode                                                     */ 
/*----------------------------------------------------------------------------*/
/* Gain change on the fly to 4 */
  OpampHandle.Init.PgaGain = OPAMP_PGA_GAIN_4;
  }
  else
  {
/*----------------------------------------------------------------------------*/
/* Step 4: (another push on Key button)                                       */
/*    DAC:     Low power mode                                                 */
/*  	OPAMP:   Low power mode - gain = 2                                      */
/*    DMA:     circular mode - DMA half transfer - no IT handled by Cortex    */
/*    Cortex:  sleep mode                                                     */ 
/*----------------------------------------------------------------------------*/
  /* Gain change on the fly to 2 */
  OpampHandle.Init.PgaGain = OPAMP_PGA_GAIN_2;
  }
  if(HAL_OK != HAL_OPAMP_Init(&OpampHandle))
  {
    Error_Handler();
  }
#endif 
}

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
