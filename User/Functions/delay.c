/**
  ******************************************************************************
  * @file    delay.c
  * @author  ROG Zephyrus M16
  * @date    11:48 AM 8/19/2022
  * @brief   None.
  *          
  ******************************************************************************
  * @attention
  * 
  * Copyright (c) 2022 UTA.
  * All rights reserved.
  *
  * By(UTA personally owned)
  * https://blog.csdn.net/qq_51913390
  *
  ******************************************************************************
  @verbatim
   
   None
   
  ******************************************************************************
  */
/********************************End of Head************************************/

/* Includes ------------------------------------------------------------------*/
#include "delay.h"



/**
 * @brief  delay us.
 * @param  delay us
 * @retval None
 */
//在此函数中加入初始化sysytick定时器步骤
//参照正点原子例程进行修改
void Delay_us(uint32_t us)
{
    uint32_t ticks;
    uint32_t told,tnow,reload,tcnt=0;
    if((0x0001&(SysTick->CTRL)) ==0)    //定时器未工作
        vPortSetupTimerInterrupt();  //初始化定时器

    reload = SysTick->LOAD;                     //获取重装载寄存器值
    ticks = us * (SystemCoreClock / 1000000);  //计数时间值
    told=SysTick->VAL;                          //获取当前数值寄存器值（开始时数值）

    while(1)
    {
        tnow=SysTick->VAL;          //获取当前数值寄存器值
        if(tnow!=told)              //当前值不等于开始值说明已在计数
        {

            if(tnow<told)             //当前值小于开始数值，说明未计到0
                tcnt+=told-tnow;     //计数值=开始值-当前值

            else                  //当前值大于开始数值，说明已计到0并重新计数
                tcnt+=reload-tnow+told;   //计数值=重装载值-当前值+开始值  （已
            //从开始值计到0）

            told=tnow;                //更新开始值
            if(tcnt>=ticks)break;     //时间超过/等于要延迟的时间,则退出.
        }
    }
}

//SystemCoreClock为系统时钟(system_stmf4xx.c中)，通常选择该时钟作为
//systick定时器时钟，根据具体情况更改

void Delay_ms(uint32_t ms)
{
    while(ms--)
        Delay_us(1000);

}


/********************************End of File************************************/