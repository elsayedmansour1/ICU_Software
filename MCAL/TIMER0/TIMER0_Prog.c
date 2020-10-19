#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"TIMER0_Reg.h"
#include"TIMER0_Config.h"
#include"../Global Interrupt/GIE_config.h"

/****** Global Pointer To Function *********/
static void (*GPFunc_OF)(void)=NULL;
static void (*GPFunc_OCM)(void)=NULL;

void TMR0_OF_SetCallBack(void(*LocPFunc)(void))
{
GPFunc_OF=LocPFunc;	
}
void TMR0_OCM_SetCallBack(void(*LocPFunc)(void))
{
GPFunc_OCM=LocPFunc;	
}
ISR(__vector_11)
{
	if(GPFunc_OF!=NULL)
	{
		GPFunc_OF();
	}
	
}
ISR(__vector_10)
{
	
	if(GPFunc_OCM!=NULL)
	{
		GPFunc_OCM();
	}
}
void TIMER0_INIT(void)
{
	/*********************TIMER0 MODE*************************/
	#if	TIMER0_MODE==Normal	
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	#elif	TIMER0_MODE==PWM_Phase_Correct 
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	#elif     TIMER0_MODE==CTC
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	#elif     TIMER0_MODE==Fast_PWM
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	#endif

	/*********************TIMER0 PRESCALER*************************/
	#if	TIMER0_Prescaler==TIMER0_NO_CLOCK_SOURCE	
    CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
          #elif	TIMER0_Prescaler==TIMER0_NO_PRESCALER
          SET_BIT(TCCR0,CS00);
          CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
          #elif 	TIMER0_Prescaler==TIMER0_Prescaler_8
          CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
          #elif 	TIMER0_Prescaler==TIMER0_Prescaler_64
          SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02); 
	#elif 	TIMER0_Prescaler==TIMER0_Prescaler_256
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	#elif 	TIMER0_Prescaler==TIMER0_Prescaler_1024
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	#elif 	TIMER0_Prescaler==TIMER0_FALLING_ADGE
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	#elif 	TIMER0_Prescaler==TIMER0_RISING_ADGE
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
          #endif
	/*********************TIMER0 OC0 MODE*************************/
	#if	TIMER0_OC0_MODE==OC0_disconnected
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif 	TIMER0_OC0_MODE==Toggle_OC0
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif 	TIMER0_OC0_MODE==RESERVED
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif 	TIMER0_OC0_MODE==Clear_OC0
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#elif 	TIMER0_OC0_MODE==Set_OC0
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#endif
}	
void TIMER0_OverFlow_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void TIMER0_OCM_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,OCIE0);
}

void TIMER0_Timer_Counter(u8 Value_of_TCNT0)
{
	TCCR0=Value_of_TCNT0;
}
void TIMER0_Output_Compare(u8 Value_of_OCR0)
{
	OCR0=Value_of_OCR0;
}
void TIMER0_Set_Duty_Cycle(u8 Duty_Cycle )
{
	u16 value=0;
	value=(Duty_Cycle*255)/100;
	OCR0=value;
}
