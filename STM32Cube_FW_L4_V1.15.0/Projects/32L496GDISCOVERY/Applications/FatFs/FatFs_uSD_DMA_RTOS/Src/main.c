/**
  ******************************************************************************
  * @file    FatFs/FatFs_uSD_DMA_RTOS/Src/main.c
  * @author  MCD Application Team
  * @brief   Main program body
  *          This sample code shows how to use FatFs with uSD card drive in RTOS
  *          mode.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
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
#define FATFS_MKFS_ALLOWED 1
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
FATFS SDFatFs;  /* File system object for SD card logical drive */
FIL MyFile;     /* File object */
char SDPath[4]; /* SD card logical drive path */

typedef enum {
  CARD_CONNECTED,
  CARD_DISCONNECTED,
}SD_ConnectionStateTypeDef;

osMessageQId ConnectionEvent;
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void FS_AppThread(void const *argument);
static void FS_FileOperations(void);
static void SD_Initialize(void);

static uint8_t isInitialized = 0;
#if FATFS_MKFS_ALLOWED
static uint8_t isFsCreated = 0;
#endif
uint8_t workBuffer[2 * _MAX_SS];


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

  /* Configure the system clock to 400 MHz */
  SystemClock_Config();

  BSP_IO_Init();

  /* Configure LED2 and LED1 */
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED1);

  /*-1- Link the micro SD disk I/O driver And Create RTOS environment */
  if(FATFS_LinkDriver(&SD_Driver, SDPath) == 0)
  {
    SD_Initialize();
    osThreadDef(uSDThread, FS_AppThread, osPriorityNormal, 0, 8 * configMINIMAL_STACK_SIZE);
    osThreadCreate(osThread(uSDThread), NULL);

    /* Create Storage Message Queue */
    osMessageQDef(osqueue, 10, uint16_t);
    ConnectionEvent = osMessageCreate (osMessageQ(osqueue), NULL);

    if(BSP_SD_IsDetected())
    {
      osMessagePut ( ConnectionEvent, CARD_CONNECTED, osWaitForever);
    }
  }
  /*-2- Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  for( ;; );
}

/**
  * @brief  Start task
  * @param  pvParameters not used
  * @retval None
  */
static void FS_AppThread(void const *argument)
{
  osEvent event;

  /* Infinite Loop */
  for( ;; )
  {
    event = osMessageGet( ConnectionEvent, osWaitForever );

    if( event.status == osEventMessage )
    {
      switch(event.value.v)
      {
      case CARD_CONNECTED:
        BSP_LED_Off(LED1);
        SD_Initialize();
        FS_FileOperations();
        break;

      case CARD_DISCONNECTED:
        BSP_LED_Off(LED2);
        BSP_LED_On(LED1);

        if(isInitialized == 1)
        {
          isInitialized = 0;
          f_mount(NULL, (TCHAR const*)"", 0);
        }
        break;
      }
    }
  }
}

/**
  * @brief  Main routine for Mass Storage Class
  * @param  None
  * @retval None
  */
static void FS_FileOperations(void)
{
  FRESULT res;                                          /* FatFs function common result code */
  uint32_t byteswritten, bytesread;                     /* File write/read counts */
  uint8_t wtext[] = "stm32l496g_discovery: This is STM32 working with FatFs uSD + DMA + FreeRTOS"; /* File write buffer */
  uint8_t rtext[100];                                   /* File read buffer */

  /* Register the file system object to the FatFs module */
  if(f_mount(&SDFatFs, (TCHAR const*)SDPath, 0) == FR_OK)
  {
#if FATFS_MKFS_ALLOWED
    /* check whether the FS has been already created */
    if (isFsCreated == 0)
    {
      if(f_mkfs(SDPath, FM_ANY, 0, workBuffer, sizeof(workBuffer)) != FR_OK)
      {
        BSP_LED_On(LED1);
        return;
      }
      isFsCreated = 1;
    }
#endif

    /* Create and Open a new text file object with write access */
    if(f_open(&MyFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE) == FR_OK)
    {
      /* Write data to the text file */
      res = f_write(&MyFile, wtext, sizeof(wtext), (void *)&byteswritten);

      if((byteswritten > 0) && (res == FR_OK))
      {
        /* Close the open text file */
        f_close(&MyFile);

        /* Open the text file object with read access */
        if(f_open(&MyFile, "STM32.TXT", FA_READ) == FR_OK)
        {
          /* Read data from the text file */
          res = f_read(&MyFile, rtext, sizeof(rtext), (void *)&bytesread);

          if((bytesread > 0) && (res == FR_OK))
          {
            /* Close the open text file */
            f_close(&MyFile);

            /* Compare read data with the expected data */
            if((bytesread == byteswritten))
            {
              /* Success of the demo: no error occurrence */
              BSP_LED_On(LED2);
              return;
            }
          }
        }
      }
    }
  }
  /* Error */
  BSP_LED_On(LED1);
}

/**
  * @brief  EXTI line detection callbacks.
  * @param  GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  uint32_t statusGpio = BSP_IO_ITGetStatus(SD_DETECT_PIN);
  if(MFX_INT_PIN == GPIO_Pin)
  {
    if(BSP_SD_IsDetected())
    {
      osMessagePut ( ConnectionEvent, CARD_CONNECTED, osWaitForever);
    }
    else
    {
      osMessagePut ( ConnectionEvent, CARD_DISCONNECTED, osWaitForever);
    }
  }

  if (statusGpio & SD_DETECT_PIN)
  {
    BSP_IO_ITClear(statusGpio);
  }

}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follows :
  *            System Clock source            = PLL (MSI)
  *            SYSCLK(Hz)                     = 80000000
  *            HCLK(Hz)                       = 80000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            MSI Frequency(Hz)              = 4000000
  *            PLL_M                          = 1
  *            PLL_N                          = 40
  *            PLL_R                          = 2
  *            PLL_P                          = 7
  *            PLL_Q                          = 4
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};

  /* MSI is enabled after System reset, activate PLL with MSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLP = 7;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    /* Initialization Error */
    while(1);
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    /* Initialization Error */
    while(1);
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
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */


static void SD_Initialize(void)
{
  if (isInitialized == 0)
  {
    BSP_SD_Init();
    BSP_SD_ITConfig();

    if(BSP_SD_IsDetected())
    {
      isInitialized = 1;
    }
  }
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
