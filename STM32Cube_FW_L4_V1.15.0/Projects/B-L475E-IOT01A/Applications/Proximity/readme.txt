/**
  @page Proximity  Description of the Proximity application
  
  @verbatim
  ******************************************************************************
  * @file    Applications/Proximity/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the Proximity application.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license SLA0044,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        http://www.st.com/SLA0044
  *
  ******************************************************************************
  @endverbatim

@par Application Description

This application shows how to use the VL53L0X sensor mounted on the B-L475E-IOT01A 
board to provide proximity information.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 80 MHz.

This application uses the hyperterminal to display proximity information and to 
get orders from user:

- "N" or "n" to display new proximity
- "Q" or "q" to quit the test


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - BSP/Src/main.c                 Main program
  - BSP/Src/system_stm32l4xx.c     STM32L4xx system clock configuration file
  - BSP/Src/stm32l4xx_it.c         Interrupt handlers 
  - BSP/Src/vl53l0x                Drivers of the vl53l0x sensor
  - BSP/Inc/main.h                 Main program header file  
  - BSP/Inc/stm32l4xx_hal_conf.h   HAL Configuration file
  - BSP/Inc/stm32l4xx_it.h         Interrupt handlers header file

        
@par Hardware and Software environment  

  - This example runs on STM32L475xx devices.
    
  - This example has been tested with STMicroelectronics B-L475E-IOT01A boards.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open an hyperterminal with following setting:
    + COM: STLink Virtual COM Port(COMxxx). This can be found by opening computer
           Device Manager, Port(COM & LPT) once the board is connected to the PC.
    + BaudRate = 115200 baud  
    + Word Length = 8 Bits (7 data bit + 1 parity bit)
    + One Stop Bit
    + Parity none
    + Hardware flow control disabled (RTS and CTS signals)
    + Reception and transmission are enabled in the time
    
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
