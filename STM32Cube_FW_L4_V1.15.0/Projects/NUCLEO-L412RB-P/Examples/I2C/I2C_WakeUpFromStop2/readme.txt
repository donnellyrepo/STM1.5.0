/**
  @page I2C_WakeUpFromStop2 I2C Two Boards Communication IT Example on Stop 2 Mode
  
  @verbatim
  ******************************************************************************
  * @file    I2C/I2C_WakeUpFromStop2/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Wake Up from Stop 2 mode example
  ******************************************************************************
  *
  * Copyright (c) 2018 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description 

How to handle I2C data buffer transmission/reception between two boards, 
using an interrupt when the device is in Stop 2 mode.

Board: NUCLEO-L412RB-P Rev C (embeds a STM32L412RBT6P device)
SCL Pin: PC0 (CN5, pin38)
SDA Pin: PC1 (CN5, pin36)

   _________________________                       _________________________ 
  |           ______________|                     |______________           |
  |          |I2C3          |                     |          I2C3|          |
  |          |              |                     |              |          |
  |          |          SCL |_____________________| SCL          |          |
  |          |              |                     |              |          |
  |          |              |                     |              |          |
  |          |              |                     |              |          |
  |          |          SDA |_____________________| SDA          |          |
  |          |              |                     |              |          |
  |          |______________|                     |______________|          |
  |                         |                     |                         |
  |                      GND|_____________________|GND                      |
  |_STM32_Board 1___________|                     |_STM32_Board 2___________|

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 16 Mhz.

The I2C peripheral configuration is ensured by the HAL_I2C_Init() function.
This later is calling the HAL_I2C_MspInit()function which core is implementing
the configuration of the needed I2C resources according to the used hardware (CLOCK, 
GPIO and NVIC). You may update this function to change I2C configuration.

The I2C communication is then initiated.
The project is splitted in two parts the Master Board and the Slave Board
- Master Board
  The HAL_I2C_Master_Receive_IT() and the HAL_I2C_Master_Transmit_IT() functions 
  allow respectively the reception and the transmission of a predefined data buffer
  in Master mode using interrupt.
- Slave Board
  The HAL_I2C_Slave_Receive_IT() and the HAL_I2C_Slave_Transmit_IT() functions 
  allow respectively the reception and the transmission of a predefined data buffer
  in Slave mode using interrupt.
The user can choose between Master and Slave through "#define MASTER_BOARD"
in the "main.c" file:
If the Master board is used, the "#define MASTER_BOARD" must be uncommented.
If the Slave board is used the "#define MASTER_BOARD" must be commented.

The user can disable internal pull-up through "#define EXTERNAL_PULL_UP_AVAILABLE"
This help for an integration of this example inside an ecosystem board with external pull-up */

For this example the aTxBuffer is predefined and the aRxBuffer size is same as aTxBuffer.

In a first step after the user presses the User push-button on the Master Board, I2C Master
starts the communication by sending aTxBuffer through HAL_I2C_Master_Transmit_IT() to 
I2C Slave which wakes up from Stop 2 mode and receives aRxBuffer through HAL_I2C_Slave_Receive_IT(). 
The second step starts when the user presses the User push-button on the Master Board,
the I2C Slave after wake up from Stop 2 mode at address match, sends aTxBuffer through HAL_I2C_Slave_Transmit_IT()
to the I2C Master which receives aRxBuffer through HAL_I2C_Master_Receive_IT().
The end of this two steps are monitored through the HAL_I2C_GetState() function
result.
Finally, aTxBuffer and aRxBuffer are compared through Buffercmp() in order to 
check buffers correctness.  

NUCLEO-L412RB-P Rev C's LEDs can be used to monitor the transfer status on the Master Board :
 - LED4 is ON when the transmission process is complete.
 - LED4 is OFF when the reception process is complete.
 - LED4 is slowly blinking (1 sec. period) in case of error in initialization or 
transmission/reception process

@note I2Cx instance used and associated resources can be updated in "main.h"
file depending hardware configuration used.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - I2C/I2C_WakeUpFromStop2/Inc/stm32l4xx_hal_conf.h    HAL configuration file
  - I2C/I2C_WakeUpFromStop2/Inc/stm32l4xx_it.h          I2C interrupt handlers header file
  - I2C/I2C_WakeUpFromStop2/Inc/main.h                  Header for main.c module
  - I2C/I2C_WakeUpFromStop2/Src/stm32l4xx_it.c          I2C interrupt handlers
  - I2C/I2C_WakeUpFromStop2/Src/main.c                  Main program
  - I2C/I2C_WakeUpFromStop2/Src/system_stm32l4xx.c      STM32L4xx system source file
  - I2C/I2C_WakeUpFromStop2/Src/stm32l4xx_hal_msp.c     HAL MSP file

@par Hardware and Software environment

  - This example runs on STM32L412xx devices.
    
  - This example has been tested with NUCLEO-L412RB-P Rev C board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-L412RB-P Rev C Set-up
    - Connect I2C_SCL line of Master board (PC0, CN5, pin38) to I2C_SCL line of Slave Board (PC0, CN5, pin38).
    - Connect I2C_SDA line of Master board (PC1, CN5, pin36) to I2C_SDA line of Slave Board (PC1, CN5, pin36).
    - Connect GND of Master board to GND of Slave Board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
    o Uncomment "#define MASTER_BOARD" and load the project in Master Board
    o Comment "#define MASTER_BOARD" and load the project in Slave Board
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
