/**
  @page COMP_Interrupt COMP Interrupt example
  
  @verbatim
  ******************************************************************************
  * @file    COMP/COMP_Interrupt/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the COMP Interrupt example.
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

How to use a comparator peripheral to compare a voltage level applied on a GPIO
pin to the the internal voltage reference (VREFINT), in interrupt mode.
When the comparator input crosses (either rising or falling edges) the internal 
reference voltage VREFINT (1.22V), the comparator generates an interrupt
and exit from Stop 2 mode.

The System enters Stop 2 mode 5 seconds after the comparator is started and 
after any system wake-up triggered by the comparator interrupt.

In this example, the comparator input is connected on the pin PC.05 the user 
shall apply a voltage on and each time the comparator input crosses VREFINT, LED1 toggles.
If LED1 is toggling continuously without any voltage update, it indicates that the system 
generated an error.

@note Care must be taken when using HAL_Delay(), this function provides 
      accurate delay (in milliseconds) based on variable incremented in SysTick ISR. 
      This implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower) than the 
      peripheral interrupt. Otherwise the caller ISR process will be blocked. 
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set 
      to 1 millisecond to have correct HAL operation.

@par Directory contents 

  - COMP/COMP_Interrupt/Inc/stm32l4xx_hal_conf.h    HAL configuration file
  - COMP/COMP_Interrupt/Inc/stm32l4xx_it.h          Interrupt handlers header file
  - COMP/COMP_Interrupt/Inc/main.h                  Header for main.c module
  - COMP/COMP_Interrupt/Src/stm32l4xx_it.c          Interrupt handlers
  - COMP/COMP_Interrupt/Src/main.c                  Main program
  - COMP/COMP_Interrupt/Src/stm32l4xx_hal_msp.c     HAL MSP file
  - COMP/COMP_Interrupt/Src/system_stm32l4xx.c      STM32L4xx system source file


@par Hardware and Software environment 

  - This example runs on STM32L476xx devices.

  - This example has been tested with STM32L476G-EVAL board and can be
    easily tailored to any other supported device and development board.

  - STM32L476G-EVAL Set-up

    - Remove LCD glass to access PC.05 pin.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */