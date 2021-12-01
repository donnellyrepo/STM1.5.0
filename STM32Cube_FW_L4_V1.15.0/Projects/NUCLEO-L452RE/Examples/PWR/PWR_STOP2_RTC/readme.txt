/**
  @page PWR_STOP2_RTC Power Stop 2 RTC example
  
  @verbatim
  ******************************************************************************
  * @file    PWR/PWR_STOP2_RTC/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWR STOP2 RTC example.
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

How to enter the Stop 2 mode and wake-up from this mode using an external reset 
or RTC wakeup timer.

It allows to measure the current consumption in Stop 2 mode with RTC enabled.

In the associated software, the system clock is set to 80 MHz and the SysTick is 
programmed to generate an interrupt each 1 ms.
The Low Speed Internal (LSI) clock is used as RTC clock source by default.
EXTI_Line20 is internally connected to the RTC Wakeup event.


The system automatically enters Stop 2 mode 5 sec. after start-up. The RTC wake-up 
is configured to generate an interrupt on rising edge about 33 sec. afterwards.
Current consumption in Stop 2 mode with RTC feature enabled can be measured during that time.
More than half a minute is chosen to ensure current convergence to its lowest operating point.

After wake-up from Stop 2 mode, program execution is resumed.

LED2 is used to monitor the system state as follows:
 - LED2 toggling: system in RUN mode
 - LED2 off : system in Stop 2 mode

These steps are repeated in an infinite loop.

@note To measure the current consumption in Stop 2 mode, remove JP6 jumper 
      and connect an amperemeter to JP6 to measure IDD current.     

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

  - PWR/PWR_STOP2_RTC/Inc/stm32l4xx_conf.h         HAL Configuration file
  - PWR/PWR_STOP2_RTC/Inc/stm32l4xx_it.h           Header for stm32l4xx_it.c
  - PWR/PWR_STOP2_RTC/Inc/main.h                   Header file for main.c
  - PWR/PWR_STOP2_RTC/Src/system_stm32l4xx.c       STM32L4xx system clock configuration file
  - PWR/PWR_STOP2_RTC/Src/stm32l4xx_it.c           Interrupt handlers
  - PWR/PWR_STOP2_RTC/Src/main.c                   Main program
  - PWR/PWR_STOP2_RTC/Src/stm32l4xx_hal_msp.c      HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L4xx devices
    
      
  - This example has been tested with STMicroelectronics NUCLEO-L452RE Rev C
    board and can be easily tailored to any other supported device 
    and development board.

  - NUCLEO-L452RE Rev C Set-up
    - LED2 connected to PA.05 pin


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Once the image is loaded, power off the NUCLEO board in unplugging
   the power cable then power on the board again 
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
