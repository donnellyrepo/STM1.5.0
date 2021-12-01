/**
  ******************************************************************************
  * @file    FIREWALL/FIREWALL_VolatileData_Shared/Src/protected_volatile_data.c
  * @author  MCD Application Team
  * @brief   Definition of array to be located in Firewall protected volatile data segment (in SRAM1)
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

#if defined(__ICCARM__)
#pragma section =".firewall_vdata"
#endif

/* Protected non-executable volatile data area (VDE = 0) */

/* The Firewall protects the area from 0x20000000 to  0x2000023F

  fw_init.VDataSegmentStartAddress    = 0x20000000;
  fw_init.VDataSegmentLength          = 0x240;   

  The lines below are extracted from IAR scatter file stm32l496xx_flash.icf.   
  The scatter file locates protected_volatile_array in a sub-region starting at 0x20000200. 
    ...
    define symbol __ICFEDIT_protected_region_SRAM1_b_start__    = 0x20000200;
    define symbol __ICFEDIT_protected_region_SRAM1_b_end__      = 0x2000023F;
    ...
    define region protected_SRAM1_b_region    = mem:[from __ICFEDIT_protected_region_SRAM1_b_start__   to __ICFEDIT_protected_region_SRAM1_b_end__];
    ...
    place in protected_SRAM1_b_region   {readwrite section .firewall_vdata };
    ...
        
 */
#if defined(__ICCARM__)
#pragma default_variable_attributes = @ ".firewall_vdata"
#endif 
#if defined(__GNUC__)
uint32_t __attribute__((section(".vdata_protected_data")))  protected_volatile_array[N] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
#else
uint32_t protected_volatile_array[N] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
#endif 

/* Stop placing data in section protected_SRAM1_b_region */
#if defined(__ICCARM__)
#pragma default_variable_attributes =
#endif







/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

