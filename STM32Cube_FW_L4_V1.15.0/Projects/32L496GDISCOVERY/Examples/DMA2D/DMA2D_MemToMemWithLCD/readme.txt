/**
  @page DMA2D_MemToMemWithLCD DMA2D Memory to Memory with LCD example
  
  @verbatim
  ******************************************************************************
  * @file    DMA2D/DMA2D_MemToMemWithLCD/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the DMA2D Memory to Memory with LCD example.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
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

  How to configure DMA2D peripheral in Memory-to-memory transfer mode and display
  the result on the LCD.
  The source buffer in format RGB565 and size 240x160 located in Flash is directly
  copied in Memory to Memory mode by the DMA2D to the LCD. 


  At the beginning of the main program the HAL_Init() function is called to reset 
  all the peripherals, initialize the Flash interface and the systick.
  Then the SystemClock_Config() function is used to configure the system
  clock (SYSCLK) to run at 80 MHz.
 
  In this basic example the goal is to explain the different fields of the DMA2D 
  structure in the case of Memory_to_Memory transfer mode.

       
STM32L496G-Discovery board's LEDs can be used to monitor the transfer status:
 - LED1 is ON when there is an initialization or a DMA2D transfer error.
 - LED2 is ON when the DMA2D transfer is complete.
 
@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents

    - DMA2D/DMA2D_MemToMemWithLCD/Inc/main.h                      Main configuration file
    - DMA2D/DMA2D_MemToMemWithLCD/Inc/stm32l4xx_it.h        Interrupt handlers header file
    - DMA2D/DMA2D_MemToMemWithLCD/Inc/stm32l4xx_hal_conf.h  HAL configuration file
    - DMA2D/DMA2D_MemToMemWithLCD/Inc/ARGB4444_150x150.h          Texture in Flash to be transferred by DMA2D in SRAM
    - DMA2D/DMA2D_MemToMemWithLCD/Src/main.c                      Main program  
    - DMA2D/DMA2D_MemToMemWithLCD/Src/stm32l4xx_it.c        Interrupt handlers
    - DMA2D/DMA2D_MemToMemWithLCD/Src/stm32l4xx_hal_msp.c   HAL MSP module    
    - DMA2D/DMA2D_MemToMemWithLCD/Src/system_stm32l4xx.c    STM32L4xx system clock configuration file

@par Hardware and Software environment  

  - This example runs on STM32L496xx devices.
  
  - This example has been tested with STMicroelectronics STM32L496G-Discovery 
    evaluation board and can be easily tailored to any other supported device 
    and development board. 


@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 
  
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
                                   