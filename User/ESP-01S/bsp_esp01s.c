#include "bsp_esp01s.h"

//
//void ESP_Init(void)
//{
//    HAL_GPIO_WritePin(ESP_01S_EN_GPIO_Port, ESP_01S_EN_Pin, GPIO_PIN_SET);
//    HAL_Delay(50);
//    HAL_GPIO_WritePin(ESP_01S_RST_GPIO_Port, ESP_01S_RST_Pin, GPIO_PIN_RESET);
//    HAL_Delay(50);
//    HAL_GPIO_WritePin(ESP_01S_RST_GPIO_Port, ESP_01S_RST_Pin, GPIO_PIN_SET);
//}
//
//
//
//extern uint8_t a;
//extern uint8_t b;
//
//
//
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//
//    //printf("HAL_UART_RxCpltCallback\n");
//
////    if(huart->Instance == USART1)
////    {
////        //printf("USART1\n");
////        HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
////        HAL_UART_Receive_IT(&huart1, &a, 1);
////        //printf("HAL_UART_RxCpltCallback\n");
////    }
//    if (huart->Instance == USART2)
//    {
//        //printf("USART2\n");
//        HAL_UART_Transmit(&huart1, &b, 1, 0);
//        HAL_UART_Receive_IT(&huart2, &b, 1);
//    }
//
//}
//
