#ifndef __SYSTEM_H
#define __SYSTEM_H

#ifdef __cplusplus
 extern "C" {
#endif

//============================��ϵͳ��ʼ����================================
void System_Init();

//==============================����ѭ����=================================
void System_Loop();

//=============================��������=================================
void System_Error_Handler();

#ifdef __cplusplus
 }
#endif

#endif /* __SYSTEM_H */


