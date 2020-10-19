#ifndef _TIMRER2_INTERFACE_H
#define _TIMRER2_INTERFACE_H

void TMR2_OF_SetCallBack(void(*LocPFunc)(void));
void TMR2_OCM_SetCallBack(void(*LocPFunc)(void));

void TIMER2_INIT(void);
void TIMER2_OverFlow_Interrupt_Enable(void);
void TIMER2_OCM_Interrupt_Enable(void);
void TIMER2_Timer_Counter(u8 Value_of_TCNT2);
void TIMER2_Output_Compare(u8 Value_of_OCR2);
void TIMER2_Set_Duty_Cycle(u8 Duty_Cycle );












#endif
