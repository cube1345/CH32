#include "KeyPress.h"
#include "SSD1306.h"
#include "ch32v30x_gpio.h"
#define  Key   GPIO_Pin_6
int time = 0;
uint8_t count = 0;
uint8_t press_flag = 0;
int press_time;
int press_result;
uint8_t timeEN = 0; //���˶�ʱ���Ŀ���
// ������ʼ������
void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = Key;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // �������룬��Ϊ�������룬�ɸ�ΪGPIO_Mode_IPU
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
/** 
  *�������ֱ水���ĵ�����˫���������ĳ�ʼ��
  *��������
  *˵������ʱ�ӣ������ö�ʱ��2�Ķ�ʱ�ж�
*/
void KeyPress_Init(void)
{
    Key_Init();

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    // ʹ��TIM2ʱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    // ��ʱ�������������ã�ȷ��1ms�ж�һ��
    TIM_TimeBaseStructure.TIM_Period = 9; // �Զ���װ��ֵ
    TIM_TimeBaseStructure.TIM_Prescaler = 14400 - 1; // Ԥ��Ƶֵ
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // ʹ��TIM2�ж�
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    // ����NVIC
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    // ʹ��TIM2
    TIM_Cmd(TIM2, ENABLE);
}
/** 
  *�������ֱ水���ĵ�����˫��������
  *��������
  *˵������⵽��������ʱ�����1��
  *       ��⵽˫��ʱ�����2��
  *       ��⵽����ʱ�����3��
  *       �����˶�ʱ��2�Ķ�ʱ�ж�
*/
// TIM2�жϷ�����
void TIM2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        // ��������Ӷ�ʱ�жϴ������
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        

        // ��ⰴ������
        if (GPIO_ReadInputDataBit(GPIOA, Key) == 0 && press_flag == 0) // �������£���֮ǰδ����
        {
			timeEN = 1;//�ڰ������£�����ʱ����ʱ�жϾ��м�ʱ����
            count++;
            press_flag = 1; // ��ǰ����Ѱ���
        }
        else if (GPIO_ReadInputDataBit(GPIOA, Key) == 1) // �����ͷ�
        {
            press_flag = 0; // ��ǰ������ͷ�,���ٰ��£�˵����˫�������߶��...
        }
		if(press_flag == 1) press_time ++;//��ʼ��¼����ʱ��	
		if(time >= 1800 && count == 1 && press_time <= 800) press_result = 1;
		if(time >= 1800 && count == 2 && press_time <= 800) press_result = 2;
		if(time >= 1800 && count == 1 && press_time > 800) press_result = 3;

		
		if(timeEN == 1)
		{
			time++;
			if (time == 2000)
			{
				time = 0;
				// �������������ÿ2s�Ķ��⴦���߼�
				press_flag = 0;
				press_time = 0;//ÿһ�����ں󣬰������µ�ʱ�����¼���
				count = 0;
				timeEN = 0;
			}
		}
    }
}










