/**
  @page QSPI_PreInitConfig QSPI pre-init configuration example
  
  @verbatim
  ******************************************************************************
  * @file    QSPI/QSPI_PreInitConfig/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the code execution from QSPI memory example with 
  *            initialization of the QSPI before main() call.
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

How to configure the QSPI Peripheral in order to have access to external memory just after reset.

This example describes how to execute a part of the code from a QSPI memory. To do this, 
a section is created where the function is stored.

The QSPI is configured in memory-mapped mode before to call main() function and QSPI memory 
is then available after the reset. 

The configuration of the QSPI is done in the file system_stm32l4xx.c file in the 
function SystemInit_ExtMemCtl(). It is called by the function SystemInit(), which
is the first function called by the Reset_Handler.

The code in executed in a forever loop. It is the same code as GPIO_IOToggle example 
with some code mapped in QSPI mode and other in Flash, to show the jump from one 
memory to the other.

LED1, LED2, LED3 and LED4 toggle in this forever loop.

In this example, HCLK is configured at 80 MHz.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents 

  - QSPI/QSPI_PreInitConfig/Inc/stm32l4xx_hal_conf.h HAL configuration file
  - QSPI/QSPI_PreInitConfig/Inc/stm32l4xx_it.h       Interrupt handlers header file
  - QSPI/QSPI_PreInitConfig/Inc/main.h               Header for main.c module  
  - QSPI/QSPI_PreInitConfig/Src/stm32l4xx_it.c       Interrupt handlers
  - QSPI/QSPI_PreInitConfig/Src/main.c               Main program
  - QSPI/QSPI_PreInitConfig/Src/system_stm32l4xx.c   STM32L4xx system source file
  - QSPI/QSPI_PreInitConfig/Src/stm32l4xx_hal_msp.c  HAL MSP file    


@par Hardware and Software environment

  - This example runs on STM32L476xx devices.
    
  - This example has been tested with STM32L476G-EVAL board and can be
    easily tailored to any other supported device and development board.

  - STM32L476G-EVAL Set-up :
    - Make sure that LCD Glass in IO position.
    - Make sure that board is configured for QuadSPI memory interface as 
      described in UM1855 "Evaluation board with STM32L476ZGT6 MCU" :
        - Solder bridges SB8, SB9, SB12, SB14, SB18 and SB21 closed
        - Solder bridges SB13, SB15, SB19 and SB20 opened
        - Resistor R62 removed

  - A specific region for the QSPI memory has been added in the scatter file 
   (STM32L476xx_flash.icf for IAR toolchain, STM32L476G_EVAL.sct for Keil toolchain)
   in order to map functions in this memory

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files 
 - Load your image into target memory with ST-Link Utility (v3.9.0 or later) and 
   select external loader N25Q256A_STM32L476G-EVAL
   -> !!! Be careful, don't try to use the toolchain to load the image, it is not able to load some code in QSPI memory !!!
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
