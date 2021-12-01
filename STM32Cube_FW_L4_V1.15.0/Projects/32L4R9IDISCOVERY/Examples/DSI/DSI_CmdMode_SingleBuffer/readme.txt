/**
  @page DSI_CmdMode_SingleBuffer : DSI examples in DSI mode Command

  @verbatim
  ******************************************************************************
  * @file    DSI/DSI_CmdMode_SingleBuffer/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the LCD DSI in mode Command example.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description

How to use the embedded LCD DSI controller (using the LTDC and DSI Host IPs) to
drive the round LCD mounted on-board.

The goal of this example is to display a 390x390 RGB image on LCD in Command mode 
using a single buffer for draw.

In this example a RGB888 picture (390x390) is displayed on LCD in DSI Mode Command 
(LED2 is switched on).

Ten seconds after the image is displayed, a dimming is initiated with a final LCD display off
after ten more seconds.

In case of error, LED1 will be switched on.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents

  - DSI/DSI_CmdMode_SingleBuffer/Inc/stm32l4xx_hal_conf.h      HAL configuration file
  - DSI/DSI_CmdMode_SingleBuffer/Inc/stm32l4xx_it.h            Interrupt handlers header file
  - DSI/DSI_CmdMode_SingleBuffer/Inc/main.h                    Header for main.c module
  - DSI/DSI_CmdMode_SingleBuffer/Inc/image_390x390_rgb888.h    Image 390x390 in RGB888 to display on LCD
  - DSI/DSI_CmdMode_SingleBuffer/Src/stm32l4xx_it.c            Interrupt handlers
  - DSI/DSI_CmdMode_SingleBuffer/Src/main.c                    Main program
  - DSI/DSI_CmdMode_SingleBuffer/Src/stm32l4xx_hal_msp.c       HAL MSP file
  - DSI/DSI_CmdMode_SingleBuffer/Src/system_stm32l4xx.c        STM32L4xx system source file

@par Hardware and Software environment

  - This example runs on STM32L4R9xx devices.

  - This example has been tested with STMicroelectronics STM32L4R9I-Discovery
    board and can be easily tailored to any other supported device
    and development board.

  - STM32L4R9I-Discovery Set-up
    - Make sure that round DSI LCD MB1314 is plugged on CN4

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
