/**
  ******************************************************************************
  * @file    PWR/PWR_ModesSelection/Src/run_range2_test.c
  * @author  MCD Application Team
  * @brief   This sample code shows how to use STM32L4xx PWR HAL API to enter
  *          power modes.
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
#include <stdio.h>

/** @addtogroup STM32L4xx_HAL_Examples
  * @{
  */

/** @addtogroup PWR_ModesSelection
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


void test_run_range2_24mhz(void)
  {
  printf("\n\r Executing test (RUN Range 2, 24MHz - with FLASH ART ON) \n\r");
  printf(" Please measure current then use Reset button to select another test \n\r");
  
  /* Set the System clock to 24 MHz */
  SystemClock_24MHz();
  
  /* Enable PWR clock */
  __HAL_RCC_PWR_CLK_ENABLE();
  /* Configure the main internal regulator output voltage */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE2);
  /* Disable PWR clock */
  __HAL_RCC_PWR_CLK_DISABLE();
  
  /* Set all GPIO in analog state to reduce power consumption */
  GPIO_AnalogState_Config();
  
#ifdef USE_STM32L4XX_NUCLEO
  /* Disable USART2 clock */
  __HAL_RCC_USART2_CLK_DISABLE();
#elif USE_STM32L4XX_NUCLEO_144
  /* Disable LPUART1 clock */
  __HAL_RCC_LPUART1_CLK_DISABLE();
#endif
  
  /* Suspend Tick increment to prevent wakeup by Systick interrupt.         */
  /* Otherwise the Systick interrupt will wake up the device within 1ms     */
  /* (HAL time base).                                                       */
  HAL_SuspendTick();
  
 __NOP();
 __NOP();
  while(1);
  
}


/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
