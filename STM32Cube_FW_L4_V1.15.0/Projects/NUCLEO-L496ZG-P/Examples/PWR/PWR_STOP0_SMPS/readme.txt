/**
  @page PWR_STOP0_SMPS Power Stop 0 SMPS Mode Example
  
  @verbatim
  ******************************************************************************
  * @file    PWR/PWR_STOP0_SMPS/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Power STOP0 SMPS Mode example.
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
 
How to enter Stop 0 mode with or without SMPS enabled and to wake up 
from this mode using an interrupt.

In the associated software, the system clock is set to 80 MHz, an EXTI line
is connected to the user button thru PC.13 and configured to generate an 
interrupt on falling edge upon key press.
The SysTick is programmed to generate an interrupt each 1 ms and in the SysTick 
interrupt handler, LED1 is toggled in order to indicate whether the MCU is in STOP 0 mode 
or RUN mode.

After start-up, the system automatically run at 80 MHz without SMPS.
After some transitions the systeme senters INTO RUN SMPS R2 at 80 MHz (A).

The User push-button can be pressed to go to step 1 then step 2. 
When RUN SMPS R2 at 80 MHz (A) is reached (LED1 toggling).
1) 1st press switches towards SMPS STOP0 mode.
2) New press switches back to SMPS 80 R2 mode for 10 seconds (LED1 toggling).

The 2 steps can be repeated in an infinite loop.

Two leds LED1 and LED2 are used to monitor the system state as following:
 - LED2 ON: configuration failed (system will go to an infinite loop)
 - LED1 toggling: system in RUN mode
 - LED1 off : system in STOP 0 mode

@note The SMPS is kept on stop0 so that run mode can restart quickly.

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

  - PWR/PWR_STOP0_SMPS/Inc/stm32l4xx_conf.h         HAL Configuration file
  - PWR/PWR_STOP0_SMPS/Inc/stm32l4xx_it.h           Header for stm32l4xx_it.c
  - PWR/PWR_STOP0_SMPS/Inc/main.h                   Header file for main.c
  - PWR/PWR_STOP0_SMPS/Src/system_stm32l4xx.c       STM32L4xx system clock configuration file
  - PWR/PWR_STOP0_SMPS/Src/stm32l4xx_it.c           Interrupt handlers
  - PWR/PWR_STOP0_SMPS/Src/main.c                   Main program
  - PWR/PWR_STOP0_SMPS/Src/stm32l4xx_hal_msp.c      HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L496xx devices
    
  - This example has been tested  This example has been tested with 
    STMicroelectronics NUCLEO-L496ZG-P MB1312/S (144 pins).

  - NUCLEO-L496ZG-P (144 pins) set-up:
    - Use LED1 and LED2 connected respectively to PC.07 and PB.07 pins
    - User push-button connected to pin PB.0 (External line 13)

    
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Disconnect toolchain 
 - Unplug the USB cable
 - Connect Amperemeter between the 2 pins of JP5 (IDD).
 - Plug the USB (starts the example)

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
