/**
  ******************************************************************************
  * @file    USB_Host/CDC_Standalone/Src/explorer.c
  * @author  MCD Application Team
  * @brief   This file provides uSD Card drive configuration
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
FATFS SD_FatFs;
char SD_Path[4]; 
FILELIST_FileTypeDef FileList;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the SD Storage.
  * @param  None
  * @retval Status
  */
uint8_t SD_StorageInit(void)
{
  /*Initializes the SD card device*/
  BSP_SD_Init();
  
  /* Check if the SD card is plugged in the slot */
  if(BSP_SD_IsDetected() == SD_PRESENT )
  {
    /* Link the SD Card disk I/O driver */
    if(FATFS_LinkDriver(&SD_Driver, SD_Path) == 0)
    {
      if((f_mount(&SD_FatFs, (TCHAR const*)SD_Path, 0) != FR_OK))
      {
        /* FatFs Initialization Error */
        LCD_ErrLog("Cannot Initialize FatFs! \n");
        return 1;
      }
      else
      {
        LCD_DbgLog ("INFO : FatFs Initialized! \n");
      }
    }  
  }
  else
  {
    LCD_ErrLog("SD card NOT plugged \n");
    return 1;
  }
  return 0;
}

/**
  * @brief  Copies disk content in the explorer list.
  * @param  None
  * @retval Operation result
  */
FRESULT SD_StorageParse(void)
{
  FRESULT res;
  FILINFO fno;
  DIR dir;
  char *fn;
  
#if _USE_LFN
  static char lfn[_MAX_LFN];
  fno.lfname = lfn;
  fno.lfsize = sizeof(lfn);
#endif
  
  res = f_opendir(&dir, SD_Path);
  FileList.ptr = 0;
  
  if(res == FR_OK)
  {
    while (1)
    {
      res = f_readdir(&dir, &fno);
      
      if(res != FR_OK || fno.fname[0] == 0)
      {
        break;
      }
      if(fno.fname[0] == '.')
      {
        continue;
      }
#if _USE_LFN
      fn = *fno.lfname ? fno.lfname : fno.fname;
#else
      fn = fno.fname;
#endif
      
      if(FileList.ptr < FILEMGR_LIST_DEPDTH)
      {
        if((fno.fattrib & AM_DIR) == 0)
        {
          strncpy((char *)FileList.file[FileList.ptr].name, (char *)fn, FILEMGR_FILE_NAME_SIZE);
          FileList.file[FileList.ptr].type = FILETYPE_FILE;
          FileList.ptr++;
        }
      }   
    }
  }
  f_closedir(&dir);
  return res;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
