#ifndef _TIMRER1_INTERFACE_H
#define _TIMRER1_INTERFACE_H

void TMR1_OF_SetCallBack(void(*LocPFunc)(void));
void TMR1_OCA_SetCallBack(void(*LocPFunc)(void));
void TMR1_IC_SetCallBack(void(*LocPFunc)(void));

void TIMER1_INIT(void);
void TIMER1_OverFlow_Interrupt_Enable(void);
void TIMER1_OCAM_Interrupt_Enable(void);
void TIMER1_OCBM_Interrupt_Enable(void);
void TIMER1_IC_Interrupt_Enable(void);
void TIMER1_Timer_Counter(u16 Value_of_TCNT1);
void TIMER1_Output_Compare_Register_1A(u16 Value_of_OCR1A);
void TIMER1_Output_Compare_Register_1B(u16 Value_of_OCR1B);














#endif
