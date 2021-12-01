/**
  ******************************************************************************
  * @file    audio_recorder_app.h
  * @author  MCD Application Team   
  * @brief   header of audio recorder application file
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __AUDIO_RECORDER_APP_H
#define __AUDIO_RECORDER_APP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "../common/audio_if.h"   
/* Exported constants --------------------------------------------------------*/
#define DEFAULT_REC_AUDIO_VOLUME                   60
/* Exported types ------------------------------------------------------------*/

typedef enum
{
  AUDIO_RECORDER_ERROR_NONE = 0, 
  AUDIO_RECORDER_ERROR_IO,
  AUDIO_RECORDER_ERROR_HW, 
  AUDIO_RECORDER_ERROR_MEM, 
  AUDIO_RECORDER_ERROR_FORMAT_NOTSUPPORTED,   
  
}AUDIO_RECORDER_ErrorTypdef;

#define AUDIO_RECORDER_StateTypdef    IN_StateTypdef
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_Init(uint8_t volume);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_SelectFile(char* file, uint8_t mode);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_StartRec(uint32_t frequency);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_DeInit(void);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_StopRec(void);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_StopPlay(void);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_GetFileInfo(char* file, WAV_InfoTypedef* info);
uint32_t                    AUDIO_RECORDER_GetElapsedTime(void);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_Stop(void);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_PauseResume(void);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_DeInit(void);
AUDIO_RECORDER_StateTypdef  AUDIO_RECORDER_GetState(void);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_Play(uint32_t frequency);
uint32_t                    AUDIO_RECORDER_GetPlayedTime(void);
uint32_t                    AUDIO_RECORDER_GetTotalTime(void);
AUDIO_RECORDER_ErrorTypdef  AUDIO_RECORDER_StopPlayer(void);
void                        AUDIO_RECORDER_RemoveAudioFile(char const*fname);

#ifdef __cplusplus
}
#endif

#endif /*__AUDIO_RECORDER_APP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
