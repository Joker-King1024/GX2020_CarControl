#ifndef TIME_H
#define TIME_H

#include "stm32f10x.h"


/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM5

#define            GENERAL_TIM4                   TIM4
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK4               RCC_APB1Periph_TIM4
#define            GENERAL_TIM_PERIOD            0XFFFF
#define            GENERAL_TIM_PSC              (7-1)

// TIM ���벶��ͨ��GPIO��غ궨��
#define            GENERAL_TIM_CH1_GPIO_CLK4      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH1_PORT4          GPIOB
#define            GENERAL_TIM_CH1_PIN4           GPIO_Pin_6
#define            GENERAL_TIM_CHANNEL_x         TIM_Channel_1

#define            GENERAL_TIM_CH2_GPIO_CLK4      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH2_PORT4          GPIOB
#define            GENERAL_TIM_CH2_PIN4           GPIO_Pin_7
#define            GENERAL_TIM_CHANNEL_x2        TIM_Channel_2

#define            GENERAL_TIM_CH3_GPIO_CLK4      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH3_PORT4          GPIOB
#define            GENERAL_TIM_CH3_PIN4           GPIO_Pin_8
#define            GENERAL_TIM_CHANNEL_x3         TIM_Channel_3

#define            GENERAL_TIM_CH4_GPIO_CLK4      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH4_PORT4          GPIOB
#define            GENERAL_TIM_CH4_PIN4           GPIO_Pin_9
#define            GENERAL_TIM_CHANNEL_x4         TIM_Channel_4


// �ж���غ궨��
#define            GENERAL_TIM_IT_CCx            TIM_IT_CC1
#define            GENERAL_TIM_IRQ               TIM4_IRQn
#define            GENERAL_TIM_INT_FUN           TIM4_IRQHandler

// ��ȡ����Ĵ���ֵ�����궨��
#define            GENERAL_TIM_GetCapturex_FUN                 TIM_GetCapture1
// �����źż��Ժ����궨��
#define            GENERAL_TIM_OCxPolarityConfig_FUN           TIM_OC1PolarityConfig

// ��������ʼ����
#define            GENERAL_TIM_STRAT_ICPolarity                TIM_ICPolarity_Rising
// �����Ľ�������
#define            GENERAL_TIM_END_ICPolarity                  TIM_ICPolarity_Falling


void TIM_Init(void);

#endif	/* __BSP_GENERALTIME_H */
