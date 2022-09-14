/**
******************************************************************************
* @file    ${FILE_NAME}
* @author  ${USER}
* @date    ${TIME} ${DATE}
* @brief   None.
*
******************************************************************************
* @attention
*
* Copyright (c) ${YEAR} UTA.
* All rights reserved.
*
* By(UTA personally owned)
* https://blog.csdn.net/qq_51913390
*
******************************************************************************
*/
/********************************End of Head************************************/


#ifndef __RETARGET_H__
#define __RETARGET_H__

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include <sys/stat.h>
#include <stdio.h>

void RetargetInit(UART_HandleTypeDef *huart);

int _isatty(int fd);

int _write(int fd, char *ptr, int len);

int _close(int fd);

int _lseek(int fd, int ptr, int dir);

int _read(int fd, char *ptr, int len);

int _fstat(int fd, struct stat *st);



#endif //__RETARGET_H__
/********************************End of File************************************/