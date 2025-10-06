#include "KeyPress.h"
#include "SSD1306.h"
#include "ch32v30x_gpio.h"
#define  Key   GPIO_Pin_6
int time = 0;
uint8_t count = 0;
uint8_t press_flag = 0;
int press_time;
int press_result;
uint8_t timeEN = 0; //此乃定时器的开关
// 按键初始化函数
void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = Key;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 浮空输入，若为上拉输入，可改为GPIO_Mode_IPU
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
/** 
  *函数：分辨按键的单击、双击、长按的初始化
  *参数：无
  *说明：打开时钟，并配置定时器2的定时中断
*/
void KeyPress_Init(void)
{
    Key_Init();

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    // 使能TIM2时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    // 定时器基本参数配置，确保1ms中断一次
    TIM_TimeBaseStructure.TIM_Period = 9; // 自动重装载值
    TIM_TimeBaseStructure.TIM_Prescaler = 14400 - 1; // 预分频值
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // 使能TIM2中断
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    // 配置NVIC
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    // 使能TIM2
    TIM_Cmd(TIM2, ENABLE);
}
/** 
  *函数：分辨按键的单击、双击、长按
  *参数：无
  *说明：检测到按键单击时，输出1；
  *       检测到双击时，输出2；
  *       检测到长按时，输出3；
  *       采用了定时器2的定时中断
*/
// TIM2中断服务函数
void TIM2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        // 在这里添加定时中断处理代码
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        

        // 检测按键单击
        if (GPIO_ReadInputDataBit(GPIOA, Key) == 0 && press_flag == 0) // 按键按下，且之前未按下
        {
			timeEN = 1;//在按键按下，允许定时器定时中断具有计时功能
            count++;
            press_flag = 1; // 标记按键已按下
        }
        else if (GPIO_ReadInputDataBit(GPIOA, Key) == 1) // 按键释放
        {
            press_flag = 0; // 标记按键已释放,若再按下，说明了双击，或者多击...
        }
		if(press_flag == 1) press_time ++;//开始记录按下时间	
		if(time >= 1800 && count == 1 && press_time <= 800) press_result = 1;
		if(time >= 1800 && count == 2 && press_time <= 800) press_result = 2;
		if(time >= 1800 && count == 1 && press_time > 800) press_result = 3;

		
		if(timeEN == 1)
		{
			time++;
			if (time == 2000)
			{
				time = 0;
				// 可以在这里添加每2s的额外处理逻辑
				press_flag = 0;
				press_time = 0;//每一个周期后，按键按下的时间重新计算
				count = 0;
				timeEN = 0;
			}
		}
    }
}










