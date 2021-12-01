/**
  ******************************************************************************
  * @file    OSPI/OSPI_NOR_ReadWrite_DMA/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module
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
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "stm32l4r9i_eval.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Definition for OSPI Pins */
#define OSPI_CS_PIN                 GPIO_PIN_2
#define OSPI_CS_GPIO_PORT           GPIOA
#define OSPI_CLK_PIN                GPIO_PIN_3
#define OSPI_CLK_GPIO_PORT          GPIOA
#define OSPI_D0_PIN                 GPIO_PIN_1
#define OSPI_D0_GPIO_PORT           GPIOB
#define OSPI_D1_PIN                 GPIO_PIN_0
#define OSPI_D1_GPIO_PORT           GPIOB
#define OSPI_D2_PIN                 GPIO_PIN_7
#define OSPI_D2_GPIO_PORT           GPIOA
#define OSPI_D3_PIN                 GPIO_PIN_6
#define OSPI_D3_GPIO_PORT           GPIOA
#define OSPI_D4_PIN                 GPIO_PIN_2
#define OSPI_D4_GPIO_PORT           GPIOH
#define OSPI_D5_PIN                 GPIO_PIN_11
#define OSPI_D5_GPIO_PORT           GPIOG
#define OSPI_D6_PIN                 GPIO_PIN_3
#define OSPI_D6_GPIO_PORT           GPIOC
#define OSPI_D7_PIN                 GPIO_PIN_4
#define OSPI_D7_GPIO_PORT           GPIOC
#define OSPI_DQS_PIN                GPIO_PIN_2
#define OSPI_DQS_GPIO_PORT          GPIOB

/* Definition for OSPI DMA */
#define OSPI_DMA_CHANNEL            DMA1_Channel1
#define OSPI_DMA_REQUEST            DMA_REQUEST_OCTOSPI2
#define OSPI_DMA_IRQ                DMA1_Channel1_IRQn
#define OSPI_DMA_IRQ_HANDLER        DMA1_Channel1_IRQHandler

/* MX25LM512ABA1G12 Macronix memory */
/* Size of the flash */
#define OSPI_FLASH_SIZE             26
#define OSPI_PAGE_SIZE              256

/* Flash commands */
#define OCTAL_IO_READ_CMD           0xEC13
#define OCTAL_PAGE_PROG_CMD         0x12ED
#define OCTAL_READ_STATUS_REG_CMD   0x05FA
#define OCTAL_SECTOR_ERASE_CMD      0x21DE
#define OCTAL_WRITE_ENABLE_CMD      0x06F9
#define READ_STATUS_REG_CMD         0x05
#define WRITE_CFG_REG_2_CMD         0x72
#define WRITE_ENABLE_CMD            0x06

/* Dummy clocks cycles */
#define DUMMY_CLOCK_CYCLES_READ     6
#define DUMMY_CLOCK_CYCLES_READ_REG 4

/* Auto-polling values */
#define WRITE_ENABLE_MATCH_VALUE    0x02
#define WRITE_ENABLE_MASK_VALUE     0x02

#define MEMORY_READY_MATCH_VALUE    0x00
#define MEMORY_READY_MASK_VALUE     0x01

#define AUTO_POLLING_INTERVAL       0x10

/* Memory registers address */
#define CONFIG_REG2_ADDR1           0x0000000
#define CR2_STR_OPI_ENABLE          0x01

#define CONFIG_REG2_ADDR3           0x00000300
#define CR2_DUMMY_CYCLES_66MHZ      0x07

/* Memory delay */
#define MEMORY_REG_WRITE_DELAY      40

/* End address of the OSPI memory */
#define OSPI_END_ADDR               (1 << OSPI_FLASH_SIZE)

/* Size of buffers */
#define BUFFERSIZE                  (COUNTOF(aTxBuffer) - 1)

/* Exported macro ------------------------------------------------------------*/
#define COUNTOF(__BUFFER__)         (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))

/* Definition for OSPI clock resources */
#define OSPI_CLK_ENABLE()           __HAL_RCC_OSPI2_CLK_ENABLE()
#define OSPI_CLK_DISABLE()          __HAL_RCC_OSPI2_CLK_DISABLE()
#define OSPIM_CLK_ENABLE()          __HAL_RCC_OSPIM_CLK_ENABLE()
#define OSPIM_CLK_DISABLE()         __HAL_RCC_OSPIM_CLK_DISABLE()
#define OSPI_CS_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()
#define OSPI_CLK_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define OSPI_D0_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOB_CLK_ENABLE()
#define OSPI_D1_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOB_CLK_ENABLE()
#define OSPI_D2_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()
#define OSPI_D3_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()
#define OSPI_D4_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOH_CLK_ENABLE()
#define OSPI_D5_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOG_CLK_ENABLE()
#define OSPI_D6_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOC_CLK_ENABLE()
#define OSPI_D7_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOC_CLK_ENABLE()
#define OSPI_DQS_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()
#define OSPI_DMA_CLK_ENABLE()       __HAL_RCC_DMA1_CLK_ENABLE()
#define OSPI_DMAMUX_CLK_ENABLE()    __HAL_RCC_DMAMUX1_CLK_ENABLE()

#define OSPI_FORCE_RESET()          __HAL_RCC_OSPI2_FORCE_RESET()
#define OSPI_RELEASE_RESET()        __HAL_RCC_OSPI2_RELEASE_RESET()

/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
