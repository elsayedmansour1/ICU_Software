#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"TIMER2_Reg.h"
#include"TIMER2_Config.h"
#include"../Global Interrupt/GIE_config.h"

/****** Global Pointer To Function *********/
static void (*GPFunc_OF)(void)=NULL;
static void (*GPFunc_OCM)(void)=NULL;

void TMR2_OF_SetCallBack(void(*LocPFunc)(void))
{
GPFunc_OF=LocPFunc;	
}
void TMR2_OCM_SetCallBack(void(*LocPFunc)(void))
{
GPFunc_OCM=LocPFunc;	
}
ISR(__vector_5)
{
	if(GPFunc_OF!=NULL)
	{
		GPFunc_OF();
	}
	
}
ISR(__vector_4)
{
	
	if(GPFunc_OCM!=NULL)
	{
		GPFunc_OCM();
	}
}
void TIMER2_INIT(void)
{
	/*********************TIMER0 MODE*************************/
	#if	TIMER2_MODE==Normal
		CLR_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);
	#elif	TIMER2_MODE==PWM_Phase_Correct
		SET_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);
	#elif     TIMER2_MODE==CTC
		CLR_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
	#elif     TIMER2_MODE==Fast_PWM
		SET_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
	#endif

	/*********************TIMER0 PRESCALER*************************/
	#if	TIMER2_Prescaler==TIMER2_NO_CLOCK_SOURCE
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
          #elif	TIMER2_Prescaler==TIMER2_NO_PRESCALER
          SET_BIT(TCCR2,CS20);
          CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
          #elif 	TIMER2_Prescaler==TIMER2_Prescaler_8
          CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
          #elif 	TIMER2_Prescaler==TIMER2_Prescaler_64
          SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22); 
	#elif 	TIMER2_Prescaler==TIMER2_Prescaler_256
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	#elif 	TIMER2_Prescaler==TIMER2_Prescaler_1024
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	#elif 	TIMER2_Prescaler==TIMER2_FALLING_ADGE
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	#elif 	TIMER2_Prescaler==TIMER2_RISING_ADGE
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
          #endif
	/*********************TIMER0 OC0 MODE*************************/
	#if	TIMER2_OC2_MODE==OC2_disconnected
		CLR_BIT(TCCR2,COM20);
		CLR_BIT(TCCR2,COM21);
	#elif 	TIMER2_OC2_MODE==Toggle_OC2
		SET_BIT(TCCR2,COM20);
		CLR_BIT(TCCR2,COM21);
	#elif 	TIMER2_OC2_MODE==RESERVED
		SET_BIT(TCCR2,COM20);
		CLR_BIT(TCCR2,COM21);
	#elif 	TIMER2_OC2_MODE==Clear_OC2
		CLR_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
	#elif 	TIMER2_OC0_MODE==Set_OC2
		SET_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
	#endif
}	
void TIMER2_OverFlow_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,TOIE2);
}
void TIMER2_OCM_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,OCIE2);
}

void TIMER2_Timer_Counter(u8 Value_of_TCNT2)
{
	TCNT2=Value_of_TCNT2;
}
void TIMER2_Output_Compare(u8 Value_of_OCR2)
{
	OCR2=Value_of_OCR2;
}
void TIMER2_Set_Duty_Cycle(u8 Duty_Cycle )
{
	OCR2=(Duty_Cycle*255)/100;
}
