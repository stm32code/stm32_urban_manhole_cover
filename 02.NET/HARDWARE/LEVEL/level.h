#ifndef __LEVEL_H
#define __LEVEL_H

#include "stm32f10x.h"

//  ���Ŷ���
#define LEVEL1_GPIO_CLK RCC_APB2Periph_GPIOA
#define LEVEL1_GPIO_PORT GPIOA
#define LEVEL1_GPIO_PIN GPIO_Pin_0

#define LEVEL2_GPIO_CLK RCC_APB2Periph_GPIOA
#define LEVEL2_GPIO_PORT GPIOA
#define LEVEL2_GPIO_PIN GPIO_Pin_6

#define LEVEL3_GPIO_CLK RCC_APB2Periph_GPIOA
#define LEVEL3_GPIO_PORT GPIOA
#define LEVEL3_GPIO_PIN GPIO_Pin_7

#define LEVEL1 GPIO_ReadInputDataBit(LEVEL1_GPIO_PORT, LEVEL1_GPIO_PIN) // ��ȡ
#define LEVEL2 GPIO_ReadInputDataBit(LEVEL2_GPIO_PORT, LEVEL2_GPIO_PIN) // ��ȡ
#define LEVEL3 GPIO_ReadInputDataBit(LEVEL3_GPIO_PORT, LEVEL3_GPIO_PIN) // ��ȡ

void Level_GPIO_Config(void);

#endif /* __LEVEL_H */
