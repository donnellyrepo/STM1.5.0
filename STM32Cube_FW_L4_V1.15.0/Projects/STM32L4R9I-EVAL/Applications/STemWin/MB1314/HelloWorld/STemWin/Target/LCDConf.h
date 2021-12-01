/**
  ******************************************************************************
  * @file    LCDConf.h
  * @author  MCD Application Team
  * @brief   Header for LCDConf.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license SLA0044,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        http://www.st.com/SLA0044
  *
  ******************************************************************************
  */  
#include "main.h"
#include "GUI.h"
#include "GUIDRV_Lin.h"

#ifndef LCDCONF_H
#define LCDCONF_H


typedef struct
{
  int32_t      address;          
  int32_t      pending_buffer;   
  int32_t      buffer_index;     
  int32_t      xSize;            
  int32_t      ySize;            
  int32_t      BytesPerPixel;
  LCD_API_COLOR_CONV   *pColorConvAPI;
}
LCD_LayerPropTypedef;

void LCD_WaitForDisplayCompletion( void );
void LCD_RefreshRequestedByApplication( void );

void DSI_IO_WriteCmd(uint32_t NbrParams, uint8_t *pParams);

#endif /* LCDCONF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
