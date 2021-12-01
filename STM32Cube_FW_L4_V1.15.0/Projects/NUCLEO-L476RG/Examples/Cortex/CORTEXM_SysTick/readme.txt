    /**
  @page CORTEXM_SysTick CORTEXM SysTick example

  @verbatim
  ******************************************************************************
  * @file    CORTEXM/CORTEXM_SysTick/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the CortexM SysTick example.
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

How to use the default SysTick configuration with a 1 ms timebase to toggle LEDs.

  A "HAL_Delay" function is implemented based on the SysTick end-of-count event.
  LED2 toggles with a timing defined by the HAL_Delay function.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - CortexM/CORTEXM_SysTick/Inc/stm32l4xx_hal_conf.h    HAL configuration file
  - CortexM/CORTEXM_SysTick/Inc/stm32l4xx_it.h          Interrupt handlers header file
  - CortexM/CORTEXM_SysTick/Inc/main.h                  Header for main.c module  
  - CortexM/CORTEXM_SysTick/Src/stm32l4xx_it.c          Interrupt handlers
  - CortexM/CORTEXM_SysTick/Src/main.c                  Main program
  - CortexM/CORTEXM_SysTick/Src/system_stm32l4xx.c      STM32L4xx system source file

@par Hardware and Software environment 

  - This example runs on STM32L476xx devices.
    
  - This example has been tested with NUCLEO-L476RG Rev C board and can be
    easily tailored to any other supported device and development board.

@par How to use it ? 
In order to make the program work, you must do the following :
- Open your preferred toolchain 
- Rebuild all files and load your image into target memory
- Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
