/**
  ******************************************************************************
  * @file    information.c
  * @author  MCD Application Team
  * @brief   information module functions
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
#include "Resources.h"
#include "information_res.h"

#include "DIALOG.h"


/** @addtogroup INFORMATION_MODULE
  * @{
  */

/** @defgroup INFORMATION
  * @brief information routines
  * @{
  */

/* Exported variables --------------------------------------------------------*/
WM_HWIN hInformation;

/* Private function prototypes -----------------------------------------------*/
static void Startup(WM_HWIN hWin, uint16_t xpos, uint16_t ypos);

/* Private typedef -----------------------------------------------------------*/
K_ModuleItem_Typedef  information =
{
  4,
  "information",
  0,
  Startup,
  NULL,
};

/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
enum
{
  /* Buttons */
  ID_BUTTON_BACK = (GUI_ID_USER + 0x01),

  /* Texts */
  ID_TEXT_TITLE,
};

static unsigned int WindowIsMoving   = 0;

/**
  * @brief  Paints back button
  * @param  hObj: button handle
  * @retval None
  */
static void _OnPaint_ButtonBack(BUTTON_Handle hObj)
{
  if (GetMotionWindowVisibility() == 0)
  {
    GUI_DrawBitmap(&bmback_button_bkg, 0, 17);
    GUI_DrawBitmap(&bmbutton_back, 63, 25);
  }
}

/**
  * @brief  callback for back button
  * @param  pMsg: pointer to data structure of type WM_MESSAGE
  * @retval None
  */
static void _cbButtonBack(WM_MESSAGE * pMsg) 
{
  switch (pMsg->MsgId) 
  {
    case WM_PAINT:
      _OnPaint_ButtonBack(pMsg->hWin);
      break;

    default:
      /* The original callback */
      BUTTON_Callback(pMsg);
      break;
  }
}

/**
  * @brief  Information window callback
  * @param  pMsg: pointer to data structure of type WM_MESSAGE
  * @retval None
  */
static void _cbInformation(WM_MESSAGE * pMsg) 
{
  WM_HWIN hItem;

  switch (pMsg->MsgId) 
  {
    case WM_CREATE:
      hItem = TEXT_CreateEx(0, 25, 390, 40, pMsg->hWin, WM_CF_HIDE, 0, ID_TEXT_TITLE, "System Information");
      TEXT_SetFont(hItem, &GUI_FontRobotoC_bold22);
      TEXT_SetTextColor(hItem, GUI_WHITE);
      TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
      break;

    case WM_PAINT:
      if (GetMotionWindowVisibility() == 0)
      {
        GUI_DrawBitmap(&bminformation, 0, 0);

        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TITLE);
        WM_HideWindow(hItem);
      }
      else
      {
        if (WindowIsMoving == 0)
        {
          hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TITLE);
          WM_ShowWindow(hItem);
        }
        else
        {
          hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TITLE);
          WM_HideWindow(hItem);
        }

        GUI_DrawBitmap(&bmmodule_entry_icon, (LCD_GetXSize() - bmmodule_entry_icon.XSize) / 2, (LCD_GetYSize() - bmmodule_entry_icon.YSize) / 2);
        GUI_DrawBitmap(&bminfo_icon, (LCD_GetXSize() - bminfo_icon.XSize) / 2, (LCD_GetYSize() - bminfo_icon.YSize) / 2);
      }
      break;

    case WM_NOTIFY_PARENT:
    {
      switch(WM_GetId(pMsg->hWinSrc))
        {
          /* Back button from the info window */
        case ID_BUTTON_BACK:
          {
            switch(pMsg->Data.v)
            {
              case WM_NOTIFICATION_CLICKED:
                BackToMainScreen();  
                break;
            }
          }
          break;
        }
    }
    break;

    case WM_MOVE:
    {
      if ((WM_GetWindowOrgX(pMsg->hWin) % LCD_GetXSize()) == 0)
      {
        WindowIsMoving = 0;
      }
      else
      {
        WindowIsMoving = 1;
      }
      WM_DefaultProc(pMsg);
    }
    break;

    default:
      WM_DefaultProc(pMsg);
      break;
  }
}

/**
  * @brief  clock faces window Startup
  * @param  hWin: pointer to the parent handle.
  * @param  xpos: X position 
  * @param  ypos: Y position
  * @retval None
  */
static void Startup(WM_HWIN hWin, uint16_t xpos, uint16_t ypos)
{
  int xSize;
  int ySize;
  BUTTON_Handle hButtonBack;

  /* Get the LCD sizes */
  xSize = LCD_GetXSize();
  ySize = LCD_GetYSize();

  /* Create the menu window */
  hInformation = WM_CreateWindowAsChild(xpos, ypos, xSize, ySize, WM_HBKWIN, WM_CF_SHOW | WM_CF_HASTRANS, _cbInformation, 0);

  /* Create buttons to be used */
  hButtonBack = BUTTON_CreateEx(90, 335, 210, 55, hInformation, WM_CF_SHOW | WM_CF_HASTRANS | WM_CF_STAYONTOP, 0 , ID_BUTTON_BACK);
  WM_SetCallback(hButtonBack, _cbButtonBack);
}


/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
