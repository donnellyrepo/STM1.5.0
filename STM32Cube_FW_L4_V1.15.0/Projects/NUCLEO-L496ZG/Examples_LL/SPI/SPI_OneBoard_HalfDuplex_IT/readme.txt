/**
  @page SPI_OneBoard_HalfDuplex_IT SPI example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/SPI/SPI_OneBoard_HalfDuplex_IT/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the SPI_OneBoard_HalfDuplex_IT example.
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

Configuration of GPIO and SPI peripherals to transmit bytes 
from an SPI Master device to an SPI Slave device in Interrupt mode. This example
is based on the STM32L4xx SPI LL API. The peripheral initialization uses 
LL unitary service functions for optimization purposes (performance and size).

This example works with only one NUCLEO-L496ZG (144 pins).

SPI1 Peripheral is configured in Master mode Half-Duplex Tx.
SPI3 Peripheral is configured in Slave mode Half-Duplex Rx.
GPIO associated to User push-button is linked with EXTI. 

Example execution:

LED1 is blinking Fast (200ms) and wait User push-button action.
Press User push-button on BOARD start a Half-Duplex communication through IT.
On MASTER side (SPI1), Clock will be generated on SCK line, Transmission done on MOSI Line.
On SLAVE side (SPI3) reception is done through the MISO Line.

LED1 is On if data is well received.

In case of errors, LED1 is blinking Slowly (1s).

@par Directory contents 

  - SPI/SPI_OneBoard_HalfDuplex_IT/Inc/stm32l4xx_it.h          Interrupt handlers header file
  - SPI/SPI_OneBoard_HalfDuplex_IT/Inc/main.h                  Header for main.c module
  - SPI/SPI_OneBoard_HalfDuplex_IT/Inc/stm32_assert.h          Template file to include assert_failed function
  - SPI/SPI_OneBoard_HalfDuplex_IT/Src/stm32l4xx_it.c          Interrupt handlers
  - SPI/SPI_OneBoard_HalfDuplex_IT/Src/main.c                  Main program
  - SPI/SPI_OneBoard_HalfDuplex_IT/Src/system_stm32l4xx.c      STM32L4xx system source file

@par Hardware and Software environment

  - This example runs on STM32L496ZG devices.

  - This example has been tested with NUCLEO-L496ZG (144 pins) board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-L496ZG (144 pins) Set-up
    - Connect Master SCK  PB3 to Slave SCK  PC10
    - Connect Master MOSI PB5 to Slave MISO PC11

Relation with Board connector:
  PB3  is connected to pin 31 of CN12 connector
  PB5  is connected to pin 29 of CN12 connector
  PC10 is connected to pin 1 of CN11 connector
  PC11 is connected to pin 2 of CN11 connector

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
