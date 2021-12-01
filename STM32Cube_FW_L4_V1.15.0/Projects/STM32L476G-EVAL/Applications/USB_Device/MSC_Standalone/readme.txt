/**
  @page MSC_Standalone USB Device Mass Storage (MSC) example
  
  @verbatim
  ******************************************************************************
  * @file    USB_Device/MSC_Standalone/readme.txt  
  * @author  MCD Application Team
  * @brief   Description of the USB Device MSC application.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license SLA0044,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       http://www.st.com/SLA0044
  *
  ******************************************************************************
  @endverbatim

@par Application Description 

Use of the USB device application based on the Mass Storage Class (MSC).

This example is part of the USB Device Library package using STM32Cube firmware.

This is a typical application on how to use the STM32L4xx USB OTG Device peripheral to communicate with a PC
Host using the Bulk Only Transfer (BOT) and Small Computer System Interface (SCSI) transparent commands, 
while the microSD card is used as storage media. The STM32 MCU is enumerated as a MSC device using the 
native PC Host MSC driver to which the STM32L476G-EVAL board is connected.

At the beginning of the main program the HAL_Init() function is called to reset all the peripherals,
initialize the Flash interface and the systick. The user is provided with the SystemClock_Config()
function to configure the system clock (SYSCLK) to run at 80 MHz. The Full Speed (FS) USB module uses
internally a 48-MHz clock, which is generated from an integrated PLL. 

When the application is started, the user has just to plug the USB cable into a PC host and the device 
is automatically detected. A new removable drive appears in the system window and write/read/format 
operations can be performed as with any other removable drive.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      
For more details about the STM32Cube USB Device library, please refer to UM1734 
"STM32Cube USB Device library".
      
@par Directory contents

  - USB_Device/MSC_Standalone/Src/main.c                  Main program
  - USB_Device/MSC_Standalone/Src/system_stm32l4xx.c      STM32L4xx system clock configuration file
  - USB_Device/MSC_Standalone/Src/stm32l4xx_it.c          Interrupt handlers
  - USB_Device/MSC_Standalone/Src/usbd_conf.c             General low level driver configuration
  - USB_Device/MSC_Standalone/Src/usbd_desc.c             USB device MSC descriptor
  - USB_Device/MSC_Standalone/Src/ubsd_storage.c          Media Interface Layer
  - USB_Device/MSC_Standalone/Inc/main.h                  Main program header file
  - USB_Device/MSC_Standalone/Inc/stm32l4xx_it.h          Interrupt handlers header file
  - USB_Device/MSC_Standalone/Inc/stm32l4xx_hal_conf.h    HAL configuration file
  - USB_Device/MSC_Standalone/Inc/usbd_conf.h             USB device driver Configuration file
  - USB_Device/MSC_Standalone/Inc/usbd_desc.h             USB device MSC descriptor header file
  - USB_Device/MSC_Standalone/Inc/ubsd_storage.h          Media Interface Layer header file   

	
@par Hardware and Software environment

  - This example runs on STM32L476xx devices.
    
  - This example has been tested with STMicroelectronics STM32L476G-EVAL 
    evaluation boards and can be easily tailored to any other supported device 
    and development board.

  - STM32L476G-EVAL Set-up
    - Make sure that LCD Glass is in position IO
    - Connect the STM32L476G-EVAL board to the PC through 'USB micro A-Male 
      to A-Male' cable to the connector CN1 (OTG-FS)
    - Make sure jumper JP1 is in connected in position 3V3.
      
@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
 
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
  