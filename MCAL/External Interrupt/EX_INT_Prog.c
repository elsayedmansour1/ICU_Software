#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"EX_INT_Reg.h"
#include"EX_INT_Config.h"
#include"../Global Interrupt/GIE_config.h"

/****** Global Pointer To Function *********/
static void (*GPFunc0)(void)=NULL;
static void (*GPFunc1)(void)=NULL;
static void (*GPFunc2)(void)=NULL;

void INT0_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc0=LocPFunc;	
}
void INT1_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc1=LocPFunc;	
}
void INT2_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc2=LocPFunc;	
}
ISR(__vector_1)
{
	if(GPFunc0!=NULL)
	{
		GPFunc0();
	}
}
ISR(__vector_2)
{
	if(GPFunc1!=NULL)
	{
		GPFunc1();
	}
}
ISR(__vector_3)
{
	if(GPFunc2!=NULL)
	{
		GPFunc2();
	}
}
void EX_INT0_enable(void)
{
	/*ENABLE EXTERNAL ENTERRUPT 0*/
		SET_BIT(GICR ,INT0);
}
void EX_INT0_Sence_Mode(u8 Sence_Mode )
{

	switch(Sence_Mode)
	{
	case Falling_Adge :
		CLR_BIT(MCUCR ,ISC00);
		SET_BIT(MCUCR ,ISC01);
	break;
	case Rising_Adge :
		SET_BIT(MCUCR ,ISC00);
		SET_BIT(MCUCR ,ISC01);		
	break;
	case Low_Level : 
		CLR_BIT(MCUCR ,ISC00);
		CLR_BIT(MCUCR ,ISC01);		
	break;
	case Any_Change :
		SET_BIT(MCUCR ,ISC00);
		CLR_BIT(MCUCR ,ISC01);		
	break;
	}
}
void EX_INT1_Sence_Mode(u8 Sence_Mode )
{
	/*ENABLE EXTERNAL ENTERRUPT 1*/
	SET_BIT(GICR ,INT1);
	switch(Sence_Mode)
	{
	case Falling_Adge :
		CLR_BIT(MCUCR ,ISC10);
		SET_BIT(MCUCR ,ISC11);
	break;
	case Rising_Adge :
		SET_BIT(MCUCR ,ISC10);
		SET_BIT(MCUCR ,ISC11);		
	break;
	case Low_Level : 
		CLR_BIT(MCUCR ,ISC10);
		CLR_BIT(MCUCR ,ISC11);		
	break;
	case Any_Change :
		SET_BIT(MCUCR ,ISC10);
		CLR_BIT(MCUCR ,ISC11);		
	break;
	}
}
void EX_INT2_Sence_Mode(u8 Sence_Mode )
{
	/*ENABLE EXTERNAL ENTERRUPT 2*/
	SET_BIT(GICR ,INT2);
	switch(Sence_Mode)
	{
	case Falling_Adge :
	CLR_BIT(MCUCSR ,ISC2);
	break;
	case Rising_Adge :
	SET_BIT(MCUCSR ,ISC2);		
	break;
	}
}
