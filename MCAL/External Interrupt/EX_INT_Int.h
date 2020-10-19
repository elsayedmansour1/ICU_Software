#ifndef _EX_INT_INTERFACE_H_
#define _EX_INT_INTERFACE_H_

void INT0_SetCallBack(void(*LocPFunc)(void));
void INT1_SetCallBack(void(*LocPFunc)(void));
void INT2_SetCallBack(void(*LocPFunc)(void));


void EX_INT0_enable	   (	void      );
void EX_INT0_Sence_Mode(u8 Sence_Mode );
void EX_INT1_Sence_Mode(u8 Sence_Mode );
void EX_INT2_Sence_Mode(u8 Sence_Mode );















#endif
