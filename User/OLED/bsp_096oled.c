#include "bsp_096oled.h"
/***********************************
	本驱动文件仅适配HAL库版本
***********************************/




void OLED_Reset(void)
{
    HAL_GPIO_WritePin(OLED_RES_GPIO_Port, OLED_RES_Pin, GPIO_PIN_RESET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(OLED_RES_GPIO_Port, OLED_RES_Pin, GPIO_PIN_SET);
}

void OLED_Send_Data(uint8_t data)
{
    HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_SET);
    HAL_SPI_Transmit(&OLED_SPI, &data, 1, 0xFF);
}

void OLED_Send_Command(uint8_t command)
{
    HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&OLED_SPI, &command, 1, 0xFF);
}


void OLED_Set_Position(uint8_t x, uint8_t y)
{
    OLED_Send_Command(0xB0+y);//设置页
    OLED_Send_Command((x & 0x0F) | 0x00);
    OLED_Send_Command((x & 0xF0 >> 4) | 0x10);
}



void OLED_Init(void)
{
    OLED_Reset();

    OLED_Send_Command(0xAE);
    OLED_Send_Command(0x00);
    OLED_Send_Command(0x10);
    OLED_Send_Command(0x40);
    OLED_Send_Command(0XA1);
    OLED_Send_Command(0xC8);
    OLED_Send_Command(0XA6);


    OLED_Send_Command(0xA8);

    OLED_Send_Command(0x3F);
    OLED_Send_Command(0xD3);//bit2，开启/关闭
    OLED_Send_Command(0x00);//设置内存地址模式
    OLED_Send_Command(0xD5);//[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;
    OLED_Send_Command(0x80);//段重定义设置,bit0:0,0->0;1,0->127;
    OLED_Send_Command(0xD9);//设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数
    OLED_Send_Command(0xF1);//设置COM硬件引脚配置
    OLED_Send_Command(0xDA);//[5:4]配置

    OLED_Send_Command(0x12);//对比度设置
    OLED_Send_Command(0xDB);//1~255;默认0X7F (亮度设置,越大越亮)
    OLED_Send_Command(0x00);//设置预充电周期
    OLED_Send_Command(0x20);//[3:0],PHASE 1;[7:4],PHASE 2;
    OLED_Send_Command(0x00);//设置VCOMH 电压倍率
    OLED_Send_Command(0x8D);//[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;
    OLED_Send_Command(0x14);//全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
    OLED_Send_Command(0xA4);//设置显示方式;bit0:1,反相显示;0,正常显示
    OLED_Send_Command(0xA6);//开启显示
    OLED_Send_Command(0xAF);//开启显示
    OLED_Clean();


}



void OLED_Full(void)
{
    //set column
    OLED_Send_Command(0x21);
    OLED_Send_Command(0x00);
    OLED_Send_Command(0x7E);
    //set page
    OLED_Send_Command(0x22);
    OLED_Send_Command(0x00);
    OLED_Send_Command(0x07);
    uint8_t x, y;

    for(y=0; y<8; y++)
    {
        for(x=0; x<OLED_WIDTH; x++)
        {
            OLED_Send_Data(0xFF);
        }
    }
}

void OLED_Clean(void)
{

    //set column
    OLED_Send_Command(0x21);
    OLED_Send_Command(0x00);
    OLED_Send_Command(0x7F);
    //set page
    OLED_Send_Command(0x22);
    OLED_Send_Command(0x00);
    OLED_Send_Command(0x07);

    uint8_t x, y;
    for(y=0; y<8; y++)
    {
        OLED_Send_Command(0xB0+y);
        OLED_Send_Command(0x01);
        OLED_Send_Command(0x10);
        for(x=0; x<OLED_WIDTH; x++)
        {
            OLED_Send_Data(0x00);
        }
    }
}

void OLED_Put_Char(uint8_t x, uint8_t y, uint8_t *Character)
{

    //set column x
    OLED_Send_Command(0x21);
    OLED_Send_Command(x*8);
    OLED_Send_Command(x*8+0x07);
    //set page y
    OLED_Send_Command(0x22);
    OLED_Send_Command(y*2);
    OLED_Send_Command(y*2+0x02);

    for(uint8_t i=0; i<16; i++)
    {
        OLED_Send_Data(0x00);
    }
//set column x
    OLED_Send_Command(0x21);
    OLED_Send_Command(x*8);
    OLED_Send_Command(x*8+0x07);
    //set page y
    OLED_Send_Command(0x22);
    OLED_Send_Command(y*2);
    OLED_Send_Command(y*2+0x02);
    for(uint8_t i=0; i<16; i++)
    {
        OLED_Send_Data(Character[i]);
    }




}




