/**
  @page ADC_RegularConversion_Interrupt conversion using interrupt

  @verbatim
  ******************************************************************************
  * @file    ADC/ADC_RegularConversion_Interrupt/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC RegularConversion interrupt example.
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

How to use the ADC in interrupt mode to convert data through the HAL API.

The ADC1 is configured to convert continuously ADC_CHANNEL_5.

Each time an end of conversion occurs an interrupt is generated and the converted 
data of ADC1 DR register is affected to the uhADCxConvertedValue variable in the 
ADC conversion complete call back function.


Conversion time (reference manual, "Reset and clock control" and "ADC clocks" sections):
  1) the system clock is 80 MHz.
  2) __HAL_RCC_ADC_CONFIG() macro in HAL_ADC_MspInit() API sets the system clock as ADC asynchronous clock source 
  2) ClockPrescaler field of initialization structure is set to ADC_CLOCK_ASYNC_DIV1
     => the input ADC clock is set in asynchronous clock mode   
     => the input ADC clock is the undivided system clock 


  Sampling time is set to ADC_SAMPLETIME_6CYCLES_5 (6.5 cycles).
  ConvTime = Sampling time + 12.5 ADC clock cycles.
           = 19 clock cycles
           = (19 / 80 MHz) = 237.5 ns 
           


Use an external power supply, adjust supply voltage and connect it to pin GPIO_PIN_0 of GPIOA (Arduino pin A4).
This allows to modify ADC_CHANNEL_5 voltage.

The converted value can be monitored through the debugger using the uhADCxConvertedValue variable.

STM32 board LED can be used to monitor the conversion:
  - LED1 is ON if an error occurs.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents 

  - ADC/ADC_RegularConversion_Interrupt/Inc/stm32l4xx_hal_conf.h    HAL configuration file
  - ADC/ADC_RegularConversion_Interrupt/Inc/stm32l4xx_it.h          DMA interrupt handlers header file
  - ADC/ADC_RegularConversion_Interrupt/Inc/main.h                  Header for main.c module  
  - ADC/ADC_RegularConversion_Interrupt/Src/stm32l4xx_it.c          DMA interrupt handlers
  - ADC/ADC_RegularConversion_Interrupt/Src/main.c                  Main program
  - ADC/ADC_RegularConversion_Interrupt/Src/stm32l4xx_hal_msp.c     HAL MSP file 
  - ADC/ADC_RegularConversion_Interrupt/Src/system_stm32l4xx.c      STM32L4xx system source file

@par Hardware and Software environment 

  - This example runs on STM32L4R9xx devices.
  
  - This example has been tested with STM32L4R9I-Discovery board and can be
    easily tailored to any other supported device and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
