#ifndef _TIMRER0_INTERFACE_H
#define _TIMRER0_INTERFACE_H

void TMR0_OF_SetCallBack(void(*LocPFunc)(void));
void TMR0_OCM_SetCallBack(void(*LocPFunc)(void));

void TIMER0_INIT(void);
void TIMER0_OverFlow_Interrupt_Enable(void);
void TIMER0_OCM_Interrupt_Enable(void);
void TIMER0_Timer_Counter(u8 Value_of_TCNT0);
void TIMER0_Output_Compare(u8 Value_of_OCR0);
void TIMER0_Set_Duty_Cycle(u8 Duty_Cycle );












#endif
