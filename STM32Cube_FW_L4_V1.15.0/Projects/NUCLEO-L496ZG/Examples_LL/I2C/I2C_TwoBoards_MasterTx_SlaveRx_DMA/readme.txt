/**
  @page I2C_TwoBoards_MasterTx_SlaveRx_DMA I2C example (DMA Mode)
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/I2C/I2C_TwoBoards_MasterTx_SlaveRx_DMA/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the I2C_TwoBoards_MasterTx_SlaveRx_DMA I2C example (DMA Mode).
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
  
How to transmit data bytes from an I2C master device using DMA mode 
to an I2C slave device using DMA mode. The peripheral is initialized 
with LL unitary service functions to optimize for performance and size.

This example guides you through the different configuration steps by mean of LL API
to configure GPIO, DMA and I2C peripherals using two NUCLEO-L496ZG (144 pins).

Boards: NUCLEO-L496ZG (144 pins) (embeds a STM32L496ZGT6 device)
SCL Pin: PC.0 (CN11, pin 38)
SDA Pin: PC.1 (CN11, pin 36)

   ______BOARD SLAVE_____                       _____BOARD MASTER_____
  |        ______________|                     |______________        |
  |       |I2C3          |                     |          I2C3|       |
  |       |              |                     |              |       |
  |       |          SCL |_____________________| SCL          |       |
  |       |              |                     |              |       |
  |       |              |                     |              |       |
  |       |          SDA |_____________________| SDA          |       |
  |       |______________|                     |______________|       |
  |         __           |                     |             __       |
  |        |__|          |                     |            |__|      |
  |        USER       GND|_____________________|GND         USER      |
  |___STM32L4xx_Nucleo_144___|                     |___STM32L4xx_Nucleo_144___|

The project is splitted in two parts the Master Board and the Slave Board
- Master Board
  I2C3 Peripheral is configured in Master mode with DMA (Clock 400Khz).
  And GPIO associated to User push-button is linked with EXTI. 
- Slave Board
  I2C3 Peripheral is configured in Slave mode with DMA (Clock 400Khz, Own address 7-bit enabled).

The user can choose between Master and Slave through "#define SLAVE_BOARD"
in the "main.h" file:
- Comment "#define SLAVE_BOARD" to select Master board.
- Uncomment "#define SLAVE_BOARD" to select Slave board.

A first program launch, BOARD SLAVE waiting Address Match code through Handle_I2C_Slave() routine.
LED1 blinks quickly on BOARD MASTER to wait for user-button press. 

Example execution:
Press the User push-button on BOARD MASTER to initiate a write request by Master through Handle_I2C_Master() routine.
This action will generate an I2C start condition with the Slave address and a write bit condition.
When address Slave match code is received on I2C3 of BOARD SLAVE, an ADDR event occurs.
Handle_I2C_Slave() routine is then checking Address Match Code and direction Write.
This will allow Slave to enter in receiver mode and then acknowledge Master to send the bytes through DMA.
When acknowledge is received on I2C3 (Master), DMA transfer the data from flash memory buffer to I2C3 TXDR register (Master).
This will allow Master to transmit a byte to the Slave.
Each time a byte is received on I2C3 (Slave), DMA transfer the data from I2C3 RXDR register to RAM memory buffer (Slave).
And so each time the Slave acknowledge the byte received,
DMA transfer the next data from flash memory buffer to I2C3 TXDR register (Master) until Transfer completed.
Master auto-generate a Stop condition when DMA transfer is achieved.

The STOP condition generate a STOP event and initiate the end of reception on Slave side.
Handle_I2C_Slave() and Handle_I2C_Master() routine are then clearing the STOP flag in both side.

LED1 is On :
- Slave side if data are well received.
- Master side if transfer sequence is completed.

In case of errors, LED1 is blinking.

@par Directory contents 

  - I2C/I2C_TwoBoards_MasterTx_SlaveRx_DMA/Inc/stm32l4xx_it.h          Interrupt handlers header file
  - I2C/I2C_TwoBoards_MasterTx_SlaveRx_DMA/Inc/main.h                  Header for main.c module
  - I2C/I2C_TwoBoards_MasterTx_SlaveRx_DMA/Inc/stm32_assert.h          Template file to include assert_failed function
  - I2C/I2C_TwoBoards_MasterTx_SlaveRx_DMA/Src/stm32l4xx_it.c          Interrupt handlers
  - I2C/I2C_TwoBoards_MasterTx_SlaveRx_DMA/Src/main.c                  Main program
  - I2C/I2C_TwoBoards_MasterTx_SlaveRx_DMA/Src/system_stm32l4xx.c      STM32L4xx system source file

@par Hardware and Software environment

  - This example runs on STM32L496ZG devices.
    
  - This example has been tested with NUCLEO-L496ZG (144 pins) board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-L496ZG (144 pins) Set-up
    - Connect GPIOs connected to Board Slave I2C3 SCL/SDA (PC.0 and PC.1)
    to respectively Board Master SCL and SDA pins of I2C3 (PC.0 and PC.1).
      - I2C3_SCL  PC.0 (CN11, pin 38) : connected to I2C3_SCL PC.0 (CN11, pin 38) 
      - I2C3_SDA  PC.1 (CN11, pin 36) : connected to I2C3_SDA PC.1 (CN11, pin 36)
    - Connect Master board GND to Slave Board GND

  - Launch the program. Press User push-button to initiate a write request by Master 
      then Slave receive bytes.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory (The user can choose between Master 
   and Slave target through "#define SLAVE_BOARD" in the "main.h" file)
    o Comment "#define SLAVE_BOARD" and load the project in Master Board
    o Uncomment "#define SLAVE_BOARD" and load the project in Slave Board
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
