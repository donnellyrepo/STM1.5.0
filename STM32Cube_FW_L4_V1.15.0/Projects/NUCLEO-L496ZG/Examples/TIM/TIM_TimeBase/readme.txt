/**
  @page TIM_TimeBase Timebase example
  
  @verbatim
  ******************************************************************************
  * @file    TIM/TIM_TimeBase/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM Timebase example
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

Configuration of the TIM peripheral to generate a timebase of 
one second with the corresponding interrupt request.

    In this example TIM3 input clock (TIM3CLK)  is set to APB1 clock (PCLK1),
    since APB1 prescaler is equal to 1.
      TIM3CLK = PCLK1
      PCLK1 = HCLK
      => TIM3CLK = HCLK = SystemCoreClock
    To get TIM3 counter clock at 10 KHz, the Prescaler is computed as following:
    Prescaler = (TIM3CLK / TIM3 counter clock) - 1
    Prescaler = (SystemCoreClock /10 KHz) - 1

SystemCoreClock is set to 80 MHz for STM32L4xx Devices.

The TIM3 ARR register value is equal to 10000 - 1, 
Update rate = TIM3 counter clock / (Period + 1) = 1 Hz,
So the TIM3 generates an interrupt each 1 s

When the counter value reaches the auto-reload register value, the TIM update 
interrupt is generated and, in the handler routine, pin PB.07 (connected to LED2 on board NUCLEO-L496ZG (144 pins))
is toggled at the following frequency: 0.5Hz.


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - TIM/TIM_TimeBase/Inc/stm32l4xx_hal_conf.h    HAL configuration file
  - TIM/TIM_TimeBase/Inc/stm32l4xx_it.h          Interrupt handlers header file
  - TIM/TIM_TimeBase/Inc/main.h                  Header for main.c module  
  - TIM/TIM_TimeBase/Src/stm32l4xx_it.c          Interrupt handlers
  - TIM/TIM_TimeBase/Src/main.c                  Main program
  - TIM/TIM_TimeBase/Src/stm32l4xx_hal_msp.c     HAL MSP file
  - TIM/TIM_TimeBase/Src/system_stm32l4xx.c      STM32L4xx system source file


@par Hardware and Software environment

  - This example runs on STM32L496xx devices.
  - In this example, the clock is set to 80 MHz.
    
  - This example has been tested with STMicroelectronics NUCLEO-L496ZG (144 pins)
    board and can be easily tailored to any other supported device
    and development board.      

  - NUCLEO-L496ZG (144 pins) Set-up
    - Use LED2 connected to PB.07 pin (pin 21 in CN11 connector) and connect it on an oscilloscope 
      to show the Time Base signal.  


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
