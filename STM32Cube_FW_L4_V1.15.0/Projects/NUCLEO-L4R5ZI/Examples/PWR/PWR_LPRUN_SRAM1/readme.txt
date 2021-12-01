/**
  @page PWR_LPRUN_SRAM1 Low Power Run Mode Example
  
  @verbatim
  ******************************************************************************
  * @file    PWR/PWR_LPRUN_SRAM1/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Low Power Run Mode example executed from SRAM1
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
 
How to enter and exit the Low-power run mode.

In the associated software, the system clock is set to 32 MHz.
The SysTick is programmed to generate an interrupt each 1 ms.

5 seconds after start-up, the system automatically enters LP RUN mode
and LED1 stops toggling.
The User push-button can be pressed at any time to exit from Low Power Run. 
to exit LP Run Mode
The software then comes back in RUN mode for 5 sec. before automatically 
entering LP RUN mode again. 

Two leds LED1 and LED2 are used to monitor the system state as following:
 - LED2 ON: configuration failed (system will go to an infinite loop)
 - LED1 toggling: system in RUN mode
 - LED1 off : system in LP RUN mode

These steps are repeated in an infinite loop.

@note To measure the current consumption in LP SLEEP mode, please refer to 
      @subpage PWR_CurrentConsumption example.

    - Low Power Run Mode from SRAM
    ================================
          - Regulator in LP mode
          - System Running at MSI (~100 KHz) 
          - MSI Range 0
          - Voltage Range 2
          - Code running from Internal SRAM (SRAM1)
          - FLASH powered down
          - All peripherals OFF
          - Exit from LP Run mode using User push-button PC.13


@note By default, the software resorts to __HAL_FLASH_PREFETCH_BUFFER_DISABLE() macro
      to disable the Adaptive Real Time (ART). The user needs to uncomment this line in
      main() function if power consumption figures with ART ON in LP RUN mode must
      be measured.

@note This example can not be used in DEBUG mode due to the fact 
      that the Cortex-M4 core is no longer clocked during low power mode 
      so debugging features are disabled.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      

@par Directory contents 

  - PWR/PWR_LPRUN_SRAM1/Inc/stm32l4xx_conf.h         HAL Configuration file
  - PWR/PWR_LPRUN_SRAM1/Inc/stm32l4xx_it.h           Header for stm32l4xx_it.c
  - PWR/PWR_LPRUN_SRAM1/Inc/main.h                   Header file for main.c
  - PWR/PWR_LPRUN_SRAM1/Src/system_stm32l4xx.c       STM32L4xx system clock configuration file
  - PWR/PWR_LPRUN_SRAM1/Src/stm32l4xx_it.c           Interrupt handlers
  - PWR/PWR_LPRUN_SRAM1/Src/main.c                   Main program

@par Hardware and Software environment

  - This example runs on STM32L4xx devices
    
  - This example has been tested with STMicroelectronics NUCLEO-L4R5ZI (144 pins)
    board and can be easily tailored to any other supported device 
    and development board.

  - NUCLEO-L4R5ZI (144 pins) set-up:
    - Use LED1 and LED2 connected respectively to PC.07 and PB.07 pins
    - Use the User push-button connected to pin PC.13.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files
 - In using ST-Link Utility tool, load your image into target memory SRAM1 area 
   at start address 0x20000000. Make sure option bytes are correctly set to 
   select SRAM1 as boot area (refer to Reference Manual if needed).
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
