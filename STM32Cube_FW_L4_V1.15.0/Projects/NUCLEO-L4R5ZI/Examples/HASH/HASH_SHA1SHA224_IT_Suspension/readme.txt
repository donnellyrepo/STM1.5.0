/**
  @page HASH_SHA1SHA224_IT_Suspension  SHA digest calculation suspension example
  
  @verbatim
  ******************************************************************************
  * @file    HASH/HASH_SHA1SHA224_IT_Suspension/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the digest calculation suspension using SHA1 and SHA224 example.
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

How to suspend the HASH peripheral when data are fed in interrupt mode.

The example first computes the HASH digest of a low priority block using SHA-1 
algorithm in entering input data in interrupt mode.

The processing is suspended in order to process a higher priority block to
compute its SHA-224 digest. For the higher priority block, data are entered in
interrupt mode as well.
Suspension request is triggered by an interrupts counter which is incremented each time
a 512-bit long block has been fed to the IP. Once the counter has reached an arbitrary
value, the low priority block processing is suspended.

It is shown how to save then how to restore later on the low priority block
context to resume its processing.
For both the low and high priority blocks, the computed digests are compared with
the expected ones.


LED1 is turned on when correct digest values are calculated.
In case of digest computation or initialization issue, LED3 is turned on. 



@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - HASH/HASH_SHA1SHA224_IT_Suspension/Inc/stm32l4xx_hal_conf.h    HAL configuration file
  - HASH/HASH_SHA1SHA224_IT_Suspension/Inc/stm32l4xx_it.h          Interrupt handlers header file
  - HASH/HASH_SHA1SHA224_IT_Suspension/Inc/main.h                  Header for main.c module  
  - HASH/HASH_SHA1SHA224_IT_Suspension/Src/stm32l4xx_it.c          Interrupt handlers
  - HASH/HASH_SHA1SHA224_IT_Suspension/Src/main.c                  Main program
  - HASH/HASH_SHA1SHA224_IT_Suspension/Src/stm32l4xx_hal_msp.c     HAL MSP module
  - HASH/HASH_SHA1SHA224_IT_Suspension/Src/system_stm32l4xx.c      STM32L4xx system source file


@par Hardware and Software environment

  - This example runs on STM32L4S5xx devices.

  - This example has been tested with a STM32L4S5xx mounted on a 
    Nucleo (144 pins) board and can be easily tailored to any other supported 
    device and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 