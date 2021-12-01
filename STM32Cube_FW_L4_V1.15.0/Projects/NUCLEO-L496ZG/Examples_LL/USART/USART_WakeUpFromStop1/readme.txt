/**
  @page USART_WakeUpFromStop1 USART example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/USART/USART_WakeUpFromStop1/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the USART_WakeUpFromStop1 USART example.
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

Configuration of GPIO and STM32L4xx USART peripherals 
to receive characters on USART_RX pin and wake up the MCU from low-power mode. This example is based on 
the STM32L4xx USART LL API. The peripheral initialization 
uses LL unitary service functions for optimization purposes (performance and size).

USART Peripheral is configured in asynchronous mode (9600 bauds, 8 data bit, 1 start bit, 1 stop bit, no parity).
No HW flow control is used.
USART Clock is based on HSI.

Example execution:
After startup from reset and system configuration, LED1 is blinking quickly during 3 sec,
then MCU  enters Stop mode 1 (LED1 off).
On first  character reception by the USART from PC Com port (ex: using HyperTerminal)
after Stop Mode period, MCU wakes up from Stop Mode.
Received character value is checked :
- On a specific value ('S' or 's'), LED1 is turned On and program ends.
- If different from 'S' or 's', program performs a quick LED1 blinks during 3 sec and 
  enters again Stop mode 1, waiting for next character to wake up.

In case of errors, LED1 is slowly blinking (1 sec period).

@par Directory contents 

  - USART/USART_WakeUpFromStop1/Inc/stm32l4xx_it.h          Interrupt handlers header file
  - USART/USART_WakeUpFromStop1/Inc/main.h                  Header for main.c module
  - USART/USART_WakeUpFromStop1/Inc/stm32_assert.h          Template file to include assert_failed function
  - USART/USART_WakeUpFromStop1/Src/stm32l4xx_it.c          Interrupt handlers
  - USART/USART_WakeUpFromStop1/Src/main.c                  Main program
  - USART/USART_WakeUpFromStop1/Src/system_stm32l4xx.c      STM32L4xx system source file

@par Hardware and Software environment

  - This example runs on STM32L496ZG devices.

  - This example has been tested with NUCLEO-L496ZG (144 pins) board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-L496ZG (144 pins) Set-up
    - Connect STM32 MCU board USART1 TX pin (GPIO PA9 connected to pin 21 of CN12 connector)
      to PC COM port RX signal
    - Connect STM32 MCU board USART1 RX pin (GPIO PA10 connected to pin 33 of CN12 connector)
      to PC COM port TX signal
    - Connect STM32 MCU board GND to PC COM port GND signal

    - Launch serial communication SW on PC (as HyperTerminal or TeraTerm) with proper configuration 
      (9600 bauds, 8 bits data, 1 stop bit, no parity, no HW flow control). 
    
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
