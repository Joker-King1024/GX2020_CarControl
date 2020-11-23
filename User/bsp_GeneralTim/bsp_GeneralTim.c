
#include "bsp_GeneralTim.h" 

extern u16 Left_Forward;
extern u16 Left_Backward;
extern u16 Right_Forward;
extern u16 Right_Backward;

static void GENERAL_TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // ����Ƚ�ͨ��1 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH1_PORT, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��2 GPIO ��ʼ��
	//RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH2_PORT, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��3 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH3_PORT, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��4 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH4_PORT, &GPIO_InitStructure);
}


static void GENERAL_TIM_GPIO_Config_Tim5(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // ����Ƚ�ͨ��1 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK5, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH1_PIN5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH1_PORT5, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��2 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK5, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH2_PIN5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH2_PORT5, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��3 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK5, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH3_PORT5, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��4 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH4_GPIO_CLK5, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH4_PIN5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH4_PORT5, &GPIO_InitStructure);
}


static void GENERAL_TIM_Mode_Config(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM_CLK,ENABLE);
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period;	
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler;	
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(GENERAL_TIM, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC1Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC2Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC3Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC4Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	// ʹ�ܼ�����
	TIM_Cmd(GENERAL_TIM, ENABLE);
}


static void GENERAL_TIM_Mode_Config_Tim5()
{
		TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
  // ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	GENERAL_TIM_APBxClock_FUN5(GENERAL_TIM_CLK5,ENABLE);

/*--------------------ʱ���ṹ���ʼ��-------------------------*/
	// �������ڣ���������Ϊ100K
	
 
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period5;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler5;	
	// ʱ�ӷ�Ƶ���� ����������ʱ��ʱ��Ҫ�õ�
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// �ظ���������ֵ��û�õ����ù�
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(GENERAL_TIM5, &TIM_TimeBaseStructure);
	
	

	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// ����Ƚ�ͨ�� 1
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC1Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC2Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC3Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC4Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);

	// ʹ�ܼ�����
	TIM_Cmd(GENERAL_TIM5, ENABLE);
	
}

//ǰ�� 
// PWM_PA0() ��ǰ��  PA0
// PWM_PA1() ��ǰ��  PA1
// PWM_PA2() �����  PA2
// PWM_PA3() �Һ���  PA3
void PWM_PA0(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = Left_Forward;
	
	TIM_OC1Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
}

void PWM_PA1(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = Right_Forward;
	
	TIM_OC2Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
}

void PWM_PA2(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = Left_Backward;
	
	TIM_OC3Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
}

void PWM_PA3(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = Right_Backward;
	
	TIM_OC4Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
}



// ���� 
// PWM_PA4() ��ǰ��  PA6
// PWM_PA5() ��ǰ��  PA7
// PWM_PA6() �����  PB0
// PWM_PA7() �Һ���  PB1
void PWM_PA4(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = Left_Forward;
	
	TIM_OC1Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}

void PWM_PA5(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = Right_Forward;
	
	TIM_OC2Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}

void PWM_PA6(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = Left_Backward;
	
	TIM_OC3Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}

void PWM_PA7(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = Right_Backward;
	
	TIM_OC4Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}

void PWM_Init(void)
{
	GENERAL_TIM_Mode_Config();	
	GENERAL_TIM_Mode_Config_Tim5();
}

void GENERAL_TIM_Init(void)
{
	GENERAL_TIM_GPIO_Config();
	GENERAL_TIM_GPIO_Config_Tim5();
	GENERAL_TIM_Mode_Config();	
	GENERAL_TIM_Mode_Config_Tim5();	
}

/*********************************************END OF FILE**********************/
