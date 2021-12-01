/**
******************************************************************************
* @file    USB_Device/HID_Standalone_BCD/Src/main.c
* @author  MCD Application Team
* @brief   USB device HID demo main file
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license SLA0044,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        http://www.st.com/SLA0044
*
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
USBD_HandleTypeDef USBD_Device;
extern PCD_HandleTypeDef hpcd;

/* Private function prototypes -----------------------------------------------*/
static void Error_Handler(void);

/* Private functions ---------------------------------------------------------*/
/**
* @brief  Main program
* @param  None
* @retval None
*/
int main(void)
{

  /* STM32L4xx HAL library initialization:
  - Configure the Flash prefetch
  - Systick timer is configured by default as source of time base, but user
  can eventually implement his proper time base source (a general purpose
  timer for example or other time source), keeping in mind that Time base
  duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and
  handled in milliseconds basis.
  - Set NVIC Group Priority to 4
  - Low Level Initialization
  */
  HAL_Init();

  /* Configure the system clock to get correspondent USB clock source */
  SystemClock_Config();

  /* Enable Power Clock*/
  __HAL_RCC_PWR_CLK_ENABLE();

  /* Enable USB power on Pwrctrl CR2 register */
  HAL_PWREx_EnableVddUSB();

  /* Init Device Library */
  USBD_Init(&USBD_Device, &HID_Desc, 0);

  /* Register the HID class */
  USBD_RegisterClass(&USBD_Device, &USBD_HID);


  /* Configure LED4 */
  BSP_LED_Init(LED4);

  while (1)
  {
  }
}

/**
* @brief  HAL_PCDEx_BCD_Callback : Send BCD message to user layer
* @param  hpcd: PCD handle
* @param  msg: LPM message
* @retval HAL status
*/
void HAL_PCDEx_BCD_Callback(PCD_HandleTypeDef *hpcd, PCD_BCD_MsgTypeDef msg)
{
  uint8_t count = 0U;
  switch(msg)
  {
  case PCD_BCD_CONTACT_DETECTION:
    BSP_LED_On(LED4);
    break;

  case PCD_BCD_STD_DOWNSTREAM_PORT:
  while (count < 100U)
  {
   BSP_LED_Toggle(LED4);
    HAL_Delay(100);
    count++;
  }
    break;

  case PCD_BCD_CHARGING_DOWNSTREAM_PORT:
    while (count < 100U)
  {
    BSP_LED_Toggle(LED4);
    HAL_Delay(500);
    count++;
  }
    break;

  case PCD_BCD_DEDICATED_CHARGING_PORT:
    while (count < 100U)
  {
    BSP_LED_Toggle(LED4);
    HAL_Delay(1000);
    count++;
  }
    break;

  case PCD_BCD_DISCOVERY_COMPLETED:
    USBD_Start(&USBD_Device);
    break;

  case PCD_BCD_ERROR:
    default:
      break;
  }
}

/**
* @brief  System Clock Configuration
*         The system Clock is configured as follow:
*
*            HSI48 used as USB clock source (USE_USB_CLKSOURCE_CRSHSI48 defined in main.h)
*              - System Clock source            = HSI
*              - HSI Frequency(Hz)              = 48000000
*              - SYSCLK(Hz)                     = 48000000
*              - HCLK(Hz)                       = 48000000
*              - AHB Prescaler                  = 1
*              - APB1 Prescaler                 = 1
*              - APB2 Prescaler                 = 2
*              - Flash Latency(WS)              = 1
*              - Main regulator output voltage  = Scale1 mode
*
* @param  None
* @retval None
*/
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_PeriphCLKInitTypeDef  PeriphClkInitStruct;

#if defined (USE_USB_CLKSOURCE_CRSHSI48)
  static RCC_CRSInitTypeDef RCC_CRSInitStruct;
#endif

#if defined (USE_USB_CLKSOURCE_CRSHSI48)

  /* Enable HSI48 Oscillator to be used as system clock source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_OFF;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;

  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Select HSI48 as USB clock source */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInitStruct.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

  /* Select HSI48 as system clock source and configure the HCLK and PCLK1
  clock dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }

  /*Configure the clock recovery system (CRS)**********************************/

  /* Enable CRS Clock */
  __HAL_RCC_CRS_CLK_ENABLE();

  /* Default Synchro Signal division factor (not divided) */
  RCC_CRSInitStruct.Prescaler = RCC_CRS_SYNC_DIV1;

  /* Set the SYNCSRC[1:0] bits according to CRS_Source value */
  RCC_CRSInitStruct.Source = RCC_CRS_SYNC_SOURCE_USB;

  /* HSI48 is synchronized with USB SOF at 1KHz rate */
  RCC_CRSInitStruct.ReloadValue =  RCC_CRS_RELOADVALUE_DEFAULT;
  RCC_CRSInitStruct.ErrorLimitValue = RCC_CRS_ERRORLIMIT_DEFAULT;

  RCC_CRSInitStruct.Polarity = RCC_CRS_SYNC_POLARITY_RISING;

  /* Set the TRIM[5:0] to the default value*/
  RCC_CRSInitStruct.HSI48CalibrationValue = RCC_CRS_HSI48CALIBRATION_DEFAULT;

  /* Start automatic synchronization */
  HAL_RCCEx_CRSConfig (&RCC_CRSInitStruct);


#endif /*USE_USB_CLKSOURCE_CRSHSI48*/

  /* Enable Power Controller clock */
  __HAL_RCC_PWR_CLK_ENABLE();
}


/**
  * @brief  Toggle LEDs.
  * @param  None
  * @retval None
  */
void Toggle_Leds(void)
{
  /* Toggle LED4 */
  BSP_LED_Toggle(LED4);
  HAL_Delay(100);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  while (1)
  {
    Toggle_Leds();
  }
}

#ifdef  USE_FULL_ASSERT

/**
* @brief  Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param  file: pointer to the source file name
* @param  line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
