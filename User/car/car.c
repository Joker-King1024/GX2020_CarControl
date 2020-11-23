#include "car.h"

extern u16 Left_Forward;
extern u16 Left_Backward;
extern u16 Right_Forward;
extern u16 Right_Backward;


// ADC1????????MDA????SRAM
extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL1];
extern __IO uint32_t ADC_ConvertedValue3[NOFCHANEL3];

// ????,????????????? 	 
float ADC_ConvertedValueLocal[NOFCHANEL1*2]; 
float ADC_ConvertedValueLocal3[NOFCHANEL3*2]; 

// ????
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

static void CAR_DOWN(void)
{	
		PWM_PA0();
		PWM_PA1();
		PWM_PA2();
		PWM_PA3();
	TIM_Cmd(TIM4,ENABLE);
	TIM_ClearFlag(TIM6,TIM_FLAG_Update);
	TIM_SetCounter(TIM6,0x00);
	while(1){
		ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
		ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
		ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
		ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
		ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3;
		ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
		PWM_PA0();
		PWM_PA1();
		PWM_PA2();
		PWM_PA3();
		if(ADC_ConvertedValueLocal[0]>1)
		{
			Right_Forward=Desired_Number;
			Right_Backward=Desired_Number;
		}
		if(ADC_ConvertedValueLocal[1]>1)
		{
			Left_Forward=Desired_Number;
      Left_Backward=Desired_Number;
		}
		if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)&&ADC_ConvertedValueLocal[0]>1&&ADC_ConvertedValueLocal[1]>1)
		{
			break;
		}
	}
	TIM_Cmd(TIM4,DISABLE);
	PWM_Init();
}

static void CAR_GO(void)
{
	
		PWM_PA4();
		PWM_PA5();
		PWM_PA6();
		PWM_PA7();
	TIM_Cmd(TIM4,ENABLE);
	TIM_ClearFlag(TIM6,TIM_FLAG_Update);
	TIM_SetCounter(TIM6,0x00);
	while(1){
		ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
			ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
			ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3;
			ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
			ADC_ConvertedValueLocal[6] =(float) ADC_ConvertedValue[6]/4096*3.3;
			ADC_ConvertedValueLocal[7] =(float) ADC_ConvertedValue[7]/4096*3.3;

      printf("\r\n CH0 = %f V \r\n",ADC_ConvertedValueLocal[0]);
			printf("\r\n CH1 = %f V \r\n",ADC_ConvertedValueLocal[1]);
			printf("\r\n CH2 = %f V \r\n",ADC_ConvertedValueLocal[2]);
			printf("\r\n CH3 = %f V \r\n",ADC_ConvertedValueLocal[3]);
			printf("\r\n CH4 = %f V \r\n",ADC_ConvertedValueLocal[4]);
			printf("\r\n CH5 = %f V \r\n",ADC_ConvertedValueLocal[5]);
			printf("\r\n CH6 = %f V \r\n",ADC_ConvertedValueLocal[6]);
			printf("\r\n CH7 = %f V \r\n",ADC_ConvertedValueLocal[7]);
      printf("\r\n CH8 = %f V \r\n",ADC_ConvertedValueLocal3[0]);
			printf("\r\n CH9 = %f V \r\n",ADC_ConvertedValueLocal3[1]);
			printf("\r\n CH10 = %f V \r\n",ADC_ConvertedValueLocal3[2]);
			printf("\r\n CH11 = %f V \r\n",ADC_ConvertedValueLocal3[3]);
		  printf("\r\n\r\n");
		  Delay(0x200000); 
		PWM_PA4();
		PWM_PA5();
		PWM_PA6();
		PWM_PA7();
		if(ADC_ConvertedValueLocal[0]>1)
		{
			Right_Forward=Desired_Number;
			Right_Backward=Desired_Number;
		}
		if(ADC_ConvertedValueLocal[1]>1)
		{
			Left_Forward=Desired_Number;
      Left_Backward=Desired_Number;
		}
		if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)&&ADC_ConvertedValueLocal[0]>1&&ADC_ConvertedValueLocal[1]>1)
		{
			break;
		}
	}
	TIM_Cmd(TIM4,DISABLE);
	PWM_Init();
}

static void CAR_LEFT(void)
{
		PWM_PA0();
		PWM_PA5();
		PWM_PA6();
		PWM_PA3();
	TIM_Cmd(TIM4,ENABLE);
	TIM_ClearFlag(TIM6,TIM_FLAG_Update);
	TIM_SetCounter(TIM6,0x00);
	while(1){
		ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
		ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
		ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
		ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
		ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3;
		ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
		PWM_PA0();
		PWM_PA5();
		PWM_PA6();
		PWM_PA3();
		if(ADC_ConvertedValueLocal[0]>1)
		{
			Right_Forward=Desired_Number;
			Right_Backward=Desired_Number;
		}
		if(ADC_ConvertedValueLocal[1]>1)
		{
			Left_Forward=Desired_Number;
      Left_Backward=Desired_Number;
		}
		if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)&&ADC_ConvertedValueLocal[0]>1&&ADC_ConvertedValueLocal[1]>1)
		{
			break;
		}
	}
	TIM_Cmd(TIM4,DISABLE);
	PWM_Init();
}

static void CAR_RIGHT(void)
{
		PWM_PA4();
		PWM_PA1();
		PWM_PA2();
		PWM_PA7();
	TIM_Cmd(TIM4,ENABLE);
	TIM_ClearFlag(TIM6,TIM_FLAG_Update);
	TIM_SetCounter(TIM6,0x00);
	while(1){
		ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
		ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
		ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
		ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
		ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3;
		ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
		PWM_PA4();
		PWM_PA1();
		PWM_PA2();
		PWM_PA7();
		if(ADC_ConvertedValueLocal[0]>1)
		{
			Right_Forward=Desired_Number;
			Right_Backward=Desired_Number;
		}
		if(ADC_ConvertedValueLocal[1]>1)
		{
			Left_Forward=Desired_Number;
      Left_Backward=Desired_Number;
		}
		if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)&&ADC_ConvertedValueLocal[0]>1&&ADC_ConvertedValueLocal[1]>1)
		{
			break;
		}
	}
	TIM_Cmd(TIM4,DISABLE);
	PWM_Init();
}

void CAR_Go(u8 step)
{
	u8 i=0;
	for(;i<step;i++)
	{
		CAR_GO();
	}
}

void CAR_Down(u8 step)
{
	u8 i=0;
	for(;i<step;i++)
	{
		CAR_DOWN();
	}
}

void CAR_Left(u8 step)
{
	u8 i=0;
	for(;i<step;i++)
	{
		CAR_LEFT();
	}
}

void CAR_Right(u8 step)
{
	u8 i=0;
	for(;i<step;i++)
	{
		CAR_RIGHT();
	}
}

