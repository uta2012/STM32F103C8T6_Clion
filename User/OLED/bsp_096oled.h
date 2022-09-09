#ifndef __BSP_096OLED_H__
#define __BSP_096OLED_H__


#include "spi.h"
#include "stm32f4xx_hal.h"	//链接HAL库
#include "delay.h"
#include "oled_font.h"



#define OLED_SPI    hspi1
#define OLED_WIDTH  128
#define OLED_HIGHT  64

extern const uint8_t ABC[1][16];

void OLED_Reset(void);
void OLED_Send_Data(uint8_t data);
void OLED_Send_Command(uint8_t command);
void OLED_Set_Position(uint8_t x, uint8_t y);
void OLED_Init(void);
void OLED_Full(void);
void OLED_Clean(void);
void OLED_Put_Char(uint8_t x, uint8_t y, uint8_t *Character);

#endif


