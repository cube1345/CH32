#include "system.h"
#include "debug.h"
#include  "../General_Files/drivers/SSD1306.h"
#include "KeyPress.h"

extern int time;
extern uint8_t count; 
extern int press_time;
extern int press_result;

void System_Init()
{
    SSD1306_Init();
    KeyPress_Init();
}

void System_Loop()
{
        SSD1306_ShowStr(0,0,"time:",SSD1306_SIZE_8,SSD1306_PO);
        SSD1306_ShowStr(0,1,"count:",SSD1306_SIZE_8,SSD1306_PO);
        SSD1306_ShowStr(0,2,"press_time:",SSD1306_SIZE_8,SSD1306_PO);
        SSD1306_ShowNum(70,0,time,4,SSD1306_SIZE_8,SSD1306_PO);
        SSD1306_ShowNum(70,1,count,4,SSD1306_SIZE_8,SSD1306_PO);
        SSD1306_ShowNum(70,2,press_time,4,SSD1306_SIZE_8,SSD1306_PO);
        
        switch(press_result)
        {
        case 1: SSD1306_ShowStr(0,5,"one   ",SSD1306_SIZE_16,SSD1306_PO);
        break;
        case 2: SSD1306_ShowStr(0,5,"two   ",SSD1306_SIZE_16,SSD1306_PO);
        break;
        case 3: SSD1306_ShowStr(0,5,"long   ",SSD1306_SIZE_16,SSD1306_PO);
        break;
        }
        //上述OLED显示，可改成其他应用层函数
        
}
