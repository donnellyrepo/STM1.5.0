/**
  @page CRYP_GCM_GMAC_CMAC_Modes  Encrypt/decrypt data and compute authentication tag 
  with GCM, GMAC and CMAC AES algorithms.
  
  @verbatim
  ******************************************************************************
  * @file    CRYP/CRYP_GCM_GMAC_CMAC_Modes/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the CRYP GCM, GMAC and CMAC Algorithms
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

How to encrypt and decrypt data, and compute an authentication tag with GCM,
GMAC, and CMAC AES algorithms.

This example provides a short description of how to use the CRYP AES peripheral to
- encrypt and decrypt data as well as to compute an authentication tag using 
  AES-based GCM algorithm with a 128-bit long key,
- compute an authentication tag using AES-based GMAC algorithm with a 256-bit long key,
- compute an authentication tag using AES-based CMAC algorithm with a 256-bit long key.

For GCM algorithm,
  Ciphering/Tag computation with a 128-bit long key is used in interrupt mode with data type set to 32-bit (no swapping).
  Deciphering/Tag computation is used in polling mode.
  The ciphering output is used as deciphering input. 
For GMAC algorithm,
  Tag computation with a 256-bit long key is used in DMA mode with data type set to 1-bit (bit swapping).
For CMAC algorithm,
  Tag computation with a 256-bit long key is used in polling mode with data type set to 32-bit (no swapping).  


The example unrolls as follows: 
- GCM encryption and tag computation (Header + Plain Data --> Encrypted Data + Authentication tag)
- GCM decryption and tag computation (Header + Encrypted Data --> Decrypted Data + Authentication tag)
- GMAC tag computation (Header --> Authentication tag)
- CMAC tag computation (Header --> Authentication tag)


Plain data and headers, encrypted and decrypted data, authentication tags are output via STLink Virtual COM Port and display 
in an Hyperterminal console on a remote Host computer. 
 
When all ciphering and deciphering operations are successful, LED2 is turned on.
In case of ciphering or deciphering issue, LED2 toggles. 


@par Directory contents 

  - CRYP/CRYP_GCM_GMAC_CMAC_Modes/Inc/stm32l4xx_hal_conf.h    HAL configuration file
  - CRYP/CRYP_GCM_GMAC_CMAC_Modes/Inc/stm32l4xx_it.h          Interrupt handlers header file
  - CRYP/CRYP_GCM_GMAC_CMAC_Modes/Inc/main.h                  Header for main.c module  
  - CRYP/CRYP_GCM_GMAC_CMAC_Modes/Src/stm32l4xx_it.c          Interrupt handlers
  - CRYP/CRYP_GCM_GMAC_CMAC_Modes/Src/main.c                  Main program
  - CRYP/CRYP_GCM_GMAC_CMAC_Modes/Src/stm32l4xx_hal_msp.c     HAL MSP module
  - CRYP/CRYP_GCM_GMAC_CMAC_Modes/Src/system_stm32l4xx.c      STM32L4xx system source file


@par Hardware and Software environment

   - This example runs on STM32L462xx devices.
  
    - This example has been tested with a STM32L462xx embedded on an 
    NUCLEO-L452RE Rev C board and can be easily tailored to any other supported 
    device and development board.

  - HyperTerminal setup of COM port associated to STLink Virtual COM Port:
    - Baud rate = 9600 
    - Data = 8 bit
	- Parity = none
    - Stop = 1 bit
    - No hardware flow control

@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
