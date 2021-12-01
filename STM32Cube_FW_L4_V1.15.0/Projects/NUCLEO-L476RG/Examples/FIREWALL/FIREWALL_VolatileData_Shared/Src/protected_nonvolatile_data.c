/**
  ******************************************************************************
  * @file    FIREWALL/FIREWALL_VolatileData_Shared/Src/protected_nonvolatile_data.c
  * @author  MCD Application Team
  * @brief   Definition of array to be located in Firewall protected non-volatile data segment (in FLASH)
  *******************************************************************************    
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include "main.h"

/* Protected non-volatile data area */

/* The Firewall protects the area from 0x080FF000 to 0x080FF0FF

  fw_init.NonVDataSegmentStartAddress = 0x080FF000;
  fw_init.NonVDataSegmentLength       = 0x100;

  The lines below are extracted from IAR scatter file stm32l476xx_flash.icf.  
  The scatter file locates protected_volatile_array in the region starting at 0x080FF000. 
    ...
    define symbol __ICFEDIT_protected_region_FLASH_start__    = 0x080FF000;
    define symbol __ICFEDIT_protected_region_FLASH_end__      = 0x080FF0FF;
    ...
   define region protected_FLASH_region    = mem:[from __ICFEDIT_protected_region_FLASH_start__   to __ICFEDIT_protected_region_FLASH_end__];
    ...
   place in  protected_FLASH_region {readonly object protected_nonvolatile_data.o};
    ...
 */
#if defined(__GNUC__)
const uint32_t __attribute__((section(".nvdata_protected_data")))  protected_non_volatile_array[N] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
#else
const uint32_t protected_non_volatile_array[N] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
#endif 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
